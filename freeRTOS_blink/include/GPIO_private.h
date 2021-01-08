/*********************************************************/
/* File  : GPIO_private.h								 */
/* Author: Eslam Shahin									 */
/* Email : eslamshahin552000@gmail.com					 */
/*														 */
/* Version : 1.0										 */
/* For ARM Based MUCs									 */
/* Created on 3 Sep 2020								 */
/*********************************************************/

#ifndef _GPIO_PRIVATE_
#define _GPIO_PRIVATE_

#define GPIOA_Base_Address        0x40010800  
#define GPIOB_Base_Address        0x40010C00   
#define GPIOC_Base_Address        0x40011000      

/***************** REGISTERS ADDRESSES FOR Port A *******************/

#define GPIOA_CRL                 *((volatile u32*)(GPIOA_Base_Address + 0x00))
#define GPIOA_CRH                 *((volatile u32*)(GPIOA_Base_Address + 0x04))
#define GPIOA_IDR                 *((volatile u32*)(GPIOA_Base_Address + 0x08))
#define GPIOA_ODR                 *((volatile u32*)(GPIOA_Base_Address + 0x0c))
#define GPIOA_BSRR                *((volatile u32*)(GPIOA_Base_Address + 0x10))
#define GPIOA_BRR                 *((volatile u32*)(GPIOA_Base_Address + 0x14))
#define GPIOA_LCKR                *((volatile u32*)(GPIOA_Base_Address + 0x18))

/***************** REGISTERS ADDRESSES FOR Port B *******************/

#define GPIOB_CRL                 *((volatile u32*)(GPIOB_Base_Address + 0x00))
#define GPIOB_CRH                 *((volatile u32*)(GPIOB_Base_Address + 0x04))
#define GPIOB_IDR                 *((volatile u32*)(GPIOB_Base_Address + 0x08))
#define GPIOB_ODR                 *((volatile u32*)(GPIOB_Base_Address + 0x0c))
#define GPIOB_BSRR                *((volatile u32*)(GPIOB_Base_Address + 0x10))
#define GPIOB_BRR                 *((volatile u32*)(GPIOB_Base_Address + 0x14))
#define GPIOB_LCKR                *((volatile u32*)(GPIOB_Base_Address + 0x18))

/***************** REGISTERS ADDRESSES FOR Port C *******************/

#define GPIOC_CRL                 *((volatile u32*)(GPIOC_Base_Address + 0x00))
#define GPIOC_CRH                 *((volatile u32*)(GPIOC_Base_Address + 0x04))
#define GPIOC_IDR                 *((volatile u32*)(GPIOC_Base_Address + 0x08))
#define GPIOC_ODR                 *((volatile u32*)(GPIOC_Base_Address + 0x0c))
#define GPIOC_BSRR                *((volatile u32*)(GPIOC_Base_Address + 0x10))
#define GPIOC_BRR                 *((volatile u32*)(GPIOC_Base_Address + 0x14))
#define GPIOC_LCKR                *((volatile u32*)(GPIOC_Base_Address + 0x18))



#endif