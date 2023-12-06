///**************************************************************************************************/
// /* @attention
//  *
//  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
//  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
//  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
//  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
//  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
//  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
//**************************************************************************************************/
//#include <font.h>
//#include <string.h>
//#include "lcd.h"
//#include "GUI.h"
///*******************************************************************
// * @name       :static void hexToAscii(char *pByDataOutPut,uint8_t *pByDataInPut,uint8_t byDataLength)
// * @date       :2023-03-02
// * @function   :
// * @parameters :
// * @retvalue   :None
//********************************************************************/
//
///*******************************************************************
// * @name       :void GUI_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
// * @date       :2018-08-09
// * @function   :draw a point in LCD screen
// * @parameters :x:the x coordinate of the point
//                y:the y coordinate of the point
//								color:the color value of the point
// * @retvalue   :None
//********************************************************************/
//void GUI_DrawPoint(uint16_t x, uint16_t y, uint16_t color)
//{
//	LCD_SetCursor(x, y);
//	Lcd_WriteData_16Bit(color);
//}
//
///*******************************************************************
// * @name       :void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color)
// * @date       :2018-08-09
// * @function   :fill the specified area
// * @parameters :sx:the bebinning x coordinate of the specified area
//                sy:the bebinning y coordinate of the specified area
//								ex:the ending x coordinate of the specified area
//								ey:the ending y coordinate of the specified area
//								color:the filled color value
// * @retvalue   :None
//********************************************************************/
//void LCD_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color)
//{
//	uint16_t i, j;
//	uint16_t width = ex - sx + 1;
//	uint16_t height = ey - sy + 1;
//	LCD_SetWindows(sx, sy, ex, ey);
//	for(i = 0; i < height; i++)
//	{
//		for(j = 0; j < width; j++)
//		Lcd_WriteData_16Bit(color);
//	}
//	LCD_SetWindows(0, 0, lcddev.width - 1, lcddev.height - 1);
//}
//
///*******************************************************************
// * @name       :void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
// * @date       :2018-08-09
// * @function   :Draw a line between two points
// * @parameters :x1:the bebinning x coordinate of the line
//                y1:the bebinning y coordinate of the line
//								x2:the ending x coordinate of the line
//								y2:the ending y coordinate of the line
// * @retvalue   :None
//********************************************************************/
//void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
//{
//	uint16_t t;
//	int xerr = 0, yerr = 0, delta_x, delta_y, distance;
//	int incx, incy, uRow, uCol;
//
//	delta_x = x2 - x1;
//	delta_y = y2 - y1;
//	uRow = x1;
//	uCol = y1;
//	if(delta_x > 0) incx = 1;
//	else if(delta_x == 0) incx = 0;
//	else {incx = -1; delta_x = -delta_x;}
//	if(delta_y > 0) incy = 1;
//	else if(delta_y == 0) incy = 0;
//	else{incy = -1; delta_y = -delta_y;}
//	if(delta_x > delta_y) distance = delta_x;
//	else distance = delta_y;
//	for(t = 0; t <= distance + 1; t++)
//	{
//		LCD_DrawPoint(uRow, uCol);
//		xerr += delta_x;
//		yerr += delta_y;
//		if(xerr > distance)
//		{
//			xerr -= distance;
//			uRow += incx;
//		}
//		if(yerr > distance)
//		{
//			yerr -= distance;
//			uCol += incy;
//		}
//	}
//}
//
///*****************************************************************************
// * @name       :void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
// * @date       :2018-08-09
// * @function   :Draw a rectangle
// * @parameters :x1:the bebinning x coordinate of the rectangle
//                y1:the bebinning y coordinate of the rectangle
//								x2:the ending x coordinate of the rectangle
//								y2:the ending y coordinate of the rectangle
// * @retvalue   :None
//******************************************************************************/
//void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
//{
//	LCD_DrawLine(x1, y1, x2, y1);
//	LCD_DrawLine(x1, y1, x1, y2);
//	LCD_DrawLine(x1, y2, x2, y2);
//	LCD_DrawLine(x2, y1, x2, y2);
//	LCD_SetColorPoint(BLACK);
//}
//
///*****************************************************************************
// * @name       :void LCD_DrawFillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
// * @date       :2018-08-09
// * @function   :Filled a rectangle
// * @parameters :x1:the bebinning x coordinate of the filled rectangle
//                y1:the bebinning y coordinate of the filled rectangle
//								x2:the ending x coordinate of the filled rectangle
//								y2:the ending y coordinate of the filled rectangle
// * @retvalue   :None
//******************************************************************************/
//void LCD_DrawFillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
//{
//	LCD_Fill(x1, y1, x2, y2, POINT_COLOR);
//}
//
///*****************************************************************************
// * @name       :void _draw_circle_8(int xc, int yc, int x, int y, uint16_t c)
// * @date       :2018-08-09
// * @function   :8 symmetry circle drawing algorithm (internal call)
// * @parameters :xc:the x coordinate of the Circular center
//                yc:the y coordinate of the Circular center
//								x:the x coordinate relative to the Circular center
//								y:the y coordinate relative to the Circular center
//								c:the color value of the circle
// * @retvalue   :None
//******************************************************************************/
//void _draw_circle_8(int xc, int yc, int x, int y, uint16_t c)
//{
//	GUI_DrawPoint(xc + x, yc + y, c);
//
//	GUI_DrawPoint(xc - x, yc + y, c);
//
//	GUI_DrawPoint(xc + x, yc - y, c);
//
//	GUI_DrawPoint(xc - x, yc - y, c);
//
//	GUI_DrawPoint(xc + y, yc + x, c);
//
//	GUI_DrawPoint(xc - y, yc + x, c);
//
//	GUI_DrawPoint(xc + y, yc - x, c);
//
//	GUI_DrawPoint(xc - y, yc - x, c);
//}
//
///*****************************************************************************
// * @name       :void gui_circle(int xc, int yc,uint16_t c,int r, int fill)
// * @date       :2018-08-09
// * @function   :Draw a circle of specified size at a specified location
// * @parameters :xc:the x coordinate of the Circular center
//                yc:the y coordinate of the Circular center
//								r:Circular radius
//								fill:1-filling,0-no filling
// * @retvalue   :None
//******************************************************************************/
//void gui_circle(int xc, int yc,uint16_t c,int r, int fill)
//{
//	int x = 0, y = r, yi, d;
//	d = 3 - 2 * r;
//
//	if (fill)
//	{
//		while (x <= y) {
//			for (yi = x; yi <= y; yi++)
//				_draw_circle_8(xc, yc, x, yi, c);
//
//			if (d < 0) {
//				d = d + 4 * x + 6;
//			} else {
//				d = d + 4 * (x - y) + 10;
//				y--;
//			}
//			x++;
//		}
//	} else
//	{
//		while (x <= y) {
//			_draw_circle_8(xc, yc, x, y, c);
//			if (d < 0) {
//				d = d + 4 * x + 6;
//			} else {
//				d = d + 4 * (x - y) + 10;
//				y--;
//			}
//			x++;
//		}
//	}
//}
//
///*****************************************************************************
// * @name       :void Draw_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
// * @date       :2018-08-09
// * @function   :Draw a triangle at a specified position
// * @parameters :x0:the bebinning x coordinate of the triangular edge
//                y0:the bebinning y coordinate of the triangular edge
//								x1:the vertex x coordinate of the triangular
//								y1:the vertex y coordinate of the triangular
//								x2:the ending x coordinate of the triangular edge
//								y2:the ending y coordinate of the triangular edge
// * @retvalue   :None
//******************************************************************************/
//void Draw_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
//{
//	LCD_DrawLine(x0,y0,x1,y1);
//	LCD_DrawLine(x1,y1,x2,y2);
//	LCD_DrawLine(x2,y2,x0,y0);
//}
//
//static void _swap(uint16_t *a, uint16_t *b)
//{
//	uint16_t tmp;
//    tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
///*****************************************************************************
// * @name       :void Fill_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
// * @date       :2018-08-09
// * @function   :filling a triangle at a specified position
// * @parameters :x0:the bebinning x coordinate of the triangular edge
//                y0:the bebinning y coordinate of the triangular edge
//								x1:the vertex x coordinate of the triangular
//								y1:the vertex y coordinate of the triangular
//								x2:the ending x coordinate of the triangular edge
//								y2:the ending y coordinate of the triangular edge
// * @retvalue   :None
//******************************************************************************/
//void Fill_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
//{
//	uint16_t a, b, y, last;
//	int dx01, dy01, dx02, dy02, dx12, dy12;
//	long sa = 0;
//	long sb = 0;
// 	if(y0 > y1)
//	{
//		_swap(&y0, &y1);
//		_swap(&x0, &x1);
// 	}
// 	if(y1 > y2)
//	{
//		_swap(&y2, &y1);
//		_swap(&x2, &x1);
// 	}
//    if(y0 > y1)
//	{
//		_swap(&y0, &y1);
//		_swap(&x0, &x1);
//    }
//	if(y0 == y2)
//	{
//		a = b = x0;
//		if(x1 < a)
//		{
//			a = x1;
//		}
//		else if(x1 > b)
//		{
//			b = x1;
//		}
//		if(x2 < a)
//		{
//			a = x2;
//		}
//		else if(x2 > b)
//		{
//			b = x2;
//		}
//		LCD_Fill(a, y0, b, y0, POINT_COLOR);
//		return;
//	}
//	dx01 = x1 - x0;
//	dy01 = y1 - y0;
//	dx02 = x2 - x0;
//	dy02 = y2 - y0;
//	dx12 = x2 - x1;
//	dy12 = y2 - y1;
//
//	if(y1 == y2)
//	{
//		last = y1;
//	}
//    else
//	{
//		last = y1 - 1;
//	}
//	for(y = y0; y <= last; y++)
//	{
//		a = x0 + sa / dy01;
//		b = x0 + sb / dy02;
//		sa += dx01;
//        sb += dx02;
//        if(a > b)
//        {
//			_swap(&a,  &b);
//		}
//		LCD_Fill(a, y, b, y, POINT_COLOR);
//	}
//	sa = dx12 * (y - y1);
//	sb = dx02 * (y - y0);
//	for(; y <= y2; y++)
//	{
//		a = x1 + sa / dy12;
//		b = x0 + sb / dy02;
//		sa += dx12;
//		sb += dx02;
//		if(a > b)
//		{
//			_swap(&a, &b);
//		}
//		LCD_Fill(a, y, b, y, POINT_COLOR);
//	}
//}
//
///*****************************************************************************
// * @name       :void LCD_ShowTitle(uint16_t sizeBox,uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
// * @date       :2023-02-24
// * @function   :Prinf Title
// * @parameters :sizeBox:the size of title box
//				fc:the color value of display character
//				bc:the background color of display character
//				*str: ascii code of display character(0~94)
//				size:the size of display character
//				mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//void LCD_ShowTitle(uint16_t sizeBox, uint16_t fc, uint16_t bc, uint8_t *str, uint8_t size, uint8_t mode)
//{
//	LCD_ClearCursor(0, 0, 320, sizeBox, WHITE);
//	LCD_Fill(0, 0, 320, sizeBox, bc);
//	Gui_StrCenter(0, sizeBox - size, fc, bc, str, 16, 1);
//}
//
///*****************************************************************************
// * @name       :uint16_t LCD_ShowOption(uint16_t sizeBox,uint16_t y,uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
// * @date       :2023-02-24
// * @function   :Prinf Title
// * @parameters :sizeBox:the size of title box
//				fc:the color value of display character
//				bc:the background color of display character
//				*str: ascii code of display character(0~94)
//				size:the size of display character
//				mode:0-no overlying,1-overlying
// * @retvalue   :(uint16_t) Cursor of the next option
//******************************************************************************/
//uint16_t LCD_ShowOption(uint16_t sizeBox,uint16_t y,uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
//{
//	uint16_t wCursor;
//	LCD_ClearCursor(10, y, 310, sizeBox+y, bc);
//	LCD_Fill(10, y, 310, y+sizeBox, bc);
//	Gui_StrCenter(0, y, fc, bc, str, size, mode);
//	wCursor = sizeBox+y+10;
//	return wCursor;
//}
//
///*****************************************************************************
// * @name       :void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t fc, uint16_t bc, uint8_t num,uint8_t size,uint8_t mode)
// * @date       :2018-08-09
// * @function   :Display a single English character
// * @parameters :x:the bebinning x coordinate of the Character display position
//                y:the bebinning y coordinate of the Character display position
//								fc:the color value of display character
//								bc:the background color of display character
//								num:the ascii code of display character(0~94)
//								size:the size of display character
//								mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t fc, uint16_t bc, uint8_t num,uint8_t size,uint8_t mode)
//{
//    uint8_t temp;
//    uint8_t pos,t;
//	uint16_t colortemp=POINT_COLOR;
//
//	num=num-' ';
//	LCD_SetWindows(x,y,x+size/2-1,y+size-1);
//	if(!mode)
//	{
//		for(pos=0;pos<size;pos++)
//		{
//			if(size==12)temp=asc2_1206[num][pos];
//			else temp=asc2_1608[num][pos];
//			for(t=0;t<size/2;t++)
//		    {
//		        if(temp&0x01)Lcd_WriteData_16Bit(fc);
//				else Lcd_WriteData_16Bit(bc);
//				temp>>=1;
//
//		    }
//
//		}
//	}else
//	{
//		for(pos=0;pos<size;pos++)
//		{
//			if(size==12)temp=asc2_1206[num][pos];
//			else temp=asc2_1608[num][pos];
//			for(t=0;t<size/2;t++)
//		    {
//				POINT_COLOR=fc;
//		        if(temp&0x01)LCD_DrawPoint(x+t,y+pos);
//		        temp>>=1;
//		    }
//		}
//	}
//	POINT_COLOR=colortemp;
//	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);
//}
//
///*****************************************************************************
// * @name       :void LCD_ShowString(uint16_t x,uint16_t y,uint8_t size,uint8_t *p,uint8_t mode)
// * @date       :2018-08-09
// * @function   :Display English string
// * @parameters :x:the bebinning x coordinate of the English string
//                y:the bebinning y coordinate of the English string
//								p:the start address of the English string
//								size:the size of display character
//								mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//void LCD_ShowString(uint16_t x,uint16_t y,uint8_t size,uint8_t *p,uint8_t mode)
//{
//    while((*p<='~')&&(*p>=' '))//�ж��ǲ��ǷǷ��ַ�!
//    {
//		if(x>(lcddev.width-1)||y>(lcddev.height-1))
//		return;
//        LCD_ShowChar(x,y,POINT_COLOR,BACK_COLOR,*p,size,mode);
//        x+=size/2;
//        p++;
//    }
//}
//
///*****************************************************************************
// * @name       :uint32_t mypow(uint8_t m,uint8_t n)
// * @date       :2018-08-09
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//void LCD_ShowNumAndStr(uint16_t x,uint16_t y,uint8_t size,char *pStr1,uint8_t lengthStr,uint32_t num,uint8_t lengthNum,uint8_t mode)
//{
//	char StrNum[8],StrNumFinal[8];
//	memset(StrNum,0,sizeof(StrNum));
//	memset(StrNumFinal,0,sizeof(StrNumFinal));
//	uint32_t numTemp,temp;
//	uint8_t i = 0,length;
//	LCD_ShowString(x,y,size,(uint8_t*)pStr1,mode);
//	numTemp = num;
//	LCD_DrawLine(x, y+ size, 320-x , y+ size);
//	LCD_DrawLine(x + lengthStr-2, y - 4, x+ lengthStr-2, y + size );
//	if(numTemp == 0)
//	{
//		StrNumFinal[0] += 48;
//	}else{
//		while(numTemp !=0)
//		{
//			temp = numTemp %10;
//			if(temp<10)
//			{
//				temp +=48;
//			}else
//			{
//				temp +=55;
//			}
//			StrNum[i] = temp;
//			i++;
//			numTemp /=10;
//		}
//		length = i-1;
//
//		for(uint8_t k = 0; k <= length; k++)
//		{
//			i--;
//			StrNumFinal[k] = StrNum[i];
//		}
//	}
//
//	LCD_ShowString(x+lengthStr,y,size,(uint8_t*)StrNumFinal,mode);
//}
//
///*****************************************************************************
// * @name       :uint32_t mypow(uint8_t m,uint8_t n)
// * @date       :2018-08-09
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//void LCD_ShowStrAndStr(uint16_t x,uint16_t y,uint8_t size,char *pStr1,uint8_t length1,char *pStr2,uint8_t length2,uint8_t mode)
//{
//	LCD_ShowString(x,y,size,(uint8_t*)pStr1,mode);
//	LCD_ShowString(x+length1,y,size,(uint8_t*)pStr2,mode);
//
//	LCD_DrawLine(x, y+ size, 320-x , y+ size);
//	LCD_DrawLine(x + length1-2, y - 4, x+ length1-2, y + size );
//}
//
///*****************************************************************************
// * @name       :uint32_t mypow(uint8_t m,uint8_t n)
// * @date       :2018-08-09
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//void LCD_ShowButton(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t *pStr,uint8_t state)
//{
//	uint16_t size = 16;
//	LCD_ClearCursor(x, y, x+width, y + height, WHITE);
//	if(state == 1)
//	{
//		LCD_Fill(x , y, x+width, y + height, GREEN);
//		Gui_StrCenterV2(x, y,width, height, BLACK, WHITE, (uint8_t*)pStr, size, 1);
//	}else
//	{
//		LCD_Fill(x, y, x+width, y + height, RED);
//		Gui_StrCenterV2(x, y,width, height, BLACK, WHITE, (uint8_t*)pStr, size, 1);
//	}
//}
//
///*****************************************************************************
// * @name       :uint32_t mypow(uint8_t m,uint8_t n)
// * @date       :2018-08-09
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//uint16_t LCD_ShowDevice(uint16_t x,uint16_t y,uint16_t r,uint8_t *pStr,uint8_t state)
//{
//	//gui_circle(lcddev.width/2-80+(i*25),lcddev.height/2-50+(i*25),ColorTab[i],30,0);
//	uint16_t size = 16;
//	uint16_t len = strlen((const char*)pStr);
//	uint16_t str_width = len*(size/2);
//	LCD_ClearCursor(x+str_width, y, x+2*r+str_width, y + 2*r, WHITE);
//	if(state == 1)
//	{
//		Show_Str(x, y, BLACK, WHITE, pStr, size, 1);
//		gui_circle(150+r, y+size/2, BLACK, r+2, 1);
//		gui_circle(150+r, y+size/2, GREEN, r, 1);
//	}else
//	{
//		Show_Str(x, y, BLACK, WHITE, pStr, size, 1);
//		gui_circle(150+r, y+size/2, BLACK, r+2, 1);
//		gui_circle(150+r, y+size/2, RED, r, 1);
//	}
//	return 150+r;
//}
//
///*****************************************************************************
// * @name       :void LCD_UpdateDeviceState(uint16_t x,uint16_t y,uint16_t r,uint8_t state)
// * @date       :2018-08-09
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//void LCD_UpdateDeviceState(uint16_t x,uint16_t y,uint16_t r,uint8_t state)
//{
//	//gui_circle(lcddev.width/2-80+(i*25),lcddev.height/2-50+(i*25),ColorTab[i],30,0);
//	uint16_t size = 16;
//	if(state == 1)
//	{
//		gui_circle(x, y+size/2, GREEN, r, 1);
//	}else
//	{
//		gui_circle(x, y+size/2, RED, r, 1);
//	}
//}
//
///*****************************************************************************
// * @name       :void LCD_ShowEditNum(uint16_t x,uint16_t y,uint16_t r,uint8_t *pStr,uint32_t Num)
// * @date       :2018-08-09
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//void LCD_ShowEditNum(uint16_t x,uint16_t y,uint8_t *pStr,uint8_t lengthNum)
//{
//	uint16_t size = 16;
//	uint16_t widthStr = 120;
//	uint16_t widthBox = lengthNum*(size/2);
//	uint16_t heightBox = 20;
//	uint16_t XsBox = x + widthStr - 5;
//	uint16_t YsBox = y - 5;
//	uint16_t XeBox = XsBox + widthBox + 5;
//	uint16_t YeBox = YsBox + heightBox+ 5;
//
//	//Draw str
//	Show_Str(x, y, BLACK, WHITE, pStr, size, 1);
//	//Draw edit box
//	LCD_DrawRectangle(XsBox,YsBox,XeBox,YeBox);
//}
//
///*****************************************************************************
// * @name       :void LCD_ShowEditNum(uint16_t x,uint16_t y,uint16_t r,uint8_t *pStr,uint32_t Num)
// * @date       :2018-08-09
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//void LCD_UpdateEditNum(uint16_t xS,uint16_t yS,uint16_t xE,uint16_t yE,uint32_t num)
//{
//	uint16_t size = 16;
//	uint8_t mode = 1;
//	//Convert hex to str
//	char StrNum[8],StrNumFinal[8];
//	uint32_t numTemp,temp;
//	uint8_t i = 0,length;
//	numTemp = num;
//	memset(StrNum,0,sizeof(StrNum));
//	memset(StrNumFinal,0,sizeof(StrNumFinal));
//	if(numTemp == 0)
//	{
//		StrNumFinal[0] += 48;
//	}else{
//		while(numTemp !=0)
//		{
//			temp = numTemp %10;
//			if(temp<10)
//			{
//				temp +=48;
//			}else
//			{
//				temp +=55;
//			}
//			StrNum[i] = temp;
//			i++;
//			numTemp /=10;
//		}
//		length = i-1;
//
//		for(uint8_t k = 0; k <= length; k++)
//		{
//			i--;
//			StrNumFinal[k] = StrNum[i];
//		}
//	}
//	/*
//	while(numTemp !=0)
//	{
//		temp = numTemp %10;
//		if(temp<10)
//		{
//			temp +=48;
//		}else
//		{
//			temp +=55;
//		}
//		StrNum[i] = temp;
//		i++;
//		numTemp /=10;
//	}
//	length = i-1;
//	memset(StrNumFinal,0,sizeof(StrNumFinal));
//	for(uint8_t k = 0; k <= length; k++)
//	{
//		i--;
//		StrNumFinal[k] = StrNum[i];
//	}*/
//	LCD_ClearCursor(xS, yS, xE, yE, WHITE);
//	Gui_StrCenterV2(xS, yS, xE-xS, yE-yS, BLACK, WHITE,(uint8_t*) StrNumFinal, size, mode);
//}
//
///*****************************************************************************
// * @name       :void LCD_ShowBtnUpDown(uint16_t x0,uint16_t y0,uint16_t width,uint16_t height);
// * @date       :2023-03-06
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//void LCD_ShowBtnUpDown(uint16_t x0,uint16_t y0,uint16_t width,uint16_t height)
//{
//	//LCD_Fill(x0 , y0, x0+width, y0 + height, GRED);
//	LCD_DrawRectangle(x0 , y0, x0+width, y0 + height);
//	LCD_SetColorPoint(BLACK);
//	Fill_Triangel(x0+width/2, y0 + 3, x0 + width/2+width/4, y0+height/3, x0 + width/4, y0+height/3);
//	Fill_Triangel(x0+width/4, y0 + height*2/3, x0 + width/2+width/4, y0+height*2/3, x0 + width/2, y0+height-3);
//}
//
///*****************************************************************************
// * @name       :void LCD_UpdateBtnUpDown(uint16_t x0,uint16_t y0,uint16_t width,uint16_t height,uint8_t event);
// * @date       :2023-03-06
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//void LCD_UpdateBtnUpDown(uint16_t x0,uint16_t y0,uint16_t width,uint16_t height,uint8_t event)
//{
//
//}
//
///*****************************************************************************
// * @name       :uint32_t mypow(uint8_t m,uint8_t n)
// * @date       :2018-08-09
// * @function   :get the nth power of m (internal call)
// * @parameters :m:the multiplier
//                n:the power
// * @retvalue   :the nth power of m
//******************************************************************************/
//uint32_t mypow(uint8_t m,uint8_t n)
//{
//	uint32_t result=1;
//	while(n--)result*=m;
//	return result;
//}
//
///*****************************************************************************
// * @name       :void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size)
// * @date       :2018-08-09
// * @function   :Display number
// * @parameters :x:the bebinning x coordinate of the number
//                y:the bebinning y coordinate of the number
//								num:the number(0~4294967295)
//								len:the length of the display number
//								size:the size of display number
// * @retvalue   :None
//******************************************************************************/
//void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size)
//{
//	uint8_t t,temp;
//	uint8_t enshow=0;
//	for(t=0;t<len;t++)
//	{
//		temp=(num/mypow(10,len-t-1))%10;
//		if(enshow==0&&t<(len-1))
//		{
//			if(temp==0)
//			{
//				LCD_ShowChar(x+(size/2)*t,y,POINT_COLOR,BACK_COLOR,' ',size,0);
//				continue;
//			}else enshow=1;
//
//		}
//	 	LCD_ShowChar(x+(size/2)*t,y,POINT_COLOR,BACK_COLOR,temp+'0',size,0);
//	}
//}
//
///*****************************************************************************
// * @name       :void GUI_DrawFont16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
// * @date       :2018-08-09
// * @function   :Display a single 16x16 Chinese character
// * @parameters :x:the bebinning x coordinate of the Chinese character
//                y:the bebinning y coordinate of the Chinese character
//								fc:the color value of Chinese character
//								bc:the background color of Chinese character
//								s:the start address of the Chinese character
//								mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//void GUI_DrawFont16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
//{
//	uint8_t i,j;
//	uint16_t k;
//	uint16_t HZnum;
//	uint16_t x0 = x;
//	HZnum = sizeof(tfont16)/sizeof(typFNT_GB16);
//
//	for (k=0;k<HZnum;k++)
//	{
//	    if ((tfont16[k].Index[0]==*(s))&&(tfont16[k].Index[1]==*(s+1)))
//	    {
//	    	LCD_SetWindows(x,y,x+16-1,y+16-1);
//		    for(i=0;i<16*2;i++)
//		    {
//				for(j=0;j<8;j++)
//		    	{
//					if(!mode)
//					{
//						if(tfont16[k].Msk[i]&(0x80>>j))	Lcd_WriteData_16Bit(fc);
//						else Lcd_WriteData_16Bit(bc);
//					}
//					else
//					{
//						POINT_COLOR=fc;
//						if(tfont16[k].Msk[i]&(0x80>>j))	LCD_DrawPoint(x,y);
//						x++;
//						if((x-x0)==16)
//						{
//							x=x0;
//							y++;
//							break;
//						}
//					}
//
//				}
//
//			}
//
//
//		}
//		continue;
//	}
//
//	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);
//}
//
///*****************************************************************************
// * @name       :void GUI_DrawFont24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
// * @date       :2018-08-09
// * @function   :Display a single 24x24 Chinese character
// * @parameters :x:the bebinning x coordinate of the Chinese character
//                y:the bebinning y coordinate of the Chinese character
//								fc:the color value of Chinese character
//								bc:the background color of Chinese character
//								s:the start address of the Chinese character
//								mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//void GUI_DrawFont24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
//{
//	uint8_t i,j;
//	uint16_t k;
//	uint16_t HZnum;
//	uint16_t x0=x;
//	HZnum=sizeof(tfont24)/sizeof(typFNT_GB24);	//�Զ�ͳ�ƺ�����Ŀ
//
//	for (k=0;k<HZnum;k++)
//	{
//	    if ((tfont24[k].Index[0]==*(s))&&(tfont24[k].Index[1]==*(s+1)))
//	    {
//	    	LCD_SetWindows(x,y,x+24-1,y+24-1);
//			for(i=0;i<24*3;i++)
//			{
//				for(j=0;j<8;j++)
//				{
//					if(!mode)
//					{
//						if(tfont24[k].Msk[i]&(0x80>>j))	Lcd_WriteData_16Bit(fc);
//						else Lcd_WriteData_16Bit(bc);
//					}
//					else
//					{
//						POINT_COLOR=fc;
//						if(tfont24[k].Msk[i]&(0x80>>j))	LCD_DrawPoint(x,y);
//						x++;
//						if((x-x0)==24)
//						{
//							x=x0;
//							y++;
//							break;
//						}
//					}
//				}
//			}
//		}
//		continue;
//	}
//
//	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);
//}
//
///*****************************************************************************
// * @name       :void GUI_DrawFont32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
// * @date       :2018-08-09
// * @function   :Display a single 32x32 Chinese character
// * @parameters :x:the bebinning x coordinate of the Chinese character
//                y:the bebinning y coordinate of the Chinese character
//								fc:the color value of Chinese character
//								bc:the background color of Chinese character
//								s:the start address of the Chinese character
//								mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//void GUI_DrawFont32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
//{
//	uint8_t i, j;
//	uint16_t k;
//	uint16_t HZnum;
//	uint16_t x0 = x;
//	HZnum = sizeof(tfont32)/sizeof(typFNT_GB32);
//	for (k = 0; k < HZnum; k++)
//	{
//	  if ((tfont32[k].Index[0]==*(s))&&(tfont32[k].Index[1]==*(s+1)))
//	  { 	LCD_SetWindows(x,y,x+32-1,y+32-1);
//			for(i=0;i<32*4;i++)
//			{
//				for(j=0;j<8;j++)
//				{
//					if(!mode)
//					{
//						if(tfont32[k].Msk[i]&(0x80>>j))	Lcd_WriteData_16Bit(fc);
//						else Lcd_WriteData_16Bit(bc);
//					}
//					else
//					{
//						POINT_COLOR = fc;
//						if(tfont32[k].Msk[i]&(0x80>>j))	LCD_DrawPoint(x,y);
//						x++;
//						if((x-x0)==32)
//						{
//							x=x0;
//							y++;
//							break;
//						}
//					}
//				}
//			}
//
//
//		}
//		continue;
//	}
//
//	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);
//}
//
///*****************************************************************************
// * @name       :void Show_Str(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
// * @date       :2018-08-09
// * @function   :Display Chinese and English strings
// * @parameters :x:the bebinning x coordinate of the Chinese and English strings
//                y:the bebinning y coordinate of the Chinese and English strings
//								fc:the color value of Chinese and English strings
//								bc:the background color of Chinese and English strings
//								str:the start address of the Chinese and English strings
//								size:the size of Chinese and English strings
//								mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//void Show_Str(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str, uint8_t size, uint8_t mode)
//{
//	uint16_t x0=x;
//  	uint8_t bHz=0;
//    while(*str!=0)
//    {
//        if(!bHz)
//        {
//			if(x>(lcddev.width-size/2)||y>(lcddev.height-size))
//			return;
//	        if(*str>0x80)bHz=1;
//	        else
//	        {
//		        if(*str==0x0D)
//		        {
//		            y+=size;
//					x=x0;
//		            str++;
//		        }
//		        else
//				{
//					if(size>16)
//					{
//					LCD_ShowChar(x,y,fc,bc,*str,16,mode);
//					x+=8;
//					}
//					else
//					{
//					LCD_ShowChar(x,y,fc,bc,*str,size,mode);
//					x+=size/2;
//					}
//				}
//				str++;
//
//	        }
//        }else
//        {
//			if(x>(lcddev.width-size)||y>(lcddev.height-size))
//			return;
//            bHz=0;
//			if(size==32)
//			GUI_DrawFont32(x,y,fc,bc,str,mode);
//			else if(size==24)
//			GUI_DrawFont24(x,y,fc,bc,str,mode);
//			else
//			GUI_DrawFont16(x,y,fc,bc,str,mode);
//
//	        str+=2;
//	        x+=size;
//        }
//    }
//}
//
///*****************************************************************************
// * @name       :void Gui_StrCenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
// * @date       :2018-08-09
// * @function   :Centered display of English and Chinese strings
// * @parameters :x:the bebinning x coordinate of the Chinese and English strings
//                y:the bebinning y coordinate of the Chinese and English strings
//								fc:the color value of Chinese and English strings
//								bc:the background color of Chinese and English strings
//								str:the start address of the Chinese and English strings
//								size:the size of Chinese and English strings
//								mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//
//void Gui_StrCenterV2(uint16_t x, uint16_t y,uint16_t width,uint16_t height, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
//{
//	uint16_t len=strlen((const char *)str);
//	uint16_t x1=(width-len*(size/2))/2;
//	Show_Str(x+x1,y,fc,bc,str,size,mode);
//}
//
///*****************************************************************************
// * @name       :void Gui_StrCenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
// * @date       :2018-08-09
// * @function   :Centered display of English and Chinese strings
// * @parameters :x:the bebinning x coordinate of the Chinese and English strings
//                y:the bebinning y coordinate of the Chinese and English strings
//								fc:the color value of Chinese and English strings
//								bc:the background color of Chinese and English strings
//								str:the start address of the Chinese and English strings
//								size:the size of Chinese and English strings
//								mode:0-no overlying,1-overlying
// * @retvalue   :None
//******************************************************************************/
//void Gui_StrCenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str, uint8_t size, uint8_t mode)
//{
//	uint16_t len = strlen((const char *)str);
//	uint16_t x1 = (lcddev.width - len * (size / 2)) / 2;
//	Show_Str(x1, y, fc, bc, str, size, mode);
//}
//
///*****************************************************************************
// * @name       :void Gui_Drawbmp16(uint16_t x,uint16_t y,const unsigned char *p)
// * @date       :2018-08-09
// * @function   :Display a 16-bit BMP image
// * @parameters :x:the bebinning x coordinate of the BMP image
//                y:the bebinning y coordinate of the BMP image
//								p:the start address of image array
// * @retvalue   :None
//******************************************************************************/
//void Gui_Drawbmp16(uint16_t x,uint16_t y,const unsigned char *p)
//{
//  	int i;
//	unsigned char picH, picL;
//	LCD_SetWindows(x, y, x+240-1, y+320-1);
//    for(i = 0; i < 240*320; i++)
//	{
//	 	picL = *(p + i*2);
//		picH = *(p + i*2+1);
//		Lcd_WriteData_16Bit(picH << 8 | picL);
//	}
//	LCD_SetWindows(0, 0, lcddev.width-1, lcddev.height-1);
//}
//
//void showimage(const unsigned char *p)
//{
//  	int i, j, k;
//	unsigned char picH, picL;
//	LCD_Fill(0, 0, lcddev.width, lcddev.height, WHITE);
//
//	for(k=0;k<3;k++)
//	{
//	   	for(j=0;j<3;j++)
//		{
//	   		LCD_SetWindows(240*j, 240*k, 240*j+239, 240*k+239);
//		    for(i = 0; i < 40*40; i++)
//			{
//			    picL = *(p+i*2);
//				picH = *(p+i*2+1);
//				Lcd_WriteData_16Bit(picH << 8 | picL);
//			}
//		}
//	}
//}
