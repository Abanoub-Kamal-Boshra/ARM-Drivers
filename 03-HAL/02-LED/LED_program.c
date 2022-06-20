/************************************************************************/
/*	Author		:	Abnoub Kamal                                        */
/* 	Version		:	V01													*/
/*	Date		: 	29 NOV 2020											*/
/*  Description	: 	LED													*/
/************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void HLED_voidInitLed(u8 Copy_u8LedPort , u8 Copy_u8LedPin)
{
	MGPIO_voidSetPinDirection(Copy_u8LedPort , Copy_u8LedPin, GPIO_OUTPUT_SPEED_2MHZ_PP);
}


void HLED_voidTurnOnLed(u8 Copy_u8LedPort , u8 Copy_u8LedPin)
{
	MGPIO_voidSetPinValue(Copy_u8LedPort , Copy_u8LedPin , GPIO_PIN_HIGH);
}

void HLED_voidTurnOffLed(u8 Copy_u8LedPort , u8 Copy_u8LedPin)
{
	MGPIO_voidSetPinValue(Copy_u8LedPort , Copy_u8LedPin , GPIO_PIN_LOW);
}

void HLED_voidTogLed(u8 Copy_u8LedPort , u8 Copy_u8LedPin)
{
	u16 Local_u8Flag = 0 ;
	while(65000 > Local_u8Flag)
	{
		MGPIO_voidSetPinValue(Copy_u8LedPort , Copy_u8LedPin , GPIO_PIN_HIGH);
		Local_u8Flag++ ;
	}
	while(1 < Local_u8Flag)
	{
		MGPIO_voidSetPinValue(Copy_u8LedPort , Copy_u8LedPin , GPIO_PIN_LOW);
		Local_u8Flag-- ;
	}
}


void HLED_voidPingPong(u8 Copy_u8LedPort , u8 Copy_u8FirstLedPin , u8 Copy_u8LastLedPin)
{
	s8 Local_s8Counter = Copy_u8FirstLedPin;
	/* forward led on */
	for( ; Local_s8Counter <= Copy_u8LastLedPin ; Local_s8Counter++)
	{
		// led on
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8Counter , GPIO_PIN_HIGH);
		// delay 200 ms
		MSTK_voidSetBusyWait(PING_DELAY);
		// led off
		MGPIO_voidSetPinValue(Copy_u8LedPort ,  Local_s8Counter    , GPIO_PIN_LOW );
	}
	/* reverse led on */
	Local_s8Counter = Copy_u8LastLedPin-1 ;
	for( ; Local_s8Counter > Copy_u8FirstLedPin ; Local_s8Counter--)
	{
		// led on
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8Counter , GPIO_PIN_HIGH);
		// delay 200 ms
		MSTK_voidSetBusyWait(PING_DELAY);
		// led off
		MGPIO_voidSetPinValue(Copy_u8LedPort ,  Local_s8Counter    , GPIO_PIN_LOW );
	}
}


void HLED_voidFatahyYaWarda(u8 Copy_u8LedPort , u8 Copy_u8FirstLedPin , u8 Copy_u8LastLedPin)
{
	/* fatahy ya warda */
	// for middle tow led
	s8 Local_s8LeftCounter  = (Copy_u8FirstLedPin+Copy_u8LastLedPin)/2;
	s8 Local_s8RightCounter = Local_s8LeftCounter +1;
	for( ; Local_s8LeftCounter >= Copy_u8FirstLedPin ; Local_s8LeftCounter--)
	{
		// tow led on
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8LeftCounter  , GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8RightCounter , GPIO_PIN_HIGH);
		// delay 200 ms
		MSTK_voidSetBusyWait(WARDA_DELAY);
		// tow led off
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8LeftCounter  , GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8RightCounter , GPIO_PIN_LOW);
		Local_s8RightCounter ++;
	}
	/* ghamady ya warda */
	/* for outer tow led */
	Local_s8LeftCounter  = Copy_u8FirstLedPin+1 ;
	Local_s8RightCounter = Copy_u8LastLedPin-1  ;
	for( ; Local_s8LeftCounter < ((Copy_u8FirstLedPin+Copy_u8LastLedPin)/2) ; Local_s8LeftCounter++)
	{
		// tow led on
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8LeftCounter  , GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8RightCounter , GPIO_PIN_HIGH);
		// delay 200 ms
		MSTK_voidSetBusyWait(WARDA_DELAY);
		// tow led off
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8LeftCounter  , GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_s8RightCounter , GPIO_PIN_LOW);
		Local_s8RightCounter --;
	}
	/* for last cycle ---> turn on the middle leds */

}

void HLED_voidFlashLed(u8 Copy_u8LedPort , u8 Copy_u8FirstLedPin , u8 Copy_u8LastLedPin)
{
	u8 Local_u8Count = Copy_u8FirstLedPin;
	for( ; Local_u8Count <= Copy_u8LastLedPin ; Local_u8Count++)
	{
		// leds on
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_u8Count  , GPIO_PIN_HIGH);
	}
	// delay
	MSTK_voidSetBusyWait(FLASH_DELAY);
	Local_u8Count = Copy_u8FirstLedPin;
	for( ; Local_u8Count <= Copy_u8LastLedPin ; Local_u8Count++)
	{
		// leds off
		MGPIO_voidSetPinValue(Copy_u8LedPort , Local_u8Count  , GPIO_PIN_LOW);
	}
	// delay
	MSTK_voidSetBusyWait(FLASH_DELAY);
}
