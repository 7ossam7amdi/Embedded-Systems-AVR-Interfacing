/********************************************************/
/*	Name	: DIO_program.c	   						    */
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 14 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_register.h"
#include "DIO_interface.h"


uint8 DIO_SetPinDirection(uint8 Copy_Port, uint8 Copy_Pin, uint8 Copy_Direction){

	uint8 Local_ErrorState = 0;

	if(Copy_Pin <= 7 && Copy_Pin >= 0){

		if(Copy_Direction == INPUT_PIN)
		{
			switch(Copy_Port)
			{
			case PORT_A:   CLR_BIT(DDRA,Copy_Pin);  break;
			case PORT_B:   CLR_BIT(DDRB,Copy_Pin);  break;
			case PORT_C:   CLR_BIT(DDRC,Copy_Pin);  break;
			case PORT_D:   CLR_BIT(DDRD,Copy_Pin);  break;
			default:	   Local_ErrorState = 1;    break;
			}
		}

		else if(Copy_Direction == OUTPUT_PIN)
		{
			switch(Copy_Port)
			{
			case PORT_A:    SET_BIT(DDRA,Copy_Pin); break;
			case PORT_B:    SET_BIT(DDRB,Copy_Pin); break;
			case PORT_C:    SET_BIT(DDRC,Copy_Pin); break;
			case PORT_D:    SET_BIT(DDRD,Copy_Pin); break;
			default:	   Local_ErrorState = 1;    break;
			}
		}

		else if(Copy_Direction == INPUT_PULLUP_PIN)
		{
			switch(Copy_Port)
			{
			case PORT_A:
				CLR_BIT(DDRA,Copy_Pin);
				SET_BIT(PORTA,Copy_Pin);
				break;
			case PORT_B:
				CLR_BIT(DDRB,Copy_Pin);
				SET_BIT(PORTB,Copy_Pin);
				break;
			case PORT_C:
				CLR_BIT(DDRC,Copy_Pin);
				SET_BIT(PORTC,Copy_Pin);
				break;
			case PORT_D:
				CLR_BIT(DDRD,Copy_Pin);
				SET_BIT(PORTD,Copy_Pin);
				break;
			default:	   Local_ErrorState = 1;    break;
			}
		}
		else {
			Local_ErrorState = 1;
		}
	}

	else {
		Local_ErrorState = 1;
	}


	return Local_ErrorState;
}

/***************************************************************************/

uint8 DIO_SetPortDirection(uint8 Copy_Port, uint8 Copy_Direction){
	uint8 Local_ErrorState = 0;
	switch(Copy_Port){
	case PORT_A:    DDRA = Copy_Direction; break;
	case PORT_B:    DDRB = Copy_Direction; break;
	case PORT_C:    DDRC = Copy_Direction; break;
	case PORT_D:    DDRD = Copy_Direction; break;
	default:	   Local_ErrorState = 1;   break;

	}
	return Local_ErrorState;
}


/***************************************************************************/

uint8 DIO_SetPinValue(uint8 Copy_Port, uint8 Copy_Pin, uint8 Copy_Value){
	uint8 Local_ErrorState = 0;

	if(Copy_Pin <= 7 && Copy_Pin >= 0){

		if(Copy_Value == PIN_LOW)
		{
			switch(Copy_Port)
			{
			case PORT_A:   CLR_BIT(PORTA,Copy_Pin);  break;
			case PORT_B:   CLR_BIT(PORTB,Copy_Pin);  break;
			case PORT_C:   CLR_BIT(PORTC,Copy_Pin);  break;
			case PORT_D:   CLR_BIT(PORTD,Copy_Pin);  break;
			default:	   Local_ErrorState = 1;    break;
			}
		}

		else if(Copy_Value == PIN_HIGH)
		{
			switch(Copy_Port)
			{
			case PORT_A:    SET_BIT(PORTA,Copy_Pin); break;
			case PORT_B:    SET_BIT(PORTB,Copy_Pin); break;
			case PORT_C:    SET_BIT(PORTC,Copy_Pin); break;
			case PORT_D:    SET_BIT(PORTD,Copy_Pin); break;
			default:	   Local_ErrorState = 1;    break;
			}
		}
	}
	else {
		Local_ErrorState = 1;
	}

	return Local_ErrorState;
}


/***************************************************************************/

uint8 DIO_SetPortValue(uint8 Copy_Port, uint8 Copy_Value){
	uint8 Local_ErrorState = 0;
	switch(Copy_Port){
	case PORT_A:    PORTA = Copy_Value; break;
	case PORT_B:    PORTB = Copy_Value; break;
	case PORT_C:    PORTC = Copy_Value; break;
	case PORT_D:    PORTD = Copy_Value; break;
	default:	    Local_ErrorState = 1;   break;
	}
	return Local_ErrorState;
}

/***************************************************************************/

uint8 DIO_GetPinValue(uint8 Copy_Port, uint8 Copy_Pin, uint8* Return_PValue){
	uint8 Local_ErrorState = 0;
	if((Return_PValue != NULL) && (Copy_Pin <= 7 && Copy_Pin >= 0)){
		switch(Copy_Port){
		case PORT_A:    *Return_PValue = GET_BIT(PINA,Copy_Pin); break;
		case PORT_B:    *Return_PValue = GET_BIT(PINB,Copy_Pin); break;
		case PORT_C:    *Return_PValue = GET_BIT(PINC,Copy_Pin); break;
		case PORT_D:    *Return_PValue = GET_BIT(PIND,Copy_Pin); break;
		default:	    Local_ErrorState = 1;   break;
		}
	}
	else {
		Local_ErrorState = 1;
	}

	return Local_ErrorState;
}
