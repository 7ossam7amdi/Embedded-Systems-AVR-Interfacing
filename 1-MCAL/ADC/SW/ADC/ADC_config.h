/********************************************************/
/*	Name	: ADC_config.h								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 25 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/* OPTIONS FOR REFERNCE ARE:
 * AREF: 	  Pin at microcontroller
 * AVCC: 	  The source voltage of ADC
 * INTERNAL:  Internal 2.56volts
 *  */
#define RFERENCE_VOLT	AVCC

/* ADJUST OPTIONS:
 * RIGHT_ADJ: for full resolution
 * LEFT_ADJ: for 8 bit resolution and read ADCH
 *  */

#define ADJUST	RIGHT_ADJ

/* SELECT THE PRESCALAR
 * PRE0
 * PRE4
 * PRE8
 * PRE16
 * PRE32
 * PRE64
 * PRE128
 * */

#define ADC_PRESCALAR	PRE128

#define ADC_TIMEOUT	50000
#endif
