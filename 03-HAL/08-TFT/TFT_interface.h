/*********************************************************/
/*********************************************************/
/***********		Author: Adel Magdy   	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: TFT   		**************/
/***********		Version: 1.00		 	**************/
/*********************************************************/
/*********************************************************/

#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

/*intialization TFT*/
void HTFT_voidInit(void);

/*display image put the array of image*/
void HTFT_voidDisplayImage(const u16 * Copy_Image);

/*fill TFT in the color  :   0x0000  ==> black
 * 							 0xffff  ==> white
 * 							 0xf0f0  ==> bink   */
void HTFT_voidFillColor( u16 Copy_Color);

/*draw rectangular  input :  x1 and x2 position of x
 * 						  :  y1 and y2 position of y
 * 						  :  color   0x0000  ==> black
 * 									 0xffff  ==> white
 * 									 0xf0f0  ==> bink  */
void HTFT_voidDrawRect(u8 x1 , u8 x2 , u8 y1 , u8 y2 , u16 Copy_Color);

/*draw character position x
 * 				 position y
 * 				character color      0x0000  ==> black
 * 									 0xffff  ==> white
 * 									 0xf0f0  ==> bink
 *
 * 				back ground color    0x0000  ==> black
 * 									 0xffff  ==> white
 * 									 0xf0f0  ==> bink
 * 				character itself */
void HTFT_voidDrawChar(u8 x1,u8 y1,u32 CharColor, u32 BackColor, u8 charcter);

/*write string  input :  x1 and x2 position of x
 * 						  :  y1 and y2 position of y
 * 						  : string color   0x0000  ==> black
 * 									       0xffff  ==> white
 * 									       0xf0f0  ==> bink
 * 						  : back color   0x0000  ==> black
 * 									       0xffff  ==> white
 * 									       0xf0f0  ==> bink
 * 						  : string itself
 * 									  */
void HTFT_voidDrawString(u8 x1,u8 y1,u32 StringColor, u32 BackColor, u8 string[]);

/*write number  input     :  x1 and x2 position of x
 * 						  :  y1 and y2 position of y
 * 						  : string color   0x0000  ==> black
 * 									       0xffff  ==> white
 * 									       0xf0f0  ==> bink
 * 						  : back color   0x0000  ==> black
 * 									       0xffff  ==> white
 * 									       0xf0f0  ==> bink
 * 						  : number itself
 * 									  */

void HTFT_voidWriteNumber(u8 x1,u8 y1,u32 StringColor, u32 BackColor,u32 Number);
#endif
