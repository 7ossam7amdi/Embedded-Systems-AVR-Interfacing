/********************************************************/
/*	Name	: Timer_config.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 27 September	2023						*/
/*	Version	: V01										*/
/********************************************************/


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/* Timer Modes */
typedef enum{
	Normal,
	PWM,
	CTC,
	Fast_PWM
}Timer_Mode;


/* Select Clock Source and Prescalars */
typedef enum {
	NO_SOURCE,
	NO_PRE,
	PRE8,
	PRE64,
	PRE256,
	PRE1024,
	EX_FALLING,
	EX_RISING
}Timer_Clk;


typedef enum CMP_OP_MODE {
	NormalC,
	Reserved,
	NON_INV,
	INV
}Cmp_Mode;



#endif
