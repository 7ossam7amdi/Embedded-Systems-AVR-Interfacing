/********************************************************/
/*	Name	: DIO_register.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 14 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

//PortA Registers

#define PORTA    *((volatile uint8*) 0x3B)
#define DDRA     *((volatile uint8*) 0x3A)
#define PINA     *((volatile uint8*) 0x39)


//PortB Registers

#define PORTB    *((volatile uint8*) 0x38)
#define DDRB     *((volatile uint8*) 0x37)
#define PINB     *((volatile uint8*) 0x36)


//PortC Registers

#define PORTC    *((volatile uint8*) 0x35)
#define DDRC     *((volatile uint8*) 0x34)
#define PINC     *((volatile uint8*) 0x33)


//PortD Registers

#define PORTD    *((volatile uint8*) 0x32)
#define DDRD     *((volatile uint8*) 0x31)
#define PIND     *((volatile uint8*) 0x30)

#endif