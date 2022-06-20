/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	25 JAN 2021											*/
/************************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H



#define AFIO_PORTA_MAP		0b0000
#define AFIO_PORTB_MAP		0b0001
#define AFIO_PORTC_MAP		0b0010


/********************************************************************
 * Description: select the source input for EXTIx external interrupt
 * Inputs     :	Copy_u8Line			range 		: EXTI_LINE0 ~ EXTI_LINE15
 *									description	: the LINE number 
 *												  for ex: EXTI_LINE15
 *														  means the interrupt can be on 
 *														  MC pins PA15 , PB15 or PC15
 *				Copy_u8PortMap    	range 		: AFIO_PORTA_MAP
 *                                                AFIO_PORTB_MAP
 *                                                AFIO_PORTC_MAP
 *                              for ex if we use: AFIO_PORTA_MAP 	for Copy_u8PortMap
 *												  EXTI_LINE13	 	for Copy_u8Line
 *												  ---> EXTI on Pin A13
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MAFIO_voidSetEXTIConfig(u8 Copy_u8Line , u8 Copy_u8PortMap);


#endif
