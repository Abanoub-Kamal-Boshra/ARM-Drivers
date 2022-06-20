/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	26 JAN 2021											*/
/*  NOTE		:  	calculations is set take into account that
					CLOCK SOURCE = AHB/8								*/
/************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/***********************************************************************
 * Description: Apply clock choice from configuration file 
 *				Disable systick interrupt
 *				Disable systick 	
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MSTK_voidInit(void);

/***********************************************************************
 * Description: synchronous function.
 *				stuck the processor for time equal number of ticks 
 *				entered multibly time of one tick (tick time = 1us).
				calculations is set take into account that CLOCK SOURCE = AHB/8

 * Inputs     :	Copy_32Ticks			range		: 0 ~ (2^24 -1)
 *										description : number of ticks
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MSTK_voidSetBusyWait(u32 Copy_32Ticks );

/***********************************************************************
 * Description: Asynchronous function.
 *				this function take function name to excute it after a time
 *				interval equal (tick time * time of one tick)
 *
 * Inputs     :	Copy_32Ticks				range		: 0 ~ (2^24 -1)
 *											description : number of ticks 
 *				
 * 				void (*Copy_ptr)(void)		value	: function name  
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MSTK_voidSetIntervalSingle(u32 Copy_32Ticks , void (*Copy_ptr)(void) );

/***********************************************************************
 * Description: Asynchronous function.
 *				this function take function name to excute it after a time
 *				interval equal (tick time * time of one tick) and repeat it periodicaly
 *
 * Inputs     :	Copy_32Ticks				range		: 0 ~ (2^24 -1)
 *											description : number of ticks 
 *				
 * 				void (*Copy_ptr)(void)		value	: function name 
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MSTK_voidSetIntervalPeriodic(u32 Copy_32Ticks , void (*Copy_ptr)(void) );

/***********************************************************************
 * Description: this function to stop the timer (SysTick)  
 *				and lock its interrupt
 *				
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MSTK_voidStopInterval(void);

/***********************************************************************
 * Description: to fined the time consumed since the timer start counting 
 *				
 * Inputs     :	void
 * return     :	u32
 * scope      :	public
 **********************************************************************/
u32 MSTK_u32GetElapsedTime(void);

/***********************************************************************
 * Description: to find the time remaining till the timer firing interrupt  
 *				and do something
 *				
 * Inputs     :	void
 * return     :	u32
 * scope      :	public
 **********************************************************************/
u32 MSTK_u32GetRemainingTime(void); 



#endif
