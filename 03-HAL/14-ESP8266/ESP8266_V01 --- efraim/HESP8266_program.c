

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART1_interface.h"

#include "HESP8266_interface.h"
#include "HESP8266_private.h"

#include "MSTK_interface.h"

u16 volatile Iterator = 0  ;
u8  volatile DataCome[1500] ;
u8  x = 0 ;

void HESP8266_CallBack ( void ){

	/* Receive ESP8266 Response */
	DataCome[ Iterator ] = MUSART1_u8ReadDataRegister();
	/* ------------------ */
	Iterator++;
	MUSART1_voidClearFlags();

}

void HESP8266_voidInit ( void ){

	/* Set USART1 CallBack To Receive The Response Of The ESP8266 */
	MUSART1_voidSetCallBack( HESP8266_CallBack );

	while( HESP8266_voidValidateBuffer() == 0 ){

		/* Clear ESP8266 Buffer */
		HESP8266_voidClearBuffer();
		/* Sending AT Command To Check ESP8266 Is Working Or Not  */
		MUSART1_voidSendSrtingSynch( (u8 *)"AT\r\n" );
		MSTK_voidSetBusyWait(1000000);

	}

	/* Clear ESP8266 Buffer */
	HESP8266_voidClearBuffer();

	while( HESP8266_voidValidateBuffer() == 0 ){

		/* Clear ESP8266 Buffer */
		HESP8266_voidClearBuffer();
		/* Sending AT Command To Check ESP8266 Is Working Or Not  */
		MUSART1_voidSendSrtingSynch( (u8 *)"AT+CWMODE=3\r\n" );
		MSTK_voidSetBusyWait(1000000);

	}

	HESP8266_voidClearBuffer();

	while( HESP8266_voidValidateBuffer() == 0 ){

		/* Clear ESP8266 Buffer */
		HESP8266_voidClearBuffer();
		/* Sending AT Command To Check ESP8266 Is Working Or Not  */
		MUSART1_voidSendSrtingSynch( (u8 *)"AT+CIPMODE=0\r\n" );
		MSTK_voidSetBusyWait(1000000);

	}

}

void HESP8266_voidConnectToWiFi ( u8 * SSID , u8 * Password ){

	HESP8266_voidClearBuffer();

	while( HESP8266_voidValidateBuffer() == 0 ){

		/* Clear ESP8266 Buffer */
		HESP8266_voidClearBuffer();

		MUSART1_voidSendSrtingSynch( (u8 *) "AT+CWJAP=\"" );
		MUSART1_voidSendSrtingSynch( (u8 *) SSID );
		MUSART1_voidSendSrtingSynch( (u8 *) "\",\"" );
		MUSART1_voidSendSrtingSynch( (u8 *) Password);
		MUSART1_voidSendSrtingSynch( (u8 *) "\"\r\n");
		MSTK_voidSetBusyWait(1000000);

	}

}


void HESP8266_voidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port ){

	HESP8266_voidClearBuffer();

	while( HESP8266_voidValidateBuffer() == 0 ){

		/* Clear ESP8266 Buffer */
		HESP8266_voidClearBuffer();

		MUSART1_voidSendSrtingSynch( (u8 *) "AT+CIPSTART=\"TCP\",\"" );
		MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8Domain );
		MUSART1_voidSendSrtingSynch( (u8 *) "\"," );
		MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8Port );
		MUSART1_voidSendSrtingSynch( (u8 *) "\r\n" );

		MSTK_voidSetBusyWait(1000000);
	}

}

void HESP8266_voidSendHttpReq( u8 * Copy_u8ChannelID , u8 * Copy_u8Length , u8 * Copy_u8Value ){

	HESP8266_voidClearBuffer();

	MUSART1_voidSendSrtingSynch( (u8 *) "AT+CIPSEND=" );
	MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8Length );
	MUSART1_voidSendSrtingSynch( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait(1000000);

	HESP8266_voidClearBuffer();

	MUSART1_voidSendSrtingSynch( (u8 *) "GET http://" );
	MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8ChannelID );
	MUSART1_voidSendSrtingSynch( (u8 *) "/fota.php?state=" );
	MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8Value );
	MUSART1_voidSendSrtingSynch( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait(1000000);

}


u8 HESP8266_u8ReceiveHttpReq( u8 * Copy_u8ChannelID , u8 * Copy_u8Length ){

	HESP8266_voidClearBuffer();

	MUSART1_voidSendSrtingSynch( (u8 *) "AT+CIPSEND=" );
	MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8Length );
	MUSART1_voidSendSrtingSynch( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait(1000000);

	HESP8266_voidClearBuffer();

	MUSART1_voidSendSrtingSynch( (u8 *) "GET http://" );
	MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8ChannelID );
	MUSART1_voidSendSrtingSynch( (u8 *) "/asmaa.txt\r\n" );
	MSTK_voidSetBusyWait(1000000);

	return  DataCome[37] ;

}

static void HESP8266_voidClearBuffer ( void ){

	u16 LOC_u8Iterator1 = 0 ;
	Iterator            = 0 ;

	for( LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 1500 ; LOC_u8Iterator1++ ){

		DataCome[ LOC_u8Iterator1 ] = 0 ;

	}

}

static u8 HESP8266_voidValidateBuffer( void ){

	u8  LOC_u8Status    = 0 ;
	u16 LOC_u8Iterator1 = 0 ;

	for( LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 1500  ; LOC_u8Iterator1++ ){

		if( ( DataCome[ LOC_u8Iterator1 ] == 'O' )  && ( DataCome[ LOC_u8Iterator1 + 1 ] == 'K' ) ){

			LOC_u8Status = 1 ;
			break ;

		}

	}
	return LOC_u8Status ;

}
