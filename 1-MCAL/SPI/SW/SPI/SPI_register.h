/********************************************************/
/*	Name	: SPI_register.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 4 October	2023							*/
/*	Version	: V01										*/
/********************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


#define SPDR			*((volatile uint8*) 0x2F)


/* SPI Status Register */
#define SPSR			*((volatile uint8*) 0x2E)
#define SPSR_SPIF		7	// SPI Interrupt flag
#define SPSR_WCOL		6	// SPI Write Collision flag
#define SPSR_SPI2X		0	// Double Speed Bit


/* SPI Control Register */
#define SPCR			*((volatile uint8*) 0x2D)

#define SPCR_SPIE		7	// SPI Interrupt Enable
#define SPCR_SPE		6	// SPI Enable
#define SPCR_DORD		5	// Data Order little or big endian
#define SPCR_MSTR		4	// Master or slave select
#define SPCR_CPOL		3	// Clock Polarity
#define SPCR_CPHA		2	// Clock Phase
#define SPCR_SPR1		1	// Clock rate select 1
#define SPCR_SPR0		0	// Clock rate select 0


#endif
