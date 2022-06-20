/***********************************************************/
/*** Author  :  Solyma                      ****************/
/*** ADC_Private            			    ****************/
/*** Date    : 5/4/2021                     ****************/
/*** Version :  01                          ****************/
/***********************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Registers Of ADC1 Peripheral */

#define ADC_BASE_ADDRESS  0x40012400

#define     ADC_SR          *((volatile u32 *)(0x40012400 + 0x00)) //ADC status register
#define     ADC_CR1         *((volatile u32 *)(0x40012400 + 0x04)) //ADC control register 1
#define     ADC_CR2         *((volatile u32 *)(0x40012400 + 0x08)) //ADC control register 2
#define     ADC_SMPR1       *((volatile u32 *)(0x40012400 + 0x0C))
#define     ADC_SMPR2      	*((volatile u32 *)(0x40012400 + 0x10))
#define     ADC_JOFR1      	*((volatile u32 *)(0x40012400 + 0x14))
#define     ADC_JOFR2       *((volatile u32 *)(0x40012400 + 0x18))
#define     ADC_JOFR3       *((volatile u32 *)(0x40012400 + 0x1C))
#define     ADC_JOFR4     	*((volatile u32 *)(0x40012400 + 0x20))
#define     ADC_HTR        	*((volatile u32 *)(0x40012400 + 0x24))//ADC watchdog high threshold register (ADC_HTR)
#define     ADC_LTR       	*((volatile u32 *)(0x40012400 + 0x28))//ADC watchdog low threshold register (ADC_LTR)
#define     ADC_SQR1       	*((volatile u32 *)(0x40012400 + 0x2C))// ADC regular sequence register 1 (ADC_SQR1)
#define     ADC_SQR2       	*((volatile u32 *)(0x40012400 + 0x30))
#define     ADC_SQR3        *((volatile u32 *)(0x40012400 + 0x34))
#define     ADC_JSQR       	*((volatile u32 *)(0x40012400 + 0x38))//ADC injected sequence register (ADC_JSQR)
#define     ADC_JDR1        *((volatile u32 *)(0x40012400 + 0x3C))
#define     ADC_JDR2        *((volatile u32 *)(0x40012400 + 0x40))
#define     ADC_JDR3        *((volatile u32 *)(0x40012400 + 0x44))
#define     ADC_JDR4        *((volatile u32 *)(0x40012400 + 0x48))
#define     ADC_DR       	*((volatile u32 *)(0x40012400 + 0x4C))// ADC regular data register (ADC_DR)



#define REGULAR_GROUP         0
#define INJECTED_GROUP        1

#define SINGLE_CONVERSION     0 
#define CONTINUOUS_CONVERSION 1
 
 
		/*Choose  the total number of conversions in the regular 
						channel conversion sequenc
		For :  #define ADC_REGULAR_CONVERSIONS  One_Conversion  */

#define  One_Conversion     0
#define  Tow_Conversion     1
#define  Three_Conversion   2


#define  TIME_14_CYCLES  0
#define  TIME_20_CYCLES	 1				
#define	 TIME_26_CYCLES	 2				
#define	 TIME_41_CYCLES	 3				
#define	 TIME_54_CYCLES	 4				
#define	 TIME_68_CYCLES	 5				
#define	 TIME_84_CYCLES	 6				
#define	 TIME_252_CYCLES 7				





#endif
