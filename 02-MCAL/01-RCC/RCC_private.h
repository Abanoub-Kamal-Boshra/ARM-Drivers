/************************************************************************/
/*	Author	:	Abanoub Kamal                                           */
/* 	Version	:	V01														*/
/*	date	: 	23 NOV 2020												*/
/************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/* Register Definitions */
// base address = 0x40021000
#define 	RCC_CR				*((volatile u32*)0x40021000) // choose the 
#define 	RCC_CFGR			*((volatile u32*)0x40021004) // clock entered to the processor
#define 	RCC_CIR				*((volatile u32*)0x40021008)
#define 	RCC_APB2RSTR		*((volatile u32*)0x4002100C)
#define 	RCC_APB1RSTR		*((volatile u32*)0x40021010)
#define 	RCC_AHBENR			*((volatile u32*)0x40021014) // responsible for  
#define 	RCC_APB2ENR			*((volatile u32*)0x40021018) // enable and disable
#define 	RCC_APB1ENR			*((volatile u32*)0x4002101C) // the clock of any peripheral
#define 	RCC_BDCR			*((volatile u32*)0x40021020)
#define 	RCC_CSR				*((volatile u32*)0x40021024)



/* Clock control register (RCC_CR) */
#define RCC_HSI_ON				0
#define RCC_HSI_RDY				1
#define RCC_HSI_TRIM0			3
#define RCC_HSI_TRIM1			4
#define RCC_HSI_TRIM2			5
#define RCC_HSI_TRIM3			6
#define RCC_HSI_TRIM4			7
#define RCC_HSE_ON				16
#define RCC_HSE_RDY				17
#define RCC_HSE_BYP				18
#define RCC_CSS_ON				19
#define RCC_PLL_ON				24
#define RCC_PLL_RDY				25

/* Clock configuration register (RCC_CFGR) */
#define RCC_SW0					0
#define RCC_SW1					1
#define RCC_SWS0				2
#define RCC_SWS1				3
#define RCC_PLL_SRC				16
#define RCC_PLL_XTPRE			17
#define RCC_PLL_MUL0			18
#define RCC_PLL_MUL1			19
#define RCC_PLL_MUL2			20
#define RCC_PLL_MUL3			21

/* clock macros */
#define RCC_HSI 				0
#define RCC_HSE_CRYSTAL			1
#define	RCC_HSE_RC			 	2
#define RCC_PLL					3

/* source of pll */
#define RCC_HSE_DIVISION_1		4
#define RCC_HSE_DIVISION_2		5
#define RCC_HSI_DIVISION_2		6

/* trimming the HSI clock */
#define POSITIVE_40KHZ			7
#define POSITIVE_80KHZ			8
#define NEGATIVE_40KHZ			9
#define NEGATIVE_80KHZ			10


#endif
