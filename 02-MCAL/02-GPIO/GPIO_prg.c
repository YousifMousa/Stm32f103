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
    volatile GPIOType * pGPIOTypePortNameLoc = (volatile GPIOType *) GPIOA;

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
/*  Check if the name (u8PinNameCpy) of the pin is in PORTA.				*/
        if(u8PinNameCpy <= GPIOA_END){
/*	Assigning a pointer to the GPIOA register.								*/
			pGPIOTypePortNameLoc = (volatile GPIOType *) GPIOA;
		}
/*  check if the name (u8PinNameCpy) of the pin is in PORTB.				*/
        else if(u8PinNameCpy <= GPIOB_END ){		
/*  if it is in range of PORTB, we calculate the position of the pin		*/
/* 	map register.              												*/
            u32PinPositionLoc = u8PinNameCpy % PINS_PREV_TO_GPIOB; 
			
/*	Assigning a pointer to the GPIOB register.								*/
			pGPIOTypePortNameLoc = (volatile GPIOType *) GPIOB;
		}
		
        else{
/*	If it is in PORTC we calculate the location of the pin relative to the 	*/
/*	port because in stm32f103 (blue pill) there is only 3 pins in portc 	*/
/* 	which are PIN13, PIN14, PIN15.											*/
            u32PinPositionLoc = 
					 (u8PinNameCpy % PINS_PREV_TO_GPIOC) + GPIOC_PINS_OFFSET;
					 
/*	Assigning a pointer to the GPIOC register.								*/
			pGPIOTypePortNameLoc = (volatile GPIOType *) GPIOC;
        }
		
/*  Check the value that is needed to be assigned to the PIN.           	*/
		if(u8PinValueCpy == GPIO_HIGH ){
/*	we dereference the Pointer that assigned to the GPIO selected. And we 	*/
/*	use the BSRR Register for atomic Operations.							*/
			pGPIOTypePortNameLoc->BSRR = 
					FIRST_BIT_LOCATION <<u32PinPositionLoc;
		}
		else{
/* 	For LOW values we use  BRR register. */
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
    volatile GPIOType * pGPIOTypePortNameLoc = (volatile GPIOType *) GPIOA;

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
/*  Check if the name (u8PinNameCpy) of the pin is in PORTA.				*/
        if(u8PinNameCpy <= GPIOA_END){
/*	Get the Location of the starting Bits in the 32-Bit register.			*/
            u32PinPositionLoc = 
					(u32)(u8PinNameCpy * NUMBER_OF_CNF_BITS);
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTB.				*/
        else if(u8PinNameCpy <= GPIOB_END ){
/*	Get the Location of the starting Bits in the 32-Bit register.			*/
            u32PinPositionLoc = 
				(u32)(u8PinNameCpy % PINS_PREV_TO_GPIOB) * NUMBER_OF_CNF_BITS;
/*	Select GPIO port B														*/
			pGPIOTypePortNameLoc = GPIOB;
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTC.				*/
        else{
/*	Get the Location of the starting Bits in the 32-Bit register.			*/
			u32PinPositionLoc = (u32)((u8PinNameCpy % PINS_PREV_TO_GPIOC) + 
									GPIOC_PINS_OFFSET) * NUMBER_OF_CNF_BITS;
/*	Select GPIO port C														*/
			pGPIOTypePortNameLoc = GPIOC;
		}
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
/*	Setting the necesseray bits to one in the lower config register.		*/
			pGPIOTypePortNameLoc->CRL |= 
						(u8GPIOModeLoc << u32PinPositionLoc);
/*	Get the zeros in the 4 bit configration bits.							*/
			u8GPIOModeLoc = (~u8GPIOModeLoc) & FIRST_FOUR_BIT_MASK;
/*	Setting the necesseray bits to zeros in the lower config register.		*/
			pGPIOTypePortNameLoc->CRL &= 
						~(u8GPIOModeLoc << u32PinPositionLoc);
		}
		else{
			u32PinPositionLoc =
						u32PinPositionLoc %  NUMBER_OF_BITS_IN_REGISTER;
/*	Setting the necesseray bits to one in the lower config register.		*/
			pGPIOTypePortNameLoc->CRH |= 
						(u8GPIOModeLoc << u32PinPositionLoc);		
/*	Get the zeros in the 4 bit configration bits.							*/
			u8GPIOModeLoc = (~u8GPIOModeLoc) & FIRST_FOUR_BIT_MASK;
/*	Setting the necesseray bits to zeros in the lower config register.		*/
			pGPIOTypePortNameLoc->CRL &= 
						~(u8GPIOModeLoc << u32PinPositionLoc);
		}
    }
    return enuErrorStatusLoc; 
}

GPIO_ErrorStatusType GPIO_enuTogglePin(u8 const u8PinNameCpy){
/*	enuErrorStatusLoc is the error status of the function if any error		*/ 
/*	happens in the function.												*/ 
    GPIO_ErrorStatusType enuErrorStatusLoc = GPIO_NO_ERRORS;

/*	u32PinPositionLoc is used to determine which bit in the 32 bit regieter */
/* 	we are going to change.													*/
    u32 u32PinPositionLoc = FIRST_BIT_LOCATION;
    
/*  check the name is the range of available pins in the TM4C123GH6PM Microcontroller           */    
    if(u8PinNameCpy > GPIO_MAX_NUM_PINS){
/* if it is not in the range we assign the Error status enum fuction to the undefined name.     */
        enuErrorStatusLoc = GPIO_UNDEFINED_NAME;
    }
/*  check if the name (u8PinNameCpy) of the pin is in PORTA.                                    */    
    else{
        if(u8PinNameCpy <= GPIO_PORTA_MAX ){ 
/*  if it is in range of PORTA, we calculate the position of the pin map register.              */
            u8PinPositionLoc = u8PinPositionLoc << u8PinNameCpy;      
/*  Toggle the Value in this register which toggles the pin value.                              */
                GPIOA->DATA[u8PinPositionLoc] ^= TOGGLE;
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTB.                                    */    
        else if(u8PinNameCpy <= GPIO_PORTB_MAX ){
/*  if it is in range of PORTB, we calculate the position of the pin map register.              */
            u8PinPositionLoc = u8PinNameCpy % GPIO_MAX_NUM_PINS_IN_PORT; 
            u8PinPositionLoc = GPIO_FIRST_PIN << u8PinPositionLoc; 
/*  Toggle the Value in this register which toggles the pin value.                              */
                GPIOB->DATA[u8PinPositionLoc] ^= TOGGLE;
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTC.                                    */    
        else if(u8PinNameCpy <= GPIO_PORTC_MAX ){
/*  if it is in range of PORTC, we calculate the position of the pin map register.              */
            u8PinPositionLoc = u8PinNameCpy % GPIO_MAX_NUM_PINS_IN_PORT;
            u8PinPositionLoc = GPIO_FIRST_PIN << u8PinPositionLoc; 
/*  Toggle the Value in this register which toggles the pin value.                              */
                GPIOC->DATA[u8PinPositionLoc] ^= TOGGLE;
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTD.                                    */    
        else if(u8PinNameCpy <= GPIO_PORTD_MAX ){
/*  if it is in range of PORTD, we calculate the position of the pin map register.              */
            u8PinPositionLoc = u8PinNameCpy % GPIO_MAX_NUM_PINS_IN_PORT; 
            u8PinPositionLoc = GPIO_FIRST_PIN << u8PinPositionLoc; 
/*  Toggle the Value in this register which toggles the pin value.                              */
                GPIOD->DATA[u8PinPositionLoc] ^= TOGGLE;
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTE.                                    */    
        else if(u8PinNameCpy <= GPIO_PORTE_MAX ){
/*  if it is in range of PORTE, we calculate the position of the pin map register.              */
            u8PinPositionLoc = u8PinNameCpy % GPIO_MAX_NUM_PINS_IN_PORT;
            u8PinPositionLoc = GPIO_FIRST_PIN << u8PinPositionLoc; 
/*  Toggle the Value in this register which toggles the pin value.                              */
                GPIOE->DATA[u8PinPositionLoc] ^= TOGGLE;
        }
/*  check if the name (u8PinNameCpy) of the pin is in PORTF.                                    */    
        else{
/*  if it is in range of PORTF, we calculate the position of the pin map register.              */
            u8PinPositionLoc = u8PinNameCpy - GPIOF_START_PIN; 
            u8PinPositionLoc = GPIO_FIRST_PIN << u8PinPositionLoc; 
/*  Toggle the Value in this register which toggles the pin value.                              */
                GPIOF->DATA[u8PinPositionLoc] = HIGH;
        }
    }
    return enuErrorStatusLoc; 
}
    
/****************************************************************************/
/*							Static FUNCTIONS								*/
/****************************************************************************/

