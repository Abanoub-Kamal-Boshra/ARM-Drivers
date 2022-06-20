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

#include "SEVSEG_interface.h"
#include "SEVSEG_private.h"
#include "SEVSEG_config.h"

// to count from 0 to 99 using one port

void main(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN);

	/* initialize right seven segment */
	SEVSEG_voidInit(SEVSEG_PORT , SEVSEG_START_PIN , SEVSEG_COMMON_PIN_RIGHT);
	/* initialize left seven segment */
	SEVSEG_voidInit(SEVSEG_PORT , SEVSEG_START_PIN , SEVSEG_COMMON_PIN_LEFT);

	u16 Local_u16Delay = 0;
	const u8 arr_num[] = {ZERO,ONE,TOW,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE} ;

	while(1)
	{
		for(u8 left_count=0 ; left_count<10 ; left_count++)		// this for_loop to show the tens numbers.
			{
				for(u8 right_count=0 ; right_count<10 ; right_count++) 	// this for_loop to show the ones numbers.
				{
					// this while_loop to stay show the one number.
					while(Local_u16Delay < 150)
					{
						// to show the left digit
						for(u16 Local_u8Count=0 ; Local_u8Count<40 ; Local_u8Count++)
						{
							SEVSEG_voidDisable(SEVSEG_COMMON_CATHODE , SEVSEG_PORT , SEVSEG_COMMON_PIN_RIGHT);
							SEVSEG_voidEnable (SEVSEG_COMMON_CATHODE , SEVSEG_PORT , SEVSEG_COMMON_PIN_LEFT);
							SEVSEG_voidDisplay(SEVSEG_COMMON_CATHODE , SEVSEG_PORT , SEVSEG_START_PIN , arr_num[left_count]);
						}
						// to show the right digit
						for(u16 Local_u8Count=0 ; Local_u8Count<40 ; Local_u8Count++)
						{
							SEVSEG_voidDisable(SEVSEG_COMMON_CATHODE , SEVSEG_PORT , SEVSEG_COMMON_PIN_LEFT);
							SEVSEG_voidEnable (SEVSEG_COMMON_CATHODE , SEVSEG_PORT , SEVSEG_COMMON_PIN_RIGHT);
							SEVSEG_voidDisplay(SEVSEG_COMMON_CATHODE , SEVSEG_PORT , SEVSEG_START_PIN , arr_num[right_count]);
						}
						Local_u16Delay ++ ;
					}
					Local_u16Delay = 0;
				}
			}
	} // end of while
}

