/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	31 JAN 2020											*/
/************************************************************************/
#ifndef OS_CONFIG_H
#define OS_CONFIG_H


/* set the number of tasks */
#define NUMBER_OF_TASKS				3

/* RCC_Clock_Processor: HSE
 * SysTick			  : HSE ---> AHP/8 = 1 us */
#define OS_TICK_TIME				1000000		/* Tick Time = 1s */


#endif
