/*
 * main.c
 *
 *  Created on: Sep 26, 2023
 *      Author: hossa
 */

#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"
#include "ADC_interface.h"
#include "LCD/CLCD_interface.h"
#include <util/delay.h>

int main(){
	float step = .0048828;
	float analog;
	uint16 ADC_reading;
	CLCD_voidInit();
	ADC_Init();

	while(1){
		ADC_reading = ADC_GetChannelReading(ADC0);
		analog = ADC_reading * step * 1000;
		CLCD_voidWrite_Number(analog/10);
		_delay_ms(100);
		CLCD_voidClear();
	}

}