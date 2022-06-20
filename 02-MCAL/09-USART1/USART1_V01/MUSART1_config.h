
#ifndef USART1_CONFIG_H_
#define USART1_CONFIG_H_


/* System Clock From 8MHZ Up To 72MHZ */

#define F_CPU                    8000000UL

/* MUSART BaudRate */

#define MUSART1_BAUD_RATE        (u32)115200

/* Options:    1- MUSART1_DISABLE
               2- MUSART1_ENABLE
                        		   */

#define MUSART1_STATUS            MUSART1_ENABLE

/* Options:    1- MUSART1_EIGHT_BIT_WORD_LENGTH
               2- MUSART1_NINE_BIT_WORD_LENGTH
                        		                */

#define MUSART1_WORD_LENGTH       MUSART1_EIGHT_BIT_WORD_LENGTH

/* Options:    1- MUSART1_PARITY_DISABLE
               2- MUSART1_EVEN_PARITY
               3- MUSART1_ODD_PARITY
                        		                */

#define MUSART1_PARITY            MUSART1_PARITY_DISABLE

/* Options:    1- MUSART1_INTERRUPT_DISABLE
               2- MUSART1_TXE_INTERRUPT_ENABLE
               3- MUSART1_TCE_INTERRUPT_ENABLE
               4- MUSART1_RXNE_INTERRUPT_ENABLE
                        		                */

#define MUSART1_INTERRUPT         MUSART1_RXNE_INTERRUPT_ENABLE

/* Options:    1- MUSART1_TRANSMITTER_DISABLE
               2- MUSART1_TRANSMITTER_ENABLE

                        		                */

#define MUSART1_TRANSMITTER       MUSART1_TRANSMITTER_ENABLE

/* Options:    1- MUSART1_RECEIVER_DISABLE
               2- MUSART1_RECEIVER_ENABLE

                        		                */

#define MUSART1_RECEIVER          MUSART1_RECEIVER_ENABLE

/* Options:    1- MUSART1_ONE_STOP_BIT
               2- MUSART1_HALF_STOP_BIT
               3- MUSART1_TWO_STOP_BIT
               4- MUSART1_ONE_AND_HALF_STOP_BIT
                        		                */

#define MUSART1_STOP_BITS         MUSART1_ONE_STOP_BIT


#endif /* USART1_CONFIG_H_ */
