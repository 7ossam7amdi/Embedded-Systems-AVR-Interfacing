/********************************************************/
/*	Name	: CLCD_program.c							*/
/*  Layer	: HAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 18 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"

#include <util/delay.h>

#include "DIO/DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"



void CLCD_voidSendCommand(uint8 Copy_Command)
{
	/*Set RS pin to low for command*/
	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , PIN_LOW);

	/*Set RW pin to low for write*/
	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , PIN_LOW);

	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , GET_BIT(Copy_Command,7));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , GET_BIT(Copy_Command,6));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , GET_BIT(Copy_Command,5));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , GET_BIT(Copy_Command,4));


	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , PIN_LOW);
	_delay_ms(2);

	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , GET_BIT(Copy_Command,PIN3));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , GET_BIT(Copy_Command,PIN2));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , GET_BIT(Copy_Command,PIN1));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , GET_BIT(Copy_Command,PIN0));

	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , PIN_LOW);
	_delay_ms(2);
}

/***************************************************************************/

void CLCD_voidSendData(uint8 Copy_Data)
{

	/*Set RS pin to high for data*/
	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , PIN_HIGH);

	/*Set RW pin to low for write*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN, PIN_LOW);

	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , GET_BIT(Copy_Data,PIN7));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , GET_BIT(Copy_Data,PIN6));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , GET_BIT(Copy_Data,PIN5));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , GET_BIT(Copy_Data,PIN4));


	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , PIN_LOW);
	_delay_ms(2);

	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , GET_BIT(Copy_Data,PIN3));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , GET_BIT(Copy_Data,PIN2));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , GET_BIT(Copy_Data,PIN1));
	DIO_SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , GET_BIT(Copy_Data,PIN0));

	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , PIN_LOW);
	_delay_ms(2);

}


/***************************************************************************/

void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set */
	DIO_SetPinDirection(CLCD_CTRL_PORT ,CLCD_RS_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(CLCD_CTRL_PORT ,CLCD_EN_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(CLCD_CTRL_PORT ,CLCD_RW_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(CLCD_DATA_PORT ,CLCD_D4_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(CLCD_DATA_PORT ,CLCD_D5_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(CLCD_DATA_PORT ,CLCD_D6_PIN , OUTPUT_PIN);
	DIO_SetPinDirection(CLCD_DATA_PORT ,CLCD_D7_PIN , OUTPUT_PIN);

	CLCD_voidSendCommand(0x33);
	CLCD_voidSendCommand(0x32);
	CLCD_voidSendCommand(0x28);
	_delay_ms(1);
	CLCD_voidSendCommand(0x0c);  //LCD display on
	_delay_ms(1);
	CLCD_voidSendCommand(0x02);  //LCD return home
	_delay_ms(1);
	CLCD_voidSendCommand(0x01);  //LCD clear
}

/***************************************************************************/

void CLCD_voidWrite_String(uint8 *String)
{
	uint8 counter = 0;
	while(String[counter] != '\0')
	{
		CLCD_voidSendData(String[counter]);
		counter++;
	}
}

/***************************************************************************/

void CLCD_voidWrite_Number(sint32 Number)
{
	sint16 counter = 0;
	uint16 arr[10] = {0};
	if(Number < 0)
	{
		Number = Number * -1;
		CLCD_voidSendData('-');
	}

	do
	{
		arr[counter] = Number % 10;
		Number = Number / 10;
		counter++;
	}while(Number != 0);

	while(counter > 0)
	{
		CLCD_voidSendData(arr[--counter] + '0');
	}
}

/***************************************************************************/

void CLCD_voidClear()
{
	CLCD_voidSendCommand(0x01); //lcd clear command
}

/***************************************************************************/

void CLCD_voidReturn_Home()
{
	CLCD_voidSendCommand(0x02); //lcd set cursor to zero
}
