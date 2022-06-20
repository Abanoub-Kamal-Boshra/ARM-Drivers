/*********************************************************/
/*********************************************************/
/***********		Author: Adel Magdy   	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: BUZERR   		**************/
/***********		Version: 1.00		 	**************/
/*********************************************************/
/*********************************************************/

#ifndef BUZERR_INTERFACE_H_
#define BUZERR_INTERFACE_H_

/*use it when low dengerous*/
void HBUZERR_LowAlarm(void);

/*use it when meduim dengerous*/
void HBUZERR_MedeumAlarm(void);

/*use it when high dengerous*/
void HBUZERR_HighAlarm(void);

#endif
