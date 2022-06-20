/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Abanoub Kamal
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

// ABANOUB   	--- 55 col
static u8 DataArray_ABANOUB[]   = { 0, 0, 0, 0, 0, 0, 0, 124, 18, 18, 124, 0, 0, 126, 74, 74, 52, 0, 0, 124, 18, 18,
									124, 0, 0, 124, 8, 16, 32, 124, 0, 0, 60, 66, 66, 60, 0, 0, 62, 64, 64, 62, 0, 0,
									126, 74, 74, 52, 0, 0, 0, 0, 0, 0, 0, 0};
// Robo Squad   --- 68 col
static u8 DataArray_RoboSquad[] = {	0, 0, 0, 0, 0, 0, 0, 126, 10, 10, 116, 0, 0, 48, 72, 72, 48, 0, 0, 126, 80, 80, 32,
									0, 0, 48, 72, 72, 48, 0, 0, 0, 0, 36, 74, 74, 48, 0, 0, 4, 10, 10, 124, 0, 0, 56, 64,
									64, 56, 0, 0, 56, 40, 120, 64, 0, 0, 32, 80, 80, 62, 0, 0, 0 ,0, 0, 0, 0};


void main(void)
{
	u16 Local_u8Delay;
	/* RCC Init and enable */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN); // GPIO A
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPB_EN); // GPIO B

	/* Init STK */
	MSTK_voidInit();

	/* Init LED matrix */
	HLEDMRX_voidInit();

	/* Send data to led matrix */
	while(1)
	{
		for(u8 Local_u8Count=0 ; Local_u8Count<=60 ; Local_u8Count++)
		{
			Local_u8Delay = 0;
			while(Local_u8Delay < 5)
			{
				HLEDMRX_voidDisplayFrame(&DataArray_RoboSquad[Local_u8Count]);
				Local_u8Delay ++ ;
			}
		}
	}
}


