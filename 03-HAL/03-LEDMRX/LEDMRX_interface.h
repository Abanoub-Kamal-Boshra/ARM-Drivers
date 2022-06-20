/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	29 JAN 2021											*/
/************************************************************************/
#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H


/********************************************************************
 * Description:	Initialize the LED_MATRIX pins direction (set in LEDMRX configuration file)
 *				by make the mode of this pin output push pull by speed 2 MHz 
 *				(GPIO_OUTPUT_SPEED_2MHZ_PP)
 *
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HLEDMRX_voidInit(void);

/********************************************************************
 * Description:	function to display one Frame on the led matrix represented as
 * 				arry of its rows.
 *
 * Inputs     :	*Copy_u8Frame				value	 	: array 
											description : array of 8 rows value of led matrix frame  
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HLEDMRX_voidDisplayFrame(u8 *Copy_u8Frame);


#endif
