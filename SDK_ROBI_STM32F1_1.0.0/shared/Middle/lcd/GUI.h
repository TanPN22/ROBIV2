/**************************************************************************************************/
 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/
#ifndef __GUI_H__
#define __GUI_H__

#include <stdint.h>

void GUI_DrawPoint(uint16_t x,uint16_t y,uint16_t color);
void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color);
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void Draw_Circle(uint16_t x0,uint16_t y0,uint16_t fc,uint8_t r);
void Draw_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void Fill_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);

void LCD_ShowTitle(uint16_t sizeBox,uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode);
uint16_t LCD_ShowOption(uint16_t sizeBox,uint16_t y,uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode);
void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t fc, uint16_t bc, uint8_t num,uint8_t size,uint8_t mode);
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);
void LCD_Show2Num(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint8_t size,uint8_t mode);
void LCD_ShowString(uint16_t x,uint16_t y,uint8_t size,uint8_t *p,uint8_t mode);
void LCD_ShowNumAndStr(uint16_t x,uint16_t y,uint8_t size,char *pStr1,uint8_t lengthStr,uint32_t num,uint8_t lengthNum,uint8_t mode);
void LCD_ShowStrAndStr(uint16_t x,uint16_t y,uint8_t size,char *pStr1,uint8_t length1,char *pStr2,uint8_t length2,uint8_t mode);
void showimage(const unsigned char *p);

void LCD_ShowButton(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t *pStr,uint8_t state);
uint16_t LCD_ShowDevice(uint16_t x,uint16_t y,uint16_t r,uint8_t *pStr,uint8_t state);
void LCD_UpdateDeviceState(uint16_t x,uint16_t y,uint16_t r,uint8_t state);

void LCD_ShowEditNum(uint16_t x,uint16_t y,uint8_t *pStr,uint8_t lengthNum);
void LCD_UpdateEditNum(uint16_t xS,uint16_t yS,uint16_t xE,uint16_t yE,uint32_t num);

void LCD_ShowBtnUpDown(uint16_t x0,uint16_t y0,uint16_t width,uint16_t height);
void LCD_UpdateBtnUpDown(uint16_t x0,uint16_t y0,uint16_t width,uint16_t height,uint8_t event);

void GUI_DrawFont16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode);
void GUI_DrawFont24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode);
void GUI_DrawFont32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode);
void Show_Str(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode);
void Gui_Drawbmp16(uint16_t x,uint16_t y,const unsigned char *p); //��ʾ40*40 QQͼƬ
void gui_circle(int xc, int yc,uint16_t c,int r, int fill);
void Gui_StrCenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode);
void Gui_StrCenterV2(uint16_t x, uint16_t y,uint16_t width,uint16_t height, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode);
void LCD_DrawFillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

#endif

/* END_FILE */
