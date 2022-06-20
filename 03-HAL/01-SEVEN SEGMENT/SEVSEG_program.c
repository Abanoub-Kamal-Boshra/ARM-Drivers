/************************************************************************/
/*	Author		:	Abnoub Kamal                                        */
/* 	Version		:	V01													*/
/*	Date		: 	29 NOV 2020											*/
/*  Description	: 	SEVEN SEGMENT										*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SEVSEG_interface.h"
#include "SEVSEG_private.h"
#include "SEVSEG_config.h"


void HSEVSEG_voidInit(u8 Copy_u8Port , u8 Copy_u8FirstPin , u8 Copy_u8CommonPin)
{
	u8 Local_u8Count;
	/* set the direction of pins*/
	for (Local_u8Count=0 ; Local_u8Count<=6 ; Local_u8Count++)
		{
			GPIO_voidSetPinDirection(Copy_u8Port , (Copy_u8FirstPin + Local_u8Count) , GPIO_OUTPUT_SPEED_2MHZ_PP);
		}
	/* for common pin */
	GPIO_voidSetPinDirection(Copy_u8Port , Copy_u8CommonPin , GPIO_OUTPUT_SPEED_2MHZ_PP);
}


void HSEVSEG_voidDisplay(u8 Copy_u8SevenSegmentType ,u8 Copy_u8Port , u8 Copy_u8FirstPin , u8 Copy_u8Number)
{
	u8 Local_u8Count, Local_u8BitValue ;
	switch(Copy_u8SevenSegmentType)
	{
		case SEVSEG_COMMON_CATHODE :  /* set the pins value for the number needed to display */
									for (Local_u8Count=0 ; Local_u8Count<=6 ; Local_u8Count++)
										{
											Local_u8BitValue = GET_BIT(Copy_u8Number , Local_u8Count) ;
											GPIO_voidSetPinValue(Copy_u8Port , (Copy_u8FirstPin + Local_u8Count) , Local_u8BitValue);
										}
									break ;
		case SEVSEG_COMMON_ANODE : /* set the pins value for the number needed to display */
									for (Local_u8Count=0 ; Local_u8Count<=6 ; Local_u8Count++)
										{
											Local_u8BitValue = (! GET_BIT(Copy_u8Number , Local_u8Count)) ;
											GPIO_voidSetPinValue(Copy_u8Port , (Copy_u8FirstPin + Local_u8Count) , Local_u8BitValue );
										}
									break ;
	}
}


void HSEVSEG_voidEnable(u8 Copy_u8SevenSegmentType , u8 Copy_u8Port , u8 Copy_u8SevSegCommonPin)
{
	switch(Copy_u8SevenSegmentType)
		{
			case SEVSEG_COMMON_CATHODE:
				GPIO_voidSetPinValue(Copy_u8Port , Copy_u8SevSegCommonPin , GPIO_PIN_LOW);
				break;
			case SEVSEG_COMMON_ANODE:
				GPIO_voidSetPinValue(Copy_u8Port , Copy_u8SevSegCommonPin , GPIO_PIN_HIGH);
				break;
		}

}


void HSEVSEG_voidDisable(u8 Copy_u8SevenSegmentType , u8 Copy_u8Port , u8 Copy_u8SevSegCommonPin)
{
	switch(Copy_u8SevenSegmentType)
			{
				case SEVSEG_COMMON_CATHODE:
					GPIO_voidSetPinValue(Copy_u8Port , Copy_u8SevSegCommonPin , GPIO_PIN_HIGH);
					break;
				case SEVSEG_COMMON_ANODE:
					GPIO_voidSetPinValue(Copy_u8Port , Copy_u8SevSegCommonPin , GPIO_PIN_LOW);
					break;
			}
}

