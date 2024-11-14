/********************************************************/
/*	Name	: SSD_interface.h							*/
/*  Layer	: HAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 16 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct {
	uint8 Type;		  /* The type of SSD "Anode" or "Cathode"    */
	uint8 Port;       /* The port which will be connected to SSD */
	uint8 EnPort;	  /* The port of the enable pin of SSD       */
	uint8 EnPin;	  /* The Enable pin of SSD					 */
}SSD_t;


uint8 SSD_Enable (SSD_t* CopyP_SSDStruct);

uint8 SSD_Disable (SSD_t* CopyP_SSDStruct);

uint8 SSD_SetNumber (uint8 Copy_Number , SSD_t* CopyP_SSDStruct);



#define COM_Cathode  1
#define COM_Anode    2


#endif