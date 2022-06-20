/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	24 JAN 2021											*/
/************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/* for EXTI lines */
#define EXTI_LINE0			0
#define EXTI_LINE1			1
#define EXTI_LINE2			2
#define EXTI_LINE3			3
#define EXTI_LINE4			4
#define EXTI_LINE5			5
#define EXTI_LINE6			6
#define EXTI_LINE7			7
#define EXTI_LINE8			8
#define EXTI_LINE9			9
#define EXTI_LINE10			10
#define EXTI_LINE11			11
#define EXTI_LINE12			12
#define EXTI_LINE13			13
#define EXTI_LINE14			14
#define EXTI_LINE15			15

/* for EXTI modes */
#define EXTI_RISING_EDGE			1
#define EXTI_FALLING_EDGE			3
#define EXTI_ON_CHANGE				5


/********************************************************************
 * Description: configure EXTI mode from EXTI_configuration file for 
 *				specific line choosed from EXTI_configuration
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MEXTI_voidInit(void);

/********************************************************************
 * Description: Set a sense MODE of a specific line for External Interrupt at run time 
 *				
 * Inputs     :	Copy_u8Line			range 		: EXTI_LINE0 ~ EXTI_LINE15
 *									description	: the LINE number 
 *												  for ex: EXTI_LINE15
 *														  means the interrupt can be on 
 *														  MC pins PA15 , PB15 or PC15
 *				Copy_u8Mode			range 		: EXTI_RISING_EDGE
 *                                                EXTI_FALLING_EDGE
 *                                                EXTI_ON_CHANGE
 *                                  description : set the mode of this line
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);

/********************************************************************
 * Description: Enable a specific EXTI_line for External Interrupt and take 
 * 				name of a function that desired to run when EXTI from this line
 *				is fired
 * Inputs     :	Copy_u8Line					range 		: EXTI_LINE0 ~ EXTI_LINE15
 *											description	: the LINE number 
 *												  		  for ex: EXTI_LINE15
 *														  means the interrupt can be on 
 *														  MC pins PA15 , PB15 or PC15 
 *				void (*Copy_ptr)(void) 		value		: function name
 *														 
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MEXTI_voidEnableEXTI(u8 Copy_u8Line , void (*Copy_ptr)(void) );

/********************************************************************
 * Description: Disable the Interrupt of a specific line for External Interrupt
 * Inputs     :	Copy_u8Line			range 		: EXTI_LINE0 ~ EXTI_LINE15
 *									description	: the LINE number 
 *												  for ex: EXTI_LINE15
 *														  means the interrupt can be on 
 *														  MC pins PA15 , PB15 or PC15 
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);

/********************************************************************
 * Description: for SoftWare Interrupt for a specific line for External Interrupt
 * Inputs     :	Copy_u8Line			range 		: EXTI_LINE0 ~ EXTI_LINE15
 *									description	: the LINE number 
 *												  for ex: EXTI_LINE15
 *														  means the interrupt can be on 
 *														  MC pins PA15 , PB15 or PC15 
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MEXTI_voidSwTrigger(u8 Copy_u8Line);





#endif
