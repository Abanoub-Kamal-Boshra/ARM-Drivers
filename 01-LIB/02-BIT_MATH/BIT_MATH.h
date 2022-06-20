/************************************************************************/
/*	author	:	Abanoub Kamal                                           */
/* 	version	:	V01														*/
/*	date	: 	10 NOV 2020												*/
/************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT( data , bit )			( data |= (1 << bit) )
#define GET_BIT( data , bit )			(( data >> bit ) & 1)
#define CLR_BIT( data , bit )			( data &= (~(1 << bit)) )
#define TOG_BIT( data , bit )	   		( data ^= (1 << bit) )


typedef enum{

	NOK,
	OK,

}error_status;


#endif /* BIT_MATH_H_ */


