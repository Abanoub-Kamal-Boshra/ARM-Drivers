/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	17 MARCH 2021										*/
/************************************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


void MDMA_voidChannelInit(void);

void MDMA_voidChannelStart(u32 * Copy_Pu32SourceAddress , u32 * Copy_Pu32DestenationAddress , u16 Copy_u16BlockLength );


#endif