/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	31 JAN 2020											*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


/* array of tasks     array of structure */
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};



void SOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Priodicity , void (*CopyPtr)(void) , u8 Copy_u8FirstDelay)
{
	OS_Tasks[Copy_u8Priority].priodicity = Copy_u16Priodicity;
	OS_Tasks[Copy_u8Priority].funPtr = CopyPtr;
	OS_Tasks[Copy_u8Priority].firstDelay = Copy_u8FirstDelay;
	OS_Tasks[Copy_u8Priority].state = TASK_READY;
}

void SOS_voidStart(void)
{
	/* initialization */
	MSTK_voidInit();					/* HSE ---> AHP/8 = 1 us */
	/* Tick = 1 ms */
	MSTK_voidSetIntervalPeriodic(OS_TICK_TIME , OS_voidScheduler);
}



static void OS_voidScheduler(void)
{
	
	for(u8 i=0 ; i<NUMBER_OF_TASKS ; i++)
	{
		if( (OS_Tasks[i].state == TASK_READY) )
		{
			if(OS_Tasks[i].firstDelay == 0)
			{
				OS_Tasks[i].firstDelay = OS_Tasks[i].priodicity -1 ;
				OS_Tasks[i].state = TASK_RUNNING;
				OS_Tasks[i].funPtr();
				OS_Tasks[i].state = TASK_READY;
			}
			else
			{
				OS_Tasks[i].firstDelay--;
			}
		}
	}
}


void SOS_voidSuspendTask(u8 Copy_u8Priority)
{
	OS_Tasks[Copy_u8Priority].state = TASK_WAITING;
}


void SOS_voidResumTask(u8 Copy_u8Priority)
{
	OS_Tasks[Copy_u8Priority].state = TASK_READY;
}


void SOS_voidDeleteTask(u8 Copy_u8Priority)
{
	OS_Tasks[Copy_u8Priority].state = TASK_DORMANT;
}

