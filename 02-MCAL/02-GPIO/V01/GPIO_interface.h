/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	29 NOV 2020											*/
/************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


#define 	GPIO_PORTA		0
#define 	GPIO_PORTB		1
#define 	GPIO_PORTC		2

#define 	GPIO_PIN0		0
#define 	GPIO_PIN1		1
#define 	GPIO_PIN2		2
#define 	GPIO_PIN3		3
#define 	GPIO_PIN4		4
#define 	GPIO_PIN5		5
#define 	GPIO_PIN6		6
#define 	GPIO_PIN7		7
#define 	GPIO_PIN8		8
#define 	GPIO_PIN9		9
#define 	GPIO_PIN10		10
#define 	GPIO_PIN11		11
#define 	GPIO_PIN12		12
#define 	GPIO_PIN13		13
#define 	GPIO_PIN14		14
#define 	GPIO_PIN15		15

#define 	GPIO_PIN_HIGH	1
#define 	GPIO_PIN_LOW	0

#define 	GPIO_INPUT_ANALOG					0b0000
#define 	GPIO_INPUT_FLOATION					0b0100
#define 	GPIO_INPUT_PULL_UP_DOWN				0b1000
	
#define 	GPIO_OUTPUT_SPEED_10MHZ_PP			0b0001
#define 	GPIO_OUTPUT_SPEED_10MHZ_OD			0b0101
#define 	GPIO_OUTPUT_SPEED_10MHZ_AFPP		0b1001
#define 	GPIO_OUTPUT_SPEED_10MHZ_AFOD		0b1101
	
#define 	GPIO_OUTPUT_SPEED_2MHZ_PP			0b0010
#define 	GPIO_OUTPUT_SPEED_2MHZ_OD			0b0110
#define 	GPIO_OUTPUT_SPEED_2MHZ_AFPP			0b1010
#define 	GPIO_OUTPUT_SPEED_2MHZ_AFOD			0b1110
	
#define 	GPIO_OUTPUT_SPEED_50MHZ_PP			0b0011
#define 	GPIO_OUTPUT_SPEED_50MHZ_OD			0b0111
#define 	GPIO_OUTPUT_SPEED_50MHZ_AFPP		0b1011
#define 	GPIO_OUTPUT_SPEED_50MHZ_AFOD		0b1111


/********************************************************************
 * Description: set the direction for any pin 
 * Inputs     :	Copy_u8Port			options: GPIO_PORTA
											 GPIO_PORTB
											 GPIO_PORTC
											 
				Copy_u8Pin			options: GPIO_PIN0 ~ GPIO_PIN15
									note   : in case GPIO_PORTC 
											 GPIO_PIN13 ~ GPIO_PIN15
											 
				Copy_u8Mode			options: GPIO_INPUT_ANALOG
											 GPIO_INPUT_FLOATION
											 GPIO_INPUT_PULL_UP_DOWN
											 ...
 * return     :	void
 * scope      :	public
 **********************************************************************/
void GPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);

/********************************************************************
 * Description:	Set the value for any pin
 * Inputs     :	Copy_u8Port			options: GPIO_PORTA
                							 GPIO_PORTB
                							 GPIO_PORTC
											 
                Copy_u8Pin			options: GPIO_PIN0 ~ GPIO_PIN15
                					note   : in case GPIO_PORTC  
                							 GPIO_PIN13 ~ GPIO_PIN15
											 
				Copy_u8Value  		options: GPIO_PIN_HIGH	
											 GPIO_PIN_LOW	
 * return     :	void
 * scope      :	public
 **********************************************************************/
void GPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

/********************************************************************
 * Description:	Get the value of any pin
 * Inputs     :	Copy_u8Port			options: GPIO_PORTA
                							 GPIO_PORTB
                							 GPIO_PORTC
											 
                Copy_u8Pin			options: GPIO_PIN0 ~ GPIO_PIN15
                					note   : in case GPIO_PORTC  
                							 GPIO_PIN13 ~ GPIO_PIN15
 * return     :	void
 * scope      :	public
 **********************************************************************/
u8 GPIO_voidGetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);




#endif
