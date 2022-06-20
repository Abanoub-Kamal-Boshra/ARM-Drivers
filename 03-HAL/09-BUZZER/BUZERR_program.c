#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include    "GPIO_interface.h"
#include    "STK_interface.h"


#include	"BUZERR_interface.h"
#include	"BUZERR_private.h"
#include	"BUZERR_config.h"

void HBUZERR_LowAlarm(void)
{
	MGPIO_voidSetPinValue(BUZERR_PIN,GPIO_U8_HIGH);
	MSTK_voidSetBusyWait(700000);
	MGPIO_voidSetPinValue(BUZERR_PIN,GPIO_U8_LOW);
	MSTK_voidSetBusyWait(700000);


}
void HBUZERR_MedeumAlarm(void)
{
	MGPIO_voidSetPinValue(BUZERR_PIN,GPIO_U8_HIGH);
	MSTK_voidSetBusyWait(500000);
	MGPIO_voidSetPinValue(BUZERR_PIN,GPIO_U8_LOW);
	MSTK_voidSetBusyWait(500000);
}
void HBUZERR_HighAlarm(void)
{
	MGPIO_voidSetPinValue(BUZERR_PIN,GPIO_U8_HIGH);
	MSTK_voidSetBusyWait(300000);
	MGPIO_voidSetPinValue(BUZERR_PIN,GPIO_U8_LOW);
	MSTK_voidSetBusyWait(300000);
}
