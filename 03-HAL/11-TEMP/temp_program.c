/*
 * temp_program.c
 *
 *  Created on: May 7, 2021
 *      Author: Efraim Yousef
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "temp_config.h"
#include "temp_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

void DHT11_Start (void)
{
	MGPIO_voidSetPinDirection (DHT11_PORT, DHT11_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);  // set the pin as output
	MGPIO_voidSetPinValue (DHT11_PORT, DHT11_PIN, GPIO_PIN_LOW);   // pull the pin low
	MSTK_voidSetBusyWait (18000);   // wait for 18ms
	MGPIO_voidSetPinValue (DHT11_PORT, DHT11_PIN, GPIO_PIN_HIGH);
	MSTK_voidSetBusyWait (20);   // wait for 20us
	MGPIO_voidSetPinDirection (DHT11_PORT, DHT11_PIN,GPIO_INPUT_FLOATION);    // set as input
}
u8 Check_Response (void)
{
	u8 Response = 0;
	MSTK_voidSetBusyWait (40);
	if (!(MGPIO_u8GetPinValue (DHT11_PORT, DHT11_PIN)))
	{
		MSTK_voidSetBusyWait (80);
		if ((MGPIO_u8GetPinValue (DHT11_PORT, DHT11_PIN))) Response = 1;
		else Response = -1;
	}
	while ((MGPIO_u8GetPinValue (DHT11_PORT, DHT11_PIN)));   // wait for the pin to go low

	return Response;
}
u8 DHT11_Read (void)
{
	u8 i,j;
	for (j=0;j<8;j++)
	{
		while (!(MGPIO_u8GetPinValue (DHT11_PORT, DHT11_PIN)));   // wait for the pin to go high
		MSTK_voidSetBusyWait (40);   // wait for 40 us
		if (!(MGPIO_u8GetPinValue (DHT11_PORT, DHT11_PIN)))   // if the pin is low
		{
			i &= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ((MGPIO_u8GetPinValue (DHT11_PORT, DHT11_PIN)));  // wait for the pin to go low
	}
	return i;
}



