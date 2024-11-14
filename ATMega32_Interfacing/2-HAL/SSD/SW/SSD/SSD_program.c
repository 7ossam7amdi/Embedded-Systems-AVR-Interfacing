/********************************************************/
/*	Name	: SSD_program.c  							*/
/*  Layer	: HAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 16 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"


#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"



uint8 SSD_SetNumber (uint8 Copy_Number , SSD_t* CopyP_SSDStruct){
	uint8 Error_State = 0;

	if((CopyP_SSDStruct ->Type == COM_Anode) || CopyP_SSDStruct->Type == COM_Cathode){
		if( CopyP_SSDStruct -> Type == COM_Anode ){
			switch(Copy_Number){
			case 0:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_0);  break;
			case 1:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_1);  break;
			case 2:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_2);  break;
			case 3:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_3);  break;
			case 4:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_4);  break;
			case 5:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_5);  break;
			case 6:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_6);  break;
			case 7:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_7);  break;
			case 8:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_8);  break;
			case 9:   DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_9);  break;
			default:  Error_State = 1;									   break;
			}

		}
		else if(CopyP_SSDStruct -> Type == COM_Cathode){
			switch(Copy_Number){
			case 0:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_0));  break;
			case 1:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_1));  break;
			case 2:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_2));  break;
			case 3:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_3));  break;
			case 4:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_4));  break;
			case 5:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_5));  break;
			case 6:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_6));  break;
			case 7:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_7));  break;
			case 8:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_8));  break;
			case 9:   DIO_SetPortValue(CopyP_SSDStruct-> Port ,~(Anode_9));  break;
			default:  Error_State = 1;										 break;
			}
		}
	}
	else {
		Error_State = 1;
	}
	return Error_State;
}

/****************************************************************************************/


uint8 SSD_Enable (SSD_t* CopyP_SSDStruct){
	uint8 Error_State = 0;

	DIO_SetPortDirection(CopyP_SSDStruct-> Port , PORT_OUTPUT);
	DIO_SetPinDirection(CopyP_SSDStruct-> EnPort ,CopyP_SSDStruct->EnPin, OUTPUT_PIN);

	if((CopyP_SSDStruct->Type == COM_Anode) || (CopyP_SSDStruct->Type == COM_Cathode)){
		if( CopyP_SSDStruct -> Type == COM_Anode ){


			DIO_SetPinValue(CopyP_SSDStruct-> EnPort ,CopyP_SSDStruct->EnPin, PIN_HIGH);
			DIO_SetPortValue(CopyP_SSDStruct-> Port , Anode_0);

		}
		else if(CopyP_SSDStruct -> Type == COM_Cathode){

			DIO_SetPinValue(CopyP_SSDStruct-> EnPort ,CopyP_SSDStruct->EnPin, PIN_LOW);
			DIO_SetPortValue(CopyP_SSDStruct-> Port , ~(Anode_0));
		}
	}
	else {
		Error_State = 1;
	}
	return Error_State;
}

/****************************************************************************************/


uint8 SSD_Disable (SSD_t* CopyP_SSDStruct){
	uint8 Error_State = 0;

	DIO_SetPortDirection(CopyP_SSDStruct-> Port , PORT_INPUT);
	DIO_SetPinDirection(CopyP_SSDStruct-> EnPort ,CopyP_SSDStruct->EnPin, OUTPUT_PIN);

	if((CopyP_SSDStruct ->Type == COM_Anode) || (CopyP_SSDStruct->Type == COM_Cathode)){
		if( CopyP_SSDStruct -> Type == COM_Anode ){


			DIO_SetPinValue(CopyP_SSDStruct-> EnPort ,CopyP_SSDStruct->EnPin, PIN_LOW);

		}
		else if(CopyP_SSDStruct -> Type == COM_Cathode){

			DIO_SetPinValue(CopyP_SSDStruct-> EnPort ,CopyP_SSDStruct->EnPin, PIN_HIGH);
		}
	}
	else {
		Error_State = 1;
	}

	return Error_State;
}

