/********************************************************/
/*	Name	: ADC_interface.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 25 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


enum ADC_CH {

	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
};


void ADC_Init (void);

uint16 ADC_GetChannelReading (uint8 Copy_Channel);




#endif
