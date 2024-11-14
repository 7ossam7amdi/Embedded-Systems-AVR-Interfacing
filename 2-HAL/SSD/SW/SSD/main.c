/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: hossa
 */


#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"
#include "SSD_interface.h"
#include <util/delay.h>

int main(){
	uint8 SW_State = 1;
	//uint8 Counter = 1;
	DIO_SetPinDirection(PORT_B, PIN1, INPUT_PULLUP_PIN);
	SSD_t My_SSD = {COM_Anode,PORT_C, PORT_B ,PIN0};


	while(1){

		DIO_GetPinValue(PORT_B, PIN1, &SW_State);
		if(SW_State == 0){
			_delay_ms(20);
			DIO_GetPinValue(PORT_B, PIN1, &SW_State);
			if(SW_State == 0){
				SSD_Enable(&My_SSD);
				}
			}
		else {
			SSD_Disable(&My_SSD);
		}




		/*******************************************************************/

		/*

		DIO_GetPinValue(PORT_B, PIN1, &SW_State);
		if(SW_State == 0){
			_delay_ms(20);
			DIO_GetPinValue(PORT_B, PIN1, &SW_State);
			if(SW_State == 0){
				_delay_ms(200);
					SSD_SetNumber(Counter,&My_SSD);
					Counter++;
					if(Counter > 9){
						Counter = 0;
					}
			}
		}
		 */

		/***************************************************************/

		/*
		SSD_SetNumber(0,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(1,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(2,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(3,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(4,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(5,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(6,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(7,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(8,&My_SSD);
		_delay_ms(1000);

		SSD_SetNumber(9,&My_SSD);
		_delay_ms(1000);
		 */
	}

}
