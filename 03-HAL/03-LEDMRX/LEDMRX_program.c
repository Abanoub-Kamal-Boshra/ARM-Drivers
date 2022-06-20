/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	29 JAN 2021											*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


static u8 Global_u8ArrayColPins[8][2] = { {LEDMRX_COL0_PIN}, {LEDMRX_COL1_PIN}, {LEDMRX_COL2_PIN}, {LEDMRX_COL3_PIN},
								  	  	  {LEDMRX_COL4_PIN}, {LEDMRX_COL5_PIN}, {LEDMRX_COL6_PIN}, {LEDMRX_COL7_PIN}  };

static u8 Global_u8ArrayRowPins[8][2] = { {LEDMRX_ROW0_PIN}, {LEDMRX_ROW1_PIN}, {LEDMRX_ROW2_PIN}, {LEDMRX_ROW3_PIN},
	  	  	  	  	  	  	  	  	  	  {LEDMRX_ROW4_PIN}, {LEDMRX_ROW5_PIN}, {LEDMRX_ROW6_PIN}, {LEDMRX_ROW7_PIN}  };

void HLEDMRX_voidInit(void)
{
	/* initialize Row pins */
	for(u8 Local_u8Count=0; Local_u8Count<8; Local_u8Count++)
	{
		MGPIO_voidSetPinDirection( Global_u8ArrayRowPins[Local_u8Count][0], Global_u8ArrayRowPins[Local_u8Count][1], GPIO_OUTPUT_SPEED_2MHZ_PP);
	}
	/* initialize Column pins */
	for(u8 Local_u8Count=0; Local_u8Count<8; Local_u8Count++)
	{
		MGPIO_voidSetPinDirection( Global_u8ArrayColPins[Local_u8Count][0], Global_u8ArrayColPins[Local_u8Count][1], GPIO_OUTPUT_SPEED_2MHZ_PP);
	}
}

void HLEDMRX_voidDisplayFrame(u8 *Copy_u8Frame)
{
	for(u8 Local_u8Count=0; Local_u8Count<8; Local_u8Count++)
	{
		/* column i */
		DisableAllColumns();
		SetRowValues(Copy_u8Frame[Local_u8Count]);
		MGPIO_voidSetPinValue( Global_u8ArrayColPins[Local_u8Count][0], Global_u8ArrayColPins[Local_u8Count][1], GPIO_PIN_LOW); /* Enable column 0 */
		MSTK_voidSetBusyWait(2500); // 2.5 ms
	}
}


static void DisableAllColumns(void)
{
	for(u8 Local_u8Count=0; Local_u8Count<8; Local_u8Count++)
	{
		MGPIO_voidSetPinValue( Global_u8ArrayColPins[Local_u8Count][0], Global_u8ArrayColPins[Local_u8Count][1], GPIO_PIN_HIGH);
	}
}


static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit;
	for(u8 Local_u8Count=0; Local_u8Count<8; Local_u8Count++)
	{
		Local_u8Bit = GET_BIT(Copy_u8Value , Local_u8Count);
		MGPIO_voidSetPinValue( Global_u8ArrayRowPins[Local_u8Count][0], Global_u8ArrayRowPins[Local_u8Count][1], Local_u8Bit);
	}
}

