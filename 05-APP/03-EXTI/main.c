/*
 * main.c
 *
 *  Created on: Jan 25, 2021
 *      Author: Abanoub Kamal
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

#include "LED_interface.h"

void toggle(void);
void toggle2(void);
/* led on at interrupt Fired */
void main(void)
{
	// initialize the clocks
	RCC_voidInitSysClock(); /* Enable the clock system */
	RCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN); /* enable the clock of GPIO_PORTA */
	RCC_voidEnableClock(RCC_APB2 , RCC_AFIO_EN); /* Enable clock of Alternative Function AFIO */

	// pins mode
	GPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_INPUT_PULL_UP_DOWN); /* A0 ---> input for receive the EXTI0 */
	GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_HIGH);
	GPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN1 , GPIO_INPUT_PULL_UP_DOWN); /* A1 ---> input for receive the EXTI1 */
	GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_PIN_HIGH);
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN2); 									/* A2 ---> used for led */
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN3); 									/* A3 ---> used for led */

	/* NVIC Initialization */
	MNVIC_voidInit();											/* to init the Group Sub Priority distribution */
	MNVIC_voidSetInterruptPriority(6 , 1 , 0);					/* EXTI0 GROUP 1 Sub 0 */
	MNVIC_voidSetInterruptPriority(7 , 0 , 0);					/* EXTI1 GROUP 0 Sub 0 */
	/* EXTI initialization */
	MEXTI_voidInit();   										/* set sense mode for line choosed in configuration file */
	MEXTI_voidSetSignalLatch(EXTI_LINE0 , EXTI_FALLING_EDGE);	/* EXTI_LINE0 ---> mode of falling edge */
	MEXTI_voidSetSignalLatch(EXTI_LINE1 , EXTI_FALLING_EDGE);	/* EXTI_LINE1 ---> mode of falling edge */
	MAFIO_voidSetEXTIConfig(EXTI_LINE0 , AFIO_PORTA_MAP); 		/* EXTI_LINE0 ---> on A0 */
	MAFIO_voidSetEXTIConfig(EXTI_LINE1 , AFIO_PORTA_MAP); 		/* EXTI_LINE1 ---> on A1 */

	/* enable EXTI from NVIC */
	MNVIC_u8EnableInterrupt(6); 		/* EXTI0 = 6 */
	MNVIC_u8EnableInterrupt(7); 		/* EXTI1 = 7 */
	/* enable the EXTI */
	MEXTI_voidEnableEXTI(EXTI_LINE0 , toggle);	/* for line 0 */
	MEXTI_voidEnableEXTI(EXTI_LINE1 , toggle2);	/* for line 1 */

	//MNVIC_u8SetPendingFlag(6); /* set pending flag of EXTI0 */
	while (1)
	{


	}
}


void toggle(void)
{
	HLED_voidTurnOnLed(GPIO_PORTA , GPIO_PIN2);
	HLED_voidTurnOffLed(GPIO_PORTA , GPIO_PIN3);
	for(u32 i=0 ; i<500000 ; i++)
	{
		asm ("NOP") ;
	}
	/*HLED_voidTurnOffLed(GPIO_PORTA , GPIO_PIN2);
	for(u16 i=0 ; i<65000 ; i++)
	{
		asm ("NOP") ;
	}*/
}

void toggle2(void)
{
	HLED_voidTurnOnLed(GPIO_PORTA , GPIO_PIN3);
	HLED_voidTurnOffLed(GPIO_PORTA , GPIO_PIN2);
	for(u32 i=0 ; i<500000 ; i++)
	{
		asm ("NOP") ;
	}
}
