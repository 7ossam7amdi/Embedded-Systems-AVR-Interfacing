/********************************************************/
/*	Name	: TWI_register.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 5 October	2023							*/
/*	Version	: V01										*/
/********************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_


#define TWDR              *((volatile uint8*) 0x23)		/* TWI Data Register */
#define TWAR              *((volatile uint8*) 0x22)		/* TWI Address Register */
#define TWSR              *((volatile uint8*) 0x21)		/* TWI Status Register */
#define TWBR              *((volatile uint8*) 0x20)		/* TWI Bit Rate Register */
#define TWCR              *((volatile uint8*) 0x56)		/* TWI Control Register */

#define TWCR_TWINT			7		/* TWI Interrupt Flag */
#define TWCR_TWEA			6		/* TWI Enable Acknowledge Bit */
#define TWCR_TWSTA			5		/* TWI START Condition Bit */
#define TWCR_TWSTO			4		/* TWI STOP Condition Bit */
#define TWCR_TWWC			3		/* TWI Write Collision Flag */
#define TWCR_TWEN			2		/* TWI Enable Bit */
#define TWCR_TWIE			0		/* TWI Interrupt Enable */

#define TWAR_TWGCE			0		/* TWI General Call Recognition Enable Bit */

#define TWSR_TWPS0			0
#define TWSR_TWPS1			1

#endif