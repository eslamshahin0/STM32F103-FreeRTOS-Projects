/*********************************************************/
/* File  : RCC_private.h								 */ 
/* Author: Eslam Shahin									 */
/* Email : eslamshahin552000@gmail.com					 */
/*														 */
/* Version : 1.0										 */
/* For ARM Based MUCs 									 */
/* Created on 8 Aug 2020, 19:50							 */	
/*********************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/************ Register Definitions **********************/
#define RCC_BASE_ADRESS  0x40021000
/* The RCC_CR , RCC_CFGR , RCC_AHBENR , RCC_APB2ENR and RCC_APB1ENR Registers 
   are responsable for the prephrals clock */
   
#define RCC_CR 			 *((volatile u32*)(RCC_BASE_ADRESS + 0X00))  //1
#define RCC_CFGR         *((volatile u32*)(RCC_BASE_ADRESS + 0x04))  //2
#define RCC_CIR			 *((volatile u32*)(RCC_BASE_ADRESS + 0x08)) 
#define RCC_APB2RSTR 	 *((volatile u32*)(RCC_BASE_ADRESS + 0x0C))
#define RCC_APB1RSTR	 *((volatile u32*)(RCC_BASE_ADRESS + 0x10))
#define RCC_AHBENR		 *((volatile u32*)(RCC_BASE_ADRESS + 0x14)) //3
#define RCC_APB2ENR		 *((volatile u32*)(RCC_BASE_ADRESS + 0x18)) //4
#define RCC_APB1ENR		 *((volatile u32*)(RCC_BASE_ADRESS + 0x1C)) //5
#define RCC_BDCR 		 *((volatile u32*)(RCC_BASE_ADRESS + 0x20))
#define RCC_CSR		 	 *((volatile u32*)(RCC_BASE_ADRESS + 0x24))

/*************** Clock Types *****************************/
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

/****************** PLL Options **************************/
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2


#endif