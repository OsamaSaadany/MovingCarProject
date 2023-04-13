/*
 * BitMath.h
 *
 * Created: 4/12/2023 7:09:48 PM
 *  Author: Osama Elsaadany
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(Reg,BitNumber)    (Reg|=(1<<BitNumber))
#define CLEAR_BIT(Reg,BitNumber)  (Reg&=~(1<<BitNumber))
#define TOGGLE_BIT(Reg,BitNumber) (Reg^=(1<<BitNumber))
#define GET_BIT(Reg,BitNumber)    ((Reg>>BitNumber)&1)


#endif /* BITMATH_H_ */