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

#include "SERVO_interface.h"


void main(void)
{
	///// Test the TIM4 CH1 for generate PWM
	MRCC_voidInitSysClock();		 				// enable clock of the processor
	MRCC_voidEnableClock(RCC_APB2 , RCC_IOPB_EN);  	// enable clock of PORTB
	MRCC_voidEnableClock(RCC_APB2 , RCC_AFIO_EN);	// enable clock of alternative function
	MRCC_voidEnableClock(RCC_APB1 , RCC_TIM4_EN);	// enable clock of timer4 for PWM
	
	// pin configuration
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN6 , GPIO_OUTPUT_SPEED_50MHZ_AFPP); 	// PIN_B6 for output PWM_CH1
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN7 , GPIO_OUTPUT_SPEED_50MHZ_AFPP); 	// PIN_B7 for output PWM_CH2
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN8 , GPIO_OUTPUT_SPEED_50MHZ_AFPP); 	// PIN_B8 for output PWM_CH3
	MGPIO_voidSetPinDirection(GPIO_PORTB , GPIO_PIN9 , GPIO_OUTPUT_SPEED_50MHZ_AFPP); 	// PIN_B9 for output PWM_CH4


	// enable the IRQ from NVIC
	MNVIC_u8EnableInterrupt(30); 					// Enable the INT for TIM4

	// setup the priority
	MNVIC_voidSetInterruptPriority(30 , 3 , 0);		// Priority for TIM4


	HSERVO_viodSetServoAngle(0 , SERVO_CHANNEL_1);
	HSERVO_viodSetServoAngle(180 , SERVO_CHANNEL_3);

	while(1)
	{

	}
}

