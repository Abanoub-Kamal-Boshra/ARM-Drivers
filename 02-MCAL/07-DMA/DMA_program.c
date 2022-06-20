/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	17 MARCH 2021										*/
/************************************************************************/
#include "STD_

void MDMA_voidChannelInit(void)
{
	/* 
		1- memory to memory
		2- very high priority
		3- source size , destination size = 32 bit
		4- MINC , PINC activated
		5- no circuler
		6- direction 
		7- transfer interrupt enable
	*/
	#if    CHANNEL_ID == 1
		DMA -> Channel[0].CCR = 
	#elif 
}

void MDMA_voidChannelStart(u32 * Copy_Pu32SourceAddress , u32 * Copy_Pu32DestenationAddress , u16 Copy_u16BlockLength )
{
	/*  make sure channel is disabled */
	CLR_BIT(DMA->Channel[0].CCR , 0);
	/* Write address */
	DMA->Channel[0].CPAR = Copy_Pu32SourceAddress ;
	DMA->Channel[0].CMAR = Copy_Pu32DestenationAddress ;
	/* Block length */
	DMA->Channel[0].CNDTR = Copy_u16BlockLength;
	/* Enable */
	SET_BIT(DMA->Channel[0].CCR , 0);
}
