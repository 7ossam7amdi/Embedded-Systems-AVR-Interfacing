/*
 * main.c
 *
 *  Created on: Sep 18, 2023
 *      Author: hossa
 */


#include "LIB/Std_Types.h"

#include "DIO/DIO_interface.h"
#include "CLCD_interface.h"

int main(){

	CLCD_voidInit();
	CLCD_voidWrite_String("Hossam");
	CLCD_voidWrite_Number(200);

	while(1){

	}
}