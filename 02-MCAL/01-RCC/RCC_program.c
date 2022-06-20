/************************************************************************/
/*	Author	:	Abanoub Kamal                                           */
/* 	Version	:	V01														*/
/*	date	: 	23 NOV 2020												*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInitSysClock(void)
{
	/* Enable the CSS Clock System Security */
	//SET_BIT(RCC_CR , RCC_CSS_ON);
	RCC_CR  |= 		0X00080000 ;
	
	/* set PLL source */
	#if RCC_SYSTEM_CLOCK == RCC_PLL
		#if RCC_PLL_SOURCE == RCC_HSE_DIVISION_1
			//SET_BIT(RCC_CFGR , RCC_PLL_SRC);
			RCC_CFGR |=	0X00010000 ;
			//CLR_BIT(RCC_CFGR , RCC_PLL_XTPRE);
			RCC_CFGR &= 0xFFFDFFFF ;
		#elif RCC_PLL_SOURCE == RCC_HSE_DIVISION_2
			//SET_BIT(RCC_CFGR , RCC_PLL_SRC);
			//SET_BIT(RCC_CFGR , RCC_PLL_XTPRE);
			RCC_CFGR |= 0X00030000 ;
		#elif RCC_PLL_SOURCE == RCC_HSI_DIVISION_2
			//CLR_BIT(RCC_CFGR , RCC_PLL_SRC);
			RCC_CFGR &= 0xFFFEFFFF ;
		#else
			//#error ("choice error")
		#endif
	#endif

	/* adjust the clock system as we need by multiply PLL by factor */
	#if RCC_SYSTEM_CLOCK == RCC_PLL
		#if RCC_PLL_MUL == 2
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL0);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL1);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL2);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL3);
			RCC_CFGR &= 0xFFC3FFFF ;
		#elif RCC_PLL_MUL == 3
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL0);
			RCC_CFGR |= 0x00040000 ;
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL1);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL2);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL3);
			RCC_CFGR &= 0xFFC7FFFF ;
		#elif RCC_PLL_MUL == 4
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL1);
			RCC_CFGR |= 0x00080000 ;
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL0);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL2);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL3);
			RCC_CFGR &= 0xFFCBFFFF ;
		#elif RCC_PLL_MUL == 5
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL0);
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL1);
			RCC_CFGR |= 0x000C0000 ;
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL2);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL3);
			RCC_CFGR &= 0xFFCFFFFF ;
		#elif RCC_PLL_MUL == 6
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL0);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL1);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL3);
			RCC_CFGR &= 0xFFD3FFFF ;
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL2);
			RCC_CFGR |= 0x00100000 ;
		#elif RCC_PLL_MUL == 7
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL0);
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL2);
			RCC_CFGR |= 0x00140000 ;
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL1);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL3);
			RCC_CFGR &= 0xFFD7FFFF ;
		#elif RCC_PLL_MUL == 8
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL1);
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL2);
			RCC_CFGR |= 0x00180000 ;
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL0);
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL3);
			RCC_CFGR &= 0xFFDBFFFF ;
		#elif RCC_PLL_MUL == 9
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL0);
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL1);
			//SET_BIT(RCC_CFGR , RCC_PLL_MUL2);
			RCC_CFGR |= 0x001C0000 ;
			//CLR_BIT(RCC_CFGR , RCC_PLL_MUL3);
			RCC_CFGR &= 0xFFDFFFFF ;
		#else
			//#error ("choece error")
		#endif
	#endif
	
	/* slelct between RCC_HSI or RCC_HSE_CRYSTAL or RCC_HSE_RC or RCC_PLL */
	#if RCC_SYSTEM_CLOCK == RCC_HSI
		/* enable HSI */
		//SET_BIT(RCC_CR , RCC_HSI_ON);
		RCC_CR   |= 0X00080001 ;
		/* switching to HSI */
		//CLR_BIT(RCC_CFGR , RCC_SW0);
		//CLR_BIT(RCC_CFGR , RCC_SW1);
		RCC_CFGR &= 0xFFFFFFFC ;
	#elif RCC_SYSTEM_CLOCK == RCC_HSE_CRYSTAL
		/* select CRYSTAL external clock */
		//CLR_BIT(RCC_CR , RCC_HSE_BYP);
		RCC_CR 	 &= 0xFFFBFFFF ;
		//SET_BIT(RCC_CR , RCC_HSE_ON);
		RCC_CR 	 |= 0x00010000 ;
		/* switching to HSE */
		//SET_BIT(RCC_CFGR , RCC_SW0);
		RCC_CFGR |= 0x00000001 ;
		//CLR_BIT(RCC_CFGR , RCC_SW1);
		RCC_CFGR &= 0xFFFFFFFD ;
	#elif RCC_SYSTEM_CLOCK == RCC_HSE_RC
		/* select RC external clock */
		//SET_BIT(RCC_RC , RCC_HSE_BYP);
		//SET_BIT(RCC_CR , RCC_HSE_ON);
		RCC_CR   |= 0x00050000 ;
		/* switching to HSE */
		//SET_BIT(RCC_CFGR , RCC_SW0);
		RCC_CFGR |= 0x00000001 ;
		//CLR_BIT(RCC_CFGR , RCC_SW1);
		RCC_CFGR &= 0xFFFFFFFD ;
	#elif RCC_SYSTEM_CLOCK == RCC_PLL
		/* Enable PLL at select it */
		//SET_BIT(RCC_RC , RCC_PLL_ON);
		RCC_CR 	 |= 0x01000000 ;
		/* switching to PLL */
		//CLR_BIT(RCC_CFGR , RCC_SW0);
		RCC_CFGR &= 0xFFFFFFFE ;
		//SET_BIT(RCC_CFGR , RCC_SW1);
		RCC_CFGR |= 0x00000002 ;
	#else 
		//#error ("choece error");
	#endif
	
	/* if there is error in HSI, and we want TRIMMING it */ 
	#if RCC_SYSTEM_CLOCK == RCC_HSI
		/* to add 40KHz to the HSI */
		#if RCC_HSI_TRIMMING == POSITIVE_40KHZ
			//SET_BIT(RCC_RC , RCC_HSI_TRIM0);
			//SET_BIT(RCC_RC , RCC_HSI_TRIM4);
			RCC_CR	 |= 0x00000088 ;
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM1);
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM2);
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM3);
			RCC_CR	 &= 0xFFFFFF8F ;
		/* to add 80KHz to the HSI */
		#elif RCC_HSI_TRIMMING == POSITIVE_80KHZ
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM0);
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM2);
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM3);
			RCC_CR	 &= 0xFFFFFF97 ;
			//SET_BIT(RCC_RC , RCC_HSI_TRIM1);
			//SET_BIT(RCC_RC , RCC_HSI_TRIM4);
			RCC_CR	 |= 0x00000090 ;
		/* to subtract 40KHz from the HSI */
		#elif RCC_HSI_TRIMMING == NEGATIVE_40KHZ
			//SET_BIT(RCC_RC , RCC_HSI_TRIM0);
			//SET_BIT(RCC_RC , RCC_HSI_TRIM1);
			//SET_BIT(RCC_RC , RCC_HSI_TRIM2);
			//SET_BIT(RCC_RC , RCC_HSI_TRIM3);
			RCC_CR	 |= 0x00000078 ;
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM4);
			RCC_CR	 &= 0xFFFFFF7F ;
		/* to subtract 80KHz from the HSI */
		#elif RCC_HSI_TRIMMING == NEGATIVE_80KHZ
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM0);
			//CLR_BIT(RCC_RC , RCC_HSI_TRIM4);
			RCC_CR	 &= 0xFFFFFF77 ;
			//SET_BIT(RCC_RC , RCC_HSI_TRIM1);
			//SET_BIT(RCC_RC , RCC_HSI_TRIM2);
			//SET_BIT(RCC_RC , RCC_HSI_TRIM3);
			RCC_CR	 |= 0x 00000070 ;
		#else
			//#error ("choece error")
		#endif
	#endif

	RCC_CFGR &= 0xFFFFC00F ; // for prescaler = 1 (not divided) for the three busses 
	/* AHB prescaler */
	#if   RCC_AHB_PRESCALER == 2
		RCC_CFGR |= 0x00000080 ;
	#elif RCC_AHB_PRESCALER == 4
		RCC_CFGR |= 0x00000090 ;
	#elif RCC_AHB_PRESCALER == 8
		RCC_CFGR |= 0x000000A0 ;
	#elif RCC_AHB_PRESCALER == 16
		RCC_CFGR |= 0x000000B0 ;
	#endif

	/* APB1 prescaler */
	#if   RCC_APB1_PRESCALER == 2
		RCC_CFGR |= 0x00004000 ;
	#elif RCC_APB1_PRESCALER == 4
		RCC_CFGR |= 0x00000500 ;
	#elif RCC_APB1_PRESCALER == 8
		RCC_CFGR |= 0x00000600 ;
	#elif RCC_APB1_PRESCALER == 16
		RCC_CFGR |= 0x00000700 ;
	#endif

	/* APB2 prescaler */
	#if   RCC_APB2_PRESCALER == 2
		RCC_CFGR |= 0x00002000 ;
	#elif RCC_APB2_PRESCALER == 4
		RCC_CFGR |= 0x00002800 ;
	#elif RCC_APB2_PRESCALER == 8
		RCC_CFGR |= 0x00003000 ;
	#elif RCC_APB2_PRESCALER == 16
		RCC_CFGR |= 0x00003800 ;
	#endif
}


void MRCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB 	: SET_BIT(RCC_AHBENR   , Copy_u8PeripheralId);  break;
			case RCC_APB1 	: SET_BIT(RCC_APB1ENR  , Copy_u8PeripheralId);  break;
			case RCC_APB2 	: SET_BIT(RCC_APB2ENR  , Copy_u8PeripheralId);  break;
		//	default			: /* error */ 								 ;  break;
		}
	}
	else
	{
		/* Retern Error */
	}
		
}


void MRCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB 	: CLR_BIT(RCC_AHBENR   , Copy_u8PeripheralId);  break;
			case RCC_APB1 	: CLR_BIT(RCC_APB1ENR  , Copy_u8PeripheralId);  break;
			case RCC_APB2 	: CLR_BIT(RCC_APB2ENR  , Copy_u8PeripheralId);  break;
		//	default			: /* error */ 								 ;  break;
		}
	}
	else
	{
		/* Retern Error */
	}
		
}
