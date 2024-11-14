/********************************************************/
/*	Name	: SPI_interface.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 4 October	2023							*/
/*	Version	: V01										*/
/********************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_Init_Master(void);
void SPI_Init_Slave(void);
void SPI_Transmit(uint8 data);
uint8 SPI_Receive(void);


#endif
