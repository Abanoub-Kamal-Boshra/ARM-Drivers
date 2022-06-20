/*
 * main.c
 *
 *  Created on: Jan 30, 2021
 *      Author: Abanoub Kamal
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"


void main(void)
{
	u8 Local_u8IrData =0 ;

 	/* RCC clock */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN);
	MRCC_voidEnableClock(RCC_APB2 , RCC_AFIO_EN);

  	/* Initialize the pin modes */
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_INPUT_FLOATION);		/* Used for IR receiver */
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN1 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN2 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN3 , GPIO_OUTPUT_SPEED_2MHZ_PP);

	/* EXTI inintialize */
	MAFIO_voidSetEXTIConfig(EXTI_LINE0 , AFIO_PORTA_MAP);
	MEXTI_voidInit();

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();				/* Set the Group Sub distribution */
	MNVIC_u8EnableInterrupt(6);		/* EXTI0 */

	/* IR Init ---> set its pin mode && Init the SysTick */
	HIR_voidInit();


	while(1)
	{
		Local_u8IrData = HIR_u8GetPressedBottom();
		switch(Local_u8IrData)
		{
			// RED
			case IR_POWER_PIN		: MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_PIN_HIGH); break;
			case IR_MODE_PIN 		: MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_PIN_LOW); break;
			//BLUE
			case IR_SOUND_ON_OFF_PIN: MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_PIN_HIGH); break;
			case IR_DECREMENT_PIN	: MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_PIN_LOW); break;
			//GREEN
			case IR_EQ_PIN		  	: MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_PIN_HIGH); break;
			case IR_VOL_MINNUS_PIN	: MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_PIN_LOW); break;
		}
	}
}



