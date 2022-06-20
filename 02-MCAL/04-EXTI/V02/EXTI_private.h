/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	24 JAN 2021											*/
/************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

// base address = 0x40010400
typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_t;

// pointer to struct
#define EXTI 		( (volatile EXTI_t *)  0x40010400 )



#endif
