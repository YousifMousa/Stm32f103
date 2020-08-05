/****************************************************************************/
/*	Author		:															*/
/*					Yousif Latif Zaki Mousa									*/
/*																			*/
/*	Date		:															*/
/*					Aug,3rd 2020											*/
/*																			*/
/*	E-mail		:															*/
/*					Yousif.Mousa97@gmail.com								*/
/*																			*/
/*	File name	:															*/
/*					RCC_cfg.h												*/
/*																			*/
/*	Github		:															*/
/*					https://github.com/YousifMousa/							*/
/*																			*/
/*	Description	:															*/
/*					This file contains all the c code implementations of	*/
/*				the RCC (Reset and clock control) peripheral in the			*/
/*				STM32f103c8t6 microcontroller.								*/
/*	Version		:															*/
/*					V1.0													*/
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*							HEADER INCLUDES									*/
/****************************************************************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"

#include "RCC_int.h"
#include "RCC_cfg.h"
#include "RCC_priv.h"

/****************************************************************************/
/*							GLOBAL VARIABLES								*/
/****************************************************************************/


/****************************************************************************/
/*							FUNCTION IMPLEMENTAIONS							*/
/****************************************************************************/

void Rcc_vidInit(void){
}


RCC_ErrorStatusType RCC_enuGPIOEnable(u8 u8GPIONameCpy){

/*	enuErrorStatusLoc is the error status of the function if any error		*/ 
/*	happens in the function.												*/ 
    RCC_ErrorStatusType enuErrorStatusLoc = RCC_NO_ERRORS_FOUND;
/* Checking which port to enable.											*/
	switch(u8GPIONameCpy){
/*	In case Port A.															*/
		case RCC_GPIOA:
/*	Assigning the bit corresponding to Port A.								*/
			RCC->APB2ENR |= RCC_GPIOA_ENABLE;
			break;

/*	In case Port B.															*/
		case RCC_GPIOB: 
/*	Assigning the bit corresponding to Port B.								*/
			RCC->APB2ENR |= RCC_GPIOB_ENABLE;
			break;

/*	In case Port C.															*/
		case RCC_GPIOC:
/*	Assigning the bit corresponding to Port C.								*/
			RCC->APB2ENR |= RCC_GPIOC_ENABLE;
			break;
/*	In case Port  Other names which are not available.						*/
		default	:
/*	Assigning the Error status to undifined peripheral name.				*/
			enuErrorStatusLoc  = RCC_UNDEFINED_NAME ; 
			break;
	}
	return enuErrorStatusLoc ; 
}



RCC_ErrorStatusType RCC_enuGPIODisable(u8 u8GPIONameCpy){

/*	enuErrorStatusLoc is the error status of the function if any error		*/ 
/*	happens in the function.												*/ 
    RCC_ErrorStatusType enuErrorStatusLoc = RCC_NO_ERRORS_FOUND;
/* Checking which port to disable.											*/
	switch(u8GPIONameCpy){
/*	In case Port A.															*/
		case RCC_GPIOA:
/*	Assigning the bit corresponding to Port A.								*/
			RCC->APB2ENR |= ~RCC_GPIOA_ENABLE;
			break;

/*	In case Port B.															*/
		case RCC_GPIOB: 
/*	Assigning the bit corresponding to Port B.								*/
			RCC->APB2ENR |= ~RCC_GPIOB_ENABLE;
			break;

/*	In case Port C.															*/
		case RCC_GPIOC:
/*	Assigning the bit corresponding to Port C.								*/
			RCC->APB2ENR |= ~RCC_GPIOC_ENABLE;
			break;
/*	In case Port  Other names which are not available.						*/
		default	:
/*	Assigning the Error status to undifined peripheral name.				*/
			enuErrorStatusLoc  = RCC_UNDEFINED_NAME ; 
			break;
	}
	return enuErrorStatusLoc ; 
}


/****************************************************************************/
/*							Static FUNCTIONS								*/
/****************************************************************************/

