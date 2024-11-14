/********************************************************/
/*	Name	: EXTINT_interface.h	   				    */
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 20 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_


void EXTINT_Int0Init(uint8 Int_Sense);

void EXTINT_Int1Init(uint8 Int_Sense);

void EXTINT_Int2Init(uint8 Int_Sense);

void EXTINT_Disable(uint8 Int);

void EXTINT1_CallBack (void (*Func_Ptr) (void));


enum Senses {
	FALLING_EDGE = 1,
	RISING_EDGE,
	ON_CHANGE,
	LOW_LEVEL
};

enum INT {
	INT0 = 1,
	INT1,
	INT2
};

#endif
