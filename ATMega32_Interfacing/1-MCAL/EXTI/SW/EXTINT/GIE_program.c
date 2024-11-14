/********************************************************/
/*	Name	: GIE_program.c	   					        */
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 20 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
#include "GIE_register.h"
#include "GIE_interface.h"


void GIE_Enable(void){
	SET_BIT(SREG, SREG_I);
}

void GIE_Disable(void){
	CLR_BIT(SREG, SREG_I);
}
