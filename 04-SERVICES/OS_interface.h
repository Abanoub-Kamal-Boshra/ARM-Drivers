/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	31 JAN 2020											*/
/************************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


/********************************************************************
 * Description: Function to Create task
 * Inputs     :	Copy_u8Priority			range  		: 0 ~ 255
 * 													  used as ID for the Task

			  :	Copy_u16Priodicity		description : number of Ticks that Task should operate again

			  :	void (*CopyPtr)(void)   value  	 	: function name
										description : function needed to operate by the Task

			  : Copy_u8FirstDelay		description : Task delay at first time for overcome on problem of CPU Load

 * return     :	void
 * scope      :	public
 **********************************************************************/
void SOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Priodicity , void (*CopyPtr)(void) , u8 Copy_u8FirstDelay);

/********************************************************************
 * Description: To Start operating in the System after creating the Tasks
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void SOS_voidStart(void);

/********************************************************************
 * Description: To make the Task be on the Waiting State
 * Inputs     :	Copy_u8Priority			description : used as ID for the Task
 * return     :	void
 * scope      :	public
 **********************************************************************/
void SOS_voidSuspendTask(u8 Copy_u8Priority);

/********************************************************************
 * Description: To make the Task be on the Ready State to enable it to Running again
 * Inputs     :	Copy_u8Priority			description : used as ID for the Task
 * return     :	void
 * scope      :	public
 **********************************************************************/
void SOS_voidResumTask(u8 Copy_u8Priority);

/********************************************************************
 * Description: To make the Task be on the Dormant State to disable it from Running again
 * 				unless we Creating this Task again
 * Inputs     :	Copy_u8Priority			description : used as ID for the Task
 * return     :	void
 * scope      :	public
 **********************************************************************/
void SOS_voidDeleteTask(u8 Copy_u8Priority);


#endif
