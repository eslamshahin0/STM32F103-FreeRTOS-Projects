/*********************************************************/
/* File  : GPIO_interface.h								 */
/* Author: Eslam Shahin									 */
/* Email : eslamshahin552000@gmail.com					 */
/*														 */
/* Version : 1.0										 */
/* For ARM Based MUCs									 */
/* Created on 3 Sep 2020								 */
/*********************************************************/
#ifndef _GPIO_INTERFACE_
#define _GPIO_INTERFACE_


/************************ Pins and Ports number *****************************/
#define HIGH     1
#define LOW      0

#define GPIOA    0
#define GPIOB    1
#define GPIOC    2

#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
#define PIN8     8
#define PIN9     9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15

/************** Input modes ********************/
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

/*************** Speed 10MHZ ******************/
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

/*************** Speed 2MHZ ******************/
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

/************** Speed 2 *********************/
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

/* Options for copy_u8Port :
	GPIOA , GPIOB and GPIOC */
	
/*Options for copy_u8Pin : PIN0 : PIN15 */

/*Options for Copy_u8Mode :  
	INPUT_ANLOG   
	INPUT_FLOATING  
	INPUT_PULLUP_PULLDOWN     

	OUTPUT_SPEED_10MHZ_PP     
	OUTPUT_SPEED_10MHZ_OD    
	OUTPUT_SPEED_10MHZ_AFPP   
	OUTPUT_SPEED_10MHZ_AFOD  
	
	OUTPUT_SPEED_2MHZ_PP    
	OUTPUT_SPEED_2MHZ_OD     
	OUTPUT_SPEED_2MHZ_AFPP   
	OUTPUT_SPEED_2MHZ_AFOD   

	OUTPUT_SPEED_50MHZ_PP     
	OUTPUT_SPEED_50MHZ_OD     
	OUTPUT_SPEED_50MHZ_AFPP   
	OUTPUT_SPEED_50MHZ_AFOD */  

/*Options for copy_u8Value : LOW ,HIGH or 0,1 */

void GPIO_voidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode  );
void GPIO_voidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value );
u8   GPIO_u8GetPinValue       ( u8 Copy_u8Port , u8 Copy_u8Pin );
void GPIO_voidLockPin( u8 copy_u8Port, u8 copy_u8Pin);
void GPIO_voidEnableLock(u8 copy_u8Port);

#endif