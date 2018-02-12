#ifndef SENSORS_H_
#define SENSORS_H_


/* TCRT-5000 */
uint8_t tcrt_5000_left;
uint8_t tcrt_5000_right;
uint8_t temp_right_value;
uint8_t temp_right_value_old;
uint8_t temp_left_value;
uint8_t temp_left_value_old;
volatile uint8_t lock_left;		// 0 = false, 1 = true
volatile uint8_t lock_right;	// 0 = false, 1 = true

/* US-015 */
volatile uint8_t us_015_start;	// 0 = false, 1 = true
volatile uint16_t us_015_counter;
volatile uint16_t us_015;


void tcrt_5000_init(void);
void tcrt_5000( char current_direction );
uint8_t measurement( uint8_t channel );

void us_015_config(void);
void us_015_permission(void);
void us_015_trigger(void);
void us_015_measurement(void);
uint16_t us_015_value();

#endif /* SENSORS_H_ */
