/********************************************************/
/*	Name	: LED_program.c							    */
/*  Layer	: HAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 17 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"

#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

void LED_Init (LED_t* CopyP_LED){
	DIO_SetPinDirection(CopyP_LED->Port , CopyP_LED->Pin, OUTPUT_PIN);
}

void LED_ON (LED_t* CopyP_LED){
	if(CopyP_LED -> Type == LED_SOURCE){
		DIO_SetPinValue(CopyP_LED->Port , CopyP_LED->Pin, PIN_HIGH);
	}
	else{
		DIO_SetPinValue(CopyP_LED->Port , CopyP_LED->Pin, PIN_LOW);
	}
}

void LED_OFF (LED_t* CopyP_LED){
	if(CopyP_LED -> Type == LED_SOURCE){
		DIO_SetPinValue(CopyP_LED->Port , CopyP_LED->Pin, PIN_LOW);
	}
	else{
		DIO_SetPinValue(CopyP_LED->Port , CopyP_LED->Pin, PIN_HIGH);
	}
}
