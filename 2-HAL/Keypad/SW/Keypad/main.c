/*
 * main.c
 *
 *  Created on: Sep 18, 2023
 *      Author: hossa
 */

#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"

#include "Keypad_interface.h"
#include "LCD/CLCD_interface.h"

int main(){
	uint8 key;

	CLCD_voidInit();
	KeyPad_Init();

	while(1){
		key = KeyPad_GetKey();
		while (key == 'n'){
			key = KeyPad_GetKey();
		}
		CLCD_voidSendData(key);
	}
}