#ifndef IO_CONFIG_H_
#define IO_CONFIG_H_

#define serwo_fr 		(1<<PB0)
#define serwo_fr_on 	PORTB |= serwo_fr
#define serwo_fr_off 	PORTB &=~serwo_fr

#define serwo_fl 		(1<<PB1)
#define serwo_fl_on 	PORTB |= serwo_fl
#define serwo_fl_off 	PORTB &=~serwo_fl

#define serwo_br 		(1<<PB2)
#define serwo_br_on 	PORTB |= serwo_br
#define serwo_br_off 	PORTB &=~serwo_br

#define serwo_bl 		(1<<PB3)
#define serwo_bl_on 	PORTB |= serwo_bl
#define serwo_bl_off 	PORTB &=~serwo_bl

#define pwm_dc 			(1<<PB4)
#define pwm_dc_on 		PORTB |= pwm_dc
#define pwm_dc_off 		PORTB &=~pwm_dc
#define pwm_dc_tog 		PORTB ^= pwm_dc

void config_timers(void);
void config_pwm(void);
void config_adc(void);
void config_servo(void);

#endif /* IO_CONFIG_H_ */
