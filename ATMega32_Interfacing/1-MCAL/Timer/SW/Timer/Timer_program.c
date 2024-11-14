/********************************************************/
/*	Name	: Timer_program.c							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 27 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
#include "DIO/DIO_interface.h"
#include "Timer_config.h"
#include "Timer_interface.h"
#include "Timer_private.h"
#include "Timer_register.h"


void Timer0_Init(uint8 mode , uint8 clk){
	switch(mode){
	case Normal:
		/* Choose normal mode */
		CLR_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		break;
	case PWM:
		//set PWM mode
		SET_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		break;
	case CTC:
		//set CTC mode
		CLR_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		break;
	case Fast_PWM:
		//set fast PWM mode
		SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		break;
	}
	Timer0_ClkSelect(clk);
}


void Timer0_ClkSelect(uint8 clk){
	switch(clk){
	case NO_SOURCE:
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;
	case NO_PRE:
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;
	case PRE8:
		//set 8 prescalar
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;
	case PRE64:
		//set 64 prescalar
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;
	case PRE256:
		//set 256 prescalar
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;
	case PRE1024:
		//set 1024 prescalar
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;
	case EX_FALLING:
		//set falling edge mode
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;
	case EX_RISING:
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
	}
}
//=================================================

uint8 READ_COUNT(){
	return TCNT0;
}


//=================================================
//set callback functions for app functions
/*
static void(*ptr)(void);

void CALL_BACK (void(*ROUTINE)(void)){
ptr=ROUTINE;
}
void __vector_11(void)  __attribute__((signal));
void __vector_11(void) {
	ptr();
}

 */
//=================================================
//set special ISR with its function "Delayms"
/*
static uint16 delay_val;
void __vector_11(void)  __attribute__((signal));
void __vector_11(void) {
	delay_val++;
}

void delayms(uint16 delay){

	while(delay_val<delay){

	}
	delay_val = 0;
}
 */

//=================================================




static void(*ptr)(void);
void Timer0_SetCallBack (void(*ROUTINE)(void)){
	ptr=ROUTINE;
}

static uint16 delay_val_ctc;
void __vector_10(void)  __attribute__((signal));
void __vector_10(void) {
	delay_val_ctc++;
	if(delay_val_ctc == 10000){
		ptr();
		delay_val_ctc = 0;
	}
}


//=================================================

void F_PWM_OCR(uint8 ocr){
	OCR0 = ocr;
}

//=================================================

void Timer1_Init(void){

	DIO_SetPinDirection(PORT_D, PIN5, OUTPUT_PIN);

	/* Set on top clear on compare */
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	/* Waveform Generation: Fast PWM, Top = ICR1 */
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	/* Select Prescalar 8*/
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);

	/* Set overflow time = period = 20000 */

	ICR1 = 20000;

}

//=================================================

void Servo_Go(uint16 Degree){
	//uint16 Ocr_Val =  mapRange(Degree, 0, 180, 1000, 2000);
		OCR1A = Degree;
}

//=================================================

double mapRange(double value, double oldMin, double oldMax, double newMin, double newMax) {
    // Check for division by zero to avoid errors
    if (oldMin == oldMax) {
        return newMin; // Return newMin when oldMin equals oldMax
    }

    // Perform the linear mapping
    return ((value - oldMin) / (oldMax - oldMin)) * (newMax - newMin) + newMin;
}