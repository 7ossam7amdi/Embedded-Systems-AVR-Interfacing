/********************************************************/
/*	Name	: TWI_private.h								*/
/*  Layer	: MCAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 5 October	2023							*/
/*	Version	: V01										*/
/********************************************************/


#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

/* Status Codes for Master Transmitter Mode */

#define START_ACK				0x08	/* Master has sent start */
#define REP_START_ACK			0x10	/* Repeated start from master */
#define SLAVE_ADD_WR_ACK		0x18	/* Master has transmit (Slave Add + Write request) */
#define SLAVE_ADD_RD_ACK		0x40	/* Master has transmit (Slave Add + Read request)  */
#define MASTER_WR_BYTE_ACK		0x28	/* Master transmit data ACK */
#define MASTER_RD_BYTE_ACK		0x50	/* Master received data with ACK */
#define MASTER_RD_BYTE_NACK		0x58	/* Master received data with not ACK */
#define SLA_RCVD_RD_REQ			0xA8    /* SLA is received with read request */
#define SLA_RCVD_WR_REQ			0x60    /* SLA is received with write request */
#define SLAVE_DATA_RECEIVED		0x80	/* Means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED  0xB8	/* Means that the written byte is transmitted */


#endif 
