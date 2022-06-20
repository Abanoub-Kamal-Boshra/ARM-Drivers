
#ifndef MPORT_INTERFACE_H_
#define MPORT_INTERFACE_H_

#define MPORT_u8_PORTA            0
#define MPORT_u8_PORTB            1
#define MPORT_u8_PORTC            2

#define MPORT_INPUT_ANLOG               0000
#define MPORT_INPUT_FLOATING            0100
#define MPORT_INPUT_PULLUP_PULLDOWN     1000

//For Speed 10
#define MPORT_OUTPUT_SPEED_10MHZ_PP     0001
#define MPORT_OUTPUT_SPEED_10MHZ_OD     0101
#define MPORT_OUTPUT_SPEED_10MHZ_AFPP   1001
#define MPORT_OUTPUT_SPEED_10MHZ_AFOD   1101

//For Speed 2
#define MPORT_OUTPUT_SPEED_2MHZ_PP      0010
#define MPORT_OUTPUT_SPEED_2MHZ_OD      0110
#define MPORT_OUTPUT_SPEED_2MHZ_AFPP    1010
#define MPORT_OUTPUT_SPEED_2MHZ_AFOD    1110

//For Speed 2
#define MPORT_OUTPUT_SPEED_50MHZ_PP     0011
#define MPORT_OUTPUT_SPEED_50MHZ_OD     0111
#define MPORT_OUTPUT_SPEED_50MHZ_AFPP   1011
#define MPORT_OUTPUT_SPEED_50MHZ_AFOD   1111


void MPORT_voidInit( void );
error_status MPORT_enumSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode );

#endif /* MPORT_INTERFACE_H_ */
