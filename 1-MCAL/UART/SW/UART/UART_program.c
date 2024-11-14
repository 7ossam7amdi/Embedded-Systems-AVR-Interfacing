/********************************************************/
/*	Name	: UART_program.c							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 27 September 2023							*/
/*	Version	: V01										*/
/********************************************************/


#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
#include "DIO/DIO_interface.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_register.h"





void UART_Init (uint16 Baudrate){

	uint8 TempUC = 0;
	uint8 TempUH = 0;
	uint16 ubrr;

	/* Set Directions of TX,RX Pins */
//	DIO_SetPinDirection(PORT_D, PIN1 , OUTPUT_PIN);	//TX Pin
//	DIO_SetPinDirection(PORT_D, PIN0 , INPUT_PIN);  //RX Pin

	/* Enable UBRRH by URSEL */
	CLR_BIT(TempUH,UCSRC_URSEL);

	/* Set Baudrate */
	ubrr = (8000000UL/(16UL*Baudrate)) - 1 ;

	UBRRL = (uint8) ubrr;
	TempUH = (uint8) (ubrr >> 8);
	UBRRH = TempUH;

	/* Enable UCSRC by URSEL */
	SET_BIT(TempUC,UCSRC_URSEL);

	/* Choose Sync modes */
	#if SYNC == ASYNCHRONOUS
		CLR_BIT(TempUC,UCSRC_UMSEL);

	#elif SYNC == SYNCHRONOUS
		SET_BIT(TempUC,UCSRC_UMSEL);
	#endif

	/* Parity Selection  */
	#if PARITY == DISABLED
		CLR_BIT(TempUC,UCSRC_UPM0);
		CLR_BIT(TempUC,UCSRC_UPM1);

	#elif PARITY == EVEN
		CLR_BIT(TempUC,UCSRC_UPM0);
		SET_BIT(TempUC,UCSRC_UPM1);

	#elif PARITY == ODD
		SET_BIT(TempUC,UCSRC_UPM0);
		SET_BIT(TempUC,UCSRC_UPM1);
	#endif


	/* Stop bit Selection */
	#if STOP_BITS == STOP1
		CLR_BIT(TempUC,UCSRC_USBS);

	#elif STOP_BITS == STOP2
		SET_BIT(TempUC,UCSRC_USBS);

	#endif

	/* Choose Char Size */
	#if	CHAR_SIZE == BIT5
		CLR_BIT(TempUC,UCSRC_UCSZ0);
		CLR_BIT(TempUC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);

	#elif CHAR_SIZE == BIT6
		SET_BIT(TempUC,UCSRC_UCSZ0);
		CLR_BIT(TempUC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);

	#elif CHAR_SIZE == BIT7
		CLR_BIT(TempUC,UCSRC_UCSZ0);
		SET_BIT(TempUC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);

	#elif CHAR_SIZE == BIT8
		SET_BIT(TempUC,UCSRC_UCSZ0);
		SET_BIT(TempUC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);

	#endif

	/* Set the Whole Register */
	UCSRC = TempUC;

	/* Disable Interrupt */
	//CLR_BIT(UCSRB,UCSRB_UDRIE);

	/* Enable transmitter */
	SET_BIT(UCSRB,UCSRB_TXEN);

	/* Enable receiver */
	SET_BIT(UCSRB,UCSRB_RXEN);

}

/*****************************************************/
void UART_Transmit (uint8 data) {

	/* Check if register is empty */
	while (	GET_BIT(UCSRA,UCSRA_UDRE) != 1);
	UDR = data;
}

/*****************************************************/
uint8 UART_Receive (void){

	while ( GET_BIT(UCSRA,UCSRA_RXC) != 1);
	return UDR;
}
