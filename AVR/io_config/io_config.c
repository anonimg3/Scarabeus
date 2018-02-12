#include <avr/io.h>

#include "io_config.h"

void config_timers(void)
{
	//	100kHz -> 0.01ms -> 10us
	TCCR2 |= (1<<WGM21);         	// CTC mode
    TCCR2 |= (1<<CS21); 			// prescaler 8
    OCR2 = 19;               		// reset counter when 9 (0 - 255)
    TIMSK |= (1<<OCIE2);         	// permission to interrupt compare match

	// 5kHz -> 0.2ms -> 200us
	TCCR0 |= (1<<WGM01);         	// CTC mode
    TCCR0 |= (1<<CS01)|(1<<CS00); 	// prescaler 64
    OCR0 = 49;               		// reset counter when 24 (0 - 255)
    TIMSK |= (1<<OCIE0);         	// permission to interrupt compare match
}

void config_pwm(void)
{
    TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        	// NON Inverted PWM
    TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS12); 			// prescaler 256, mode 14 ( fast PWM )
    ICR1=1249;  										// fPWM = 50Hz ( period = 20ms standard )
    DDRD|=(1<<PD4)|(1<<PD5);   							// PWM pins as Out
}


void config_adc(void)
{
	ADCSRA |= (1<<ADEN); 						// enable ADC
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // prescaler = 128
	ADMUX |= (1<<REFS1)|(1<<REFS0);				// Uref = 2,56V (inside source)
}

void config_servo(void)
{
	DDRB |= serwo_fr | serwo_fl | serwo_br | serwo_bl | pwm_dc;
}
