


#ifndef ESP8266_INTERFACE_H_
#define ESP8266_INTERFACE_H_

void HESP8266_voidInit            ( void                                                    ) ;
void HESP8266_voidConnectToWiFi   ( u8 * SSID , u8 * Password                               ) ;
void HESP8266_voidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port                   ) ;
u8   HESP8266_u8ReceiveHttpReq    ( u8 * Copy_u8ChannelID , u8 * Copy_u8Length              ) ;
void HESP8266_voidSendHttpReq     ( u8 * Copy_u8ChannelID , u8 * Copy_u8Length , u8 * Copy_u8Value );

#endif /* ESP8266_INTERFACE_H_ */
