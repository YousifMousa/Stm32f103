/****************************************************************************/
/*	Author		:															*/
/*					Yousif Latif Zaki Mousa									*/
/*																			*/
/*	Date		:															*/
/*					Aug, 3rd 2020											*/
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
/*						This file contains all the private parameters that	*/
/*					used by the RCC implementation file (RCC_prg.c) for the	*/
/*					STM32f103c8t6 Microcontroller.							*/
/*																			*/
/*	Version		:															*/
/*					V1.0													*/
/*																			*/
/****************************************************************************/

#ifndef _RCC_PRIV_H_
#define _RCC_PRIV_H_


/*	All registers defined in a Structure with RCCType. These Registers	*/
/*	are ordered according to its location in memory.					*/
typedef struct RCCType {
	u32 CR;					/*	Clock control register					*/
	u32 CFGR;				/*	Clock configuration register			*/
	u32 CIR;				/*	Clock interrupt register				*/
	u32 APB2RSTR;			/*	APB2 peripheral reset registe			*/
	u32 APB1RSTR;			/*	APB1 peripheral reset register          */
	u32 AHBENR;				/*	AHB peripheral clock enable register    */
	u32 APB2ENR;			/*	APB2 peripheral clock enable register   */
	u32 APB1ENR;			/*	APB1 peripheral clock enable register   */
	u32 BDCR;				/*	Backup domain control register          */
	u32 CSR;				/*	Control/status register                 */
}RCCType;

#define RCC_BASE			(0x40021000)
#define RCC					((volatile RCCType* const)RCC_BASE)

#define RCC_GPIOA_ENABLE  	((u32) 0x00000002)
#define RCC_GPIOB_ENABLE	((u32) 0x00000004)
#define RCC_GPIOC_ENABLE	((u32) 0x00000008)


#define ENABLE 				((u8) 0xff)
#endif 
		