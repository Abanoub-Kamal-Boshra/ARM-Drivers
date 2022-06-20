/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	30 JAN 2021											*/
/************************************************************************/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H



#define IR_POWER_PIN			69
#define IR_MODE_PIN				70
#define IR_SILENCE_PIN			71

#define IR_SOUND_ON_OFF_PIN		68
#define IR_DECREMENT_PIN		64
#define IR_ENCREMENT_PIN		67

#define IR_EQ_PIN				7
#define IR_VOL_MINNUS_PIN		21
#define IR_VOL_PLUS_PIN			9

#define IR_0_PIN				22
#define IR_RPT_PIN				25
#define IR_U_SD_PIN				13

#define IR_1_PIN				12
#define IR_2_PIN				24
#define IR_3_PIN				94

#define IR_4_PIN				8
#define IR_5_PIN				28
#define IR_6_PIN				90

#define IR_7_PIN				66
#define IR_8_PIN				82
#define IR_9_PIN				74


/********************************************************************
 * Description:	Initialize the IR pin direction (set in LEDMRX configuration file)
 *				by make the mode of this pin Input floating (GPIO_INPUT_FLOATION)
 *				Initialize the SysTick (to set its clock to AHP/8 = 1MHz)
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HIR_voidInit(void);

/********************************************************************
 * Description:	Enable the EXTI Line of the pin connected on it output of IR Receiver
 *				Return the value of Bottom pressed on NEC Remote control
 *
 * Inputs     :	void
 * return     :	u8 					value 	: Bottom value that pressed on NEC Remote control
 * scope      :	public
 **********************************************************************/
u8 HIR_u8GetPressedBottom(void);
 
 
 
#endif
