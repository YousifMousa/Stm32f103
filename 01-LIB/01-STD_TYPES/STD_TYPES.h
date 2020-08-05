/*************************************************************************************************
*   Author      :
*                   Yousif Latif Zaki Mousa
*
*   Date        :
*                   December, 1st 2019
*
*   E-mail      :
*                   Yousif.Mousa97@gmail.com
*
*   File name   :
*                   Std_types.h
*
*   Description :
*                   This file contains all the variable definitions  peripheral that the user
*                   needs.
*               .
*   Version     :
*                   V1.0
*
*************************************************************************************************/

/**					Std_types 	Gurad to Avoid Multiple Inclusion					 **/
#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_


typedef unsigned char u8 ;

typedef signed   char s8 ;

typedef unsigned short int u16;

typedef signed short int s16 ;

typedef unsigned long int u32;

typedef signed  long int s32 ;

typedef float f32;

typedef double f64;

typedef long double f128;

typedef	void (*vidPfvid)(void);

typedef const u32 u32UnaccessibleType ;

typedef const u32 u32ReadOnlyType;

typedef volatile u32 u32VolatileType ;

typedef enum error{
	OK = 0,
	NOK = 4,
	INDEX_OUT_OF_RANGE = 8,
	NULL_POINTER = 16,
	ARRAY_OUT_OF_BOUNDS = 32
}Error_Status;

#endif
