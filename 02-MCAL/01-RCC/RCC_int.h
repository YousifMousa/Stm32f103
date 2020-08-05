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
/*					This file contains interface parameters that the user	*/
/*					can use in the application  of the RCC (Reset and Clock	*/
/*					Control) in	the STM32f103c8t6.							*/
/*																			*/
/*	Version		:															*/
/*					V1.0													*/
/*																			*/
/****************************************************************************/
 
#ifndef _RCC_INT_H_
#define _RCC_INT_H_

/********************************************************************************/
/*							PARAMETER DEFINITIONS								*/
/********************************************************************************/


#define RCC_GPIOA		((u8) 0x00)
#define RCC_GPIOB		((u8) 0x01)
#define RCC_GPIOC		((u8) 0x02)

#define RCC_CLK_ENABLE 	((u8) 0xff)
#define RCC_CLK_DISABLE	((u8) 0x00)
/*	Error Status of a function. there are many possible errors that can	happen	*/
/* 	in a function. which defined in the follwing enum. if the function finished	*/
/* 	with no errors it will return  GPIO_NO_ERRORS.								*/
/*	The error status can be :													*/
/* 		- GPIO_CLK_NOTCONNECTED: if the clock is not conected to the GPIO 		*/
/*		peripheral.																*/
/*																				*/
/* 		- GPIO_NOT_DEFINED_NAME: if the input name of the pin is not defined or	*/
/*		out of range.															*/
/*																				*/
/* 		- GPIO_NOT_DEFINED_VALUE: if the input value of a specific pin is not 	*/
/*		defined.																*/
/*																				*/
/* 		- GPIO_PIN_IS_INPUT: if the GPIO pin is used as output and it is in 	*/
/*		input mode.																*/
/* 		- GPIO_NO_ERRORS: if the clock is not conected to the GPIO peripheral.	*/

typedef enum {
	RCC_NO_ERRORS_FOUND		= 0X00000000,
	RCC_UNDEFINED_NAME		= 0X00000001,
	RCC_UNDEFINED_VALUE		= 0X00000002,
	RCC_PIN_IS_INPUT		= 0x00000004,
	RCC_CLK_NOTCONNECTED	= 0x00000008,
	RCC_UNDEFINED_MODE		= 0X00000010
}RCC_ErrorStatusType;



/********************************************************************************/
/*							Function Prototypes									*/
/********************************************************************************/


/********************************************************************************/
/*																				*/
/*	Function	:																*/
/*					RCC_vidInit													*/
/*																				*/
/*	Description	:																*/
/*					This function is used to initlizing the RCC peripherals		*/
/*				according to the configration parameters defined in RCC_cfg.h	*/
/*				File.															*/
/*																				*/
/*	Input		:																*/
/*					NONE														*/
/*																				*/
/*	OUTPUT		:																*/
/*					NONE														*/
/*																				*/
/*	Example		:																*/
/*					RCC_vidInit();												*/
/*																				*/
/********************************************************************************/
void RCC_vidInit(void);


/********************************************************************************/
/*																				*/
/*	Function	:																*/
/*					RCC_enuGPIOEnable											*/
/*																				*/
/*	Description	:																*/
/*					This function is used to enable  a GPIO port by enabling	*/
/*					the clock of this port.										*/
/*																				*/
/*	Input		:																*/
/*					-u8GPIONameCpy												*/
/*																				*/
/*	OUTPUT		:																*/
/*					- enuErrorStatusLoc : an error status of the function that	*/
/*					reports any errors happened in the function.				*/
/*	Example		:																*/
/*					RCC_enuGPIOEnable();										*/
/*																				*/
/********************************************************************************/
RCC_ErrorStatusType RCC_enuGPIOEnable(u8 u8GPIONameCpy);

/********************************************************************************/
/*																				*/
/*	Function	:																*/
/*					RCC_enuGPIODisable											*/
/*																				*/
/*	Description	:																*/
/*					This function is used to disable  a GPIO port by disableings	*/
/*					the clock of this port.										*/
/*																				*/
/*	Input		:																*/
/*					-u8GPIONameCpy												*/
/*																				*/
/*	OUTPUT		:																*/
/*					- enuErrorStatusLoc : an error status of the function that	*/
/*					reports any errors happened in the function.				*/
/*	Example		:																*/
/*					RCC_enuGPIODisable();										*/
/*																				*/
/********************************************************************************/
RCC_ErrorStatusType RCC_enuGPIODisable(u8 u8GPIONameCpy);


#endif
