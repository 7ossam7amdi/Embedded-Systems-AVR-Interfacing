/********************************************************/
/*	Name	: EXTINT_program.c	   					    */
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 20 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
#include "DIO/DIO_interface.h"
#include "EXTINT_interface.h"

#include "EXTINT_register.h"
#include "EXTINT_private.h"
#include "EXTINT_config.h"


void EXTINT_Int1Init(uint8 Int_Sense){

	/* Disable PIE */

	CLR_BIT(GICR,GICR_INT2);

	/* Set Direction Of INT1 as Input Pullup */

	DIO_SetPinDirection(PORT_D, PIN3 , INPUT_PULLUP_PIN);

	/* Set Sense Control of INT1 */

	switch (Int_Sense){

	case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;

	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;

	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;

	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;

	}

	/* Enable PIE of INT1 */

	SET_BIT(GICR,GICR_INT1);
}

/********************************************************/

void EXTINT_Int0Init(uint8 Int_Sense){

	/* Disable PIE */

	CLR_BIT(GICR,GICR_INT2);

	/* Set Direction Of INT0 as Input Pullup */

	DIO_SetPinDirection(PORT_D, PIN2 , INPUT_PULLUP_PIN);

	/* Set Sense Control of INT0 */

	switch (Int_Sense){

	case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;

	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;

	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;

	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;

	}

	/* Enable PIE of INT0 */

	SET_BIT(GICR,GICR_INT0);

}

/********************************************************/

void EXTINT_Int2Init(uint8 Int_Sense){
	/* Disable PIE */

	CLR_BIT(GICR,GICR_INT2);

	/* Set Direction Of INT2 as Input Pullup */

	DIO_SetPinDirection(PORT_B, PIN2 , INPUT_PULLUP_PIN);

	/* Set Sense Control of INT2 */

	if(Int_Sense == FALLING_EDGE)
	{
		CLR_BIT(MCUCSR, MCUCR_ISC2);
	}
	else if(Int_Sense == RISING_EDGE)
	{
		SET_BIT(MCUCSR, MCUCR_ISC2);
	}

	/* Enable PIE of INT2 */

	SET_BIT(GICR,GICR_INT2);
}


/********************************************************/

void EXTINT_Disable(uint8 Int){
	switch (Int){
	case INT0: CLR_BIT(GICR,GICR_INT0);		break;
	case INT1: CLR_BIT(GICR,GICR_INT1);		break;
	case INT2: CLR_BIT(GICR,GICR_INT2);		break;

	}
}

/********************************************************/

void (*GlobalFuncP) (void) = NULL;

void EXTINT1_CallBack (void (*Func_Ptr) (void)){
	if(Func_Ptr != NULL){
		GlobalFuncP = Func_Ptr;
	}

}



/********************************************************/


void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	GlobalFuncP();
}

/********************************************************/