/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	24 JAN 2021											*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/* global variable  in pointer to function type */
static void (*EXTI_Callback[5])(void) = {NULL};


/* we must to check on tow parameter line and mode */
void MEXTI_voidInit(void)
{
	#if  	EXTI_SENSE_MODE	== EXTI_RISING_EDGE
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif 	EXTI_SENSE_MODE	== EXTI_FALLING_EDGE
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif 	EXTI_SENSE_MODE	== EXTI_ON_CHANGE
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else 	
			#error "Wrong Mode Choice"
	#endif
	/* Disable interrupt */
	CLR_BIT(EXTI -> IMR , EXTI_LINE);
}


void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case EXTI_RISING_EDGE 	: SET_BIT(EXTI -> RTSR , Copy_u8Line); break;
		case EXTI_FALLING_EDGE 	: SET_BIT(EXTI -> FTSR , Copy_u8Line); break;
		case EXTI_ON_CHANGE		: SET_BIT(EXTI -> RTSR , Copy_u8Line);
							  	  SET_BIT(EXTI -> FTSR , Copy_u8Line); break;
	}
}


void MEXTI_voidEnableEXTI(u8 Copy_u8Line , void (*Copy_ptr)(void) )
{
	EXTI_Callback[Copy_u8Line] = Copy_ptr ;

	// should Copy_u8Line <=15 
	SET_BIT(EXTI -> IMR , Copy_u8Line);
}


void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> IMR , Copy_u8Line);
}

// ?????
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> IMR   , Copy_u8Line);
	CLR_BIT(EXTI -> PR 	  , Copy_u8Line);
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
}

/************************************************************************************/
/*								ISRs of EXTI interrupts								*/
							   /***********************/

void EXTI0_IRQHandler(void)
{
	EXTI_Callback[0]();
	/* clear pending bit */
	SET_BIT(EXTI->PR , EXTI_LINE0);
}

void EXTI1_IRQHandler(void)
{
	EXTI_Callback[1]();
	/* clear pending bit */
	SET_BIT(EXTI->PR , EXTI_LINE1);
}

void EXTI2_IRQHandler(void)
{
	EXTI_Callback[2]();
	/* clear pending bit */
	SET_BIT(EXTI->PR , EXTI_LINE2);
}

void EXTI3_IRQHandler(void)
{
	EXTI_Callback[3]();
	/* clear pending bit */
	SET_BIT(EXTI->PR , EXTI_LINE3);
}

void EXTI4_IRQHandler(void)
{
	EXTI_Callback[4]();
	/* clear pending bit */
	SET_BIT(EXTI->PR , EXTI_LINE4);
}

/*
void EXTI9_5_IRQHandler(void)
{
	EXTI_Callback[5]();
	/// clear pending bit
	SET_BIT(EXTI->PR , EXTI_LINE5_9);
}

void EXTI15_10_IRQHandler(void)
{
	EXTI_Callback[6]();
	/// clear pending bit
	SET_BIT(EXTI->PR , EXTI_LINE10_15);
}
*/
