/********************************************************/
/*	Name	: TWI_program.c								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 5 October	2023							*/
/*	Version	: V01										*/
/********************************************************/

#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"


void TWI_V_MasterInit (uint8 Copy_SLA){

	/* Set Master Clock */
	/*  Set Prescaler = 0 */

	CLR_BIT(TWSR , TWSR_TWPS0);
	CLR_BIT(TWSR , TWSR_TWPS1);

	/* CPU Clock is 16M and SCL Frequency is 400 khz */
	TWI_V_SetBitRate(16000000UL , 400000);

	/* Assign an address to my node */
	if(Copy_SLA != 0){
		TWAR = Copy_SLA << 1 ;
	}

	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);

}
void TWI_V_SlaveInit (uint8 Copy_SLA){

	/* Assign an address to my node */
	TWAR = Copy_SLA << 1 ;

	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
}


TWI_ErrStatus TWI_SendStartCondition (void){

	TWI_ErrStatus Local_Status = NoError;

	/* Send Start Condition */
	SET_BIT(TWCR , TWCR_TWSTA);

	/* Clear interrupt flag to execute operation */
	CLR_BIT(TWCR , TWCR_TWINT);

	/* Wait until flag is raised again */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check if start condition is done */
	if((TWSR & 0xF8) != START_ACK)
	{
		Local_Status = StartConErr;
	}

	return Local_Status;
}
TWI_ErrStatus TWI_SendRepeatedStart (void){

	TWI_ErrStatus Local_Status = NoError;

	/* Send Start Condition */
	SET_BIT(TWCR , TWCR_TWSTA);

	/* Clear interrupt flag to execute operation */
	CLR_BIT(TWCR , TWCR_TWINT);

	/* Wait until flag is raised again */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check if start condition is done */
	if((TWSR & 0xF8) != REP_START_ACK)
	{
		Local_Status = RepStartErr;
	}

	return Local_Status;

}
TWI_ErrStatus TWI_SendSLA_WR (uint8 Copy_SLA){

	TWI_ErrStatus Local_Status = NoError;


	/* Clear Start Condition Bit */
	CLR_BIT(TWCR , TWCR_TWSTA);

	/* Choose Write option at LSB "WR = 0 , RD = 1" */
	CLR_BIT(TWDR , 0);

	/* Set Slave Addresss on MSB */
	TWDR =  Copy_SLA << 1;

	/* Clear interrupt flag to execute operation */
	CLR_BIT(TWCR , TWCR_TWINT);

	/* Wait until flag is raised again */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check if Send SLA + WR is done */
	if((TWSR & 0xF8) != SLAVE_ADD_WR_ACK)
	{
		Local_Status = SlaveAddWRErr;
	}


	return Local_Status;
}
TWI_ErrStatus TWI_SendSLA_RD (uint8 Copy_SLA){

	TWI_ErrStatus Local_Status = NoError;

	/* Clear Start Condition Bit */
	CLR_BIT(TWCR , TWCR_TWSTA);

	/* Choose Read option at LSB "WR = 0 , RD = 1" */
	SET_BIT(TWDR , 0);

	/* Set Slave Addresss on MSB */
	TWDR =  Copy_SLA << 1;

	/* Clear interrupt flag to execute operation */
	CLR_BIT(TWCR , TWCR_TWINT);

	/* Wait until flag is raised again */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check if Send SLA + WR is done */
	if((TWSR & 0xF8) != SLAVE_ADD_RD_ACK)
	{
		Local_Status = SlaveAddRDErr;
	}

	return Local_Status;
}

TWI_ErrStatus TWI_MasterWriteData (uint8 Copy_Data){

	TWI_ErrStatus Local_Status = NoError;

	/* Write Data to Bus */
	TWDR =  Copy_Data;

	/* Clear interrupt flag to execute operation */
	CLR_BIT(TWCR , TWCR_TWINT);

	/* Wait until flag is raised again */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check if Sending Data is done */
	if((TWSR & 0xF8) != MASTER_WR_BYTE_ACK)
	{
		Local_Status = MasterWDErr;
	}

	return Local_Status;

}
TWI_ErrStatus TWI_MasterReadData (uint8 *Copy_PData){

	TWI_ErrStatus Local_Status = NoError;

	/* Enable Master Ack While Receiving Data */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Clear interrupt flag to execute operation */
	CLR_BIT(TWCR , TWCR_TWINT);

	/* Wait until flag is raised again */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check if Sending Data is done */
	if((TWSR & 0xF8) != MASTER_RD_BYTE_ACK)
	{
		Local_Status = MasterRDErr;
	}
	else {
		/* Read Data Byte from bus */
		*Copy_PData = TWDR;

	}

	return Local_Status;
}

void TWI_SendStopCondition (void){

	/* Send Start Condition */
	SET_BIT(TWCR , TWCR_TWSTO);

	/* Clear interrupt flag to execute operation */
	CLR_BIT(TWCR , TWCR_TWINT);

}


void TWI_V_SetBitRate(uint32 SCL_Freq , uint32 CPU_Clock){
	//TWBR = (CPU_Clock - 16*SCL_Freq) / 2*SCL_Freq;
	TWBR = 72;
}


