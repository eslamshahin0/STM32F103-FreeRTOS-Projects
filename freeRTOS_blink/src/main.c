
/* include libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include freeRTOS header files */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

/* Drivers headers */
#include "RCC_interface.h"
#include "GPIO_interface.h"

#include <stdio.h>
#include <stdint.h>
/* Functions declarations */
void Task1 (void* arg) ;
void Task2 (void* arg) ;

/* Semihosting debug */
//extern void initialise_monitor_handles();

/* main */
int main (void)
{

	//initialise_monitor_handles();

	/* Init System clock 8mhz internal rc*/
	RCC_voidInitSysClock() ;

	RCC_voidEnableClock(APB2, IOPCEN); /* Enable clock for GPIOC */
	/* Set pin mode as output */
	GPIO_voidSetPinDirection(GPIOC,PIN13,OUTPUT_SPEED_2MHZ_PP);
	/* turn off led (logic low) */
	GPIO_voidSetPinValue(GPIOC,PIN13,LOW);

	/* Crate tasks */
	xTaskCreate(Task2 ,"OFF",configMINIMAL_STACK_SIZE,NULL ,1,NULL) ;
	xTaskCreate(Task1 ,"On" ,configMINIMAL_STACK_SIZE,NULL ,1,NULL) ;


	/* Start Scheduler */
	vTaskStartScheduler() ;


	while(1);
}


void Task1 (void* arg){

	while (1)
	{
		GPIO_voidSetPinValue(GPIOC,PIN13,LOW);

	}

}



void Task2 (void* arg){

	while (1)
	{
		GPIO_voidSetPinValue(GPIOC,PIN13,HIGH);


	}

}
