/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	26 JAN 2021											*/
/************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


/* base address = 0xE000E010 */
/* Register difinition */
typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_t;

/* pointer to struct */
#define STK 		( (volatile STK_t*) 0xE000E010 )


#define STK_ENABLE				0	
#define STK_TICKINT				1
#define STK_CLKSOURCE			2
#define STK_COUNTFLAG			16

#define STK_AHB_CLK_DIV_8		0
#define STK_AHB_CLK				1

#define STK_SINGLE_INTERVAL		2
#define STK_PERIODIC_INTERVAL	3


#endif
