/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	22 JAN 2021											*/
/************************************************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H


/* to control in number of Groups and number of sub priorities in your system
	(number of bits for Group & number of bits for Sub)
	
	options	:	NVIC_4BITS_GROUP_0BIT_SUB
				NVIC_3BITS_GROUP_1BIT_SUB
				NVIC_2BITS_GROUP_2BITS_SUB
				NVIC_1BIT_GROUP_3BITS_SUB
				NVIC_0BIT_GROUP_4BITS_SUB	*/
#define NO_OF_GROUPS_SUB  	 		NVIC_2BITS_GROUP_2BITS_SUB





#endif
