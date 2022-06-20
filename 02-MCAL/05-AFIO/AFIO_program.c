/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	25 JAN 2021											*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void MAFIO_voidSetEXTIConfig(u8 Copy_u8Line , u8 Copy_u8PortMap)
{
	u8 Local_u8RegisterIndix = 0 ;
	
	if(Copy_u8Line <= 15)
	{
		u8 Local_u8RegisterIndix = Copy_u8Line/4 ;
		/* Assign to EXTICRX register									*/
		AFIO -> EXTICR[Local_u8RegisterIndix] &= ~( (0b1111)         << ( (Copy_u8Line%4) * 4) );
		AFIO -> EXTICR[Local_u8RegisterIndix] |=  ( (Copy_u8PortMap) << ( (Copy_u8Line%4) * 4) );
	}
	else 
	{
		/* Error State */
	}
	
}