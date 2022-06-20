


#ifndef ESP8266_INTERFACE_H_
#define ESP8266_INTERFACE_H_

void HESP8266_voidInit            ( void                                                    ) ;
void HESP8266_voidConnectToWiFi   ( u8 * SSID , u8 * Password                               ) ;
void HESP8266_voidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port                   ) ;
u8 HESP8266_u8ReceiveHttpReq( u8 * Copy_u8FileID , u8 * Copy_u8Length );
void HESP8266_voidSendHttpReq     ( u8 * Copy_u8ChannelID , u8 * Copy_u8Length , u8 * Copy_u8Value );
void HESP8266_voidSendHttpReq2( u8 * Copy_u8ChannelID , u8 * Copy_u8Length ,u8 * Copy_u8Length2, u8 * Copy_u8Value );
void HESP8266_voidSendHttpReq3 ( u8 * Copy_u8ChannelID , u8 * Copy_u8Length , u8*Copy_u8Value) ;
void HESP8266_voidSendHttpReq4(  u8 * Copy_u8Length) ;
void HESP8266_voidSendHttpReq5( u8*Copy_u8temprature,u8*Copy_humidity,u8*Copy_gas);
void CIP_send(void) ;


/*********************************************************************/
void HESP8266_voidCIPsend(u8 * Copy_u8Length);
void HESP8266_voidNaturalgas(u8* Copy_u8Value);
void HESP8266_voidCogas(u8* Copy_u8Value);
void HESP8266_voidStealingSys(u8* Copy_u8Value);
void HESP8266_voidroom1(u8* Copy_u8Value);
void HESP8266_voidroom2(u8* Copy_u8Value);

u8  N(u8 Copy_u8Port , u8 Copy_u8Pin);     //Naturalgas   B0
u8  C(u8 Copy_u8Port , u8 Copy_u8Pin);     //Cogas        B1
u8  S(u8 Copy_u8Port , u8 Copy_u8Pin);     //StealingSys  B15
u8  R1(u8 Copy_u8Port , u8 Copy_u8Pin);    //room1        B5
u8  R2(u8 Copy_u8Port , u8 Copy_u8Pin);    //room2        B6

#endif /* ESP8266_INTERFACE_H_ */
