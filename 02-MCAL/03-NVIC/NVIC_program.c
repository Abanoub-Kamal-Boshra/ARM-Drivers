/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	22 JAN 2021											*/
/************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	#define SCB_AIRCR		*((volatile u32*) 0xE000ED0C )
	SCB_AIRCR = NO_OF_GROUPS_SUB ;
}


u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber)
{
	u8 ErrorStatus;
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ISER0 = ( 1 << Copy_u8IntNumber ) ;
		ErrorStatus = 0;
	}
	else if ( Copy_u8IntNumber <= 59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = ( 1 << Copy_u8IntNumber ) ;
		ErrorStatus = 0;
	}
	else 
	{
		/* Return Error */
		ErrorStatus = 1;
	}
	return ErrorStatus;
}


u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
{
	u8 ErrorStatus;
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ICER0 = ( 1 << Copy_u8IntNumber ) ;
		ErrorStatus = 0;
	}
	else if ( Copy_u8IntNumber <= 59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = ( 1 << Copy_u8IntNumber ) ;
		ErrorStatus = 0;
	}
	else 
	{
		/* Return Error */
		ErrorStatus = 1;
	}
	return ErrorStatus;
}


u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber)
{
	u8 ErrorStatus;
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ISPR0 = ( 1 << Copy_u8IntNumber ) ;
		ErrorStatus = 0;
	}
	else if ( Copy_u8IntNumber <= 59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = ( 1 << Copy_u8IntNumber ) ;
		ErrorStatus = 0;
	}
	else 
	{
		/* Return Error */
		ErrorStatus = 1;
	}
	return ErrorStatus;
}


u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber)
{
	u8 ErrorStatus;
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ICPR0 = ( 1 << Copy_u8IntNumber ) ;
		ErrorStatus = 0;
	}
	else if ( Copy_u8IntNumber <= 59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = ( 1 << Copy_u8IntNumber ) ;
		ErrorStatus = 0;
	}
	else 
	{
		/* Return Error */
		ErrorStatus = 1;
	}
	return ErrorStatus;
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if ( Copy_u8IntNumber <= 31 )
	{
		Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59 )
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
	}
	else 
	{
		/* Return Error */
	}
	return Local_u8Result;
}


void MNVIC_voidSetInterruptPriority(s8 Copy_s8IntNumber , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority )
{
	if (Copy_s8IntNumber <= 59)
	{
		/*0x05FA0400 3 Group & 1 sub priority*/
		u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<((NO_OF_GROUPS_SUB - 0x05FA0300)/256));
		/* core peripheral 			*/
		if(Copy_s8IntNumber < 0)
		{

		}
		/* external peripheral		*/ /*EXTI0 = 6*/
		else if(Copy_s8IntNumber >= 0)
		{
			NVIC_IPR[Copy_s8IntNumber] = Local_u8Priority << 4 ;
		}
	}
	else
	{
		/* Return Error */
	}

}
