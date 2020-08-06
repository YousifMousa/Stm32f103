/****************************************************************************/
/*	Author      :                                                          	*/
/*                   Yousif Latif Zaki Mousa                               	*/
/*                                                                         	*/
/*	Date        :                                                          	*/
/*                   Aug, 1st 2020											*/
/*                                                                         	*/
/*	E-mail      :                                                          	*/
/*                   Yousif.Mousa97@gmail.com                              	*/
/*                                                                         	*/
/*	File name   :                                                          	*/
/*                   GPIO_priv.h                                           	*/
/*                       													*/
/*	Github		:                                                          	*/
/*					https://github.com/YousifMousa/							*/
/*                                                                         	*/
/*	Description	:                                                          	*/
/*             		    This file contains all the private parameters that	*/
/*             		used by the GPIO implementation file (GPIO_prg.c) for	*/
/*             		STM32f103c8t6 Microcontroller.							*/
/*							                                               	*/
/*	Version     :                                                          	*/
/*                   V1.0                                                  	*/
/*                                                                         	*/
/****************************************************************************/

#ifndef _GPIO_PRIV_H_
#define _GPIO_PRIV_H_


/*	All registers defined in a Structure with GPIOType. These Registers */
/*	are ordered according to its location in memory.					*/
typedef struct{                            
    u32 CRL;					/* Port configuration register low		*/
    u32 CRH;					/* Port configuration register high		*/
    u32 IDR;					/* Port input data register 			*/    
    u32 ODR;  					/* Port output data register			*/    
    u32 BSRR;					/* Port bit set/reset register			*/    
    u32 BRR; 					/* Port bit reset register				*/    
    u32 LCKR;					/* Port configuration lock register		*/    
}GPIOType;

typedef GPIOType *	pGPIOType;
#define GPIOA_BASE              	((u32) 0x40010800)
#define GPIOB_BASE              	((u32) 0x40010C00)
#define GPIOC_BASE              	((u32) 0x40011000)

#define GPIOA                       ((volatile pGPIOType const ) GPIOA_BASE)
#define GPIOB                       ((volatile pGPIOType const ) GPIOB_BASE)
#define GPIOC                       ((volatile pGPIOType const ) GPIOC_BASE)


#define GPIO_START_PIN                 	GPIO_PIN_NUM_00
#define GPIO_END_PIN                 	GPIO_PIN_NUM_31

#define GPIOA_START						GPIO_PIN_NUM_00
#define GPIOA_END						GPIO_PIN_NUM_12

#define PINS_PREV_TO_GPIOB				((u8) 0x0D)	
#define GPIOB_START						GPIO_PIN_NUM_13
#define GPIOB_END						GPIO_PIN_NUM_28

#define PINS_PREV_TO_GPIOC				((u8) 0x1D)
#define GPIOC_PINS_OFFSET				((u8) 0x0D)
#define GPIOC_START						GPIO_PIN_NUM_29
#define GPIOC_END						GPIO_PIN_NUM_31

#define GPO_PUSHPULL_CNF_MODE			((u8) 0x01)
#define GPO_OPEN_DRAIN_CNF_MODE			((u8) 0x05)
#define AFO_PUSHPULL_CNF_MODE			((u8) 0x09)
#define AFO_OPEN_DRAIN_CNF_MODE			((u8) 0x0D)
#define INPUT_ANALOG_CNF_MODE			((u8) 0x00)
#define INPUT_FLOATING_CNF_MODE			((u8) 0x04)
#define INPUT_PULLDOWN_PULLUP_CNF_MODE	((u8) 0x08)

#define FIRST_FOUR_BIT_MASK				((u8) 0x0f)

#define LOWER_CONFIG_REG			((u8) 0x20)

#define NUMBER_OF_BITS_IN_REGISTER		((u8) 0x20)
#define NUMBER_OF_CNF_BITS				((u8) 0x04)
#define	FIRST_BIT_LOCATION				((u8) 0x01)



static void GPIO_vidPinLocation(u8 u8PinNameCpy,  
								volatile pGPIOType * ppGPIOTypePortNameCpy,
								u32 * pu32PinPositionCpy);
#endif 

		