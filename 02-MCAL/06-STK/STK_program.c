/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	26 JAN 2021											*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


/* global variable    ---> from type    pointer to function 
						   variable store address of function */
static void (*Callback)(void);

/* Define Variable for interval mode to differenaciate single from periodic Interval */
static u8 STK_u8ModeOfInterval;



void MSTK_voidInit(void)
{
	#if   STK_SOURCE_CLOCK == STK_AHB_CLK_DIV_8
	STK->CTRL = 0x00000000;
	#elif STK_SOURCE_CLOCK == STK_AHB_CLK
	STK->CTRL = 0x00000004;
	#else
		#warning "Wrong Systick Clock Configuration"
	#endif
}


void MSTK_voidSetBusyWait(u32 Copy_32Ticks )
{
	/* check on the number of ticks to avoid overflow of the register reslution (24 bits)*/
	if (Copy_32Ticks <= 16777215)
	{
		/* Load ticks to load register */
		STK->LOAD = Copy_32Ticks;
		/* Start Timer */   /* i do not want INT here so i don't enable the interrupt */
		SET_BIT(STK->CTRL , STK_ENABLE);
		/* Waite for counter reach to 0 and so flag is raised */
		while( 0 == GET_BIT(STK->CTRL , STK_COUNTFLAG) );
		
		/* Stop Timer */
		SET_BIT(STK->CTRL, STK_ENABLE);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}
	else
	{
		/* return error */
	}
}


void MSTK_voidSetIntervalSingle(u32 Copy_32Ticks , void (*Copy_ptr)(void) )
{
	/* Disable Timer */
	CLR_BIT(STK->CTRL , STK_ENABLE);
	STK->VAL = 0;

	/* check on the number of ticks to avoid overflow of the register reslution (24 bits)*/
	if (Copy_32Ticks <= 16777215)
	{
		/* Load ticks to load register */
		STK->LOAD = Copy_32Ticks;          	  	STK->VAL = 0;
		/* Start Timer */
		SET_BIT(STK->CTRL , STK_ENABLE);
		/* stor the address of desired function on Callback variable */
		Callback = Copy_ptr;
		/* Set Mode to Single */
		STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
		/* Enable STK Interrupt */
		SET_BIT(STK->CTRL, STK_TICKINT);
	}
	else
	{
		/* return error */
	}
}


void MSTK_voidSetIntervalPeriodic(u32 Copy_32Ticks , void (*Copy_ptr)(void) )
{
	/* check on the number of ticks to avoid overflow of the register reslution (24 bits)*/
	if (Copy_32Ticks <= 16777215)
	{
		/* Load ticks to load register */
		STK->LOAD = Copy_32Ticks-1 ;			STK->VAL = 0;
		/* Start Timer */
		SET_BIT(STK->CTRL , STK_ENABLE);
		/* store the address of desired function on Callback variable */
		Callback = Copy_ptr;
		/* Set Mode to periodic */
		STK_u8ModeOfInterval = STK_PERIODIC_INTERVAL;
		/* Enable STK Interrupt */
		SET_BIT(STK->CTRL, STK_TICKINT);
	}
	else
	{
		/* return error */
	}
}


void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, STK_TICKINT);
	
	/* Stop Timer */
	SET_BIT(STK->CTRL, STK_ENABLE);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}


u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime = 0;
	Local_u32ElapsedTime = STK->LOAD - STK->VAL;
	return  Local_u32ElapsedTime;
}


u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainingTime = 0;
	Local_u32RemainingTime = STK->VAL ;
	return Local_u32RemainingTime ;
}



/* the ISR Handler for SysTic Timer Periphera */
void SysTick_Handler(void)
{
	u8 Local_u8Temporary;

	/* if the interval is single ---> */
	if (STK_SINGLE_INTERVAL == STK_u8ModeOfInterval)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, STK_TICKINT);
		
		/* Stop Timer */
		SET_BIT(STK->CTRL, STK_ENABLE);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}

	 Callback();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,STK_COUNTFLAG);
}
