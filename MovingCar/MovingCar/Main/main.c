/*
 * MovingCar.c
 *
 * Created: 4/13/2023 11:00:34 AM
 * Author : Osama Elsaadany
 */ 

//#include <avr/io.h>

#include "ext_interrupt.h"
#include "timer.h"
#include "motors.h"
#include "led.h"
uint8_t PB2_is_pressed = 0;
void isr (void)
{
	/* write here your ISR
	*/
	motors_stop(PIND0_,PIND1_,PIND2_,PIND3_);
	PB2_is_pressed =1;
	
	/*
	DDRC = 0xff;
	PORTC ^= (1<<0);
	Delay(100);
	PORTC ^= (1<<1);
	*/
	
}

int main(void)
{	
	// confuiguring PB1 and PB2 as push buttons
	button_init(PINB1_);
	button_init(PINB2_);
	
	//setting the call back function for interrupt on PB2
	EXTINT_CallBack(EXTINT2, isr);
	EXTINT_init(EXTINT2, RISING_EDGE);

	// configuring PC0,PC1,PC2,PC3 for leds
	LED_init(PINC0_);
	LED_init(PINC1_);
	LED_init(PINC2_);
	LED_init(PINC3_);

	// configuring PD0,PD1,PD2,PD3 for motors
	motors_init(PIND0_,PIND1_,PIND2_,PIND3_);
	
	/* System Requirements */ 
	
	while (1) // super loop 
	{
		
		// busy wait on PB1
		{
			if(Button_Check(PINB1_) == LOW )
			{
				while(Button_Check(PINB1_) == LOW) 
				{
					
				}
				Delay((20));  // denounce effect
			}
		}
					
		while (1) // repetitive sequence 3->6
		{
			
			Delay(1000); //waiting 1 second
			
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
			motors_forward (PIND0_,PIND1_,PIND2_,PIND3_,(uint8_t) 250);
			LED_ON(PINC0_);
			LED_OFF(PINC1_);
			LED_OFF(PINC2_);
			LED_OFF(PINC3_);
			Delay(3000); //waiting 3 seconds
			
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
			
			motors_stop(PIND0_,PIND1_,PIND2_,PIND3_);
			LED_OFF(PINC0_);
			LED_OFF(PINC1_);
			LED_ON(PINC2_);
			LED_OFF(PINC3_);
			Delay(500);
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
			
			motors_right(PIND0_,PIND1_,PIND2_,PIND3_,(uint8_t) 250);
			LED_OFF(PINC0_);
			LED_OFF(PINC1_);
			LED_OFF(PINC2_);
			LED_ON(PINC3_);
			Delay(500);
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
			
			motors_stop(PIND0_,PIND1_,PIND2_,PIND3_);
			LED_OFF(PINC0_);
			LED_OFF(PINC1_);
			LED_ON(PINC2_);
			LED_OFF(PINC3_);
			Delay(500);
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
			
			motors_forward (PIND0_,PIND1_,PIND2_,PIND3_,(uint8_t) 128);
			LED_ON(PINC0_);
			LED_OFF(PINC1_);
			LED_OFF(PINC2_);
			LED_OFF(PINC3_);
			Delay(2000);
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
	
			motors_stop(PIND0_,PIND1_,PIND2_,PIND3_);
			LED_OFF(PINC0_);
			LED_OFF(PINC1_);
			LED_ON(PINC2_);
			LED_OFF(PINC3_);
			Delay(500);
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
			
			motors_right(PIND0_,PIND1_,PIND2_,PIND3_,(uint8_t) 250);
			LED_OFF(PINC0_);
			LED_OFF(PINC1_);
			LED_OFF(PINC2_);
			LED_ON(PINC3_);
			Delay(500);
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
			
			motors_stop(PIND0_,PIND1_,PIND2_,PIND3_);
			LED_OFF(PINC0_);
			LED_OFF(PINC1_);
			LED_ON(PINC2_);
			LED_OFF(PINC3_);
			Delay(500);
			if(PB2_is_pressed == 1)
			{
				PB2_is_pressed = 0;
				break;
			}
	
		
		}
	}

}

