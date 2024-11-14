/********************************************************/
/*	Name	: CLCD_interface.h							*/
/*  Layer	: HAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 18 September	2023						*/
/*	Version	: V01										*/
/********************************************************/


/*Preprocessor file guard*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(uint8 Copy_Command);

void CLCD_voidSendData(uint8 Copy_Data);

void CLCD_voidInit(void);

void CLCD_voidWrite_String(uint8 *String);

void CLCD_voidReturn_Home();

void CLCD_voidClear();

void CLCD_voidWrite_Number(sint32 Number);



#endif
