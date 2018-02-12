#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include "util/delay.h"
#include <stdbool.h>		//bool
#include <avr/pgmspace.h>	//PSTR
#include "io_config/io_config.h"
#include "sensors/sensors.h"
#include "servo/servo.h"
#include "uart/mkuart.h"

#define bufor_rx_size		16			// size of receive buffer		(2^4)
#define bufor_tx_size		5			// size of broadcasting buffer	(4+1)
#define bufor_rx_max_index	4			// max index of received frame	(5-1)

// direction | speed gripper | gripper up/down | gripper jaws | servo step mode
char bufor_rx[bufor_rx_size] = { 0x5, 0x5, 0x55, 0x3C, 0x65 }; // NOT NULL 0x0 { 5, 5, 85, 60, 101 }
char bufor_tx[bufor_tx_size];

volatile uint16_t Timer = 0;

void clear_bufor(void);
void get_bufor(void);


int main(void){
	pwm_dc_user = 0xff;
	speed_gripper = 50;

	config_timers();
	config_pwm();
	config_adc();
	config_servo();
	us_015_config();
	tcrt_5000_init();

	sei();	// enable global interrupt
	USART_Init( __UBRR );	// initialization USART

while(1){
/*********************** update and send bufor_tx[], read US-015 value ***********************/
	if ( Timer > 2500 ){		// 2500 == ~500 ms

		us_015_trigger();

		if( bufor_rx[bufor_rx_max_index] && bufor_rx[0] == 0x6 ){	// display ADC value (no pulses)
			bufor_tx[0] = (char)measurement( PA6 );
			bufor_tx[1] = (char)measurement( PA7 );

		}else{
			bufor_tx[0] = (char)tcrt_5000_left;
			tcrt_5000_left = 100;
			bufor_tx[1] = (char)tcrt_5000_right;
			tcrt_5000_right = 100;
		}

		bufor_tx[2] = (char)us_015_value();
		bufor_tx[3] = (char)(us_015_value() >> 8);

		uart_puts(bufor_tx);
		Timer = 0;
	}

/******************************** read and analyze bufor_rx[] ********************************/
	if ( !(Timer % 500) ){	// 500 == ~100 ms

		get_bufor();		// read data from UART

		if( bufor_rx[bufor_rx_max_index] ) platform_control( bufor_rx[0] );

		if( bufor_rx[bufor_rx_max_index] ) set_speed_gripper( bufor_rx[1] );

		if( bufor_rx[bufor_rx_max_index] ) pwm_dc_user = bufor_rx[4];

		if( !strncasecmp("AT+RST?", bufor_rx, 7) ) {
			cli();              // disable interrupts
			wdt_enable( 0 );  	// set  watchdog
			while(1);           // wait for RESET
		}

	}

/**************************** read value from ADC (in while loop) ****************************/
	if( !(Timer % speed_gripper ) && bufor_rx[bufor_rx_max_index] )					// speed gripper
	{
		speed_gripper_change( bufor_rx[2], bufor_rx[3] );
		Timer++;	//this case event only one
	}
	tcrt_5000( bufor_rx[0] );

	}//end while(1)
}//end main(void)
/******************************* interrupt from US-015 echo pin ******************************/
ISR(INT1_vect)
{
	us_015_permission();
}

/****************** 100 kHz -> 0.01 ms -> 10 us (US-015 echo signal counter) *****************/
ISR(TIMER2_COMP_vect)
{
	us_015_measurement();
}

/*********** 5 kHz -> 0.2 ms -> 200 us (software PWM, TowerPro MG996R 360 Robotic) ***********/
ISR(TIMER0_COMP_vect)
{
	static uint16_t pwm_timer;

	if (pwm_dc_set)
	{
		( pwm_timer <= serwo_fr_set ) ? (serwo_fr_on) : (serwo_fr_off);
		( pwm_timer <= serwo_fl_set ) ? (serwo_fl_on) : (serwo_fl_off);
		( pwm_timer <= serwo_br_set ) ? (serwo_br_on) : (serwo_br_off);
		( pwm_timer <= serwo_bl_set ) ? (serwo_bl_on) : (serwo_bl_off);
		( pwm_timer >= pwm_dc_set ) ? (pwm_dc_on) : (pwm_dc_off);
	}

	( pwm_timer >= 100 ) ? pwm_timer=0  : pwm_timer++;

	Timer++;
}

/** We collect data from the buffer and assign a char array of size "bufor_size" characters **/
void  get_bufor (void)
{
	register char temp_sign;

	temp_sign=uart_getc();

		if( temp_sign >= 1 )
		{
			clear_bufor();
			for( uint8_t i=0; i<bufor_rx_size; i++ )
			{
			   ( temp_sign >= 1 ) ? ( bufor_rx[i]=temp_sign ) : ( i=bufor_rx_size );
			   temp_sign=uart_getc();
			}
		}
}

/************************************ clear bufor[] array ************************************/
void clear_bufor(void)
{
	for( uint8_t x = 0; x < bufor_rx_size; x++ ){ bufor_rx[x] = '\0';	}
}




