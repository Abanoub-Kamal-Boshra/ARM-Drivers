
#ifndef USART1_INTERFACE_H_
#define USART1_INTERFACE_H_

#define MUSART1_DISABLE                     0
#define MUSART1_ENABLE                      1

#define MUSART1_EIGHT_BIT_WORD_LENGTH       0
#define MUSART1_NINE_BIT_WORD_LENGTH        1

#define MUSART1_PARITY_DISABLE              0
#define MUSART1_EVEN_PARITY                 1
#define MUSART1_ODD_PARITY                  2

#define MUSART1_INTERRUPT_DISABLE           0
#define MUSART1_TXE_INTERRUPT_ENABLE        1
#define MUSART1_TCE_INTERRUPT_ENABLE        3
#define MUSART1_RXNE_INTERRUPT_ENABLE       5

#define MUSART1_TRANSMITTER_DISABLE         0
#define MUSART1_TRANSMITTER_ENABLE          1

#define MUSART1_RECEIVER_DISABLE            0
#define MUSART1_RECEIVER_ENABLE             1

#define MUSART1_ONE_STOP_BIT                0
#define MUSART1_HALF_STOP_BIT               1
#define MUSART1_TWO_STOP_BIT                2
#define MUSART1_ONE_AND_HALF_STOP_BIT       3


void MUSART1_voidInit             ( void                ) ;
void MUSART1_voidSendCharSync     ( u8 Copy_u8Char      ) ;
void MUSART1_voidSendSrtingSynch  ( u8 * Copy_ptrString ) ;
u8   MUSART1_u8RecCharSynch       ( void                ) ;
u8 * MUSART1_PtrReadStringSynch   ( void                ) ;
void MUSART1_voidSetCallBack      ( void (*ptr) (void)  ) ;
u8   MUSART1_u8ReadDataRegister     ( void              ) ;
void MUSART1_voidClearFlags       ( void                ) ;

#endif /* USART1_INTERFACE_H_ */
