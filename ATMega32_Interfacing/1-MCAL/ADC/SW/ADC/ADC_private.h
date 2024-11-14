/********************************************************/
/*	Name	: ADC_private.h								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 25 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define AREF		1
#define AVCC		2
#define INTERNAL	3

#define LEFT_ADJ	1
#define RIGHT_ADJ	2


#define PRE0		0
#define PRE2		1
#define PRE4  		2
#define PRE8  		3
#define PRE16 		4
#define PRE32 		5
#define PRE64 		6
#define PRE128		7

#define PRESCALAR_MASK	0b11111000
#define MUX_MASK		0b11100000


#define ADC_CH0		0b00000000
#define ADC_CH1		0b00000001
#define ADC_CH2		0b00000010
#define ADC_CH3		0b00000011
#define ADC_CH4		0b00000100
#define ADC_CH5		0b00000101
#define ADC_CH6		0b00000110
#define ADC_CH7		0b00000111








#endif
