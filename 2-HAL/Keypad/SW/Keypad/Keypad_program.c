/********************************************************/
/*	Name	: Keypad_program.c							*/
/*  Layer	: HAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 18 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"
#include <util/delay.h>

#include "Keypad_config.h"
#include "Keypad_private.h"
#include "Keypad_interface.h"


void KeyPad_Init(void){

	//Init Rows Pins
	DIO_SetPinDirection(KEYPAD_ROW_PORT , KEYPAD_R0_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(KEYPAD_ROW_PORT , KEYPAD_R1_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(KEYPAD_ROW_PORT , KEYPAD_R2_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(KEYPAD_ROW_PORT , KEYPAD_R3_PIN , OUTPUT_PIN);

	//Init Cols Pins
	DIO_SetPinDirection(KEYPAD_COL_PORT , KEYPAD_C0_PIN , INPUT_PULLUP_PIN);
	DIO_SetPinDirection(KEYPAD_COL_PORT , KEYPAD_C1_PIN , INPUT_PULLUP_PIN);
	DIO_SetPinDirection(KEYPAD_COL_PORT , KEYPAD_C2_PIN , INPUT_PULLUP_PIN);
	DIO_SetPinDirection(KEYPAD_COL_PORT , KEYPAD_C3_PIN , INPUT_PULLUP_PIN);

}

/************************************************************************/

uint8 KeyPad_GetKey(void){

	uint8 Button_State = HIGH;
	uint8 Rows_Arr[]= ROW_PINS;
	uint8 Cols_Arr[]= COLS_PINS;
	uint8 Keys[ROWS_NUM][COLS_NUM] = KEYPAD_MAP;

	for(int i = 0 ; i < ROWS_NUM ; i++){

		DIO_SetPinValue(KEYPAD_ROW_PORT ,Rows_Arr[i], PIN_LOW);

		for(int j = 0 ; j < COLS_NUM ; j++){

			DIO_GetPinValue(KEYPAD_COL_PORT , Cols_Arr[j] , &Button_State);

			/*if(Button_State == LOW)
				{
					_delay_ms(10);
					DIO_GetPinValue(KEYPAD_COL_PORT , Cols_Arr[j] , &Button_State);
					if(Button_State == LOW)
					{
						while (Button_State == LOW)
						{DIO_GetPinValue(KEYPAD_COL_PORT , Cols_Arr[j] , &Button_State);}
						return  Keys[i][j];
					}
				}*/

			if(Button_State == LOW){
				while(Button_State == LOW){
					DIO_GetPinValue(KEYPAD_COL_PORT , Cols_Arr[j] , &Button_State);
				}
				return Keys[i][j];
			}
		}

		DIO_SetPinValue(KEYPAD_ROW_PORT ,Rows_Arr[i], PIN_HIGH);
	}
	return NO_PRESSED_KEY;
}

