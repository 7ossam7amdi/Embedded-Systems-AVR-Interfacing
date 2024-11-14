/*
 * main.c
 *
 *  Created on: Sep 27, 2023
 *      Author: hossa
 */

#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"
#include "UART_interface.h"
#include <util/delay.h>
int main(){
	//uint8 Received = 0;
	UART_Init(9600);
	DIO_SetPinDirection(PORT_B,PIN0 , OUTPUT_PIN);

	while(1)
	{
		UART_Transmit('o');
		_delay_ms(1000);
		UART_Transmit('f');
		_delay_ms(1000);
//		Received = UART_Receive();
//		if(Received == 'o'){
//			DIO_SetPinValue(PORT_B, PIN0, PIN_HIGH);
//		}
//		else {
//			DIO_SetPinValue(PORT_B, PIN0, PIN_LOW);
//		}
	}

}
