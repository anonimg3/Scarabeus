#include <avr/io.h>
#include "util/delay.h"
#include "sensors.h"

void us_015_config(void)
{
	DDRA |= (1<<PA0);				// Trig US-015
	PORTA |= (1<<PA0);				// ON Trig US-015

    // US-015
    DDRD &= ~(1<<PD3); 		// konfiguracja 2 pinu portu D jako wejście
    PORTD &= ~ (1<<PD3); 	// ustawienie rezystora podciągającego
    MCUCR |= (1<<ISC10);	// any logical change on INT1 generates an interrupt request.
    GICR |= (1<<INT1); 		// włączamy przerwanie INT1
}

void tcrt_5000( char current_direction )
{

	if ( current_direction == 0x1 ||  current_direction == 0x4 )
		{

			temp_right_value = measurement( PA7 );		// dokonujemy pomiaru na kanale PA7
			if ( lock_right == 1 && (temp_right_value < temp_right_value_old )  )
			{
				current_direction == 0x1 ? tcrt_5000_right++ : tcrt_5000_right--;
				lock_right = 0;
			}

			if ( lock_right == 0  && (temp_right_value > temp_right_value_old +5 )  )
			{
				lock_right = 1;
			}
			temp_right_value_old = temp_right_value;


			temp_left_value = measurement( PA6 );		// dokonujemy pomiaru na kanale PA6
			if ( lock_left == 1 && (temp_left_value < temp_left_value_old )  )
			{
				current_direction == 0x1 ? tcrt_5000_left++ : tcrt_5000_left--;
				lock_left = 0;
			}

			if ( lock_left == 0  && (temp_left_value > temp_left_value_old +5 )  )
			{
				lock_left = 1;
			}
			temp_left_value_old = temp_left_value;

		}
}

uint8_t measurement( uint8_t channel )
{
	ADMUX = (ADMUX & 0b11111000) | channel;
	ADCSRA |= (1<<ADSC);  // start konwersji
	while( ADCSRA & (1<<ADSC) );
	return (uint8_t)ADCW;
}

void us_015_permission(void)
{
	if ( (PIND & (1<<PD3)) ){
		us_015_start = 1;

	}else{
		us_015_start = 0;
		us_015 = us_015_counter;
		us_015_counter = 0;
	}
}

void us_015_trigger(void)
{
	if ( !us_015_start ){	// start the measurement US-015
		PORTA |= (1<<PA0);	// ON Trig US-015
		_delay_us(20);
		PORTA &= ~(1<<PA0); // OFF Trig US-015
	}
}

uint16_t us_015_value(void)
{
	return us_015;
}

void us_015_measurement(void)
{
	if ( us_015_start ) {us_015_counter++;}
}

void tcrt_5000_init(void)
{
	tcrt_5000_left = 100;
	tcrt_5000_right = 100;
	temp_right_value = 0xff;
	temp_right_value_old = 0xff;
	temp_left_value = 0xff;
	temp_left_value_old = 0xff;
}























