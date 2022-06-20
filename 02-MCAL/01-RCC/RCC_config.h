/************************************************************************/
/*	Author	:	Abanoub Kamal                                           */
/* 	Version	:	V01														*/
/*	date	: 	23 NOV 2020												*/
/************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*note:  HSI = 8 MHz (RC)   //	 HSE = 8 MHz (CRYSTAL) */

/* Set the system clock
allowed choices is: 	RCC_HSI
						RCC_HSE_CRYSTAL
						RCC_HSE_RC
						RCC_PLL			 */
#define RCC_SYSTEM_CLOCK			RCC_HSE_CRYSTAL


/* Set the PLL source 
allowed choices is: 	RCC_HSI_DIVISION_2
						RCC_HSE_DIVISION_1
						RCC_HSE_DIVISION_2 */
#if RCC_SYSTEM_CLOCK == RCC_PLL
#define RCC_PLL_SOURCE 				RCC_HSE_DIVISION_1
#endif


/* adjust the clock system as we need
 allowed choices is: 	2,3,4,5,6,7,8,9	*/
#if RCC_SYSTEM_CLOCK == RCC_PLL
#define RCC_PLL_MUL 				NULL
#endif


/* to TRIMMING tne (adjust) HSI clock 
allowed choices is: 	POSITIVE_40KHZ
						POSITIVE_80KHZ
						NEGATIVE_40KHZ
						NEGATIVE_80KHZ */
#if RCC_SYSTEM_CLOCK == RCC_HSI
#define RCC_HSI_TRIMMING			NULL
#endif


/* prescaler for AHB bus from clk processor
 * devision by ...
 * options 	:	 2, 4, 8, 16 */
#define RCC_AHB_PRESCALER  			NULL


/* prescaler for APB2 from AHB
 * devision by ...
 * options 	:	 2, 4, 8, 16 */
#define RCC_APB2_PRESCALER			NULL


/* prescaler for APB1 from AHB, the clk must not exceed 36 MHz
 * devision by ...
 * options 	:	 2, 4, 8, 16 */
#define RCC_APB1_PRESCALER			NULL


#endif
