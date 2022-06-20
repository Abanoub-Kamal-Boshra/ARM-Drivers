/***********************************************************/
/*** Author  :  Solyma                      ****************/
/*** ADC_Private            			    ****************/
/*** Date    : 14/4/2021                     ****************/
/*** Version :  01                          ****************/
/***********************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


void ADC_voidInit( u8 Copy_u8Channel , u8 Copy_u8Sample_Time );/********(USED)*********/
/*
EX : 
void ADC_voidInit(      ADC_CH0      ,   TIME_14_CYCLES      );
*/
/*
(1) Copy_u8Channel    >>>   choosing the channel 
*/
#define ADC_CH0   0
#define ADC_CH1   1
#define ADC_CH2   2
#define ADC_CH3	  3 
#define ADC_CH4   4
#define ADC_CH5   5
#define ADC_CH6   6
#define ADC_CH7   7
#define ADC_CH8   8 
#define ADC_CH9   9
#define ADC_CH10  10
#define ADC_CH11  11
#define ADC_CH12  12
#define ADC_CH13  13
#define ADC_CH14  14
#define ADC_CH15  15
#define ADC_CH16  16
#define ADC_CH17  17
/*		****Note****  : 	ADC1 analog Channel 16 and Channel 17 are internally connected to the temperature 
												sensor and to VREFINT, respectively
*/

/*
(2) Copy_u8Sample_Time
Select the sample time individually for each channel
The total conversion time is calculated as follows:
        ( Tconv = Sampling time + 12.5 cycles)
*/
#define ADC_SAMPLE_TIME    TIME_252_CYCLES  //As an example
/*Choose one of these :  0- TIME_14_CYCLES
						 1- TIME_20_CYCLES
						 2- TIME_26_CYCLES
						 3- TIME_41_CYCLES
						 4- TIME_54_CYCLES
						 5- TIME_68_CYCLES
						 6- TIME_84_CYCLES
						 7- TIME_252_CYCLES
*/



u32 ADC_u32StartConversion( u8 Copy_u8Channel);/********(USED)*********/


void ADC_Init(void);
u32 ADC_Start(void);
u32 ADC_SingleMODE(void);

#define ADC_CHANNELS_GROUP   REGULAR_GROUP
/* Choose : 1-REGULAR_GROUP
			2-INJECTED_GROUP
			*/  

#define ADC_CONVERSION_MODE   SINGLE_CONVERSION 
/* Choose : 1-CONTINUOUS_CONVERSION
			2-SINGLE_CONVERSION
			*/  



/*Choose  the total number of conversions in the regular 
channel conversion sequenc*/

#define ADC_REGULAR_CONVERSIONS  One_Conversion



#endif
