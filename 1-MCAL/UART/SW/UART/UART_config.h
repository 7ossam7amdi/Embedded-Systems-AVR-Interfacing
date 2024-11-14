/********************************************************/
/*	Name	: UART_config.h							    */
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 27 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/* Sync options are:
 * SYNCHRONOUS
 * ASYNCHRONOUS
 *  */
#define SYNC	ASYNCHRONOUS

/* Parity options are:
 * DISABLED
 * EVEN
 * ODD
 *  */

#define PARITY	DISABLED

/* Stop bit options:
 * STOP1
 * STOP2
 *  */

#define STOP_BITS	STOP1

/* Character Size Options:
 * BIT5
 * BIT6
 * BIT7
 * BIT8
 * BIT9
 *   */

#define CHAR_SIZE	BIT8

#endif
