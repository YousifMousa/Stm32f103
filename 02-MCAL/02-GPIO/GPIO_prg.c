/****************************************************************************/
/*	Author      :                                                          	*/
/*                   Yousif Latif Zaki Mousa                               	*/
/*                                                                         	*/
/*	Date        :                             	                        	*/
/*                   Aug, 1st 2020											*/
/*                                                                         	*/
/*	E-mail      :                                                          	*/
/*                   Yousif.Mousa97@gmail.com                              	*/
/*                                                                         	*/
/*	File name   :                                                          	*/
/*                   GPIO_prg.c                                          	*/
/*                       													*/
/*	Github		:                                                          	*/
/*					https://github.com/YousifMousa/							*/
/*                                                                         	*/
/*	Description	:                                                          	*/
/*             	    This file contains all the c code implementations 		*/
/*             	of the GPIO peripheral in STM32f103c8t6.					*/
/*             																*/
/*	Version     :                                                          	*/
/*                   V1.0                                                  	*/
/*                                                                         	*/
/****************************************************************************/

/****************************************************************************/
/*							HEADER INCLUDES									*/
/****************************************************************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"

#include "GPIO_int.h"
#include "GPIO_cfg.h"
#include "GPIO_priv.h"

/****************************************************************************/
/*							GLOBAL VARIABLES								*/
/****************************************************************************/

/****************************************************************************/
/*							FUNCTION IMPLEMENTAIONS 						*/
/****************************************************************************/

void GPIO_vidInit(void){
}

GPIO_ErrorStatusType GPIO_enuSetPinValue(u8 const u8PinNameCpy, u8 const u8PinValueCpy){

/*	enuErrorStatusLoc is the error status of the function if any error		*/ 
/*	happens in the function.												*/ 
    GPIO_ErrorStatusType enuErrorStatusLoc = GPIO_NO_ERRORS_FOUND;
	
/*	A local pointer to select which port the pin used in. It is initialized */
/*	to GPIO port A.															*/
    volatile pGPIOType pGPIOTypePortNameLoc = (volatile pGPIOType) GPIOA;

/*	u32PinPositionLoc is used to determine which bit in the 32 bit regieter */
/* 	we are going to change.													*/
    u32 u32PinPositionLoc = u8PinNameCpy;


/*  Check the name is in the range of available pins in the STM32f103c8t6.	*/
    if(u8PinNameCpy > GPIO_END_PIN){
/*	If it is not in the range we assign the Error status enum to the		*/
/*	undefined name.															*/
        enuErrorStatusLoc = GPIO_UNDEFINED_NAME;
    }
/*  Check the value that we need it to be assigned to the Pin.				*/
    else if((u8PinValueCpy != GPIO_HIGH) && (u8PinValueCpy != GPIO_LOW)){
/*  If it is not either GPIO_HIGH or GPIO_LOW then Status error will be    	*/
/*	assigned to undefined Value.											*/
        enuErrorStatusLoc = GPIO_UNDEFINED_VALUE;
    }
    else{
/*	Getting the Selected Port And the selected Pin in that port.			*/
		GPIO_vidPinLocation(u8PinNameCpy, &pGPIOTypePortNameLoc,&u32PinPositionLoc );
		
/*  Check the value that is needed to be assigned to the PIN.           	*/
		if(u8PinValueCpy == GPIO_HIGH ){
/*	we dereference the Pointer that assigned to the GPIO selected. And we 	*/
/*	use the BSRR Register for atomic Operations.							*/
			pGPIOTypePortNameLoc->BSRR = 
					FIRST_BIT_LOCATION <<u32PinPositionLoc;
		}
		else{
/* 	For LOW values we use  BRR register. 									*/
			pGPIOTypePortNameLoc->BRR = 
					FIRST_BIT_LOCATION << u32PinPositionLoc;
		}
	}
    return enuErrorStatusLoc; 
}

GPIO_ErrorStatusType GPIO_enuSetMode(u8 const u8PinNameCpy, u8 const u8ModeCpy ){
/*	enuErrorStatusLoc is the error status of the function if any error		*/
/*	happens in the function.												*/
    GPIO_ErrorStatusType enuErrorStatusLoc = GPIO_NO_ERRORS_FOUND;

/*	A local pointer to select which port the pin used in. It is initialized */
/*	to GPIO port A.															*/
    volatile pGPIOType pGPIOTypePortNameLoc = (volatile pGPIOType) GPIOA;
	
/*	This pointer is used to chose which register is used in control			*/
/*	depending on the pin if it is in the upper half of the port CRH is used	*/
/*	if it is in the lower part CRL is used.									*/
	volatile u32 * pu32ControlRegisterLoc = &GPIOA->CRL;
	
/*	u32PinPositionLoc is used to determine which bits in the 32  			*/
/* 	bit-regieter we are going to change.									*/
    u32 u32PinPositionLoc = FIRST_BIT_LOCATION;
	
/*	u8GPIOModeLoc is used to hold the value of the GPIO Configuration.		*/
	u8 u8GPIOModeLoc = GPO_PUSHPULL_CNF_MODE;

/*  Check the name is in the range of available pins in the STM32f103c8t6.	*/
    if(u8PinNameCpy > GPIO_END_PIN){
/*	If it is not in the range we assign the Error status enum to the		*/
/*	undefined name.															*/
        enuErrorStatusLoc = GPIO_UNDEFINED_NAME;
    }
/*	Check on the Values of the u8ModeCpy argument.							*/
    else if(( GPIO_GPO_PUSHPULL 	!=	u8ModeCpy)	&&
			( GPIO_GPO_OPEN_DRAIN	!=	u8ModeCpy)	&&
			( GPIO_AFO_PUSHPULL		!=	u8ModeCpy)	&&
			( GPIO_AFO_OPEN_DRAIN	!=	u8ModeCpy)	&&
			( GPIO_INPUT_ANALOG		!=	u8ModeCpy)	&&
			( GPIO_INPUT_FLOATING	!=	u8ModeCpy)	&&
			( GPIO_INPUT_PULLDOWN	!=	u8ModeCpy)	&&
			( GPIO_INPUT_PULLUP		!=	u8ModeCpy)	
			){
/*	If the u8ModeCpy is neither one of the defined arguments then error		*/
/* 	flag wil be assigned to the error status.								*/
        enuErrorStatusLoc = GPIO_UNDEFINED_MODE;
    }
    else{
/*	Getting the Selected Port And the selected Pin in that port.			*/
		GPIO_vidPinLocation(u8PinNameCpy, &pGPIOTypePortNameLoc,&u32PinPositionLoc );
/* 	Because each pin has 4 bits for configuration we multiply the pin 		*/
/*	location by 4.															*/
		u32PinPositionLoc = u32PinPositionLoc* NUMBER_OF_CNF_BITS;
		
/*	Get the configuration and the mode bits.								*/
		switch (u8ModeCpy){
/*	In case its a general purpose output pin Pushpull.						*/
			case GPIO_GPO_PUSHPULL		:
/* 	Assign the u8GPIOModeLoc to PushPull output mode.						*/
				u8GPIOModeLoc = GPO_PUSHPULL_CNF_MODE;
				break;

/*	In case its a general purpose output pin opendrain.						*/
			case GPIO_GPO_OPEN_DRAIN	:
/* 	Assign the u8GPIOModeLoc to open Drain output mode.						*/
				u8GPIOModeLoc = GPO_OPEN_DRAIN_CNF_MODE;
				break;

/*	In case its a alternate function output pin Pushpull.					*/
			case GPIO_AFO_PUSHPULL	 	:
/* 	Assign the u8GPIOModeLoc to  alternate function mode Pushpull. 			*/
				u8GPIOModeLoc = AFO_PUSHPULL_CNF_MODE;	
				break;

/*	In case its a alternate function output pin openc drain.				*/
			case GPIO_AFO_OPEN_DRAIN	:
/* 	Assign the u8GPIOModeLoc to open drain alternate function mode.			*/
				u8GPIOModeLoc = AFO_OPEN_DRAIN_CNF_MODE;	
				break;
 
/*	In case its a analog input pin.											*/
			case GPIO_INPUT_ANALOG	 	:
/* 	Assign the u8GPIOModeLoc to analog input  mode.							*/
				u8GPIOModeLoc = INPUT_ANALOG_CNF_MODE;	
				break;

/*	In case its a analog input floating pin.								*/
			case GPIO_INPUT_FLOATING	:
/* 	Assign the u8GPIOModeLoc to  input floating mode.						*/
				u8GPIOModeLoc = INPUT_FLOATING_CNF_MODE;	
				break;
	
/*	In case it is an analog input pullup pin OR input pulldown				*/
			default		:
/* 	Assign the u8GPIOModeLoc to pullup pin OR input pulldown.				*/
				u8GPIOModeLoc = INPUT_PULLDOWN_PULLUP_CNF_MODE;	
				break;			
		}
		
/*	Check on the location of the pin to operate on the lower or the higher 	*/
/*	Register.																*/
		if (u32PinPositionLoc < LOWER_CONFIG_REG ){
/* 	Selecting the lower register  for configuration.						*/
			pu32ControlRegisterLoc = &pGPIOTypePortNameLoc->CRH;
		}
		else{
/* 	Get the position of the bit in the higher register.						*/
			u32PinPositionLoc =
					u32PinPositionLoc %  NUMBER_OF_BITS_IN_REGISTER;
/*	selelcting the higher register for mode configration.					*/
			pu32ControlRegisterLoc = &pGPIOTypePortNameLoc->CRH;
		}
		
		*pu32ControlRegisterLoc |= 
						(u8GPIOModeLoc << u32PinPositionLoc);
/*	Get the zeros in the 4 bit configration bits.							*/
		u8GPIOModeLoc = (~u8GPIOModeLoc) & FIRST_FOUR_BIT_MASK;
/*	Setting the necesseray bits to zeros in the lower config register.		*/
		*pu32ControlRegisterLoc &= 
						~(u8GPIOModeLoc << u32PinPositionLoc);
    }
    return enuErrorStatusLoc; 
}

GPIO_ErrorStatusType GPIO_enuTogglePin(u8 const u8PinNameCpy){
/*	enuErrorStatusLoc is the error status of the function if any error		*/ 
/*	happens in the function.												*/ 
    GPIO_ErrorStatusType enuErrorStatusLoc = GPIO_NO_ERRORS_FOUND;

/*	u32PinPositionLoc is used to determine which bit in the 32 bit regieter */
/* 	we are going to change.													*/
    u32 u32PinPositionLoc = FIRST_BIT_LOCATION;
    
/*	A local pointer to select which port the pin used in. It is initialized */
/*	to GPIO port A.															*/
    volatile pGPIOType pGPIOTypePortNameLoc = (volatile pGPIOType) GPIOA;

/*  check the name is the range of available pins in the STM32f103c8t6 		*/
/*	microcontroller.														*/    
    if(u8PinNameCpy > GPIO_END_PIN){
/* 	if it is not in the range of pin numbers, we assign the Error status	*/
/*	enum Value to the undefined name.										*/
        enuErrorStatusLoc = GPIO_UNDEFINED_NAME;
    }
    else{
/*	Getting the Selected Port And the selected Pin in that port.			*/
		GPIO_vidPinLocation(u8PinNameCpy, &pGPIOTypePortNameLoc,&u32PinPositionLoc );
/*	Toggle the pin in the selected port.									*/
		pGPIOTypePortNameLoc->ODR ^= 
				(FIRST_BIT_LOCATION<<u32PinPositionLoc);
    }
    return enuErrorStatusLoc; 
}
    
/****************************************************************************/
/*							Static FUNCTIONS								*/
/****************************************************************************/
static void GPIO_vidPinLocation(u8 u8PinNameCpy,  
								volatile pGPIOType * ppGPIOTypePortNameCpy,
								u32 * pu32PinPositionCpy){
									
/*  check if the name (u8PinNameCpy) of the pin is in PORTA.				*/    
        if(u8PinNameCpy <=  GPIOA_END){ 
/* 	Assign the pointer pGPIOTypePortNameLoc to PORTA address.				*/
			*ppGPIOTypePortNameCpy = (volatile pGPIOType) GPIOA;
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTB.				*/    
        else if(u8PinNameCpy <= GPIOB_END ){
/*  if it is in range of PORTB, we calculate the position of the pin.		*/
            *pu32PinPositionCpy = u8PinNameCpy % PINS_PREV_TO_GPIOB; 
/* 	Assign the pointer pGPIOTypePortNameLoc to PORTB address.				*/
			*ppGPIOTypePortNameCpy = (volatile pGPIOType) GPIOB;
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTC.				*/    
        else {
/*	If it is in PORTC we calculate the location of the pin relative to the 	*/
/*	port because in stm32f103 (blue pill) there is only 3 pins in portc 	*/
/* 	which are PIN13, PIN14, PIN15.											*/
			*pu32PinPositionCpy = (u32)((u8PinNameCpy % PINS_PREV_TO_GPIOC) + 
									GPIOC_PINS_OFFSET);
/* 	Assign the pointer pGPIOTypePortNameLoc to PORTB address.				*/
			*ppGPIOTypePortNameCpy = (volatile pGPIOType) GPIOC;
        }									
	
}