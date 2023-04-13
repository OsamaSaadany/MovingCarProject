/*
 * timer.c
 *
 * Created: 4/6/2023 11:14:21 PM
 *  Author: MOHAMED ABDELSALAM
 */ 

#include "timer.h"


void TIMER_init (uint8_t Mode,uint8_t intial_value){
//choose timer mode
TCCR2 &= Mode;
//TimerSet initial value
TCNT2 = intial_value;
}
void TIMER_start (uint8_t prescaler_value){

TCCR2 |= prescaler_value;  //Set Pre_scaler, for ex:ck(source)(8MHz)/8 to get,
//T(tick) = 1 microseconds
//Stop after one overflow 250 microseconds
}
void TIMER_set(uint8_t intial_value){
//TimerSet initial value
TCNT2 = intial_value;
}
void TIMER_getStatus(uint8_t *value){
	if ((TIFR & clear) == 0)
	{
		*value = 0x01;
	}
	else if ((TIFR & clear) == 1)
	{
		*value = 0x00;
		TIFR |= clear;
	}
}
	void TIMER_Stop (void){
		//Timer Stop
		TCCR2 = no_clk;	
	}
void Delay(uint32_t milliseconds)
{
	TIMER_init (normal,ticks_250);
	TIMER_start (pres_8);
	uint32_t i;
	uint8_t counter;
	
	for(i=0;i< milliseconds ;i++){
	
	// N = (1000us)/(250u);  //= 4 without approximation
	//for one millisecond delay iterate 4 times of timer2 overflow
	counter = 0;
	while(counter<4){
		
		while((TIFR & clear) == 0);
		TIMER_set(ticks_250);
		TIFR |= clear;
		counter++;
	}
	

	}
	TIMER_Stop ();
}
