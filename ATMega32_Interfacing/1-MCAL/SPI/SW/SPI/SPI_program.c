/********************************************************/
/*	Name	: SPI_program.c								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 4 October	2023							*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
#include "DIO/DIO_interface.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"

void SPI_Init_Master (){

	/*   MASTER     */
	/* Set MOSI Pin */
	DIO_SetPinDirection(PORT_B,PIN5,OUTPUT_PIN);
	/* Set MISO Pin */
	DIO_SetPinDirection(PORT_B,PIN6,INPUT_PIN);
	/*Set CLK Pin*/
	DIO_SetPinDirection(PORT_B,PIN7,OUTPUT_PIN);
	/*Set CS Pin*/
	DIO_SetPinDirection(PORT_B,PIN4,OUTPUT_PIN);


	/*Enable SPI Master */

	SET_BIT(SPCR,SPCR_MSTR); //master

	/* Set CLK */
#if CLOCK_RATE == F_DIV_4

	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

#elif	CLOCK_RATE == F_DIV_16

	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

#elif	CLOCK_RATE == F_DIV_64

	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

#elif	CLOCK_RATE == F_DIV_128

	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

#elif	CLOCK_RATE == F_DIV_2

	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);

#elif	CLOCK_RATE == F_DIV_8

	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);

#elif	CLOCK_RATE == F_DIV_32

	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);


#endif


	/* Data Order*/

#if DATA_ORDER == LSB_ORDER
	SET_BIT(SPCR,SPCR_DORD);
#elif DATA_ORDER == MSB_ORDER
	CLR_BIT(SPCR,SPCR_DORD);
#endif


	/* Phase Check*/
#if CLOCK_PHASE == SETUP_LEADING
	SET_BIT(SPCR,SPCR_CPHA);
#elif CLOCK_PHASE == SAMPLE_LEADING
	CLR_BIT(SPCR,SPCR_CPHA);
#endif

	/* Polarity Check */
#if CLOCK_POLARITY == IDLE_HIGH
	SET_BIT(SPCR,SPCR_CPOL);
#elif CLOCK_POLARITY == IDLE_LOW
	CLR_BIT(SPCR,SPCR_CPOL);
#endif

	/*Enable SPI*/

	SET_BIT(SPCR,SPCR_SPE);
}

//========================================
void SPI_Init_Slave (){
	/*    SLAVE     */
	/* Set MOSI Pin */
	DIO_SetPinDirection(PORT_B,PIN5,INPUT_PIN);
	/* Set MISO Pin */
	DIO_SetPinDirection(PORT_B,PIN6,OUTPUT_PIN);
	/*Set CLK Pin*/
	DIO_SetPinDirection(PORT_B,PIN7,INPUT_PIN);
	/*Set CS Pin*/
	DIO_SetPinDirection(PORT_B,PIN4,INPUT_PIN);

	/*Enable SPI Slave */
	CLR_BIT(SPCR,SPCR_MSTR); //slave

	/* Set CLK */
	#if CLOCK_RATE == F_DIV_4

		CLR_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1);
		CLR_BIT(SPSR,SPSR_SPI2X);

	#elif	CLOCK_RATE == F_DIV_16

		SET_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1);
		CLR_BIT(SPSR,SPSR_SPI2X);

	#elif	CLOCK_RATE == F_DIV_64

		CLR_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPR1);
		CLR_BIT(SPSR,SPSR_SPI2X);

	#elif	CLOCK_RATE == F_DIV_128

		SET_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPR1);
		CLR_BIT(SPSR,SPSR_SPI2X);

	#elif	CLOCK_RATE == F_DIV_2

		CLR_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1);
		SET_BIT(SPSR,SPSR_SPI2X);

	#elif	CLOCK_RATE == F_DIV_8

		SET_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1);
		SET_BIT(SPSR,SPSR_SPI2X);

	#elif	CLOCK_RATE == F_DIV_32

		CLR_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPR1);
		SET_BIT(SPSR,SPSR_SPI2X);


	#endif

		/* Data Order*/
	#if DATA_ORDER == LSB_ORDER
		SET_BIT(SPCR,SPCR_DORD);
	#elif DATA_ORDER == MSB_ORDER
		CLR_BIT(SPCR,SPCR_DORD);
	#endif

		/* Phase Check*/
	#if CLOCK_PHASE == SETUP_LEADING
		SET_BIT(SPCR,SPCR_CPHA);
	#elif CLOCK_PHASE == SAMPLE_LEADING
		CLR_BIT(SPCR,SPCR_CPHA);
	#endif

		/* Polarity Check */
	#if CLOCK_POLARITY == IDLE_HIGH
		SET_BIT(SPCR,SPCR_CPOL);
	#elif CLOCK_POLARITY == IDLE_LOW
		CLR_BIT(SPCR,SPCR_CPOL);
	#endif

		/*Enable SPI*/
		SET_BIT(SPCR,SPCR_SPE);
}

//=================================

void SPI_Transmit (uint8 data) {

	SPDR = data;
	while(!(GET_BIT(SPSR,SPSR_SPIF))){

	}
}

uint8 SPI_Receive (void){

	/*while(!(GET_BIT(SPSR,Pin7))){

		}*/

	return SPDR;
}