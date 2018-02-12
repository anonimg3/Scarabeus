#ifndef SERVO_H_
#define SERVO_H_

#define forward_PWM			3	// right forward PWM
#define backward_PWM		10	// left forward	PWM

uint8_t pwm_dc_user;
uint16_t speed_gripper;

volatile uint8_t pwm_dc_set;
volatile uint8_t serwo_fl_set;
volatile uint8_t serwo_fr_set;
volatile uint8_t serwo_br_set;
volatile uint8_t serwo_bl_set;

enum { _forward = 0x01, _left, _right, _backward, _stop };

void speed_gripper_change(char servo_arm, char servo_jaw);
void set_speed_gripper(char speed);
void platform_control(char direction);

#endif /* SERVO_H_ */
