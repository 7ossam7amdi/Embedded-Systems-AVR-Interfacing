/********************************************************/
/*	Name	: Timer_register.h							*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 27 September	2023						*/
/*	Version	: V01										*/
/********************************************************/


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/* Timer0 Registers */

#define TCCR0			*((volatile uint8*) 0x53)		/*  Timer0 Control Register  		*/

#define TCCR0_CS00		0								/* Prescaler bit 0  */
#define TCCR0_CS01		1								/* Prescaler bit 1  */
#define TCCR0_CS02		2								/* Prescaler bit 2  */
#define TCCR0_WGM01		3								/* Waveform generation mode bit 1  */
#define TCCR0_WGM00		6								/* Waveform generation mode bit 0  */

#define TIMSK			*((volatile uint8*) 0x59)   	/*  Interrupt Mask Register 		*/
#define TIMSK_OCIE0 	1								/* Output Compare0 Interrupt Enable */


#define TCNT0			*((volatile uint8*) 0x52)   	/*  Timer/Counter Register			*/
#define OCR0			*((volatile uint8*) 0x5C) 		/*  Timer0 Output Compare Register  */
#define TIFR			*((volatile uint8*) 0x58) 		/*	Interrupt Flag Register			*/

/* Timer1 Registers */

#define TCCR1A			*((volatile uint8*) 0x4F)		/*  Timer1 Control Register  		*/
#define TCCR1B			*((volatile uint8*) 0x4E)

#define TCNT1H			*((volatile uint8*) 0x4D)   	/*  Timer/Counter Register			*/
#define TCNT1L			*((volatile uint8*) 0x4C)


#define OCR1A			*((volatile uint16*) 0x4A)		/*  Timer1 Output Compare Register  */

#define ICR1			*((volatile uint16*) 0x46)

#define TIFR			*((volatile uint8*) 0x58) 		/*	Interrupt Flag Register			*/



#endif
