

#ifndef DIO_H_
#define DIO_H_


#include "../../UTILITIES/Utlise.h"
#include "../../UTILITIES/Standard_Type.h"
#include "../../UTILITIES/Registers.h"


typedef enum {
	PINA0_,
	PINA1_,
	PINA2_,
	PINA3_,
	PINA4_,
	PINA5_,
	PINA6_,
	PINA7_,
	PINB0_,
	PINB1_,
	PINB2_,
	PINB3_,
	PINB4_,
	PINB5_,
	PINB6_,
	PINB7_,
	PINC0_,
	PINC1_,
	PINC2_,
	PINC3_,
	PINC4_,
	PINC5_,
	PINC6_,
	PINC7_,
	PIND0_,
	PIND1_,
	PIND2_,
	PIND3_,
	PIND4_,
	PIND5_,
	PIND6_,
	PIND7_
}PIn_name;
typedef enum{
	OUTPUT,
	INFREE,
	INPUT
}PIN_Status;

/*
#define PINA0 (uint8_t) 0
#define	PINA1 (uint8_t) 1
#define	PINA2 (uint8_t) 2
#define	PINA3 (uint8_t) 3
#define PINA4 (uint8_t) 4
#define PINA5 (uint8_t) 5
#define PINA6 (uint8_t) 6
#define PINA7 (uint8_t) 7
#define PINB0 (uint8_t) 8
#define PINB1 (uint8_t) 9
#define PINB2 (uint8_t) 10
#define PINB3 (uint8_t) 11
#define PINB4 (uint8_t) 12
#define PINB5 (uint8_t) 13
#define PINB6 (uint8_t) 14
#define PINB7 (uint8_t) 15
#define PINC0 (uint8_t) 16
#define PINC1 (uint8_t) 17
#define PINC2 (uint8_t) 18
#define PINC3 (uint8_t) 19
#define PINC4 (uint8_t) 20
#define PINC5 (uint8_t) 21
#define PINC6 (uint8_t) 22
#define PINC7 (uint8_t) 23
#define PIND0 (uint8_t) 24
#define PIND1 (uint8_t) 25
#define PIND2 (uint8_t) 26
#define PIND3 (uint8_t) 27
#define PIND4 (uint8_t) 28
#define PIND5 (uint8_t) 29
#define PIND6 (uint8_t) 30
	
*/

typedef enum {
	PA,
	PB,
	PC,
	PD
	}PORT_Type;

typedef enum {
LOW,
HIGH
}Voltage_type;

void DIO_InitPin (PIn_name pin ,PIN_Status status );

void DIO_init (void);

void DIO_WRitePin (PIn_name pin ,Voltage_type s);

Voltage_type DIO_ReadPin(PIn_name pin);

void DIO_WritePort(PORT_Type l,u8 k);

void DIO_TogglePin(PIn_name pin);




#endif /* DIO_INTERFACE_H_ */




