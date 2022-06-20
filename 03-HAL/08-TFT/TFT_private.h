/*********************************************************/
/*********************************************************/
/***********		Author: Adel Magdy   	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: TFT   		**************/
/***********		Version: 1.00		 	**************/
/*********************************************************/
/*********************************************************/

#ifndef TFT_PRIVATE_H_
#define TFT_PRIVATE_H_

static void voidWriteCommand(u8 Copy_u8Command);
static void voidWriteData(u8 Copy_u8Data);

static void HTFT_voidDrawPixel(u8 x1, u8 y1, u16  Copy_u16Color);
static void DrawTheColor(u16 Color);
static void HTFT_voidBounders(u8 x1, u8 x2, u8 y1, u8 y2);

#endif
