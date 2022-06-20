/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	26 JAN 2021											*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"


void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;

	MGPIO_voidSetPinValue(STP_STORE_CLOCK , GPIO_PIN_LOW);

	for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
	{
		/* Send bit by bit starting from MSB */
		Local_u8Bit = GET_BIT(Copy_u8DataToSend , Local_s8Counter);
		
		MGPIO_voidSetPinValue(STP_SERIAL_DATA , (Local_u8Bit) );
		
		/* send pulse to shift clock */
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_PIN_LOW);
		MSTK_voidSetBusyWait(1);
	}
	
	/* send pulse to Store clock */
	MGPIO_voidSetPinValue(STP_STORE_CLOCK , GPIO_PIN_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(STP_STORE_CLOCK , GPIO_PIN_LOW);
}

void HSTP_voidSendTwoByte(u8 Copy_u8LeftDataToSend , u8 Copy_u8RightDataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	
	MGPIO_voidSetPinValue(STP_STORE_CLOCK , GPIO_PIN_LOW);

	/* send the right byte */
	for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
	{
		/* Send bit by bit starting from MSB */
		Local_u8Bit = GET_BIT(Copy_u8RightDataToSend , Local_s8Counter);
		
		MGPIO_voidSetPinValue(STP_SERIAL_DATA , Local_u8Bit);
		
		/* send pulse to shift clock */
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_PIN_LOW);
		MSTK_voidSetBusyWait(1);
	}
	
	/* send pulse to Store clock */
	MGPIO_voidSetPinValue(STP_STORE_CLOCK , GPIO_PIN_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(STP_STORE_CLOCK , GPIO_PIN_LOW);

	
	/***************************************************************/
	/* send the second byte */
	for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
	{
		/* Send bit by bit starting from MSB */
		Local_u8Bit = GET_BIT(Copy_u8RightDataToSend , Local_s8Counter);
		
		MGPIO_voidSetPinValue(STP_SERIAL_DATA , Local_u8Bit);
		
		/* send pulse to shift clock */
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_PIN_LOW);
		MSTK_voidSetBusyWait(1);
	}
	
	/* send pulse to Store clock */
	MGPIO_voidSetPinValue(STP_STORE_CLOCK , GPIO_PIN_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(STP_STORE_CLOCK , GPIO_PIN_LOW);

}

