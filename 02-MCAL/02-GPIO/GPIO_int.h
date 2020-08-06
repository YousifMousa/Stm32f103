/********************************************************************************/
/*	Author      :                                                          		*/
/*                   Yousif Latif Zaki Mousa                               		*/
/*                                                                         		*/
/*	Date        :                                                          		*/
/*                   Aug, 1st 2020												*/
/*                                                                         		*/
/*	E-mail      :                                                          		*/
/*                   Yousif.Mousa97@gmail.com                              		*/
/*                                                                         		*/
/*	File name   :                                                          		*/
/*                   GPIO_int.h                                           		*/
/*                       														*/
/*	Github		:                                                          		*/
/*					https://github.com/YousifMousa/								*/
/*                                                                         		*/
/*	Description	:                                                          		*/
/*             		This file contains interface parameters that the user		*/
/*					can use in the application  of the GPIO peripheral in		*/
/*             		the STM32f103c8t6.											*/
/*             																	*/
/*	Version     :                                                          		*/
/*                   V1.0                                                  		*/
/*                                                                         		*/
/********************************************************************************/
 
#ifndef _GPIO_INT_H_
#define _GPIO_INT_H_

/********************************************************************************/
/*							PARAMETER DEFINITIONS	          					*/
/********************************************************************************/

/*	The LOW and HIGH Values that is used in digital input or digital output		*/
/*	functions.																	*/
#define GPIO_LOW                ((u8) 0x00)
#define GPIO_HIGH               ((u8) 0xFF)

/*	The maximum speed of each pin that can be configured to operate on.			*/
#define	GPIO_MAX_SPEED_02MHZ	((u8) 0x01)
#define	GPIO_MAX_SPEED_10MHZ	((u8) 0x02)
#define	GPIO_MAX_SPEED_20MHZ	((u8) 0x04)

/* 	For the general purpose output modes (Push-pull or Open Drain).				*/
#define	GPIO_GPO_PUSHPULL		((u8) 0x01)		
#define	GPIO_GPO_OPEN_DRAIN		((u8) 0x02)

/*	For the Alternate Function Output (Push-pull or Open Drain).				*/
#define	GPIO_AFO_PUSHPULL		((u8) 0x04)		
#define	GPIO_AFO_OPEN_DRAIN		((u8) 0x08)	

/*	For Input Modes (Analog, Input floating, Input pull-down, Input pull-up).	*/
#define GPIO_INPUT_ANALOG		((u8) 0x10)		
#define GPIO_INPUT_FLOATING		((u8) 0x20)		
#define GPIO_INPUT_PULLDOWN		((u8) 0x40)		
#define GPIO_INPUT_PULLUP		((u8) 0x80)		


/*	This order of pins is ordered individually from 0 to 31.					*/
/*                    		PORTA												*/
#define GPIO_PIN_NUM_00         ((u8) 0x00)	
#define GPIO_PIN_NUM_01         ((u8) 0x01)	
#define GPIO_PIN_NUM_02         ((u8) 0x02)	
#define GPIO_PIN_NUM_03         ((u8) 0x03)	
#define GPIO_PIN_NUM_04         ((u8) 0x04)	
#define GPIO_PIN_NUM_05         ((u8) 0x05)	
#define GPIO_PIN_NUM_06         ((u8) 0x06)	
#define GPIO_PIN_NUM_07         ((u8) 0x07)	
#define GPIO_PIN_NUM_08         ((u8) 0x08)	
#define GPIO_PIN_NUM_09         ((u8) 0x09)	
#define GPIO_PIN_NUM_10         ((u8) 0x0A)	
#define GPIO_PIN_NUM_11         ((u8) 0x0B)	
#define GPIO_PIN_NUM_12         ((u8) 0x0C)	
	
/*                  		PORTB                                       		*/
#define GPIO_PIN_NUM_13         ((u8) 0x0D)	
#define GPIO_PIN_NUM_14         ((u8) 0x0E)	
#define GPIO_PIN_NUM_15         ((u8) 0x0F)	
#define GPIO_PIN_NUM_16         ((u8) 0x10)	
#define GPIO_PIN_NUM_17         ((u8) 0x11)	
#define GPIO_PIN_NUM_18         ((u8) 0x12)	
#define GPIO_PIN_NUM_19         ((u8) 0x13)	
#define GPIO_PIN_NUM_20         ((u8) 0x14)	
#define GPIO_PIN_NUM_21         ((u8) 0x15)	
#define GPIO_PIN_NUM_22         ((u8) 0x16)	
#define GPIO_PIN_NUM_23         ((u8) 0x17)
#define GPIO_PIN_NUM_24         ((u8) 0x18)	
#define GPIO_PIN_NUM_25         ((u8) 0x19)	
#define GPIO_PIN_NUM_26         ((u8) 0x1A)	
#define GPIO_PIN_NUM_27         ((u8) 0x1B)	
#define GPIO_PIN_NUM_28         ((u8) 0x1C)	
	
/*                        	PORTC												*/
#define GPIO_PIN_NUM_29         ((u8) 0x1D)	
#define GPIO_PIN_NUM_30         ((u8) 0x1E)	
#define GPIO_PIN_NUM_31         ((u8) 0x1F)	


/*	This order of pins is ordered individually from port A to port C.			*/
/*                     		PORTA												*/
#define GPIOA_PIN_00			GPIO_PIN_NUM_00      	
#define GPIOA_PIN_01			GPIO_PIN_NUM_01
#define GPIOA_PIN_02			GPIO_PIN_NUM_02
#define GPIOA_PIN_03			GPIO_PIN_NUM_03
#define GPIOA_PIN_04			GPIO_PIN_NUM_04
#define GPIOA_PIN_05			GPIO_PIN_NUM_05
#define GPIOA_PIN_06			GPIO_PIN_NUM_06
#define GPIOA_PIN_07			GPIO_PIN_NUM_07
#define GPIOA_PIN_08			GPIO_PIN_NUM_08                  	
#define GPIOA_PIN_09			GPIO_PIN_NUM_09	
#define GPIOA_PIN_10			GPIO_PIN_NUM_10	
#define GPIOA_PIN_11			GPIO_PIN_NUM_11	
#define GPIOA_PIN_12			GPIO_PIN_NUM_12	

/*                     		PORTB												*/
#define GPIOB_PIN_00			GPIO_PIN_NUM_13	
#define GPIOB_PIN_01			GPIO_PIN_NUM_14	
#define GPIOB_PIN_02			GPIO_PIN_NUM_15	
#define GPIOB_PIN_03			GPIO_PIN_NUM_16	
#define GPIOB_PIN_04			GPIO_PIN_NUM_17	
#define GPIOB_PIN_05			GPIO_PIN_NUM_18	
#define GPIOB_PIN_06			GPIO_PIN_NUM_19	
#define GPIOB_PIN_07			GPIO_PIN_NUM_20	
#define GPIOB_PIN_08			GPIO_PIN_NUM_21	
#define GPIOB_PIN_09			GPIO_PIN_NUM_22	
#define GPIOB_PIN_10			GPIO_PIN_NUM_23	
#define GPIOB_PIN_11			GPIO_PIN_NUM_24	
#define GPIOB_PIN_12			GPIO_PIN_NUM_25	
#define GPIOB_PIN_13			GPIO_PIN_NUM_26	
#define GPIOB_PIN_14			GPIO_PIN_NUM_27	
#define GPIOB_PIN_15			GPIO_PIN_NUM_28	
                                             
/*                    		PORTC			 									*/
#define GPIOC_PIN_13			GPIO_PIN_NUM_29	
#define GPIOC_PIN_14			GPIO_PIN_NUM_30
#define GPIOC_PIN_15			GPIO_PIN_NUM_31


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
    GPIO_NO_ERRORS_FOUND	= 0X00000000,
    GPIO_UNDEFINED_NAME 	= 0X00000001,
    GPIO_UNDEFINED_VALUE 	= 0X00000002,
    GPIO_PIN_IS_INPUT   	= 0x00000004,
    GPIO_CLK_NOTCONNECTED	= 0x00000008,
	GPIO_UNDEFINED_MODE		= 0X00000010
}GPIO_ErrorStatusType;



/********************************************************************************/
/*							Function Prototypes									*/
/********************************************************************************/


/********************************************************************************/
/*																				*/
/*   Function    :                                                              */
/*                   GPIO_vidInit                                               */
/*                                                                              */
/*   Description:                                                               */
/*                  this function is used to initlizing the GPIO peripheral     */
/*               according to the configration file parameters (GPIO_cfg.h).    */
/*                                                                              */
/*   Input       :                                                              */
/*                   NONE                                                       */
/*                                                                              */
/*   OUTPUT      :                                                              */
/*                   NONE                                                       */
/*                                                                              */
/*   Example     :                                                              */
/*                   GPIO_vidInit();                                            */
/*                                                                              */
/********************************************************************************/
void GPIO_vidInit(void);



/********************************************************************************/
/*																				*/
/*   Function    :                                                              */
/*                   GPIO_enuSetPinValue                                        */
/*                                                                              */
/*   Description:                                                               */
/*                   This function is used to set a pin to either HIGH or       */
/*               LOW according to the u8PinValueCpy which can be GPIO_LOW       */
/*               or GPIO_HIGH also it must pass the name of the pin which       */
/*               is defined earlier in this file (GPIO_int.h).                  */
/*                                                                              */
/*   Input       :                                                              */
/*                   - u8PinNameCpy : Name of the pin defined earlier in the	*/
/*					GPIO_int.h file.											*/
/*																				*/
/*                   - u8PinValueCpy: Value that the pin take which can be      */
/*               GPIO_HIGH or GPIO_LOW.                                         */
/*                                                                              */
/*   OUTPUT      :                                                              */
/*                   - enuErrorStatusLoc : an error status of the function that */
/*               reports any errors happened in the function.                   */
/*																				*/
/*   Example     :                                                              */
/*                   - GPIO_enuSetPinValue(GPIOA_PIN_00, GPIO_HIGH);			*/
/*                                                                              */
/********************************************************************************/
GPIO_ErrorStatusType GPIO_enuSetPinValue(u8 const u8PinNameCpy, u8 const u8PinValueCpy);



/********************************************************************************/
/*																				*/
/*   Function    :                                                              */
/*                   GPIO_enuTogglePin                                          */
/*                                                                              */
/*   Description:                                                               */
/*                   This function is used to Toggle a pin from high to low or 	*/
/*               or from low to high depending on its previous state.			*/
/*                                                                              */
/*   Input       :                                                              */
/*                   - u8PinNameCpy  : Name of the pin defined earlier in this  */
/*               file.                                                          */
/*                                                                              */
/*   OUTPUT      :                                                              */
/*                   enuErrorStatusLoc : an error status of the function that   */
/*               reports any errors happened in the function.                   */
/*                                                                              */
/*   Example     :                                                              */
/*                   - GPIO_enuTogglePin(GPIOA_PIN_00);							*/
/*                                                                              */
/********************************************************************************/
GPIO_ErrorStatusType GPIO_enuTogglePin(u8 const u8PinNameCpy);


/********************************************************************************/
/*																				*/
/*   Function    :                                                              */
/*                   GPIO_enuSetPinValue                                        */
/*                                                                              */
/*   Description:                                                               */
/*                   This function is used to set a pin Direction to either     */
/*               INPUT or OUTPUT according to the u8PinDirCpy which can be      */
/*               GPIO_INPUT or GPIO_OUTPUT also it must pass the name of the    */
/*               pin which is defined earlier in this file (GPIO_int.h).        */
/*                                                                              */
/*   Input       :                                                              */
/*                   - u8PinNameCpy : Name of the pin which defined earlier     */
/*               in this file.                                                  */
/*                   - u8PinDirCpy: Direction that the pin take which can be    */
/*               GPIO_INPUT or GPIO_OUTPUT.                                     */
/*                                                                              */
/*   OUTPUT      :                                                              */
/*                   - enuErrorStatusLoc : an error status of the function that */
/*               reports any errors happened in the function.                   */
/*   Example     :                                                              */
/*               	- GPIO_enuSetPinDir(GPIOF_PIN_00, GPIO_INPUT);				*/
/*                                                                              */
/********************************************************************************/
GPIO_ErrorStatusType GPIO_enuSetPinDir(u8 const u8PinNameCpy, u8 const u8PinDirCpy );



/********************************************************************************/
/*                                                                              */
/*   Function    :																*/
/*                   GPIO_enuSetMode											*/
/*                                                                              */
/*   Description:                                                               */
/*              	This function is used to set the functionality of the pin  	*/
/*				to either to input, output or alternate Function  according to 	*/
/*				the u8ModeCpy which can be many options :  						*/
/*					- GPIO_GPO_PUSHPULL											*/
/*					- GPIO_GPO_OPEN_DRAIN                                       */
/*					- GPIO_AFO_PUSHPULL	                                        */
/*					- GPIO_AFO_OPEN_DRAIN										*/
/*					- GPIO_INPUT_ANALOG											*/
/*	                - GPIO_INPUT_FLOATING										*/
/*					- GPIO_INPUT_PULLDOWN										*/
/*					- GPIO_INPUT_PULLUP											*/
/*				which are defined earlier in this file (GPIO_int.h).			*/
/*                                                                              */
/*   Input       :                                                              */
/*                   - u8PinNameCpy : Name of the pin which defined earlier     */
/*               	in this file.												*/
/*                   - u8ModeCpy 	: The mode of the Pin.						*/
/*                                                                              */
/*   OUTPUT      :                                                              */
/*                   - enuErrorStatusLoc : an error status of the function that */
/*               	reports any errors happened in the function.				*/
/*                                                                              */
/*   Example     :                                                              */
/*              	- GPIO_enuSetMode(GPIOA_PIN_01, GPIO_INPUT_ANALOG);			*/
/*																				*/
/********************************************************************************/
GPIO_ErrorStatusType GPIO_enuSetMode(u8 const u8PinNameCpy, u8 const u8ModeCpy );




#endif

