/********************************************************/
/*	Name	: SPI_config.h								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 4 October	2023							*/
/*	Version	: V01										*/
/********************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* Options are:
 * IDLE_HIGH
 * IDLE_LOW
 *  */
#define CLOCK_POLARITY	IDLE_HIGH


/* Options are:
 * LSB_ORDER
 * MSB_ORDER
 *  */
#define DATA_ORDER	LSB_ORDER

/* Options are:
 * SAMPLE_LEADING
 * SETUP_LEADING
 *  */
#define CLOCK_PHASE  SETUP_LEADING

/* Options are:
 * F_DIV_4
 * F_DIV_16
 * F_DIV_64
 * F_DIV_128
 * F_DIV_2
 * F_DIV_8
 * F_DIV_32
 *  */
#define CLOCK_RATE	F_DIV_2

#endif
