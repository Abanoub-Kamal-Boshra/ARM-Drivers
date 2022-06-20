/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	4 April 2021										*/
/************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"


/* global variable of type pointer to function
 * to store the address of a function to be execute by TIM3*/
static void (*TIM3_CallBack)(void);

/* global variable for Input Capture TIM4 CH1 */
volatile u16 Global_u16Tim4Ch1InputCaptures[2] ={0};
volatile u8  Global_u8Tim4Ch1Counter =1;
volatile u8  Global_u8Tim4Ch1IsCaptureDone = FALSE;

/* global variable for Input Capture TIM1 CH1 */
volatile u16 Global_u16Tim1Ch1InputCaptures[2] ={0};
volatile u8  Global_u8Tim1Ch1Counter =1;
volatile u8  Global_u8Tim1Ch1IsCaptureDone = FALSE;

/* Define Variable for interval mode to differenaciate single from periodic Interval */
static u8 TIM3_u8ModeOfInterval;


void MTIM2_voidSetBusyWaitMs(u32 Copy_u32MsNumber)
{
	u32 Copy_u32Count;
	/* configer the timer */
	TIM2->PSC = 800-1; 	// prescaler=800 at AHP=8MHz and so APB1=8MHz --> CNT_CLK=10KHZ & T=100us
	TIM2->ARR = 10-1 ;
	/* enable timer 2 */
	TIM2->CNT = 0;
	TIM2->CR1 = 0x1;
	
	/* wait for the timer flag is set */
	for(Copy_u32Count=0 ; Copy_u32Count<Copy_u32MsNumber ; Copy_u32Count++)
	{
		while(! GET_BIT(TIM2->SR , 0) );
		/* clear the flag */
		CLR_BIT(TIM2->SR , 0);
	}
	/* disable the timer */
	TIM2->CR1 = 0;
}    


void MTIM2_voidSetBusyWaitAccurateMs(u32 Copy_u32MsNumber)
{
	/* configer the timer */
	TIM2->PSC = 1000-1; 	// prescaler=1000 at AHP=8KHz and so APB1=8KHz --> CNT_CLK=8KHZ & T=125us
	TIM2->ARR = 8*Copy_u32MsNumber-1 ;
	/* enable timer 2 */
	TIM2->CNT = 0;
	TIM2->CR1 = 0x1;

	/* wait for the timer flag is set */
	while(! GET_BIT(TIM2->SR , 0) );
	/* clear the flag */
	CLR_BIT(TIM2->SR , 0);
	/* disable the timer */
	TIM2->CR1 = 0;
}


void MTIM2_voidSetBusyWaitUs(u32 Copy_u32UsNumber)
{
	/* configer the timer */
	TIM2->PSC = 4-1; 	                 // prescaler=4 at AHP=2MHz and so APB1=2MHz --> CNT_CLK=2MHZ & T=0.5us
	TIM2->ARR = 2*Copy_u32UsNumber-1;    //
	/* enable timer 2 */
	TIM2->CNT = 0;
	TIM2->CR1 = 0x1;
	
	/* wait for the timer flag is set */
	while(! GET_BIT(TIM2->SR , 0) );
	/* clear the flag */
	CLR_BIT(TIM2->SR , 0);
	/* disable the timer */
	TIM2->CR1 = 0;
}




void MTIM3_voidSetIntervalSingle(u16 Copy_16Ticks , void (*Copy_ptr)(void) )
{
	/* configer the timer */
	TIM3->PSC = TIM3_PRESCALER -1;		// Set the prescaler
	TIM3->ARR = Copy_16Ticks -1;		// load number of ticks

	/* enable timer 3 */
	TIM3->CNT = 0;
	TIM3->CR1 = 0x1;

	/* store the address of desired function on TIM3_CallBack variable */
	TIM3_CallBack = Copy_ptr;

	/* Set Mode to Single */
	TIM3_u8ModeOfInterval = TIM3_SINGLE_INTERVAL;

	/* enable the interrupt */
	SET_BIT(TIM3->DIER , 0);
}


void MTIM3_voidSetIntervalPeriodic(u16 Copy_16Ticks , void (*Copy_ptr)(void) )
{
	/* configer the timer */
	TIM3->PSC = TIM3_PRESCALER -1;		// Set the prescaler
	TIM3->ARR = Copy_16Ticks -1;		// load number of ticks

	/* enable timer 3 */
	TIM3->CNT = 0;
	TIM3->CR1 = 0x1;

	/* store the address of desired function on TIM3_CallBack variable */
	TIM3_CallBack = Copy_ptr;

	/* Set Mode to periodic */
	TIM3_u8ModeOfInterval = TIM3_PERIODIC_INTERVAL;

	/* enable the interrupt */
	SET_BIT(TIM3->DIER , 0);
}


u16 MTIM3_u16GetElapsedTime(void)
{
	return TIM3->CNT;
}


u16 MTIM3_u16GetRemainingTime(void)
{
	return (TIM3->ARR - TIM3->CNT);
}


void MTIM3_voidStopInterval(void)
{
	/* Disable the interrupt */
	CLR_BIT(TIM3->DIER , 0);
	/* clear the flag */
	CLR_BIT(TIM2->SR , 0);
	/* disable the timer */
	TIM2->CR1 = 0;
}




void MTIM1_f32Ch1Ch2InitMeasureTonPeriod(void)
{
	/* configer the timer */
	TIM1->PSC = TIM1_PRESCALER -1;		// Set the prescaler
	TIM1->ARR = 0xFFFF;					// set ARR for max value
	TIM1->CNT = 0 ;						// Clear counter

	/* capture is done ---> CH1 is rising edge and CH2 is falling edge */
	TIM1->CCER &=  ~0x2;
	TIM1->CCER |=  0x20;
	/* configure CH1 as direct input TI1 & CH2 as indirect input TI2 */
	//TIM1->CCMR1 |=  0x1;	//TIM1->CCMR1 &= ~0x2;
	//TIM1->CCMR1 &= ~0x10;	//TIM1->CCMR1 |=  0x20;
	/* no prescaler, capture is done each time an edge is detected on the capture input --> on CH1 & CH2 */
	//TIM1->CCMR1 &= ~0xC;	//TIM1->CCMR1 &= ~0xC00;
	/* No filter, sampling is done at fDTS --> on CH1 & CH2 */
	//TIM1->CCMR1 &= ~0xF0;	//TIM1->CCMR1 &= ~0xF000;
	TIM1->CCMR1 = 0x0201;

	/* configure the timer slave mode with TI1FP1 as reset signal */
	TIM1->SMCR = 0x54;

	/* Capture enable for CH1 & CH2 */
	TIM1->CCER |=  0x11;
	/* counter enable */
	TIM1->CR1  |= 0x1;
	/* interrupt enable for CH1 & CH2 */
	TIM1->DIER  |= 0x6;

} // end of function


f32 MTIM1_f32Ch1Ch2MeasureTonPeriod(void)
{
	volatile u16 Local_u16Capture;
	f32 Local_f32Timer1ClockResolution;
	volatile f32 Local_f32UserSignalTimeOnPeriod =0;

	if(Global_u8Tim1Ch1IsCaptureDone)
	{
		Local_u16Capture = Global_u16Tim1Ch1InputCaptures[1];

		Local_f32Timer1ClockResolution = 1.0/TIM1_CNT_CLK;
		Local_f32UserSignalTimeOnPeriod = Local_u16Capture * Local_f32Timer1ClockResolution;

		Global_u8Tim1Ch1IsCaptureDone = FALSE;
	}
	return Local_f32UserSignalTimeOnPeriod;
}





void MTIM4_f32Ch1InitMeasurePWM(void)
{
	/* configer the timer */
	TIM4->PSC = TIM4_PRESCALER -1;		// Set the prescaler
	TIM4->ARR = 0xFFFF;					// for maximum value to let us free in design
	TIM4->CNT = 0 ;						// Clear counter

	/* configure channel is configured as input,  IC1 is mapped on TI1 */
	TIM4->CCMR1 |=  0x1;
	TIM4->CCMR1 &= ~0x2;
	/* no prescaler, capture is done each time an edge is detected on the capture input */
	TIM4->CCMR1 &= ~0xC;
	/* No filter, sampling is done at fDTS */
	TIM4->CCMR1 &= ~0xF0;
	/* capture is done on a rising edge */
	TIM4->CCER &= ~0x2;

	/* Capture enable */
	TIM4->CCER |=  0x1;
	/* counter enable */
	TIM4->CR1  |= 0x1;
	/* interrupt enable */
	TIM4->DIER  |= 0x2;
}


f32 MTIM4_f32Ch1MeasurePWM(void)
{
	volatile u16 Local_u16CaptureDifference;
	f32 Local_f32Timer4ClockResolution;
	volatile f32 Local_f32UserSignalTimePeriod;
	volatile f32 Local_f32UserSignalFrequency =0;


	if(Global_u8Tim4Ch1IsCaptureDone)
	{
		if(Global_u16Tim4Ch1InputCaptures[1] > Global_u16Tim4Ch1InputCaptures[0])
		{
			Local_u16CaptureDifference = Global_u16Tim4Ch1InputCaptures[1] - Global_u16Tim4Ch1InputCaptures[0];
		}
		else
		{
			/// max_ARR = 0xFFFF
			Local_u16CaptureDifference = (0xFFFF - Global_u16Tim4Ch1InputCaptures[0]) + Global_u16Tim4Ch1InputCaptures[1];
		}

		Local_f32Timer4ClockResolution = 1.0/TIM4_CNT_CLK;
		Local_f32UserSignalTimePeriod = Local_u16CaptureDifference * Local_f32Timer4ClockResolution;
		Local_f32UserSignalFrequency  = 1.0 / Local_f32UserSignalTimePeriod;

		Global_u8Tim4Ch1IsCaptureDone = FALSE;
	}
	return Local_f32UserSignalFrequency;
}



void MTIM4_voidSetPWM(f32 Copy_f32Period , f32 Copy_f32DutySycle , u8 Copy_u8Channel)
{
	switch(Copy_u8Channel)
	{
	case TIM4_CHANNEL_1:/* To initialization */
						TIM4->PSC = TIM4_PRESCALER-1;
						/* 3. Program the period and the duty cycle respectively in ARR and CCRx registers */
							TIM4->ARR  = (Copy_f32Period * TIM4_CNT_CLK) -1;  // ARR = Period / ( T of one count ) --> Clk = AHB_Clk / PSC
							TIM4->CCR1 = (Copy_f32Period * (Copy_f32DutySycle / 100) ) * TIM4_CNT_CLK ;  // CCR1 = Ton / ( T of one count )
						/* 5. Select the counting mode:
						   a) PWM edge-aligned mode: the counter must be configured up-counting or downcounting
						   b) PWM center aligned mode: the counter mode must be center aligned counting
						   mode (CMS bits different from '00'). */
							TIM4->CR1 &= ~0x70;  // PWM edge-aligned mode & up-counting

						/* To configure the timer in this mode: */
						/* 1. Configure the output pin:
						 * a) Select the output mode by writing CCS bits in CCMRx register */
							TIM4->CCMR1 &= ~0x3 ;
						/* b) Select the polarity by writing the CCxP bit in CCER register. CC1P=0 */
							TIM4->CCER &= ~0x2 ;
						/* 2. Select the PWM mode (PWM1 or PWM2) by writing OCxM bits in CCMRx register. PWM1 is choosed */
							TIM4->CCMR1 &= ~0x70;
							TIM4->CCMR1 |= 0x60;

						/* 6. Enable the capture compare */
							SET_BIT(TIM4->CCER , 0);
						/* 7. Enable the counter. */
							TIM4->CNT = 0 ; 			// Clear timer counter
							SET_BIT(TIM4->CR1 , 0);
						break;

	case TIM4_CHANNEL_2:/* To initialization & configuration */
						TIM4->PSC = TIM4_PRESCALER-1;

						TIM4->ARR  = (Copy_f32Period * TIM4_CNT_CLK) -1;  // ARR = Period / ( T of one count ) --> Clk = AHB_Clk / PSC
						TIM4->CCR2 = (Copy_f32Period * (Copy_f32DutySycle / 100) ) * TIM4_CNT_CLK ;  // CCR1 = Ton / ( T of one count )

						TIM4->CR1 &= ~0x70;  // PWM edge-aligned mode & up-counting

						TIM4->CCMR1 &= ~0x300 ; // output mode

						TIM4->CCER &= ~0x20 ; // polarity selected active high

						TIM4->CCMR1 &= ~0x7000; // PWM1 mode
						TIM4->CCMR1 |= 0x6000;

						SET_BIT(TIM4->CCER , 4); // Enable the capture compare

						TIM4->CNT = 0 ; // Clear timer counter
						SET_BIT(TIM4->CR1 , 0); // Enable the counter
						break;

	case TIM4_CHANNEL_3:/* To initialization & configuration */
						TIM4->PSC = TIM4_PRESCALER-1;

						TIM4->ARR  = (Copy_f32Period * TIM4_CNT_CLK) -1;  // ARR = Period / ( T of one count ) --> Clk = AHB_Clk / PSC
						TIM4->CCR3 = (Copy_f32Period * (Copy_f32DutySycle / 100) ) * TIM4_CNT_CLK ;  // CCR1 = Ton / ( T of one count )

						TIM4->CR1 &= ~0x70;  // PWM edge-aligned mode & up-counting

						TIM4->CCMR2 &= ~0x3 ; // output mode

						TIM4->CCER &= ~0x200 ; // polarity selected active high

						TIM4->CCMR2 &= ~0x70; // PWM1 mode
						TIM4->CCMR2 |= 0x60;

						SET_BIT(TIM4->CCER , 8); // Enable the capture compare

						TIM4->CNT = 0 ; // Clear timer counter
						SET_BIT(TIM4->CR1 , 0); // Enable the counter
						break;

	case TIM4_CHANNEL_4:/* To initialization & configuration */
						TIM4->PSC = TIM4_PRESCALER-1;

						TIM4->ARR  = (Copy_f32Period * TIM4_CNT_CLK) -1;  // ARR = Period / ( T of one count ) --> Clk = AHB_Clk / PSC
						TIM4->CCR4 = (Copy_f32Period * (Copy_f32DutySycle / 100) ) * TIM4_CNT_CLK ;  // CCR1 = Ton / ( T of one count )

						TIM4->CR1 &= ~0x70;  // PWM edge-aligned mode & up-counting

						TIM4->CCMR2 &= ~0x300 ; // output mode

						TIM4->CCER &= ~0x2000 ; // polarity selected active high

						TIM4->CCMR2 &= ~0x7000; // PWM1 mode
						TIM4->CCMR2 |= 0x6000;

						SET_BIT(TIM4->CCER , 12); // Enable the capture compare

						TIM4->CNT = 0 ; // Clear timer counter
						SET_BIT(TIM4->CR1 , 0); // Enable the counter

	} // end switch case
} // end the function





/************************************************************************************/
/*									 ISRs of TIMx 									*/
							   /***********************/

/* used for execute a function after an elapsed time */
void TIM3_IRQHandler(void)
{

	/* to ensure that IRQ done only one time (single interval) */
	if(TIM3_SINGLE_INTERVAL == TIM3_u8ModeOfInterval)
	{
		/* Disable the interrupt */
		CLR_BIT(TIM3->DIER , 0);
		/* disable the timer */
		TIM3->CR1 = 0;
	}

	/* execute the required function passed from the main.c file */
	TIM3_CallBack();

	/* clear the flag */
	CLR_BIT(TIM3->SR , 0);

}


/* used for input capture mode to read frequency and time period for a user signal (measure PWM signal) */
void TIM4_IRQHandler(void)
{
#if TIM4_USAGE == TIM4_READ_PWM
	if(! Global_u8Tim4Ch1IsCaptureDone)
	{
		if(1 == Global_u8Tim4Ch1Counter)
		{
			Global_u16Tim4Ch1InputCaptures[0] = TIM4->CCR1 ;
			Global_u8Tim4Ch1Counter++;
		}
		else if(2 == Global_u8Tim4Ch1Counter)
		{
			Global_u16Tim4Ch1InputCaptures[1] = TIM4->CCR1;
			Global_u8Tim4Ch1Counter = 1;
			Global_u8Tim4Ch1IsCaptureDone = TRUE;
		}
	}
#endif
}


void TIM1_CC_IRQHandler(void)
{
	if(! Global_u8Tim1Ch1IsCaptureDone)
	{
		if(1 == Global_u8Tim1Ch1Counter)
		{
			Global_u16Tim1Ch1InputCaptures[0] = TIM1->CCR1 ;
			Global_u8Tim1Ch1Counter++;
		}
		else if(2 == Global_u8Tim1Ch1Counter)
		{
			Global_u16Tim1Ch1InputCaptures[1] = TIM1->CCR2;
			Global_u8Tim1Ch1Counter = 1;
			Global_u8Tim1Ch1IsCaptureDone = TRUE;
		}
	}
} // end the IRQ

