/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	26 June 2021 										*/
/************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SERVO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"

#include "TIM_interface.h"

void HSERVO_viodSetServoAngle(u8 Copy_u8Angle , u8 Copy_u8Channel )
{
	/* this equation comes from manual calibrating */
	f32 Local_f32DutyCycle = (Copy_u8Angle / 18.0) + 2.5 ;

	MTIM4_voidSetPWM( SERVO_PERIOD , Local_f32DutyCycle , Copy_u8Channel );
}
