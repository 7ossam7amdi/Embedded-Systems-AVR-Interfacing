/********************************************************/
/*	Name	: Keypad_config.h							    */
/*  Layer	: HAL										*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 18 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

/*Preprocessor file guard*/
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define KEYPAD_ROW_PORT	  PORT_B
#define KEYPAD_R0_PIN	  PIN0
#define KEYPAD_R1_PIN	  PIN1
#define KEYPAD_R2_PIN	  PIN2
#define KEYPAD_R3_PIN	  PIN3



#define KEYPAD_COL_PORT	  PORT_B
#define KEYPAD_C0_PIN	  PIN4
#define KEYPAD_C1_PIN	  PIN5
#define KEYPAD_C2_PIN	  PIN6
#define KEYPAD_C3_PIN	  PIN7

#define ROWS_NUM	4
#define COLS_NUM	4

#define KEYPAD_MAP	{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}}

#define NO_PRESSED_KEY	'n'

#endif
