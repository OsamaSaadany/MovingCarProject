/*
 * pwm.c
 *
 * Created: 4/6/2023 11:18:12 PM
 *  Author: MOHAMED ABDELSALAM
 */ 

#include "pwm.h"

void PWM_init (uint8_t Mode){
	//OC0 pin direction
	/* THE FOLLOWING LINE IS REMOVED */
	//DIO_init(OC0_port,OC0_pin,OUT);
	DIO_InitPin(PINB3_,OUTPUT);
	//choose PWM mode
	TCCR0 &= Mode;
	TCCR0 |= Mode;
}
void PWM_start (uint8_t duty_percent){

	OCR0 = duty_percent;			//set the duty cycle
	//R0 = duty_percent;
	TCCR0 |= pres_1;  //Set Pre_scaler, for ex:ck(8MHz)/1 to get,
}

void PWM_Stop (void)
{
	//Timer Stop
	TCCR0 = no_clk;
}
