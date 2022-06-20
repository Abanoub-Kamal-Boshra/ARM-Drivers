/************************************************************************/
/*	Author	:	Abanoub Kamal                                           */
/* 	Version	:	V01														*/
/*	date	: 	23 NOV 2020												*/
/************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/* Bus macros */
#define RCC_AHB					0
#define RCC_APB1				1
#define RCC_APB2				2

/* AHB peripheral clock enable register (RCC_AHBENR) */
#define RCC_DMA1_EN				0
#define RCC_DMA2_EN				1
#define RCC_SRAM_EN				2
#define RCC_FLITF_EN			4
#define RCC_CRC_EN				6
#define RCC_FSMC_EN				8
#define RCC_SDIO_EN				10

/* APB2 peripheral clock enable register (RCC_APB2ENR) */
#define RCC_AFIO_EN				0
#define RCC_IOPA_EN				2
#define RCC_IOPB_EN				3
#define RCC_IOPC_EN				4
#define RCC_IOPD_EN		 		5
#define RCC_IOPE_EN				6
#define RCC_IOPF_EN				7
#define RCC_IOPG_EN				8
#define RCC_ADC1_EN				9
#define RCC_ADC2_EN				10
#define RCC_TIM1_EN				11
#define RCC_SPI1_EN				12
#define RCC_TIM8_EN				13
#define RCC_USART1_EN			14
#define RCC_ADC3_EN				15
#define RCC_TIM9_EN				19
#define RCC_TIM10_EN			20
#define RCC_TIM11_EN			21

/* APB1 peripheral clock enable register (RCC_APB1ENR) */
#define RCC_TIM2_EN				0
#define RCC_TIM3_EN				1
#define RCC_TIM4_EN				2
#define RCC_TIM5_EN				3
#define RCC_TIM6_EN				4
#define RCC_TIM7_EN				5
#define RCC_TIM12_EN			6
#define RCC_TIM13_EN			7
#define RCC_TIM14_EN			8
#define RCC_W_WDG_EN			11
#define RCC_SPI2_EN				14
#define RCC_SPI3_EN				15
#define RCC_USART2_EN			17
#define RCC_USART3_EN			18
#define RCC_UART4_EN			19
#define RCC_UART5_EN			20
#define RCC_I2C1_EN				21
#define RCC_I2C2_EN				22
#define RCC_USB_EN				23
#define RCC_CAN_EN				25
#define RCC_BKP_EN				27
#define RCC_PWR_EN				28
#define RCC_DAC_EN				29

/* APB2 peripheral reset register (RCC_APB2RSTR) */
#define RCC_AFIO_RST				0
#define RCC_IOPA_RST				2
#define RCC_IOPB_RST				3
#define RCC_IOPC_RST				4
#define RCC_IOPD_RST				5
#define RCC_IOPE_RST				6
#define RCC_IOPF_RST				7
#define RCC_IOPG_RST				8
#define RCC_ADC1_RST				9
#define RCC_ADC2_RST				10
#define RCC_TIM1_RST				11
#define RCC_SPI1_RST				12
#define RCC_TIM8_RST				13
#define RCC_USART1_RST				14
#define RCC_ADC3_RST				15
#define RCC_TIM9_RST				19
#define RCC_TIM10_RST				20
#define RCC_TIM11_RST				21

/* APB1 peripheral reset register (RCC_APB1RSTR) */
#define RCC_TIM2_RST				0
#define RCC_TIM3_RST				1
#define RCC_TIM4_RST				2
#define RCC_TIM5_RST				3
#define RCC_TIM6_RST				4
#define RCC_TIM7_RST				5
#define RCC_TIM12_RST				6
#define RCC_TIM13_RST				7
#define RCC_TIM14_RST				8
#define RCC_W_WDG_RST				11
#define RCC_SPI2_RST				14
#define RCC_SPI3_RST				15
#define RCC_USART2_RST				17
#define RCC_USART3_RST				18
#define RCC_UART4_RST				19
#define RCC_UART5_RST				20
#define RCC_I2C1_RST				21
#define RCC_I2C2_RST				22
#define RCC_USB_RST					23
#define RCC_CAN_RST					25
#define RCC_BKP_RST					27
#define RCC_PWR_RST					28
#define RCC_DAC_RST					29




/********************************************************************
 * Description:	initialize the system clock (clock of the processor)
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MRCC_voidInitSysClock(void);

/********************************************************************
 * Description:	Enable the clock for any peripheral
 * Inputs     :	Copy_u8BusId			options : RCC_AHB
 * 												  RCC_APB1
 * 												  RCC_APB2
 * 				Copy_u8PeripheralId		options	: 0 ~ 31
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MRCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PeripheralId);

/********************************************************************
 * Description:	Disable the clock for any peripheral
 * Inputs     :	Copy_u8BusId			options : RCC_AHB
 * 												  RCC_APB1
 * 												  RCC_APB2
 * 				Copy_u8PeripheralId		options : 0 ~ 31
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MRCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PeripheralId);


#endif
