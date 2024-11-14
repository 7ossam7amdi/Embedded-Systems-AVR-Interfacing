/********************************************************/
/*	Name	: TWI_interface.h								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 5 October	2023							*/
/*	Version	: V01										*/
/********************************************************/


#include "TWI_config.h"
#include "TWI_private.h"

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum{
 NoError,
 StartConErr,
 RepStartErr,
 SlaveAddWRErr,
 SlaveAddRDErr,
 MasterWDErr,
 MasterRDErr

}TWI_ErrStatus;

/* Write Address = 0 in case it won't be a slave at any time */
void TWI_V_MasterInit (uint8 Copy_SLA);

void TWI_V_SlaveInit (uint8 Copy_SLA);
TWI_ErrStatus TWI_SendStartCondition (void);
TWI_ErrStatus TWI_SendRepeatedStart (void);
TWI_ErrStatus TWI_SendSLA_WR (uint8 Copy_SLA);
TWI_ErrStatus TWI_SendSLA_RD (uint8 Copy_SLA);
TWI_ErrStatus TWI_MasterWriteData (uint8 Copy_Data);
TWI_ErrStatus TWI_MasterReadData (uint8 *Copy_PData);

void TWI_SendStopCondition (void);
void TWI_V_SetBitRate(uint32 SCL_Freq , uint32 CPU_Clock);



#endif 
