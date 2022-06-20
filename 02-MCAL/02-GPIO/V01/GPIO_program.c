/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	29 NOV 2020											*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void GPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :
		  			if 		(Copy_u8Pin <= 7)
					{
						// clear the bits for mode
						GPIOA_CRL &= ~ ( (0b1111) << (Copy_u8Pin*4) );
						// set the mode 
						GPIOA_CRL |=   ( (Copy_u8Mode) << (Copy_u8Pin*4) );
					}
					else if	(Copy_u8Pin <= 15)
					{
						// clear the bits for mode
						Copy_u8Pin -= 8; // as we begin by bit 0 in a new register GPIOA_CRH
						GPIOA_CRH &= ~ ( (0b1111) << (Copy_u8Pin*4) );
						// set the mode 
						GPIOA_CRH |=   ( (Copy_u8Mode) << (Copy_u8Pin*4) );
					}
					break ;
		case GPIO_PORTB :
					if 		(Copy_u8Pin <= 7)
					{
						// clear the bits for mode
						GPIOB_CRL &= ~ ( (0b1111) << (Copy_u8Pin*4) );
						// set the mode 
						GPIOB_CRL |=   ( (Copy_u8Mode) << (Copy_u8Pin*4) );
					}
					else if	(Copy_u8Pin <= 15)
					{
						// clear the bits for mode
						Copy_u8Pin -= 8; 			// as we begin by bit 0 in a new regester GPIOB_CRH
						GPIOB_CRH &= ~ ( (0b1111) << (Copy_u8Pin*4) );
						// set the mode 
						GPIOB_CRH |=   ( (Copy_u8Mode) << (Copy_u8Pin*4) );
					}
					break ;
		case GPIO_PORTC :
					if 		(Copy_u8Pin <= 7)
					{
						// clear the bits for mode
						GPIOC_CRL &= ~ ( (0b1111) << (Copy_u8Pin*4) );
						// set the mode 
						GPIOC_CRL |=   ( (Copy_u8Mode) << (Copy_u8Pin*4) );
					}
					else if	(Copy_u8Pin <= 15)
					{
						// clear the bits for mode
						Copy_u8Pin -= 8; 			// as we begin by bit 0 in a new regester GPIOC_CRH
						GPIOC_CRH &= ~ ( (0b1111) << (Copy_u8Pin*4) );
						// set the mode 
						GPIOC_CRH |=   ( (Copy_u8Mode) << (Copy_u8Pin*4) );
					}
					break ;
		//default    : Error porT break ;
	}
}


void GPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :
					if 		(Copy_u8Value == GPIO_PIN_HIGH)
					{
						SET_BIT(GPIOA_ODR , Copy_u8Pin);
					}
					else if	(Copy_u8Value == GPIO_PIN_LOW)
					{
						CLR_BIT(GPIOA_ODR , Copy_u8Pin);
					}
					break ;
		case GPIO_PORTB :
					if 		(Copy_u8Value == GPIO_PIN_HIGH)
					{
						SET_BIT(GPIOB_ODR , Copy_u8Pin);
					}
					else if	(Copy_u8Value == GPIO_PIN_LOW)
					{
						CLR_BIT(GPIOB_ODR , Copy_u8Pin);
					}
					break ;
		case GPIO_PORTC :
					if 		(Copy_u8Value == GPIO_PIN_HIGH)
					{
						SET_BIT(GPIOC_ODR , Copy_u8Pin);
					}
					else if	(Copy_u8Value == GPIO_PIN_LOW)
					{
						CLR_BIT(GPIOC_ODR , Copy_u8Pin);
					}
					break ;
		//default    :                       	break ;
	}
}


u8 GPIO_voidGetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8Reselt ;
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :Local_u8Reselt = GET_BIT(GPIOA_IDR , Copy_u8Pin);
						 break ;
		case GPIO_PORTB :Local_u8Reselt = GET_BIT(GPIOB_IDR , Copy_u8Pin);
						 break ;
		case GPIO_PORTC :Local_u8Reselt = GET_BIT(GPIOC_IDR , Copy_u8Pin);
						 break ;
		//default    	:                  		break ;
	}
	return Local_u8Reselt;
}
