/********************************************************/
/*	Name	: UART_interface.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 27 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init (uint16 Baudrate);

void UART_Transmit (uint8 data);

uint8 UART_Receive (void);

#endif
