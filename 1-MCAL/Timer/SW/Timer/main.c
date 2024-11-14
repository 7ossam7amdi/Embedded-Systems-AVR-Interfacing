/*
 * main.c
 *
 *  Created on: Sep 27, 2023
 *      Author: hossa
 */

#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"
#include "Timer_interface.h"
#include "util/delay.h"


int main(){

	Timer1_Init();

	while(1){
//		for(int i=1000 ; i< 2000 ; i += 100){
//			Servo_Go(i);
//			_delay_ms(30);
//		}

		Servo_Go(1500);
	}
}
