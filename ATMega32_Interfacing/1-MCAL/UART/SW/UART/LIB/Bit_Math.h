/********************************************************/
/*	Name	: Bit_Math.h								*/
/*  Layer	: Library									*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 14 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef BIT_BATH_H_
#define BIT_BATH_H_

#define SET_BIT(Reg,Bit)    (Reg |= (1<<Bit))

#define CLR_BIT(Reg,Bit)    (Reg &= ~(1<<Bit))

#define TGL_BIT(Reg,Bit)    (Reg ^= (1<<Bit))

#define GET_BIT(Reg,Bit)    ((Reg & (1<<Bit))>>Bit)


#endif 



