#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include    "GPIO_interface.h"
#include    "STK_interface.h"
#include    "AFIO_interface.h"
#include    "NVIC_interface.h"
#include	"TIM_interface.h"

#include	"ULTRASONIC_interface.h"
#include	"ULTRASONIC_private.h"
#include	"ULTRASONIC_config.h"



void HUltrasonicInti(void)
{
	// init the Input Caputer mode for TIM1_CC
	MTIM1_f32Ch1Ch2InitMeasureTonPeriod();


	// enable the IRQ from NVIC
	MNVIC_u8EnableInterrupt(27); 					// Enable the INT for TIM1_CC
	MNVIC_u8EnableInterrupt(29); 					// Enable the INT for TIM3
	MNVIC_u8EnableInterrupt(28); 					// Enable the INT for TIM2


	// setup the priority
	MNVIC_voidSetInterruptPriority(27 , 1 , 0);		// Priority for TIM1
	MNVIC_voidSetInterruptPriority(29 , 3 , 0);		// Priority for TIM3
	MNVIC_voidSetInterruptPriority(28 , 2 , 0);		// Priority for TIM2

}
void HUltraSonicTriger(void)
{
	MGPIO_voidSetPinValue(TRIGGER_PIN , GPIO_PIN_HIGH);
	MTIM2_voidSetBusyWaitUs(10);
	MGPIO_voidSetPinValue(TRIGGER_PIN, GPIO_PIN_LOW);
}

f32 HUltrasonicReturnDistance(void)
{
	volatile f32 Local_f32TonPeriod ;
	////// test the ultrasonic
	Local_f32TonPeriod = MTIM1_f32Ch1Ch2MeasureTonPeriod();
	volatile f32 distance =( Local_f32TonPeriod *340 /2)*100;

	return distance;
}
