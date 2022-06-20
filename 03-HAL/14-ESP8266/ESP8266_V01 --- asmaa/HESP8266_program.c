

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART1_interface.h"
#include "HESP8266_private.h"
#include "HESP8266_interface.h"
//#include "HESP8266_private.h"

#include "STK_interface.h"

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


			HESP8266_voidClearBuffer();


			MUSART1_voidSendSrtingSynch( (u8 *)"AT+CWMODE=1\r\n" );
			MUSART1_voidSendSrtingSynch( (u8 *)"AT+CIPMUX=0\r\n" );
			MSTK_voidSetBusyWait(1000000);

		}
	HESP8266_voidClearBuffer();



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


void HESP8266_voidConnectToSrvTcp ( u8 * Copy_u8thingspeak , u8 * Copy_u8Port ){

	HESP8266_voidClearBuffer();

	while( HESP8266_voidValidateBuffer() == 0 ){

		/* Clear ESP8266 Buffer */
		HESP8266_voidClearBuffer();

		MUSART1_voidSendSrtingSynch( (u8 *) "AT+CIPSTART=\"TCP\",\"" );
		MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8thingspeak  );
		MUSART1_voidSendSrtingSynch( (u8 *) "\"," );
		MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8Port );
		MUSART1_voidSendSrtingSynch( (u8 *) "\r\n" );

		MSTK_voidSetBusyWait(1000000);
	}

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


void HESP8266_voidCIPsend(u8 * Copy_u8Length)
{
	u8	LOC_U8Result=0 ;
   while(LOC_U8Result==0 )
    {
    	HESP8266_voidClearBuffer();
		MUSART1_voidSendSrtingSynch( (u8 *) "AT+CIPSEND=" );
		MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8Length );
		MUSART1_voidSendSrtingSynch( (u8 *) "\r\n" );
		MSTK_voidSetBusyWait(1000000);
		LOC_U8Result = HESP8266_voidValidateBuffer() ;

		HESP8266_voidClearBuffer();
    }
}

void HESP8266_voidNaturalgas(u8* Copy_u8Value)
{

	u8	LOC_U8Result=0 ;
while(LOC_U8Result==0 )
{
	   MUSART1_voidSendSrtingSynch( (u8 *) "GET /update?api_key=F4EJ50ZYJNUACA8X&field1=");
	   MUSART1_voidSendSrtingSynch( (u8*) Copy_u8Value);

		MUSART1_voidSendSrtingSynch( (u8 *) "\r\n\r\n\r\n\r\n" );
		MSTK_voidSetBusyWait(1000000);
		LOC_U8Result = HESP8266_voidValidateBuffer() ;
}
}

void HESP8266_voidCogas(u8* Copy_u8Value)
{
	u8	LOC_U8Result=0 ;
while(LOC_U8Result==0 )
{
	   MUSART1_voidSendSrtingSynch( (u8 *) "GET /update?api_key=F4EJ50ZYJNUACA8X&field2=");
	   MUSART1_voidSendSrtingSynch( (u8*) Copy_u8Value);

		MUSART1_voidSendSrtingSynch( (u8 *) "\r\n\r\n\r\n\r\n" );
		MSTK_voidSetBusyWait(1000000);
		LOC_U8Result = HESP8266_voidValidateBuffer() ;
}
}

void HESP8266_voidStealingSys(u8* Copy_u8Value)
{
	u8	LOC_U8Result=0 ;
while(LOC_U8Result==0 )
{
	   MUSART1_voidSendSrtingSynch( (u8 *) "GET /update?api_key=F4EJ50ZYJNUACA8X&field3=");
	   MUSART1_voidSendSrtingSynch( (u8*) Copy_u8Value);

		MUSART1_voidSendSrtingSynch( (u8 *) "\r\n\r\n\r\n\r\n" );
		MSTK_voidSetBusyWait(1000000);
		LOC_U8Result = HESP8266_voidValidateBuffer() ;
}
}
void HESP8266_voidroom1(u8* Copy_u8Value)
{
	u8	LOC_U8Result=0 ;
while(LOC_U8Result==0 )
{
	   MUSART1_voidSendSrtingSynch( (u8 *) "GET /update?api_key=F4EJ50ZYJNUACA8X&field4=");
	   MUSART1_voidSendSrtingSynch( (u8*) Copy_u8Value);

		MUSART1_voidSendSrtingSynch( (u8 *) "\r\n\r\n\r\n\r\n" );
		MSTK_voidSetBusyWait(1000000);
		LOC_U8Result = HESP8266_voidValidateBuffer() ;
}
}
void HESP8266_voidroom2(u8* Copy_u8Value)
{
	u8	LOC_U8Result=0 ;
while(LOC_U8Result==0 )
{
	   MUSART1_voidSendSrtingSynch( (u8 *) "GET /update?api_key=F4EJ50ZYJNUACA8X&field5=");
	   MUSART1_voidSendSrtingSynch( (u8*) Copy_u8Value);

		MUSART1_voidSendSrtingSynch( (u8 *) "\r\n\r\n\r\n\r\n" );
		MSTK_voidSetBusyWait(1000000);
		LOC_U8Result = HESP8266_voidValidateBuffer() ;
}
}


/******Natural_gas pinB0********Salma*********/
u8  N(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 status = MGPIO_u8GetPinValue(Copy_u8Port , Copy_u8Pin );
		if (status == 1)
		{
			HESP8266_voidNaturalgas((u8*) "1");
		}
		else
		{
			HESP8266_voidNaturalgas((u8*) "0");
		}
	return status;
}

/******Co_gas pinB1************Salma*****/
u8  C(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 status = MGPIO_u8GetPinValue(Copy_u8Port , Copy_u8Pin );
		if (status == 1)
		{
			HESP8266_voidCogas((u8*) "1");
		}
		else
		{
			HESP8266_voidCogas((u8*) "0");
		}
	return status;
}

/******Stealing_sys pinB15************Adel*****/
u8  S(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 status = MGPIO_u8GetPinValue(Copy_u8Port , Copy_u8Pin );
		if (status == 1)
		{
			HESP8266_voidStealingSys((u8*) "1");
		}
		else
		{
			HESP8266_voidStealingSys((u8*) "0");
		}
	return status;
}

/******fire_room1 pinB5***********Salma******/
u8  R1(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 status = MGPIO_u8GetPinValue(Copy_u8Port , Copy_u8Pin );
		if (status == 1)
		{
			HESP8266_voidroom1((u8*) "1");
		}
		else
		{
			HESP8266_voidroom1((u8*) "0");
		}
	return status;
}

/******fire_room2 pinB6************Salma*****/
u8  R2(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 status = MGPIO_u8GetPinValue(Copy_u8Port , Copy_u8Pin );
		if (status == 1)
		{
			HESP8266_voidroom2((u8*) "1");
		}
		else
		{
			HESP8266_voidroom2((u8*) "0");
		}
	return status;
}

/**********************Efraim*************************************************************/

u8 HESP8266_u8ReceiveHttpReq( u8 * Copy_u8FileID , u8 * Copy_u8Length ){

	HESP8266_voidClearBuffer();
while(HESP8266_voidValidateBuffer()==0 )
{
	MUSART1_voidSendSrtingSynch( (u8 *) "AT+CIPSEND=" );
	MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8Length );
	MUSART1_voidSendSrtingSynch( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait(1000000);
}
	HESP8266_voidClearBuffer();
while(HESP8266_voidValidateBuffer()==0 )
{
	MUSART1_voidSendSrtingSynch( (u8 *) "GET http://efraimyousef3.freevar.com/" );
	MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8FileID );
	MUSART1_voidSendSrtingSynch( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait(1000000);
}
	return  DataCome[37] ;

}

void CIP_send(void)
{

	u8	LOC_U8Result=0 ;
while(LOC_U8Result==0 )
{
    	HESP8266_voidClearBuffer();
		MUSART1_voidSendSrtingSynch( (u8 *) "AT+CIPSEND=95\r\n" );
		MSTK_voidSetBusyWait(1000000);
		LOC_U8Result = HESP8266_voidValidateBuffer() ;
}
		HESP8266_voidClearBuffer();
}

void HESP8266_voidSendHttpReq5( u8*Copy_u8temprature,u8*Copy_humidity,u8*Copy_gas)
{
	u8	LOC_U8Result=0 ;

while(LOC_U8Result==0 )
{

	    MUSART1_voidSendSrtingSynch( (u8 *) "GET /index.php?tmp=");
	    MUSART1_voidSendSrtingSynch( (u8 *) Copy_u8temprature);
	    MUSART1_voidSendSrtingSynch( (u8 *) "&hum=");
	    MUSART1_voidSendSrtingSynch( (u8 *) Copy_humidity);
	    MUSART1_voidSendSrtingSynch( (u8 *) "&gas=");
	    MUSART1_voidSendSrtingSynch( (u8 *) Copy_gas);



	    MUSART1_voidSendSrtingSynch( (u8 *) " HTTP/1.1\r\nHost: efraimyousef3.freevar.com\r\n\r\n");

		MSTK_voidSetBusyWait(1000000);
		LOC_U8Result = HESP8266_voidValidateBuffer() ;
}
}

