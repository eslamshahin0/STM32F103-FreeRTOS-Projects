/*********************************************************/
/* File  : RCC_program.h								 */
/* Author: Eslam Shahin									 */
/* Email : eslamshahin552000@gmail.com					 */
/*														 */
/* Version : 1.0										 */
/* For ARM Based MUCs									 */
/* Created on 8 Aug 2020, 19:50							 */
/*********************************************************/

#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;

	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /* Enable HSE with bypass */
		RCC_CFGR = 0x00000001;

	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC_CFGR = 0x00000000;

	#elif   RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CR=0x01000081;
			RCC_CFGR=0x00000002;
			RCC_CFGR &=0xffc3ffff;//Clear the 4 bits of PLLMUL
			RCC_CFGR|=((RCC_PLL_MUL_VAL-2)<<18);
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		/* on External Crystal OSC*/
			RCC_CR=0x01010080;
			RCC_CFGR=0x00030002;
			RCC_CFGR &=0xffc3ffff;//Clear the 4 bits of PLLMUL
			RCC_CFGR|=((RCC_PLL_MUL_VAL-2)<<18);
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC_CR=0x01010080;
			RCC_CFGR=0x00010002;
			RCC_CFGR &=0xffc3ffff;//Clear the 4 bits of PLLMUL
			RCC_CFGR|=((RCC_PLL_MUL_VAL-2)<<18);
		#endif

	#else

	#endif
}



void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}

	else
	{
		/* Return Error */

	}

}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLEAR_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : CLEAR_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : CLEAR_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}

	else
	{
		/* Return Error */

	}

}


void RCC_voidSetBusClock(u8 copy_u8busid, u8 copy_busSpeedDivFactor){
	if (copy_u8busid<=2){
		switch(copy_u8busid){
			case AHB :
			RCC_CFGR &=0xffffff0f;/*Set and cleared by software to control the division factor of the AHB clock*/
			RCC_CFGR|=(copy_busSpeedDivFactor<<4);
			break;
			
			case APB1 :
			RCC_CFGR &=0xfffff8ff;/* the software has to set correctly these bits to not exceed 36 MHz on this domain.*/
			RCC_CFGR|=(copy_busSpeedDivFactor<<8);
			break;
			
			case APB2 :
			RCC_CFGR &=0xffc7ff0f;/*Set and cleared by software to control the division factor of the APB high-speed clock*/
			RCC_CFGR|=(copy_busSpeedDivFactor<<11);
			break;			
			
		}
			
	}
	else
	{
		/* Return Error */

	}
	
}
