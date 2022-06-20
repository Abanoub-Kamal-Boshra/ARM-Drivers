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


void MGPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
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


void MGPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :
				switch(Copy_u8Value)
				{
					case GPIO_PIN_HIGH :
							//SET_BIT(GPIOA_ODR , Copy_u8Pin);
							GPIOA_BSRR = (1 << Copy_u8Pin) ;
							break;
					case GPIO_PIN_LOW :
							//CLR_BIT(GPIOA_ODR , Copy_u8Pin);
							GPIOA_BRR = (1 << Copy_u8Pin) ;
							break;
				}
				break ;
		case GPIO_PORTB :
				switch(Copy_u8Value)
				{
					case GPIO_PIN_HIGH :
							//SET_BIT(GPIOB_ODR , Copy_u8Pin);
							GPIOB_BSRR = (1 << Copy_u8Pin) ;
							break;
					case GPIO_PIN_LOW :
							//CLR_BIT(GPIOB_ODR , Copy_u8Pin);
							GPIOB_BRR = (1 << Copy_u8Pin) ;
							break;
				}
				break ;
		case GPIO_PORTC :
				switch(Copy_u8Value)
				{
					case GPIO_PIN_HIGH :
							//SET_BIT(GPIOC_ODR , Copy_u8Pin);
							GPIOC_BSRR = (1 << Copy_u8Pin) ;
							break;
					case GPIO_PIN_LOW :
							//CLR_BIT(GPIOC_ODR , Copy_u8Pin);
							GPIOC_BRR = (1 << Copy_u8Pin) ;
							break;
				}
				break ;
		//default    :                       	break ;
	}
}


u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
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

void MGPIO_u8LockPinMode(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	// variable for read the LCKK
	u32 Local_u32LockKeyState;
	switch(Copy_u8Port)
	{
		case GPIO_PORTA : GPIOA_LCKR |= (1 << Copy_u8Pin);
			// Write sequence on LOCK KEY Bit (LCKK ---> 16)
			GPIOA_LCKR |= 0x00010000;
			GPIOA_LCKR &= 0xFFFEFFFF;
			GPIOA_LCKR |= 0x00010000;
			Local_u32LockKeyState = GPIOA_LCKR ;
			Local_u32LockKeyState = GPIOA_LCKR ;
			break;
		case GPIO_PORTB : GPIOB_LCKR |= (1 << Copy_u8Pin);
			// Write sequence on LOCK KEY Bit (LCKK ---> 16)
			GPIOB_LCKR |= 0x00010000;
			GPIOB_LCKR &= 0xFFFEFFFF;
			GPIOB_LCKR |= 0x00010000;
			Local_u32LockKeyState = GPIOA_LCKR ;
			Local_u32LockKeyState = GPIOA_LCKR ;
			break;
		case GPIO_PORTC : GPIOC_LCKR |= (1 << Copy_u8Pin);
			// Write sequence on LOCK KEY Bit (LCKK ---> 16)
			GPIOC_LCKR |= 0x00010000;
			GPIOC_LCKR &= 0xFFFEFFFF;
			GPIOC_LCKR |= 0x00010000;
			Local_u32LockKeyState = GPIOA_LCKR ;
			Local_u32LockKeyState = GPIOA_LCKR ;
			break;
	}
}
