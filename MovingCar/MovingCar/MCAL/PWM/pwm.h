/*
 * pwm.h
 *
 * Created: 4/6/2023 11:17:52 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#include "../../UTILITIES/Registers.h"
#include "../DIO/dio.h"

#ifndef PWM_H_
#define PWM_H_

//pwm output pin
#define percent_30 73
#define percent_50 127

//pwm output pin
#define OC0_port 'B'
#define OC0_pin 3
//PWM Modes
#define NonInv_correct_phase 0x60
//intial values
#define no_clk 0x00
#define zero_intial 0x00
#define Intial_value_PWM 0x00  
//prescaler values
#define pres_1 0x01
#define pres_8 0x02
#define pres_64 0x03
#define pres_256 0x04
#define pres_1024 0x05
#define clear_PWM 0x01
void PWM_Stop (void);
void PWM_init (uint8_t Mode);
void PWM_start (uint8_t duty_percent);



#endif /* PWM_H_ */
