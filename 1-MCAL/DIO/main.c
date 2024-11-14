/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: hossa
 */

#include "Std_Types.h"
#include "DIO_interface.h"
#include <util/delay.h>

int main(){

	uint8 Switch_Read = 1;

	DIO_SetPortDirection(PORT_A,PORT_OUTPUT);
	DIO_SetPinDirection(PORT_C,PIN0,INPUT_PULLUP_PIN);

	while(1){
		DIO_GetPinValue (PORT_C,PIN0,&Switch_Read);
		if(Switch_Read == PIN_LOW){
			_delay_ms(20);
			DIO_GetPinValue (PORT_C,PIN0,&Switch_Read);
			if(Switch_Read == PIN_LOW){
				DIO_SetPortValue(PORT_A, PORT_HIGH);
			}
		}
		else{
			DIO_SetPortValue(PORT_A, PORT_LOW);
		}
	}
}
