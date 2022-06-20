/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	17 MARCH 2021										*/
/************************************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


// Base address = 0x4002 0000
typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESERVED;
}DMA_Channel;                // group of regesters for each channel

typedef struct
{
	volatile u32 ISR;  // for all channels
	volatile u32 IFCR; // for all channels
	DMA_Channel Channel[7];
}DMA_t;

// pointer to struct
#define DMA       ((volatile DMA_t *) 0x40020000)


#endif