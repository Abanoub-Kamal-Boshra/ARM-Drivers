
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include    "GPIO_interface.h"
#include    "SPI_interface.h"
#include    "STK_interface.h"

#include	"TFT_interface.h"
#include	"TFT_private.h"
#include	"TFT_config.h"
#include    "font.h"


//static void HTFT_voidBounders(0,127,0,159);

		/* static functions used just here */
static void HTFT_voidDrawPixel(u8 x1, u8 y1, u16  Copy_u16Color)
{

	/* adusting pixel size */
	u8 x2 = x1 + PixelLenght - 1;
	u8 y2 = y1 + PixelLenght - 1;
	HTFT_voidBounders(x1,x2,y1,y2);

	u8 PixelSize = PixelLenght * PixelLenght;
	/* RAM write */
	voidWriteCommand(0x2C);

	for(u8 Counter = 0 ; Counter <= PixelSize ; Counter++)
	{
		DrawTheColor(Copy_u16Color);
	}
}

static void DrawTheColor(u16 Color)
{
	/* write the high byte */
	voidWriteData(Color >> 8);
	/* write the low byte */
	voidWriteData(Color & 0x00FF);
}

static void HTFT_voidBounders(u8 x1, u8 x2, u8 y1, u8 y2)
{
	/* Set 'x' address */
	voidWriteCommand(0x2A);
		/* area of working */
	/* start of 'x' */
	voidWriteData(0);
	voidWriteData(x1);
	/* end of 'x' */
	voidWriteData(0);
	voidWriteData(x2);

	/* Set 'y' address */
	voidWriteCommand(0x2B);
		/* area of working */
	/* start of 'y' */
	voidWriteData(0);
	voidWriteData(y1);
	/* end of 'y' */
	voidWriteData(0);
	voidWriteData(y2);

}

void HTFT_voidInit(void)
{
	/*Reset Pulse */
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_PIN_HIGH);
	MSTK_voidSetBusyWait(100);

	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_PIN_LOW);
	MSTK_voidSetBusyWait(1);

	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_PIN_HIGH);
	MSTK_voidSetBusyWait(100);

	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_PIN_LOW);
	MSTK_voidSetBusyWait(100);

	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_PIN_HIGH);
	MSTK_voidSetBusyWait(120000);

	/*Sleep out command*/
	voidWriteCommand(0x11);

	/*wait 150 ms*/
	MSTK_voidSetBusyWait(150000);

	/*color mode command */
	voidWriteCommand(0x3A);
	voidWriteData(0x05);

	/*Display on command */
	voidWriteCommand(0x29);
}
void HTFT_voidDisplayImage(const u16 * Copy_Image)
{
	u16 Local_Counter;
	/*Set x address*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/*Set y address*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	
	/*Write ram*/
	voidWriteCommand(0x2C);

//	voidWriteData(0x0000);
	//voidWriteData(0xf0f0);

	for ( Local_Counter = 0 ; Local_Counter<20480;Local_Counter++)
	{
		/*write the high byte*/
		voidWriteData ((Copy_Image[Local_Counter])>>8);
		/*write the low byte*/
		voidWriteData ((Copy_Image[Local_Counter]) & 0x00FF);
	}
}

static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	/*Set A0 pin to low*/
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_PIN_LOW);
	/*Send commend over SPI*/
	MSPI1_voidSendReceiveSynch(Copy_u8Command,&Local_u8Temp);
}


static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	/*Set A0 pin to High*/
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_PIN_HIGH);
	/*Send DATA over SPI*/
	MSPI1_voidSendReceiveSynch(Copy_u8Data,&Local_u8Temp);
}

void HTFT_voidFillColor( u16 Copy_Color)
{
	u16 Local_Counter;
	/*Set x address*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/*Set y address*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/*Write ram*/
	voidWriteCommand(0x2C);

//	voidWriteData(0x0000);
	//voidWriteData(0xf0f0);

	for ( Local_Counter = 0 ; Local_Counter<20480;Local_Counter++)
	{
		/*write the high byte*/
		voidWriteData ((Copy_Color)>>8);
		/*write the low byte*/
		voidWriteData (Copy_Color & 0x00FF);
	}
}
void HTFT_voidDrawRect(u8 x1 , u8 x2 , u8 y1 , u8 y2 , u16 Copy_Color)
{
	u16 Local_Counter;
	u16 size = (x2 - x1) * (y2 - y1);
	/*Set x address*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(x1);
	voidWriteData(0);
	voidWriteData(x2);

	/*Set y address*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);

	/*Write ram*/
	voidWriteCommand(0x2C);

//	voidWriteData(0x0000);
	//voidWriteData(0xf0f0);

	for ( Local_Counter = 0 ; Local_Counter<size;Local_Counter++)
	{
		/*write the high byte*/
		voidWriteData ((Copy_Color)>>8);
		/*write the low byte*/
		voidWriteData (Copy_Color & 0x00FF);
	}
}
void HTFT_voidDrawChar(u8 x1,u8 y1,u32 CharColor, u32 BackColor, u8 charcter)
{
	u8 value;

	u8 charX1 = x1;
	u8 charY1 = y1;

    for (u8 i = 0; i < 5; i++)
    {
        for (u8 j = 0; j < 7; j++)
        {
            value = 0;

            value = ((font[(charcter) - 32][i]));

            if(value & (1 << j))
            {
            	HTFT_voidDrawPixel(charX1, charY1, CharColor);
            }
            else
            {
            	HTFT_voidDrawPixel(charX1, charY1, BackColor);
            }
            charY1 += PixelLenght;
            /* drawing "t"
              ####0###
              ###000##
              ####0###
              ####0###
              ####000#		<< shifting by charY1 += 3; to draw 8 pixels
             */

         }
        /* to set the charY1 to the start box of the letter */
        charY1 = y1;

        charX1 += PixelLenght;
        /* drawing "t"
          ####0###
          ###000##
          ####0###		/\
          ####0###		/\
          ####000#		/\ shifting by charX1 += 3; to draw 5 raws
         */
     }


}

void HTFT_voidDrawString(u8 x1,u8 y1,u32 StringColor, u32 BackColor, u8 string[])
{
	u8 x = x1;
	u8 y = y1;
	u8 c = 0;
	u8 i = 0;
	while(string[i] != '\0' )
	{

		c = string[i];
		HTFT_voidDrawChar(x,y,StringColor,BackColor,c);
		i++;
		x += ((PixelLenght * 5) + 2);
		//y += (PixelLenght * 5);
	}

}



void HTFT_voidWriteNumber(u8 x1,u8 y1,u32 StringColor, u32 BackColor,u32 Number)
{
	u32 Local_u32Number=0;
	u32 Local_u32DigitNumber;
	u32 Local_u32Counter1=0;
	u32 Local_u32Counter2=0;
	u32 Local_u32Iterms;
	u32 Local_u32Flag=0;



	while(Number!=0)
	{
		Local_u32Number=(Local_u32Number*10)+(Number%10);
		Number/=10;
		Local_u32Counter1++;
		Local_u32Flag=1;
	}

	while(Local_u32Number!=0)
	{


		Local_u32DigitNumber=Local_u32Number % 10;

		HTFT_voidDrawChar(x1,y1,StringColor,BackColor,Local_u32DigitNumber+'0');
		x1 += ((PixelLenght * 5) + 2);
		//CLCD_voidSendData(Local_u32DigitNumber+'0');


		Local_u32Number/=10;
		Local_u32Counter2++;


	}
	if(Local_u32Flag==0){

		for(Local_u32Iterms=0;Local_u32Iterms<=Local_u32Counter1-Local_u32Counter2;Local_u32Iterms++)
		{
			HTFT_voidDrawChar(x1,y1,StringColor,BackColor,'0');
			x1 += ((PixelLenght * 5) + 2);
			//CLCD_voidSendData('0');

		}
	}
	else{
		for(Local_u32Iterms=0;Local_u32Iterms<Local_u32Counter1-Local_u32Counter2;Local_u32Iterms++)
		{
			HTFT_voidDrawChar(x1,y1,StringColor,BackColor,'0');
			x1 += ((PixelLenght * 5) + 2);
//			CLCD_voidSendData('0');

		}
	}
}
