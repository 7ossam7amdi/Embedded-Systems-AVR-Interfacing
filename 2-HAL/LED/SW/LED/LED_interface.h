/********************************************************/
/*	Name	: LED_interface.h							*/
/*  Layer	: HAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 17 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


typedef struct {
	uint8 Type;		  /* The type of LED "Source" or "Sink"          */
	uint8 Port;       /* The port in which LED will be connected to  */
	uint8 Pin;	      /* The Enable pin of LED					     */
}LED_t;

#define LED_SINK	0
#define LED_SOURCE	1


void LED_Init (LED_t* CopyP_LED);

void LED_ON (LED_t* CopyP_LED);

void LED_OFF (LED_t* CopyP_LED);




#endif
