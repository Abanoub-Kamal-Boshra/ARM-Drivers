

#ifndef MPORT_PRIVATE_H_
#define MPORT_PRIVATE_H_

#define MGPIOA_BASSE_ADDRESS 0x40010800
#define MGPIOB_BASSE_ADDRESS 0x40010C00
#define MGPIOC_BASSE_ADDRESS 0x40011000


#define MGPIOA_CRL *((volatile u32 *)( MGPIOA_BASSE_ADDRESS + 0x00 ) )
#define MGPIOA_CRH *((volatile u32 *)( MGPIOA_BASSE_ADDRESS + 0x04 ) )
#define MGPIOA_ODR *((volatile u32 *)( MGPIOA_BASSE_ADDRESS + 0x0C ) )


#define MGPIOB_CRL *((volatile u32 *)( MGPIOB_BASSE_ADDRESS + 0x00 ) )
#define MGPIOB_CRH *((volatile u32 *)( MGPIOB_BASSE_ADDRESS + 0x04 ) )
#define MGPIOB_ODR *((volatile u32 *)( MGPIOB_BASSE_ADDRESS + 0x0C ) )

#define MGPIOC_CRL *((volatile u32 *)( MGPIOC_BASSE_ADDRESS + 0x00 ) )
#define MGPIOC_CRH *((volatile u32 *)( MGPIOC_BASSE_ADDRESS + 0x04 ) )
#define MGPIOC_ODR *((volatile u32 *)( MGPIOC_BASSE_ADDRESS + 0x0C ) )


#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)	    0b##b7##b6##b5##b4##b3##b2##b1##b0


#define PORTA_DIR_L 		CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTA_DIR_H 	    CONC(PORTA_PIN15_DIR,PORTA_PIN14_DIR,PORTA_PIN13_DIR,PORTA_PIN12_DIR,PORTA_PIN11_DIR,PORTA_PIN10_DIR,PORTA_PIN9_DIR,PORTA_PIN8_DIR)

#define PORTB_DIR_L 		CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTB_DIR_H 		CONC(PORTB_PIN15_DIR,PORTB_PIN14_DIR,PORTB_PIN13_DIR,PORTB_PIN12_DIR,PORTB_PIN11_DIR,PORTB_PIN10_DIR,PORTB_PIN9_DIR,PORTB_PIN8_DIR)

#define PORTC_DIR_H			CONC(PORTC_PIN15_DIR,PORTC_PIN14_DIR,PORTC_PIN13_DIR,PORTC_PIN13_DIR,PORTC_PIN13_DIR,PORTC_PIN13_DIR,PORTC_PIN13_DIR,PORTC_PIN13_DIR)





#define PORTA_INITIAL_VALUE_L		CONC(PORTA_PIN7_INITIAL_VALUE,PORTA_PIN6_INITIAL_VALUE,PORTA_PIN5_INITIAL_VALUE,PORTA_PIN4_INITIAL_VALUE,PORTA_PIN3_INITIAL_VALUE,PORTA_PIN2_INITIAL_VALUE,PORTA_PIN1_INITIAL_VALUE,PORTA_PIN0_INITIAL_VALUE)
#define PORTA_INITIAL_VALUE_H		CONC(PORTA_PIN15_INITIAL_VALUE,PORTA_PIN14_INITIAL_VALUE,PORTA_PIN13_INITIAL_VALUE,PORTA_PIN12_INITIAL_VALUE,PORTA_PIN11_INITIAL_VALUE,PORTA_PIN10_INITIAL_VALUE,PORTA_PIN9_INITIAL_VALUE,PORTA_PIN8_INITIAL_VALUE)

#define PORTB_INITIAL_VALUE_L		CONC(PORTB_PIN7_INITIAL_VALUE,PORTB_PIN6_INITIAL_VALUE,PORTB_PIN5_INITIAL_VALUE,PORTB_PIN4_INITIAL_VALUE,PORTB_PIN3_INITIAL_VALUE,PORTB_PIN2_INITIAL_VALUE,PORTB_PIN1_INITIAL_VALUE,PORTB_PIN0_INITIAL_VALUE)
#define PORTB_INITIAL_VALUE_H		CONC(PORTB_PIN15_INITIAL_VALUE,PORTB_PIN14_INITIAL_VALUE,PORTB_PIN13_INITIAL_VALUE,PORTB_PIN12_INITIAL_VALUE,PORTB_PIN11_INITIAL_VALUE,PORTB_PIN10_INITIAL_VALUE,PORTB_PIN9_INITIAL_VALUE,PORTB_PIN8_INITIAL_VALUE)


#define PORTC_INITIAL_VALUE_H		CONC(PORTC_PIN15_INITIAL_VALUE,PORTC_PIN14_INITIAL_VALUE,PORTC_PIN13_INITIAL_VALUE,PORTC_PIN13_INITIAL_VALUE,PORTC_PIN13_INITIAL_VALUE,PORTC_PIN13_INITIAL_VALUE,PORTC_PIN13_INITIAL_VALUE,PORTC_PIN13_INITIAL_VALUE)



void MPORT_voidInit( void );


#endif /* MPORT_PRIVATE_H_ */
