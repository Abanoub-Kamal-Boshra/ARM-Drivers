/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	30 JAN 2021											*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

static volatile u8 Global_u8StartFlag 		= 0;
static volatile u32 Gobal_u32FramData[50] 	= {0};
static volatile u8 Global_u8EdgeCounter 	= 0;
static volatile u8 Global_u8Data 			= 0;
static volatile u8 Global_u8DataFlag 		= 0;


void HIR_voidInit(void)
{
	MGPIO_voidSetPinDirection(IR_INPUT_PORT , IR_INPUT_PIN , GPIO_INPUT_FLOATION);
	
	/* SysTick Initialize */
	MSTK_voidInit();  				/* Enable systick AHP/8 = 1MHz */
}


u8 HIR_u8GetPressedBottom(void)
{
	Global_u8DataFlag = 0;
	MEXTI_voidEnableEXTI(IR_INPUT_PIN , IR_voidGetIrFrame);
	
	/* Busy wait for get data */
	while(Global_u8DataFlag == 0);
	
	return Global_u8Data;
}


static void IR_voidGetIrFrame(void)
{
	if(Global_u8StartFlag == 0)
	{
		/* start count */
		MSTK_voidSetIntervalSingle(300000 , IR_voidGetData);
		Global_u8StartFlag = 1;
	}
	else
	{
		Gobal_u32FramData[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(300000 , IR_voidGetData);
		Global_u8EdgeCounter++;
	}
}



static void IR_voidGetData(void)
{
	u8 i;
	Global_u8Data = 0;

	//if(Gobal_u32FramData[0] >= 10000 && Gobal_u32FramData[0] <= 14000)
	{
		for (i=0 ; i<8; i++)
		{
			if(Gobal_u32FramData[17+i] >= 2000 && Gobal_u32FramData[17+i] <= 2300)
			{
				SET_BIT(Global_u8Data , i);
			}
			else
			{
				CLR_BIT(Global_u8Data , i);
			}
		}
	}
	//else
	{
		/* Invalide frame */
	}

	Global_u8StartFlag   = 0;
	Gobal_u32FramData[0] = 0;
	Global_u8EdgeCounter = 0;

	Global_u8DataFlag = 1;
}


