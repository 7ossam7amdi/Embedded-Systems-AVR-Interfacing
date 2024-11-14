/********************************************************/
/*	Name	: ADC_private.h								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 25 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

/* ADC Multiplexer Selection Register */

#define ADMUX    		*((volatile uint8*) 0x27)

#define ADMUX_REFS1		7
#define ADMUX_REFS0		6
#define ADMUX_ADLAR		5


/* ADC Control and Status Register*/

#define ADCSRA   		*((volatile uint8*) 0x26)

#define ADCSRA_ADEN		7
#define ADCSRA_ADSC		6
#define ADCSRA_ADATE	5
#define ADCSRA_ADIF		4
#define ADCSRA_ADIE		3
#define ADCSRA_ADPS2	2
#define ADCSRA_ADPS1	1
#define ADCSRA_ADPS0	0


/* The ADC Data Register – ADCL and ADCH */

#define ADCH     		*((volatile uint8*) 0x25)
#define ADCL     		*((volatile uint8*) 0x24)

/* Special FunctionIO Register – SFIOR */

#define SFIOR   		*((volatile uint8*) 0x50)

#define SFIOR_ADTS2		7
#define SFIOR_ADTS1		6
#define SFIOR_ADTS0		5

#endif
