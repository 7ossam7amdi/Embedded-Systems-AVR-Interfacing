/*
 * main.c
 *
 *  Created on: Sep 21, 2023
 *      Author: hossa
 */


#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
#include "DIO/DIO_interface.h"
#include "EXTINT_interface.h"
#include "GIE_interface.h"


void Led_ON(void){
	DIO_SetPinValue(PORT_C , PIN0 , PIN_HIGH);
}


int main(){
	DIO_SetPinDirection(PORT_C , PIN0 , OUTPUT_PIN);
	GIE_Enable();
	EXTINT_Int1Init(FALLING_EDGE);
	EXTINT1_CallBack(&Led_ON);
	while(1){

	}
}


