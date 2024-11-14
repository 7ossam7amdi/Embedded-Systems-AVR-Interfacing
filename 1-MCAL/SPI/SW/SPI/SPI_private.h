/********************************************************/
/*	Name	: SPI_private.h								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 4 October	2023							*/
/*	Version	: V01										*/
/********************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


/* Clock Polarity */

#define IDLE_HIGH	1
#define IDLE_LOW	2


/* Data Order */

#define LSB_ORDER	1
#define MSB_ORDER	2

/* Clock Phase */

#define SETUP_LEADING	1
#define SAMPLE_LEADING	2

/* Clock Rate */

#define   F_DIV_4  		1
#define   F_DIV_16 		2
#define   F_DIV_64 		3
#define   F_DIV_128		4
#define   F_DIV_2  		5
#define   F_DIV_8  		6
#define   F_DIV_32 		7

#endif
