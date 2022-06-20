/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	24 JAN 2021											*/
/************************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H


/*Set the EXTI_LINE for Select the EXTI_SENSE_MODE
	for example EXTI_LINE15 ---> means the interrupt can be on MC pins PA15 , PB15 or PC15
	options	:		EXTI_LINE0 ~ EXTI_LINE15
													*/
#define EXTI_LINE				EXTI_LINE0


/* Set the EXTI mode 
	options : 		EXTI_RISING_EDGE
					EXTI_FALLING_EDGE
					EXTI_ON_CHANGE
													*/
#define EXTI_SENSE_MODE			EXTI_RISING_EDGE


/* set EXTI_LINE for ISR_LINES (line5 -> line9)
 * options 	: 		EXTI_LINE5 ~ EXTI_LINE9
 * 													*/
//#define EXTI_LINE5_9			EXTI_LINE8


/* set EXTI_LINE for ISR_LINES (line10 -> line15)
 * options 	: 		EXTI_LINE10 ~ EXTI_LINE15
 * 													*/
//#define EXTI_LINE10_15			EXTI_LINE10




#endif
