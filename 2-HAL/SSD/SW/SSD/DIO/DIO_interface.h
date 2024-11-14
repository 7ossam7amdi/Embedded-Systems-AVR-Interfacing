/********************************************************/
/*	Name	: DIO_interface.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 14 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

uint8 DIO_SetPinDirection (uint8 Copy_Port, uint8 Copy_Pin, uint8 Copy_Direction);

uint8 DIO_SetPortDirection (uint8 Copy_Port, uint8 Copy_Direction);

uint8 DIO_SetPinValue (uint8 Copy_Port, uint8 Copy_Pin, uint8 Copy_Value);

uint8 DIO_SetPortValue (uint8 Copy_Port, uint8 Copy_Value);

uint8 DIO_GetPinValue (uint8 Copy_Port, uint8 Copy_Pin, uint8* Return_PValue);


#define PORT_INPUT	0
#define PORT_OUTPUT	0xFF

#define PORT_LOW	0x00
#define PORT_HIGH	0xFF

#define PIN_HIGH	1
#define PIN_LOW		0


enum Ports {
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
};


enum Pins {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
};


enum Directions {
	INPUT_PIN,
	OUTPUT_PIN,
	INPUT_PULLUP_PIN
};

#endif
