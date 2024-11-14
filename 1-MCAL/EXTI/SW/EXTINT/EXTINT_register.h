/********************************************************/
/*	Name	: EXTINT_register.h	   					    */
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 20 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef EXTINT_REGISTER_H_
#define EXTINT_REGISTER_H_

/*******************************************************/

/* MCU Control Register */
#define MCUCR    		*((volatile uint8*) 0x55)
#define MCUCR_ISC11		3
#define MCUCR_ISC10		2
#define MCUCR_ISC01		1
#define MCUCR_ISC00		0
/*******************************************************/

/* MCU Control and Status Register */
#define MCUCSR    		*((volatile uint8*) 0x54)
#define MCUCR_ISC2		6

/*******************************************************/

/* General Interrupt Control Register */
#define GICR    		*((volatile uint8*) 0x5B)
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5

/*******************************************************/

/* General Interrupt Flag Register */
#define GIFR    	*((volatile uint8*) 0x5A)
#define GIFR_INTF1	7
#define GIFR_INTF0	6
#define GIFR_INTF2	5


#endif
