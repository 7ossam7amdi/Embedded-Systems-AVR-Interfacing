/********************************************************/
/*	Name	: ADC_program.c								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 25 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"
#include "LIB/Bit_Math.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_register.h"

void ADC_Init(void){

	/* Select the voltage reference */

#if RFERENCE_VOLT == AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);


#elif RFERENCE_VOLT == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif RFERENCE_VOLT == INTERNAL
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#endif

	/* Select the adjust mode */

#if	ADJUST == LEFT_ADJ
	SET_BIT(ADMUX,ADMUX_ADLAR);
#else
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#endif

	/* Select the prescalar */

	ADCSRA &= PRESCALAR_MASK;

#if   ADC_PRESCALAR == PRE0
	ADCSRA |= PRE0;

#elif ADC_PRESCALAR == PRE2
	ADCSRA |= PRE2;

#elif ADC_PRESCALAR == PRE4
	ADCSRA |= PRE4;

#elif ADC_PRESCALAR == PRE8
	ADCSRA |= PRE8;

#elif ADC_PRESCALAR == PRE16
	ADCSRA |= PRE16;

#elif ADC_PRESCALAR == PRE32
	ADCSRA |= PRE32;

#elif ADC_PRESCALAR == PRE64
	ADCSRA |= PRE64;

#elif ADC_PRESCALAR == PRE128
	ADCSRA |= PRE128;

#endif

	/* Enable the ADC */
	SET_BIT(ADCSRA, ADCSRA_ADEN);

}

/*********************************************************************/

uint16 ADC_GetChannelReading (uint8 Copy_Channel){

	uint32 Counter = 0;
	uint16 Return_Val = 0;
	uint16* P_ADCL = &ADCL;

	/*Select the channel*/
	ADMUX &= MUX_MASK;
	switch(Copy_Channel){
		case ADC0:	ADMUX |= ADC_CH0;	break;
		case ADC1:	ADMUX |= ADC_CH1;	break;
		case ADC2:	ADMUX |= ADC_CH2;	break;
		case ADC3:	ADMUX |= ADC_CH3;	break;
		case ADC4:	ADMUX |= ADC_CH4;	break;
		case ADC5:	ADMUX |= ADC_CH5;	break;
		case ADC6:	ADMUX |= ADC_CH6;	break;
		case ADC7:	ADMUX |= ADC_CH7;	break;
	}

	/* Start Single Conversion */
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/* Wait until the conversion complete with timeout to not stuck to inf */
	while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0 && Counter != ADC_TIMEOUT){
		Counter++;
	}

	/* Clear the conversion complete flag */
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	/* Return the value */

	#if ADJUST == LEFT_ADJ
	Return_Val =  ADCH;

	#else
	Return_Val = *P_ADCL;
	#endif

	/* Loop is broken cause of timeout */
	if(Counter == ADC_TIMEOUT){
		Return_Val = 0;
	}
	return Return_Val;
}