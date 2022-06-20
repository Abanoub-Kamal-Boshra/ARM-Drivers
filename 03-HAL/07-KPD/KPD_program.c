/*******************************************************************/
/*******************************************************************/
/***************************     Author: Magdy     *************/
/***************************     Layer:HALL            *************/
/***************************     SWC:KPD               *************/
/***************************     Version:1.00          *************/
/***************************     Data:1-9-2020        *************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "GPIO_interface.h"
//#include "CLCD_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"
//#include <util/delay.h>




u8 KPD_U8GetPressedKey(void)
{
	// this is the iterator of the COLUMNS
	u8 Local_u8ColIdx;

	// this is the iterator of the ROWS
	u8 Local_u8RowIdx;

	//this variable is to show if there is no pressed key
	u8 Local_u8PressedKey=NO_PRESSED_KEY;

	u8 Local_u8PinState;


	// this [array] takes the number of columns and  the number of rows
	//and all the values of both the columns and the rows are given by
	//the user in the process of configuration
	u8 Local_KPDArr[ROW_NUMBER][COLLUM_NUMBER]=KPD_BUTTONS_VAL;

	u8 Local_u8ColArr[COLLUM_NUMBER]={COLLUM_PIN0,COLLUM_PIN1,COLLUM_PIN2,COLLUM_PIN3};

	u8 Local_u8RowArr[ROW_NUMBER]={ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};



  // this first Outer "for loop" is used to activate the needed column
	for(Local_u8ColIdx=0;Local_u8ColIdx<COLLUM_NUMBER;Local_u8ColIdx++)
	{
		// 01_Step One :   activate the current column : //makes it OUTPUT_LOW//
		MGPIO_voidSetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIdx],GPIO_PIN_LOW);

		// this second inner "for loop" is used to find which
		//Button of the for keys corresponding to this column is pressed
		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUMBER;Local_u8RowIdx++)
		{
			Local_u8PinState = MGPIO_voidGetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIdx]/*,&Local_u8PinState*/);
			if(Local_u8PinState==GPIO_PIN_LOW)
			{
				Local_u8PressedKey=Local_KPDArr[Local_u8RowIdx][Local_u8ColIdx];
				while(Local_u8PinState==GPIO_PIN_LOW)
				{
					Local_u8PinState = MGPIO_voidGetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIdx]/*,&Local_u8PinState*/);
				}
				return Local_u8PressedKey;
			}
		}
		MGPIO_voidSetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIdx],GPIO_PIN_HIGH);
	}
	return Local_u8PressedKey;
}




/*
void Keypad_voidComplateCalculator()

{
	u8 Local_u8Number=0xff;
	u8 Local_u8Number1=0,Local_u8Number2=0;
	u8 Local_u8Mark;
	Local_u8Number=KPD_U8GetPressedKey();
	while (Local_u8Number==0xff)
	{
		Local_u8Number=KPD_U8GetPressedKey();
	}
	while ((Local_u8Number!= '+')&&(Local_u8Number!= '-')&&(Local_u8Number!= '*')&&(Local_u8Number!= '/'))
	{
		CLCD_voidSendData(Local_u8Number+'0');
		Local_u8Number1=Local_u8Number1*10+Local_u8Number;
		Local_u8Number=KPD_U8GetPressedKey();
		while (Local_u8Number==0xff)
		{
			Local_u8Number=KPD_U8GetPressedKey();
		}
	}


	if (Local_u8Number=='+')
	{
		Local_u8Mark='+';
	}
	else if (Local_u8Number=='-')
	{
		Local_u8Mark='-';
	}
	else if (Local_u8Number=='*')
	{
		Local_u8Mark='*';
	}
	else if (Local_u8Number=='/')
	{
		Local_u8Mark='/';
	}
	while ((Local_u8Number== '+')||(Local_u8Number== '-')||(Local_u8Number== '*')||(Local_u8Number== '/'))
	{
		CLCD_voidSendData(Local_u8Number);
		Local_u8Number=KPD_U8GetPressedKey();
		while (Local_u8Number==0xff)
		{
			Local_u8Number=KPD_U8GetPressedKey();
		}
	}


	while ((Local_u8Number!= '=')&&(Local_u8Number!= '+')&&(Local_u8Number!= '-')&&(Local_u8Number!= '*')&&(Local_u8Number!= '/'))
	{
		CLCD_voidSendData(Local_u8Number+'0');
		Local_u8Number2=Local_u8Number2*10+Local_u8Number;
		Local_u8Number=KPD_U8GetPressedKey();
		while (Local_u8Number==0xff)
		{
			Local_u8Number=KPD_U8GetPressedKey();
		}
	}
	CLCD_voidSendData(Local_u8Number);

	switch(Local_u8Mark)
	{
	case '+'  :
		CLCD_voidWriteNumber(Local_u8Number1 + Local_u8Number2);break ;
	case '-' :if(Local_u8Number1>Local_u8Number2){

		CLCD_voidWriteNumber(Local_u8Number1 - Local_u8Number2);
	}
	else if (Local_u8Number1<Local_u8Number2)
	{
		CLCD_voidSendData('-');
		CLCD_voidWriteNumber(Local_u8Number2 - Local_u8Number1);
	}
	break ;
	case '*' :
		CLCD_voidWriteNumber(Local_u8Number1 * Local_u8Number2);break ;
	case '/' :   if(Local_u8Number2 !=0){
		f32 Local_u32FloatNumber=((f32)Local_u8Number1 /(f32) Local_u8Number2)-(Local_u8Number1 / Local_u8Number2);

		CLCD_voidWriteNumber(Local_u8Number1 / Local_u8Number2);
		CLCD_voidSendData('.');
		Local_u32FloatNumber=Local_u32FloatNumber*100;
		CLCD_voidWriteNumber(Local_u32FloatNumber);
	}
	else{

		CLCD_voidSendString("Infinity");
	}
	break ;


	}
	_delay_ms(2000);
	CLCD_voidSendCommend(1);
}
*/

/*
void Keypad_voidTimer()
{
	u8 Local_u8Number=0xff;
	u8 Local_u8Number1=0xff;
	u8 Local_u8Number2=0xff;
	u8 Local_u8Number3=0xff;
	u8 Local_u8Number4=0xff;
	u8 Local_u8Number5=0xff;
	u8 Local_u8Number6=0xff;
	u8 Local_u8Haor;
	u8 Local_u8Minite;
	u8 Local_u8Second;
	u8 Local_u8Initial;
	u8 Local_u8Initial2;
	u8 Local_u8Initial3;
	u8 Local_u8XPos=0;
	u8 Local_u8YPos=0;
	u8 Local_u8n1;
	u8 Local_u8n2;
	u8 Local_u8n3;
	u8 Local_u8n4;
	u8 Local_u8n5;
	u8 Local_u8n6;
	u8 Local_u8i;
	u8 Local_u8j;
	u8 Local_u8Pattern[8]={0b00000100,0b00000100,0b00001110,0b00010101,0b00010101,0b00000100,0b00000100,0};
		u8 Local_u8Pattern1[8]={0};
		u8 Local_u8Hamoksha_UP[8]={0,0b00000100,0b00001010,0b00000100,0b00000100,0b00001110,0b00000100,0};
			u8 Local_u8Hamoksha_Down[8]={0b00000100,0b00000100,0b00000100,0b00000100,0b00000100,0b00001010,0b00000000,0};

	CLCD_voidSendData('0');
	CLCD_voidSendData('0');
	CLCD_voidSendData(':');
	CLCD_voidSendData('0');
	CLCD_voidSendData('0');
	CLCD_voidSendData(':');
	CLCD_voidSendData('0');
	CLCD_voidSendData('0');
	while (1)
	{


	while(Local_u8XPos==0)
	{
		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,0,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		CLCD_voidSendData(Local_u8Number1+'0');
		Local_u8n1=	Local_u8Number1;
		Local_u8Number1=KPD_U8GetPressedKey();
		while (Local_u8Number1==0xff)
		{

			Local_u8Number1=KPD_U8GetPressedKey();
		}
		if(Local_u8Number1=='+')
		{

			Local_u8XPos=1;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,0,1);
		}
		else if(Local_u8Number1=='-')
		{
			Local_u8XPos=7;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,0,1);
		}
		else if(Local_u8Number1=='=')
		{
			Local_u8XPos=10;
			Local_u8Number='=';
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,0,1);
		}
	}
	while(Local_u8XPos==1)
	{
		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,1,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		CLCD_voidSendData(Local_u8Number2+'0');
		Local_u8n2=Local_u8Number2;
		Local_u8Number2=KPD_U8GetPressedKey();
		while (Local_u8Number2==0xff)
		{
			Local_u8Number2=KPD_U8GetPressedKey();
		}
		if(Local_u8Number2=='+')
		{

			Local_u8XPos=3;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,1,1);
		}
		else if(Local_u8Number2=='-')
		{
			Local_u8XPos=0;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,1,1);
		}
		else if(Local_u8Number2=='=')
		{
			Local_u8XPos=10;
			Local_u8Number='=';
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,1,1);
		}
	}
	CLCD_voidGoToXY(2,Local_u8YPos);
	CLCD_voidSendData(':');
	while(Local_u8XPos==3)
	{
		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,3,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		CLCD_voidSendData(Local_u8Number3+'0');
		Local_u8n3=Local_u8Number3;
		Local_u8Number3=KPD_U8GetPressedKey();
		while (Local_u8Number3==0xff)
		{
			Local_u8Number3=KPD_U8GetPressedKey();
		}
		if(Local_u8Number3=='+')
		{

			Local_u8XPos=4;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,3,1);
		}
		else if(Local_u8Number3=='-')
		{
			Local_u8XPos=1;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,3,1);
		}
		else if(Local_u8Number3=='=')
		{
			Local_u8XPos=10;
			Local_u8Number='=';
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,3,1);
		}
	}
	while(Local_u8XPos==4)
	{
		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,4,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		CLCD_voidSendData(Local_u8Number4+'0');
		Local_u8n4=Local_u8Number4;
		Local_u8Number4=KPD_U8GetPressedKey();
		while (Local_u8Number4==0xff)
		{
			Local_u8Number4=KPD_U8GetPressedKey();
		}
		if(Local_u8Number4=='+')
		{

			Local_u8XPos=6;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,4,1);
		}
		else if(Local_u8Number4=='-')
		{
			Local_u8XPos=3;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,4,1);
		}
		else if(Local_u8Number4=='=')
		{
			Local_u8XPos=10;
			Local_u8Number='=';
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,4,1);
		}
	}
	CLCD_voidGoToXY(5,Local_u8YPos);
	CLCD_voidSendData(':');
	while(Local_u8XPos==6)
	{
		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,6,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		CLCD_voidSendData(Local_u8Number5+'0');
		Local_u8n5=Local_u8Number5;
		Local_u8Number5=KPD_U8GetPressedKey();
		while (Local_u8Number5==0xff)
		{
			Local_u8Number5=KPD_U8GetPressedKey();
		}
		if(Local_u8Number5=='+')
		{

			Local_u8XPos=7;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,6,1);
		}
		else if(Local_u8Number5=='-')
		{
			Local_u8XPos=4;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,6,1);
		}
		else if(Local_u8Number5=='=')
		{
			Local_u8XPos=10;
			Local_u8Number='=';
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,6,1);
		}
	}
	while(Local_u8XPos==7)
	{
		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,7,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		CLCD_voidSendData(Local_u8Number6+'0');
		Local_u8n6=Local_u8Number6;
		Local_u8Number6=KPD_U8GetPressedKey();
		while (Local_u8Number6==0xff)
		{
			Local_u8Number6=KPD_U8GetPressedKey();
		}
		if(Local_u8Number6=='+')
		{

			Local_u8XPos=0;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,7,1);
		}
		else if(Local_u8Number6=='-')
		{
			Local_u8XPos=6;
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,7,1);
		}
		else if(Local_u8Number6=='=')
		{
			Local_u8XPos=10;
			Local_u8Number='=';
			CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,7,1);
		}

	}
	if(Local_u8Number=='=')
			{
				break;
			}

	}


	while(Local_u8Number=='=')
	{
		Local_u8Haor=Local_u8n1*10+Local_u8n2;
		Local_u8Minite=Local_u8n3*10+Local_u8n4;
		Local_u8Second=Local_u8n5*10+Local_u8n6;
		Local_u8Initial2=Local_u8Minite;
		Local_u8Initial3=Local_u8Second;

		for(Local_u8Initial=Local_u8Haor;(Local_u8Initial>=0)&&(Local_u8Initial<=Local_u8Haor);Local_u8Initial--)
		{
			CLCD_voidSendCommend(1);
			CLCD_voidGoToXY(0,0);
			CLCD_voidWriteNumber(Local_u8Initial);
			CLCD_voidGoToXY(2,0);
			CLCD_voidSendData(':');

			if(Local_u8Initial2!=0){
				for(Local_u8Initial2=Local_u8Minite;(Local_u8Initial2>=0)&&(Local_u8Initial2<=Local_u8Minite);Local_u8Initial2--)
				{
					CLCD_voidGoToXY(3,0);
					CLCD_voidWriteNumber(Local_u8Initial2);
					CLCD_voidGoToXY(5,0);
					CLCD_voidSendData(':');

					if(Local_u8Initial3!=0){
						for(Local_u8Initial3=Local_u8Second;(Local_u8Initial3>=0)&&(Local_u8Initial3<=Local_u8Second);Local_u8Initial3--)
						{
							CLCD_voidGoToXY(6,0);
							CLCD_voidSendData(' ');
							CLCD_voidGoToXY(7,0);
							CLCD_voidSendData(' ');
							CLCD_voidGoToXY(6,0);
							CLCD_voidWriteNumber(Local_u8Initial3);
							_delay_ms(1000);
							if(Local_u8Initial3==0)
							{
								break ;
							}
						}
					}else if(Local_u8Initial3==0){
						for(Local_u8i=59;(Local_u8i>=0);Local_u8i--)
						{
							CLCD_voidGoToXY(6,0);
							CLCD_voidSendData(' ');
							CLCD_voidGoToXY(7,0);
							CLCD_voidSendData(' ');
							CLCD_voidGoToXY(6,0);
							CLCD_voidWriteNumber(Local_u8i);
							_delay_ms(1000);
							if(Local_u8i==0)
							{
								break ;
							}
						}
					}
					if(Local_u8Initial2==0)
					{
						break ;
					}
				}
			}
			else if(Local_u8Initial2==0)
			{
				for(Local_u8j=59;(Local_u8j>=0);Local_u8j--)
				{
					CLCD_voidGoToXY(3,0);
					CLCD_voidWriteNumber(Local_u8Initial2);
					CLCD_voidGoToXY(5,0);
					CLCD_voidSendData(':');
					if(Local_u8Initial3!=0){
						for(Local_u8Initial3=Local_u8Second;(Local_u8Initial3>=0)&&(Local_u8Initial3<=Local_u8Second);Local_u8Initial3--)
						{
							CLCD_voidGoToXY(6,0);
							CLCD_voidSendData(' ');
							CLCD_voidGoToXY(7,0);
							CLCD_voidSendData(' ');
							CLCD_voidGoToXY(6,0);
							CLCD_voidWriteNumber(Local_u8Initial3);
							_delay_ms(1000);
							if(Local_u8Initial3==0)
							{
								break ;
							}
						}
					}else if(Local_u8Initial3==0){
						for(Local_u8i=59;(Local_u8i>=0);Local_u8i--)
						{
							CLCD_voidGoToXY(6,0);
							CLCD_voidSendData(' ');
							CLCD_voidGoToXY(7,0);
							CLCD_voidSendData(' ');
							CLCD_voidGoToXY(6,0);
							CLCD_voidWriteNumber(Local_u8i);
							_delay_ms(1000);
							if(Local_u8i==0)
							{
								break ;
							}
						}
					}
					if(Local_u8j==0)
					{
						break ;
					}
				}
			}
			if(Local_u8Initial==0)
			{
				break ;
			}
		}
		CLCD_voidSendCommend(1);

			CLCD_voidWriteSpecialCharacter(Local_u8Hamoksha_UP,4,0,0);
				CLCD_voidWriteSpecialCharacter(Local_u8Hamoksha_Down,5,0,1);
				CLCD_voidGoToXY(2,0);
				CLCD_voidSendString("Time off");
				DIO_u8SetPinValue (DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
				_delay_ms(3000);
				DIO_u8SetPinValue (DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_LOW);
				CLCD_voidSendCommend(1);
break;

	}



}

*/
