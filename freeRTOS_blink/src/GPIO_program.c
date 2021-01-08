/*********************************************************/
/* File  : GPIO_program.c								 */
/* Author: Eslam Shahin									 */
/* Email : eslamshahin552000@gmail.com					 */
/*														 */
/* Version : 1.0										 */
/* For ARM Based MUCs									 */
/* Created on 3 Sep 2020								 */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"


void GPIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode ){

	switch(Copy_u8Port)
	{
	case GPIOA:
	
		if(Copy_u8Pin <= 7 )
		{/* For the lower pins register (every pin has a 4 bits to config )*/
			GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));
			GPIOA_CRL |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}
		else if(Copy_u8Pin <=15 )
		{/* For the higher pins register (every pin has a 4 bits to config )*/
			Copy_u8Pin = Copy_u8Pin - 8; /* to reset count to deal with the register easy*/
			GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOA_CRH |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}
		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 )
		{/* For the lower pins register (every pin has a 4 bits to config )*/
			GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRL |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{/* For the higher pins register (every pin has a 4 bits to config )*/
			Copy_u8Pin = Copy_u8Pin - 8; /* to reset count to deal with the register easy*/
			GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRH |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	case GPIOC:
		if(Copy_u8Pin <= 7 )
		{
			GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRL |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRH |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	default :
	/* Return Error */
	break;
	}


}

void GPIO_voidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value ){

	switch(Copy_u8Port)
	{
	case GPIOA:
		if( Copy_u8Value == HIGH ){
			SET_BIT( GPIOA_ODR , Copy_u8Pin ); /* Read , Modify , Write */
			//GPIOA_BSRR=(1<<Copy_u8Pin); /* To set the equal bit in the ODR register in one step*/
		}else if( Copy_u8Value == LOW ){
			CLEAR_BIT( GPIOA_ODR , Copy_u8Pin );/* Read , Modify , Write */
			//GPIOA_BRR=(1<<Copy_u8Pin); /* To reset the equal bit in the ODR register in one step*/
		}
		break;
		
	case GPIOB:
		if( Copy_u8Value == HIGH ){
			SET_BIT( GPIOB_ODR  , Copy_u8Pin );
			GPIOB_BSRR=(1<<Copy_u8Pin);
		}else if( Copy_u8Value == LOW ){
			CLEAR_BIT( GPIOB_ODR  , Copy_u8Pin );
			GPIOB_BRR=(1<<(Copy_u8Pin+16));
		}
		break;
		
	case GPIOC:
		if( Copy_u8Value == HIGH ){
			SET_BIT( GPIOC_ODR , Copy_u8Pin );
			GPIOC_BSRR=(1<<Copy_u8Pin);
		}else if( Copy_u8Value == LOW ){
			CLEAR_BIT( GPIOC_ODR , Copy_u8Pin );
			GPIOC_BRR=(1<<(Copy_u8Pin+16));
		}
		break;

	}

}

u8 GPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT(GPIOA_IDR , Copy_u8Pin );
		break;
		
	case GPIOB:
		LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );
		break;
		
	case GPIOC:
		LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );
		break;
	default :
		/*Return Error*/
		break;	
	}
	
	return LOC_u8Result;
}

void GPIO_voidLockPin( u8 copy_u8Port, u8 copy_u8Pin){
	
	switch(copy_u8Port)
	{
	case GPIOA:
		SET_BIT(GPIOA_LCKR , copy_u8Pin );
		break;
		
	case GPIOB:
		SET_BIT(GPIOB_LCKR , copy_u8Pin );
		break;
		
	case GPIOC:
		SET_BIT(GPIOC_LCKR , copy_u8Pin );
		break;
	default :
		/*Return Error*/
		break;	
	}	

}
void GPIO_voidEnableLock(u8 copy_u8Port){
	/* LCKK Bit num 16  It can only be modified using the Lock Key Writing Sequence. */
	/* Startting Write Sequance to enabe Lock */
	switch(copy_u8Port)
	{
	case GPIOA:
		SET_BIT(GPIOA_LCKR , copy_u8Port );
		CLEAR_BIT(GPIOA_LCKR , copy_u8Port );
		SET_BIT(GPIOA_LCKR , copy_u8Port );
		break;
		
	case GPIOB:
		SET_BIT(GPIOB_LCKR , copy_u8Port );
		CLEAR_BIT(GPIOB_LCKR , copy_u8Port );
		SET_BIT(GPIOB_LCKR , copy_u8Port );
		break;
		
	case GPIOC:
		SET_BIT(GPIOC_LCKR , copy_u8Port );
		CLEAR_BIT(GPIOC_LCKR , copy_u8Port );
		SET_BIT(GPIOC_LCKR , copy_u8Port );
		break;
	default :
		/*Return Error*/
		break;	
	}	
		
}

