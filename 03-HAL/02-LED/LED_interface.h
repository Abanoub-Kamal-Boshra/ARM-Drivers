/************************************************************************/
/*	Author		:	Abnoub Kamal                                        */
/* 	Version		:	V01													*/
/*	Date		: 	29 NOV 2020											*/
/*  Description	: 	LED													*/
/************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


/********************************************************************
 * Description:	Initialize the led pin direction by make the mode of this pin
 * 				output push pull by speed 2 MHz (GPIO_OUTPUT_SPEED_2MHZ_PP)
 *
 * Inputs     :	Copy_u8LedPort		options: GPIO_PORTA
 *               							 GPIO_PORTB
 *               							 GPIO_PORTC
 *
 *              Copy_u8LedPin		options: GPIO_PIN0 ~ GPIO_PIN15
 *              					note   : in case GPIO_PORTC
 *              							 GPIO_PIN13 ~ GPIO_PIN15
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HLED_voidInitLed(u8 Copy_u8LedPort , u8 Copy_u8LedPin);

/********************************************************************
 * Description:	turn a desired led on by make the output of this pin
 * 				is HIGH
 * Inputs     :	Copy_u8LedPort		options: GPIO_PORTA
 *               							 GPIO_PORTB
 *               							 GPIO_PORTC
 *
 *              Copy_u8LedPin		options: GPIO_PIN0 ~ GPIO_PIN15
 *              					note   : in case GPIO_PORTC
 *              							 GPIO_PIN13 ~ GPIO_PIN15
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HLED_voidTurnOnLed(u8 Copy_u8LedPort , u8 Copy_u8LedPin);

/********************************************************************
 * Description:	turn a desired led off by make the output of this pin
 * 				is LOW
 * Inputs     :	Copy_u8LedPort		options: GPIO_PORTA
 *               							 GPIO_PORTB
 *               							 GPIO_PORTC
 *
 *              Copy_u8LedPin		options: GPIO_PIN0 ~ GPIO_PIN15
 *              					note   : in case GPIO_PORTC
 *              							 GPIO_PIN13 ~ GPIO_PIN15
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HLED_voidTurnOffLed(u8 Copy_u8LedPort , u8 Copy_u8LedPin);

/********************************************************************
 * Description:	toggle a desired led by make the output of this pin
 * 				toggle between LOW and HIGH
 * Inputs     :	Copy_u8LedPort		options: GPIO_PORTA
 *               							 GPIO_PORTB
 *               							 GPIO_PORTC
 *
 *              Copy_u8LedPin		options: GPIO_PIN0 ~ GPIO_PIN15
 *              					note   : in case GPIO_PORTC
 *              							 GPIO_PIN13 ~ GPIO_PIN15
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HLED_voidTogLed(u8 Copy_u8LedPort , u8 Copy_u8LedPin);


void HLED_voidPingPong(u8 Copy_u8LedPort , u8 Copy_u8FirstLedPin , u8 Copy_u8LastLedPin);

void HLED_voidFatahyYaWarda(u8 Copy_u8LedPort , u8 Copy_u8FirstLedPin , u8 Copy_u8LastLedPin);

void HLED_voidFlashLed(u8 Copy_u8LedPort , u8 Copy_u8FirstLedPin , u8 Copy_u8LastLedPin);


#endif
