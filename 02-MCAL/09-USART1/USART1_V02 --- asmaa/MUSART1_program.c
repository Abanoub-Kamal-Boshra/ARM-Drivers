

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART1_config.h"
#include "MUSART1_private.h"
#include "MUSART1_interface.h"
//#include "MUSART1_private.h"


#define THRESHOLD_VALUE  9000000UL

void (*MUSART1_CallBack)(void);

void MUSART1_voidInit ( void ){

	u32 LOC_u32Mantissa = ( F_CPU ) / ( 16 * MUSART1_BAUD_RATE ) ;

	u32 LOC_u64Fraction = ( ( ( F_CPU * 100 ) / ( 16 * MUSART1_BAUD_RATE )  ) % 100 ) * 16 ;

	if( LOC_u64Fraction >= 1550 ){ LOC_u32Mantissa += 1 ; LOC_u64Fraction  = 0 ; }

	#if MUSART1_STATUS == MUSART1_ENABLE

		MUSART1 -> SR = 0 ;

		#if   MUSART1_WORD_LENGTH == MUSART1_EIGHT_BIT_WORD_LENGTH

					CLR_BIT( MUSART1 -> CR1 , 12 );

		#elif MUSART1_WORD_LENGTH == MUSART1_NINE_BIT_WORD_LENGTH

					SET_BIT( MUSART1 -> CR1 , 12 );

		#endif

		#if   MUSART1_PARITY == MUSART1_PARITY_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 10 );

		#elif MUSART1_PARITY == MUSART1_EVEN_PARITY

					SET_BIT( MUSART1 -> CR1 , 10 );
					CLR_BIT( MUSART1 -> CR1 , 11 );

		#elif MUSART1_PARITY == MUSART1_ODD_PARITY

					SET_BIT( MUSART1 -> CR1 , 10 );
					SET_BIT( MUSART1 -> CR1 , 11 );

		#endif

		#if  MUSART1_INTERRUPT == MUSART1_INTERRUPT_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 5 );
					CLR_BIT( MUSART1 -> CR1 , 6 );
					CLR_BIT( MUSART1 -> CR1 , 7 );

		#elif MUSART1_INTERRUPT == MUSART1_TXE_INTERRUPT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 7 );

		#elif MUSART1_INTERRUPT == MUSART1_TCE_INTERRUPT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 6 );

		#elif MUSART1_INTERRUPT == MUSART1_RXNE_INTERRUPT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 5 );

		#endif

		#if   MUSART1_TRANSMITTER == MUSART1_TRANSMITTER_ENABLE

					SET_BIT( MUSART1 -> CR1 , 3 );

		#elif MUSART1_TRANSMITTER == MUSART1_TRANSMITTER_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 3 );

		#endif

		#if   MUSART1_RECEIVER == MUSART1_RECEIVER_ENABLE

					SET_BIT( MUSART1 -> CR1 , 2 );

		#elif MUSART1_RECEIVER == MUSART1_RECEIVER_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 2 );

		#endif

		#if   MUSART1_STOP_BITS == MUSART1_ONE_STOP_BIT

					CLR_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );

		#elif MUSART1_STOP_BITS == MUSART1_HALF_STOP_BIT

					SET_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );

		#elif MUSART1_STOP_BITS == MUSART1_TWO_STOP_BIT

					CLR_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );

		#elif MUSART1_STOP_BITS == MUSART1_ONE_AND_HALF_STOP_BIT

					SET_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );


		#endif

		MUSART1 -> BRR = ( LOC_u32Mantissa << 4  ) | ( LOC_u64Fraction / 100 ) ;
		SET_BIT( MUSART1 -> CR1 , 13 );

	#elif MUSART1_STATUS == MUSART1_DISABLE
		CLR_BIT( MUSART1 -> CR1 , 0 );

	#endif

}


void MUSART1_voidSendCharSync ( u8 Copy_u8Char ){

	MUSART1 -> DR = Copy_u8Char ;

	while( GET_BIT( MUSART1 -> SR , 6 ) == 0 );

	CLR_BIT( MUSART1 -> SR , 6 );

}

void MUSART1_voidSendSrtingSynch ( u8 * Copy_ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while ( Copy_ptrString[ LOC_u8Iterator ] != '\0' ){

		MUSART1_voidSendCharSync( Copy_ptrString[ LOC_u8Iterator ] );
		LOC_u8Iterator++ ;

	}

}

u8 MUSART1_u8RecCharSynch ( void ){

	u8  LOC_u8Data  = 0 ;
	u32 LOC_TimeOut = 0 ;

	CLR_BIT ( MUSART1 -> SR, 5);

	while( ( GET_BIT ( MUSART1 -> SR, 5) == 0 ) && ( LOC_TimeOut < THRESHOLD_VALUE ) )
	{
		LOC_TimeOut++;
	}

	if( LOC_TimeOut == THRESHOLD_VALUE )
	{
		LOC_u8Data = 255;
	}
	else
	{

		LOC_u8Data = MUSART1 -> DR;
	}

	return LOC_u8Data;

}

u8 String[20];
u8 * MUSART1_PtrReadStringSynch ( void ){

	u8 LOC_Iterator = 0 , LOC_u8DataCome ;

	while( ( LOC_u8DataCome = MUSART1_u8RecCharSynch() ) != 13 ){

		String[ LOC_Iterator ] = LOC_u8DataCome ;
		LOC_Iterator++ ;
	}

	String[LOC_Iterator] = '\0';

	return ( String );

}

u8 MUSART1_u8ReadDataRegister ( void ){

	return ( MUSART1 -> DR );

}

void MUSART1_voidClearFlags( void ){

	/* Clear all flags */
	MUSART1 -> SR = 0;

}


void MUSART1_voidSetCallBack( void (*ptr) (void) ){

	MUSART1_CallBack = ptr ;

}

void USART1_IRQHandler(void){

	MUSART1 -> SR = 0 ;
	MUSART1_CallBack();

}
