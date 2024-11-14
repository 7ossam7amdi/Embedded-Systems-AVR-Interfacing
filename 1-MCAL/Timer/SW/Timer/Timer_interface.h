/********************************************************/
/*	Name	: Timer_interface.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 27 September	2023						*/
/*	Version	: V01										*/
/********************************************************/


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer0_Init(uint8 mode , uint8 clk);
void Timer0_ClkSelect(uint8 clk);

uint8 READ_COUNT();
void delayms(uint16 delay);

void Timer0_SetCallBack (void(*ROUTINE)(void));
void FPWM_50_INIT(void);
void F_PWM_OCR(uint8 ocr);

void Timer1_Init(void);

void Servo_Go(uint16 Degree);

double mapRange(double value, double oldMin, double oldMax, double newMin, double newMax);

#endif 
