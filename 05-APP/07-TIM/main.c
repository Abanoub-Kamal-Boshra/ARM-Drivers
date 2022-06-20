/*
 * main.c
 *
 *  Created on: Apr 4, 2021
 *      Author: Abanoub Kamal
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "GPIO_interface.h"
#include "TIM_interface.h"
#include "STK_interface.h"


#include "LED_interface.h"

void HUltraSonicTriger(void);
void toggleLed(void);
void main(void)
{
/*
	///// Test the timer2 for delay
	MRCC_voidInitSysClock();		 				// enable clock of the processor
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN);  	// enable clock of PORTA
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM2_EN);  	// enable clock of timer2

	// pin configuration for test delay with TIM2
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP); 		// PIN_A0 is output

	// enable the IRQ from NVIC
	MNVIC_u8EnableInterrupt(28); 					// Enable the INT for TIM2

	// setup the priority
	MNVIC_voidSetInterruptPriority(28 , 3 , 0);		// Priority for TIM2
*/
/*
	///// Test the timer3 for
	MRCC_voidInitSysClock();		 				// enable clock of the processor
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN);  	// enable clock of PORTA
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM3_EN);  	// enable clock of timer3

	// pin configuration for test delay with TIM6
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP); 		// PIN_A0 is output

	// enable the IRQ from NVIC
	MNVIC_u8EnableInterrupt(29); 					// Enable the INT for TIM3

	// setup the priority
	MNVIC_voidSetInterruptPriority(29 , 3 , 0);		// Priority for TIM3

	MTIM3_voidSetIntervalSingle(1000 , func);
*/
/*
	///// Test the TIM4 CH1 for INPUT CAPTURE
	volatile f32 Local_f32Frepuncy = 0;
	MRCC_voidInitSysClock();		 				// enable clock of the processor
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN);  	// enable clock of PORTA
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPB_EN);  	// enable clock of PORTB
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM4_EN);  	// enable clock of timer4
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM2_EN);  	// enable clock of timer2

	// pin configuration for test delay with TIM5
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN6 , GPIO_INPUT_FLOATION); 		// PIN_B6 is Floating
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP); 		// PIN_A0 for output SW PWM

	// init the Input Caputer mode for TIM4
	MTIM4_f32Ch1InitMeasurePWM();

	// enable the IRQ from NVIC
	MNVIC_u8EnableInterrupt(30); 					// Enable the INT for TIM4

	// setup the priority
	MNVIC_voidSetInterruptPriority(30 , 3 , 0);		// Priority for TIM4
*/

/*
	///// Test the TIM1 CH1 for INPUT CAPTURE for Ultrasonic
	volatile f32 Local_f32TonPeriod = 0;
	MRCC_voidInitSysClock();		 				// enable clock of the processor
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN);  	// enable clock of PORTA
	MRCC_voidEnableClock(RCC_APB2 , RCC_TIM1_EN);  	// enable clock of timer1
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM2_EN);  	// enable clock of timer2 for busy wait
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM3_EN);	// enable clock of timer3 for trigger source for ultrasonec

	// pin configuration for test delay with TIM1
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN8 , GPIO_INPUT_FLOATION); 		// PIN_A8 is Floating for TIM1
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP); 	// PIN_A0 for output trigger

	// init the Input Caputer mode for TIM1_CC
	MTIM1_f32Ch1Ch2InitMeasureTonPeriod();

	// enable the IRQ from NVIC
	MNVIC_u8EnableInterrupt(27); 					// Enable the INT for TIM1_CC
	MNVIC_u8EnableInterrupt(29); 					// Enable the INT for TIM3


	// setup the priority
	MNVIC_voidSetInterruptPriority(27 , 3 , 0);		// Priority for TIM1
	MNVIC_voidSetInterruptPriority(29 , 3 , 0);		// Priority for TIM3


	MSTK_voidSetIntervalPeriodic(100000 , HUltraSonicTriger);		// Send Trigger with 10Hz frequency
*/
/*
	///// Test the TIM4 CH1 for generate PWM
	MRCC_voidInitSysClock();		 				// enable clock of the processor
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPB_EN);  	// enable clock of PORTB
	MRCC_voidEnableClock(RCC_APB2 , RCC_AFIO_EN);	// enable clock of alternative function
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM4_EN);	// enable clock of timer4 for PWM
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM2_EN);  	// enable clock of timer2 for busy wait

	// pin configuration
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN6 , GPIO_OUTPUT_SPEED_50MHZ_AFPP); 	// PIN_B6 for output PWM_CH1
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN7 , GPIO_OUTPUT_SPEED_50MHZ_AFPP); 	// PIN_B7 for output PWM_CH2
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN8 , GPIO_OUTPUT_SPEED_50MHZ_AFPP); 	// PIN_B8 for output PWM_CH3
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN9 , GPIO_OUTPUT_SPEED_50MHZ_AFPP); 	// PIN_B9 for output PWM_CH4


	// enable the IRQ from NVIC
	MNVIC_u8EnableInterrupt(30); 					// Enable the INT for TIM4

	// setup the priority
	MNVIC_voidSetInterruptPriority(30 , 3 , 0);		// Priority for TIM4

	// generate PWM
	//MTIM4_voidSetPWM( 0.02  , 5 );
	f32 i;
*/
	////// test TIM3 for periodic and single interval
	MRCC_voidInitSysClock();		 				// enable clock of the processor
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPA_EN);  	// enable clock of PORTA
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM3_EN);	// enable clock of timer3
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM2_EN);  	// enable clock of timer2 for busy wait

	MNVIC_u8EnableInterrupt(29); 					// Enable the INT for TIM3

	MNVIC_voidSetInterruptPriority(29, 3, 0);

	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP); 	// PIN_A0 for output

	MTIM3_voidSetIntervalSingle(2000 , toggleLed);

	while(1)
	{
/*
 	 	///// Test the timer2 for delay
		MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_HIGH);
		MTIM2_voidSetBusyWaitAccurateMs(8000);
		MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_LOW);
		MTIM2_voidSetBusyWaitAccurateMs(1000);
*/
/*
		////// test the timer for Input Capture
		MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_HIGH);
		MTIM2_voidSetBusyWaitMs(1000);
		MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_LOW);
		MTIM2_voidSetBusyWaitMs(500);
*/
/*
		////// test the ultrasonic

			Local_f32TonPeriod = MTIM1_f32Ch1Ch2MeasureTonPeriod();
*/
/*
		// test PWM
		for(i = 5 ; i<=13 ; i+=2)
		{
			MTIM4_voidSetPWM( 0.02  , i , TIM4_CHANNEL_1);
			MTIM4_voidSetPWM( 0.02  , i , TIM4_CHANNEL_2);
			MTIM4_voidSetPWM( 0.02  , i , TIM4_CHANNEL_3);
			MTIM4_voidSetPWM( 0.02  , i , TIM4_CHANNEL_4);
			MTIM2_voidSetBusyWaitAccurateMs(600);
		}
*/


	}
}

void HUltraSonicTriger(void)
{
	MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_HIGH);
	MTIM2_voidSetBusyWaitUs(10);
	MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_LOW);
}

void toggleLed(void)
{
	MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_HIGH);
	MTIM2_voidSetBusyWaitMs(1000);
	MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_PIN_LOW);
}
