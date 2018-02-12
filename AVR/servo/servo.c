#include <avr/io.h>
#include "servo.h"

void speed_gripper_change(char servo_arm, char servo_jaw)
{
	if( servo_arm > OCR1A ){ OCR1A++; }
	if( servo_arm < OCR1A ){ OCR1A--; }
	if( servo_jaw > OCR1B ){ OCR1B++; }
	if( servo_jaw < OCR1B ){ OCR1B--; }
}

void platform_control(char direction)
{
	if( direction == _forward )	// forward
	{
		pwm_dc_set = pwm_dc_user;
		serwo_fl_set = backward_PWM;
		serwo_fr_set = forward_PWM;
		serwo_bl_set = backward_PWM;
		serwo_br_set = forward_PWM;
	}

	if( direction == _backward )	// backward
	{
		pwm_dc_set = pwm_dc_user;
		serwo_fl_set = forward_PWM;
		serwo_fr_set = backward_PWM;
		serwo_bl_set = forward_PWM;
		serwo_br_set = backward_PWM;
	}

	if( direction == _left )	// left
	{
		pwm_dc_set = pwm_dc_user;
		serwo_fl_set = forward_PWM;
		serwo_fr_set = forward_PWM;
		serwo_bl_set = forward_PWM;
		serwo_br_set = forward_PWM;
	}

	if( direction == _right )	// right
	{
		pwm_dc_set = pwm_dc_user;
		serwo_fl_set = backward_PWM;
		serwo_fr_set = backward_PWM;
		serwo_bl_set = backward_PWM;
		serwo_br_set = backward_PWM;
	}

	if( direction == _stop )	// stop
	{
		pwm_dc_set = 0x0;
		serwo_fl_set = 0;
		serwo_fr_set = 0;
		serwo_bl_set = 0;
		serwo_br_set = 0;
		PORTB |= (1<<PB4); 		// pwm_dc_on;
	}
}

void set_speed_gripper(char speed)
{
	if ( speed > 0 ) speed_gripper = speed * 20;
}



