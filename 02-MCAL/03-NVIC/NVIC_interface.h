/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	22 JAN 2021											*/
/************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


/* to configure number of bits for groups and sub Priority */
void MNVIC_voidInit(void);

/********************************************************************
 * Description: Enable the NVIC_Peripheral_Enable of External Interrupt
 * Inputs     :	Copy_u8IntNumber	range 		: 0 ~ 59
 *									description	: number of External Interrupt 
 * return     :	u8					range 		: 0 or 1
 *									description	: to check on Error State for this function
 *												  0 ---> Error happened 
 *												  1 ---> no Error happened 
 * scope      :	public
 **********************************************************************/
u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber);

/********************************************************************
 * Description: Disable the NVIC_Peripheral_Enable of External Interrupt
 * Inputs     :	Copy_u8IntNumber	range 		: 0 ~ 59
 *									description	: number of External Interrupt 
 * return     :	u8					range 		: 0 or 1
 *									description	: to check on Error State for this function
 *												  0 ---> Error happened 
 *												  1 ---> no Error happened 
 * scope      :	public
 **********************************************************************/
u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber);

/********************************************************************
 * Description: Set the Pending Flag of External Interrupt
 * Inputs     :	Copy_u8IntNumber	range 		: 0 ~ 59
 *									description	: number of External Interrupt 
 * return     :	u8					range 		: 0 or 1
 *									description	: to check on Error State for this function
 *												  0 ---> Error happened 
 *												  1 ---> no Error happened 
 * scope      :	public
 **********************************************************************/
u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber);

/********************************************************************
 * Description: Clear the Pending Flag of External Interrupt
 * Inputs     :	Copy_u8IntNumber	range 		: 0 ~ 59
 *									description	: number of External Interrupt 
 * return     :	u8					range 		: 0 or 1
 *									description	: to check on Error State for this function
 *												  0 ---> Error happened 
 *												  1 ---> no Error happened 
 * scope      :	public
 **********************************************************************/
u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber);

/********************************************************************
 * Description: Read the Active Flag of External Interrupt
 * Inputs     :	Copy_u8IntNumber	range 		: 0 ~ 59
 *									description	: number of External Interrupt 
 * return     :	u8					range 		: 0 or 1
 *									description	: 0 ---> Interrupt not Active
 *												  1 ---> Interrupt Active
 * scope      :	public
 **********************************************************************/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);

/********************************************************************
 * Description: Set the Interrupt SW Priority of External and Internal Interrupts
 * Inputs     :	Copy_u8IntNumber		range 		: -15 ~ 0 ~ 59
 *										description	: -15 ~ -1 ---> the number of Internal Interrupts
 *												   	   0  ~ 59  ---> the number of External Interrupts
 *				Copy_u8GroupPriority 	range 		: 0 ~ 15 based on NO_OF_GROUPS_SUB chossed in NVIC_config.h
 *				Copy_u8SubPriority		range 		: 0 ~ 15 based on NO_OF_GROUPS_SUB chossed in NVIC_config.h
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MNVIC_voidSetInterruptPriority(s8 Copy_s8IntNumber , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority );



#endif
