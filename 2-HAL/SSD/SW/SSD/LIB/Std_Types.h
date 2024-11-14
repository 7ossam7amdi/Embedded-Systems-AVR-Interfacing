/********************************************************/
/*	Name	: Std_Types.h								*/
/*	Author	: Hossam Hamdy								*/
/* 	Date	: 14 September	2023						*/
/*	Version	: V01										*/
/********************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


#ifndef TRUE
#define TRUE 1U
#endif

#ifndef FALSE
#define FALSE 0U
#endif

#ifndef NULL
#define NULL (void*) 0
#endif

typedef unsigned char      bool;
typedef unsigned char      uint8;
typedef signed char        sint8;
typedef unsigned short     uint16;
typedef signed short       sint16;
typedef unsigned long      uint32;
typedef signed long        sint32;
typedef unsigned long long uint64;
typedef signed long long   sint64;
typedef float              float32;
typedef double             float64;


#endif 
