/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	31 JAN 2020											*/
/************************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

enum taskState {TASK_DORMANT , TASK_READY , TASK_RUNNING  , TASK_WAITING };

typedef struct
{
	u16 priodicity ;
	void (*funPtr)(void);
	u8 firstDelay;
	enum taskState state;
}Task;


static void OS_voidScheduler(void);



#endif
