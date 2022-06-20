/***********************************************************/
/*** Author  :  Solyma                      ****************/
/*** ADC_PROGRAM.c			                ****************/
/*** Date    : 14/4/2020                    ****************/
/*** Version :  01                          ****************/
/***********************************************************/

#include "A_STD_TYPES.h"
#include "A_BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

/*

	******************	Functiona which will be used   ************************

*/

void ADC_voidInit( u8 Copy_u8Channel , u8 Copy_u8Sample_Time )
{
	/*
	(1)ADC Sample Time
	*/
	if (Copy_u8Channel <= 9 )
	{
		ADC_SMPR2 &= ~ ( 0b111  << (Copy_u8Channel*3)); // Bit Masking
		ADC_SMPR2 |=  ( Copy_u8Sample_Time<< (Copy_u8Channel*3)); // Set the value of sampling time
	}
	else if (  (9 < Copy_u8Channel) && ( Copy_u8Channel <= 17) ) 
	{
		Copy_u8Channel -= 10;
		ADC_SMPR1 &= ~ ( 0b111  << (Copy_u8Channel*3)); // Bit Masking
		ADC_SMPR1 |=  ( Copy_u8Sample_Time<< (Copy_u8Channel*3)); // Set the value of sampling time
	}
	else
	{
		/*Error*/
	}
	
	/*
	(2)Select the alignment Converted data
	*/
	 SET_BIT(ADC_CR2 , 11);// ALIGN Bit ( 0 : Right Aligned , 1 : Left Aligned)
	
	/*
	(3)select the external event used to trigger the start of conversion of a regular group
	*/
	ADC_CR2 &=~ 0x000E0000; //Bit Masking for bits (17,18,19)
	ADC_CR2 |=  0x000E0000; //to select SWSTART bit as a trigger source to start the conversion
	
	
	
	/*
	(4)Power On the ADC peripheral
	*/
	SET_BIT(ADC_CR2 , 0); //Setting ADON bit 
	
		
}


u16 ADC_u32StartConversion( u8 Copy_u8Channel)
{
	/*
	(1) Setting the channel
	*/
	SET_BIT(ADC_CR1 , 0);//AWDCH 1
	// L[3:0]: Regular channel sequence length (No_OF_Conversions)
	ADC_SQR1 &=~ 0x00F00000; //Bit masking for bits (20,21,22,23)
	ADC_SQR1 |=  ADC_REGULAR_CONVERSIONS << 20 ; 
	
	ADC_SQR3 &=~ ( 0b11111  << (0)); //As we usually use single conversion ,// for multi channels "Scan mode" ( 0b11111  << (Copy_u8Channel*5));
	ADC_SQR3 |=  Copy_u8Channel;
	
	/*
	(2)According to the mode we will start the conversion
	*/
	#if    ADC_CONVERSION_MODE == CONTINUOUS_CONVERSION
	/*ADC_CR2 = 0x000E0000*/ 
		SET_BIT(ADC_CR2 , 1); // CONT: Continuous conversion
		SET_BIT(ADC_CR2 , 22);//SWSTART: Start conversion of regular channels
		
	
	#elif  ADC_CONVERSION_MODE == SINGLE_CONVERSION
	
	/*
	(2)>>>(1) start conversion
	*/
	
	CLR_BIT(ADC_CR2 , 1);	//Clearing CONT bit
	SET_BIT(ADC_CR2 , 0); //Setting ADON bit
	SET_BIT(ADC_CR2 , 2); //Setting CAL bit "Caliperation"
	SET_BIT(ADC_CR2 , 22);//SWSTART: Start conversion of regular channels
	/*
	(2)>>>(2) waiting for the flag
	*/
	while (GET_BIT(ADC_SR , 1) == 0);//EOC flag
	/*
	(2)>>>(3)clearing the flag
	*/
	CLR_BIT(ADC_SR , 1);//EOC bit
	#else 
	#error("You chosed wrong Conversion Mode")
	#endif
	/*
	(3) Reading the result
	*/
	 // Local_ADC_Result = ADC_DR ;
	return ( ADC_DR >> 4); //to read the data at first 12 bit of the register
}

/* ################################################################################################################## */
/*Functions According to Mazidi Book*/
void ADC_Init(void)
{
	ADC_CR2 = 0;
	ADC_CR2 &=~ 0x000E0000; //Bit Masking for bits (17,18,19)
	ADC_CR2 |=  0x000E0000; //to select SWSTART bit as a trigger source to start the conversion
	
	ADC_SQR3 = 1; // Channel 1
	ADC_SQR1 = 0; //length = 0
	ADC_CR2 = 1;
	
}

u32 ADC_Start(void)
{
	SET_BIT(ADC_CR2 , 22);//SWSTART: Start conversion of regular channels
	while (!(ADC_SR & 2)){}
	CLR_BIT(ADC_SR , 1);//EOC bit
	return ADC_DR;
	
}
u32 ADC_SingleMODE(void)
{
	
	//	1. Enable ADC clock to ADC in RCC_APB2ENR register.
	/*2. Configure ADC right adjusted result (ALIGN), free running conversion
	(CONT, continuous conversion) using ADC_CR2 register.

	*/
	ADC_CR2 = 0;
	ADC_SQR3 = 1; // Channel 1
	ADC_SQR1 = 0; //length = 0
	
	CLR_BIT(ADC_CR2 , 11);// ALIGN Bit ( 0 : Right Aligned , 1 : Left Aligned)
	//3. Using ADC_CR1 register,  the analog input channel.
	SET_BIT(ADC_CR1 , 0);//AWDCH 1

	/*5. Using ADC_CR2 register Enable the ADC (ADON) and START
	(SWSTART) to start the conversion.
	*/
	SET_BIT(ADC_CR2 , 0); //Setting ADON bit

	//6. Monitor the EOC flag in the ADC_SR register for end-of-conversion. 
	while (GET_BIT(ADC_SR , 1)==0);

	/*7. When the EOC flag goes HIGH, read the ADC data result from the
	ADC_DR register and save it.
	*/
	CLR_BIT(ADC_SR , 1);//EOC Flag
	return ADC_DR;
		
	
    
	//SET_BIT(ADC_CR2 , 2);//ADC Enable CAL
	
}
/***********************************************************/
/*** Author  :  Solyma                      ****************/
/*** ADC_PROGRAM.c			                ****************/
/*** Date    : 1/5/2020                    ****************/
/*** Version :  02                          ****************/
/***********************************************************/

//function for multi used channels
//u32 MADC_u32StartRegularConversions(u8 Copy_u8NomberOFChannels ,  )






