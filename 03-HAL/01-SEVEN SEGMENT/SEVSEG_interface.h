/************************************************************************/
/*	Author		:	Abnoub Kamal                                        */
/* 	Version		:	V01													*/
/*	Date		: 	29 NOV 2020											*/
/*  Description	: 	SEVEN SEGMENT										*/
/************************************************************************/
#ifndef SEVSEG_INTERFACE_H
#define SEVSEG_INTERFACE_H


/********************************************************************
 * Description: Initialize a seven segment by make corresponding pins in
 * 				output mode (GPIO_OUTPUT_SPEED_2MHZ_PP)
 * Inputs     : Copy_u8Port					options: GPIO_PORTA
											 	 	 GPIO_PORTB
 *
 * 				Copy_u8FirstPin				options : GPIO_PIN0 ~ GPIO_PIN9

 * 				Copy_u8CommonPin			options : GPIO_PIN0 ~ GPIO_PIN15
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HSEVSEG_voidInit(u8 Copy_u8Port , u8 Copy_u8FirstPin , u8 Copy_u8CommonPin);

/********************************************************************
 * Description: Display a number on a seven segment
 *
 * Inputs     :	Copy_u8SevenSegmentType 	options : SEVSEG_COMMON_ANODE
 * 													  SEVSEG_COMMON_CATHODE
 *
 * 				Copy_u8Port					options: GPIO_PORTA
											 	 	 GPIO_PORTB
 *
 * 				Copy_u8FirstPin				options : GPIO_PIN0 ~ GPIO_PIN9

 * 				Copy_u8Number				options : ZERO, ONE, TOW, THREE, FOUR
 * 													  FIVE, SIX, SEVEN, EIGHT, NINE
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HSEVSEG_voidDisplay(u8 Copy_u8SevenSegmentType ,u8 Copy_u8Port , u8 Copy_u8FirstPin , u8 Copy_u8Number);

/********************************************************************
 * Description: Enable a seven segment by make the common pin be HIGH or LOW
 * 				according to its type (common cathode or anode)
 *
 * Inputs     : Copy_u8SevenSegmentType 	options: SEVSEG_COMMON_CATHODE
 * 													 SEVSEG_COMMON_ANODE
 *
 * 				Copy_u8Port					options: GPIO_PORTA
											 	 	 GPIO_PORTB
 *
 * 				Copy_u8CommonPin			options : GPIO_PIN0 ~ GPIO_PIN15
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HSEVSEG_voidEnable(u8 Copy_u8SevenSegmentType ,u8 Copy_u8Port , u8 Copy_u8SevSegCommonPin);

/********************************************************************
 * Description: Disable a seven segment by make the common pin be HIGH or LOW
 * 				according to its type (common cathode or anode)
 *
 * Inputs     : Copy_u8SevenSegmentType 	options: SEVSEG_COMMON_CATHODE
 * 													 SEVSEG_COMMON_ANODE
 *
 * 				Copy_u8Port					options: GPIO_PORTA
											 	 	 GPIO_PORTB
 *
 * 				Copy_u8CommonPin			options : GPIO_PIN0 ~ GPIO_PIN15
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HSEVSEG_voidDisable(u8 Copy_u8SevenSegmentType ,u8 Copy_u8Port , u8 Copy_u8SevSegCommonPin);

#endif
