/*
 * main.c
 *
 *  Created on: Nov 30, 2020
 *      Author: Abanoub Kamal
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STK_private.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


/* Led Animations */
void main(void)
{
	/* System clock */
	MRCC_voidInitSysClock();
	/* Clock of pins */
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN);

	MSTK_voidInit();

	/* initialize the pins direction */
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN0);
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN1);
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN2);
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN3);
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN4);
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN5);
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN6);
	HLED_voidInitLed(GPIO_PORTA , GPIO_PIN7);



	while(1)
	{
		u8 Local_u8Count=0;
		/* 4 times shift leds */
		for( ; Local_u8Count < 4 ; Local_u8Count++)
		{
			HLED_voidPingPong(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN7);
		}
		MSTK_voidSetBusyWait(500000);
		/* 4 times fatahy ya warda and ghamady ya warda */
		for( Local_u8Count=0 ; Local_u8Count < 4 ; Local_u8Count++)
		{
			HLED_voidFatahyYaWarda(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN7);
		}
		MSTK_voidSetBusyWait(500000);
		/* 8 times flash */
		for( Local_u8Count=0 ; Local_u8Count < 8 ; Local_u8Count++)
		{
			HLED_voidFlashLed(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN7);
		}
		MSTK_voidSetBusyWait(500000);
	}
}

