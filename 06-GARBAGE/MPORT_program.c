
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MPORT_interface.h"
#include "MPORT_config.h"
#include "MPORT_private.h"


void MPORT_voidInit( void ){

	/* Initializing The Direction Of GPIOA LOW  Based On The Value That Configured In MPORT_config.h  */
	MGPIOA_CRL = PORTA_DIR_L ;
	/* Initializing The Direction Of GPIOA HIGH Based On The Value That Configured In MPORT_config.h  */
	MGPIOA_CRH = PORTA_DIR_H ;

	/* Initializing The Direction Of GPIOB LOW  Based On The Value That Configured In MPORT_config.h  */
	MGPIOB_CRL = PORTB_DIR_L ;
	/* Initializing The Direction Of GPIOB HIGH Based On The Value That Configured In MPORT_config.h  */
	MGPIOB_CRH = PORTB_DIR_H ;

	/* Initializing The Direction Of GPIOC HIGH Based On The Value That Configured In MPORT_config.h  */
	MGPIOC_CRH = PORTC_DIR_H ;

	/* Initializing The Digital Value Of GPIOA LOW & HIGH Based On The Value That Configured In MPORT_config.h  */
	MGPIOA_ODR = ( ( PORTA_INITIAL_VALUE_H ) << 8 ) | PORTA_INITIAL_VALUE_L ;

	/* Initializing The Digital Value Of GPIOB LOW & HIGH Based On The Value That Configured In MPORT_config.h  */
	MGPIOB_ODR = ( ( PORTB_INITIAL_VALUE_H ) << 8 ) | PORTB_INITIAL_VALUE_L ;

	/* Initializing The Digital Value Of GPIOC HIGH Based On The Value That Configured In MPORT_config.h  */
	MGPIOC_ODR = ( PORTC_INITIAL_VALUE_H ) << 8 ;

}

error_status MPORT_enumSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode ){

	error_status LOC_enumStatus = OK ;

	if( ( Copy_u8Port < 3 ) && ( Copy_u8Pin < 16 ) ){

		switch(Copy_u8Port){

		case MPORT_u8_PORTA :

			if(Copy_u8Pin <= 7 ){

				/* Clearing GPIOA LOW Before Accessing It */
				MGPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));
				/* Setting The Direction Of GPIOA LOW */
				MGPIOA_CRL |= ( Copy_u8Mode )   << ( Copy_u8Pin * 4 );

			}else if(Copy_u8Pin <=15 ){

				Copy_u8Pin = Copy_u8Pin - 8;

				/* Clearing GPIOA HIGH Before Accessing It */
				MGPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				/* Setting The Direction Of GPIOA HIGH */
				MGPIOA_CRH |= ( Copy_u8Mode )   << ( Copy_u8Pin * 4 );
			}

			break;

		case MPORT_u8_PORTB :

			if(Copy_u8Pin <= 7 ){

				/* Clearing GPIOB LOW Before Accessing It */
				MGPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				/* Setting The Direction Of GPIOB LOW */
				MGPIOB_CRL |= ( Copy_u8Mode )   << ( Copy_u8Pin * 4 )  ;

			}else if(Copy_u8Pin <=15 ){

				Copy_u8Pin = Copy_u8Pin - 8;
				/* Clearing GPIOB HIGH Before Accessing It */
				MGPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				/* Setting The Direction Of GPIOB HIGH */
				MGPIOB_CRH |= ( Copy_u8Mode )   << ( Copy_u8Pin * 4 )  ;
			}

			break;

		case MPORT_u8_PORTC:

			if(Copy_u8Pin <= 7 ){

				/* Clearing GPIOC LOW Before Accessing It */
				MGPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				/* Setting The Direction Of GPIOC LOW */
				MGPIOC_CRL |= ( Copy_u8Mode )   << ( Copy_u8Pin * 4 )  ;

			}else if(Copy_u8Pin <=15 ){

				Copy_u8Pin = Copy_u8Pin - 8;

				/* Clearing GPIOC HIGH Before Accessing It */
				MGPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				/* Setting The Direction Of GPIOC HIGH */
				MGPIOC_CRH |= ( Copy_u8Mode )   << ( Copy_u8Pin * 4 )  ;
			}

			break;

		default : LOC_enumStatus = NOK ; break;

		}

	}

	else{ LOC_enumStatus = NOK ; }

	return LOC_enumStatus ;

}

