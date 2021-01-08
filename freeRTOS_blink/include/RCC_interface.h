/*********************************************************/
/* File  : RCC_interface.h								 */ 
/* Author: Eslam Shahin									 */
/* Email : eslamshahin552000@gmail.com					 */
/*														 */
/* Version : 1											 */
/* For ARM Based MUCs									 */
/* Created on 8 Aug 2020, 19:50							 */	
/*********************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2
/***************** Buses Speed ***************************/
#define AHB 	0
#define APB1	1
#define APB2	2

#define SYSCLK_NOT_DIV 	 	 0b0000
#define SYSCLK_DIV_2	 	 0b1000
#define SYSCLK_DIV_4		 0b1001
#define SYSCLK_DIV_8 		 0b1010
#define SYSCLK_DIV_16 		 0b1011
#define SYSCLK_DIV_64 		 0b1100
#define SYSCLK_DIV_128 		 0b1101
#define SYSCLK_DIV_256 		 0b1110
#define SYSCLK_DIV_512		 0b1111

#define AHP_CLOCK_NOT_DIV	 0b000
#define AHP_CLOCK_DIV_2		 0b100
#define AHP_CLOCK_DIV_4		 0b101
#define AHP_CLOCK_DIV_8		 0b110
#define AHP_CLOCK_DIV_16	 0b111


/**************** RCC_AHBENR ***************************/
#define DMA1    0
#define DMA2    1
#define SRAM    2
#define FLITF   4
#define CRCE    6
#define FSMC    8
#define SDIO    10

/******************* RCC_APB2ENR *************************/
#define AFIOEN		0
#define IOPAEN 		2
#define IOPBEN 		3
#define IOPCEN 		4
#define IOPDEN 		5
#define IOPEEN 		6
#define IOPFEN 		7
#define IOPGEN 		8
#define ADC1EN 		9
#define ADC2EN 		10
#define TIM1EN 		11
#define SPI1EN 		12
#define TIM8EN 		13 
#define USART1EN	14 
#define ADC3EN 		15
#define TIM9EN      19
#define TIM10EN		20
#define TIM11EN		21

/******************* RCC_APB1ENR *************************/
#define TIM2EN		0
#define TIM3EN		1
#define TIM4EN		2
#define TIM5EN		3
#define TIM6EN		4
#define TIM7EN		5
#define TIM12EN		6		
#define TIM13EN		7
#define TIM14EN		8
#define WWDGEN		11
#define SPI2EN		14
#define SPI3EN		15
#define USART2EN	17
#define USART3EN	18
#define UART4EN		19
#define UART5EN		20
#define I2C1EN		21
#define I2C2EN		22
#define USBEN 		23
#define CANEN		25
#define BKPEN		27
#define PWREN		28
#define DACEN		29

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
/* Options : AHP,APB1,APB2 for frist argument 

*** Argument 2 if it AHB
		SYSCLK_NOT_DIV 	 	
		SYSCLK_DIV_2	 	
		SYSCLK_DIV_4		
		SYSCLK_DIV_8 		
		SYSCLK_DIV_16 	
		SYSCLK_DIV_64 	
		SYSCLK_DIV_128 		
		SYSCLK_DIV_256 		
		SYSCLK_DIV_512	
*** Argument 2 if it APB1 or APB2 (It take its clock from AHP)
		AHP_CLOCK_NOT_DIV	 	
		AHP_CLOCK_DIV_2			
		AHP_CLOCK_DIV_4		 		
		AHP_CLOCK_DIV_8			
		AHP_CLOCK_DIV_16
*/
void RCC_voidSetBusClock(u8 copy_u8busid, u8 copy_busSpeedDivFactor);
#endif