///*******************************************************************************
// *
// * Copyright (c) 2023
// * Lumi, JSC.
// * All Rights Reserved
// *
// *
// * Description:
// *
// * Author: ThaiHM
// *
// * Last Changed By:  $Author: ThaiHM $
// * Revision:         $Revision: 2.0 $
// * Last Changed:     $Date:  28/11/23 $
// *
//*******************************************************************************/
//#ifndef _LCD_H_
//#define _LCD_H_
///******************************************************************************/
///*                              INCLUDE FILES                                 */
///******************************************************************************/
//#include <stdint.h>
//#include "stm32f10x.h"
///******************************************************************************/
///*                     EXPORTED TYPES and DEFINITIONS                         */
///******************************************************************************/
///*! @brief LCD Pins */
//#define LCD_SPI					SPI2
//#define LCD_SPI_RCC				RCC_APB1Periph_SPI2
//#define LCD_GPIO_RCC			RCC_APB2Periph_GPIOB
//
//#define LCD_SPI_PORT			GPIOB
//#define LCD_SPI_GPIO_CS			GPIO_Pin_12
//#define LCD_SPI_GPIO_SCK		GPIO_Pin_13
//#define LCD_SPI_GPIO_MOSI		GPIO_Pin_15
//
//#define LCD_SPI_AF				GPIO_AF_0
//
//#define LCD_GPIO_PORT			GPIOA
//#define LCD_GPIO_RCC			RCC_APB2Periph_GPIOA
//
//#define LCD_RST_PIN 			GPIO_Pin_8
//#define LCD_A0_PIN 			    GPIO_Pin_11
//#define LCD_LED_PIN 			GPIO_Pin_12
//
//#define USE_HORIZONTAL  	0
//
///*! @brief LCD pixels */
//#define LCD_W 				240
//#define LCD_H 				320
//
///*! @brief Color */
//#define WHITE       		0xFFFF
//#define BLACK      			0x0000
//#define BLUE       			0x001F
//#define BRED        		0XF81F
//#define GRED 				0XFFE0
//#define GBLUE				0X07FF
//#define RED         		0xF800
//#define MAGENTA     		0xF81F
//#define GREEN       		0x07E0
//#define CYAN        		0x7FFF
//#define YELLOW      		0xFFE0
//#define BROWN 				0XBC40
//#define BRRED 				0XFC07
//#define GRAY  				0X8430
////GUI
//
//#define DARKBLUE      	 	0X01CF
//#define LIGHTBLUE      	 	0X7D7C
//#define GRAYBLUE       	 	0X5458
//
//#define LIGHTGREEN     		0X841F
//#define LIGHTGRAY     		0XEF5B
//#define LGRAY 				0XC618
//
//#define LGRAYBLUE      		0XA651
//#define LBBLUE          	0X2B12
//
///*! @brief structure lcd */
//typedef struct
//{
//	uint16_t width;
//	uint16_t height;
//	uint16_t id;
//	uint16_t wramcmd;
//	uint16_t setxcmd;
//	uint16_t setycmd;
//}_lcd_dev;
//
//typedef struct
//{
//	uint16_t LCD_REG;
//	uint16_t LCD_RAM;
//}LCD_TypeDef;
//
///******************************************************************************/
///*                              PRIVATE DATA                                  */
///******************************************************************************/
///******************************************************************************/
///*                              EXPORTED DATA                                 */
///******************************************************************************/
//extern _lcd_dev lcddev;
//extern uint16_t POINT_COLOR;
//extern uint16_t BACK_COLOR;
///******************************************************************************/
///*                            EXPORTED FUNCTIONS                              */
///******************************************************************************/
////void LCD_Init(void);
////void LCD_SetColorPoint(uint16_t color);
////void LCD_Clear(uint16_t Color);
////void LCD_ClearCursor(uint16_t wXs,uint16_t wYs,
////					 uint16_t wXe, uint16_t wYe,
////					 uint16_t wColor);
////void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
////void LCD_DrawPoint(uint16_t x, uint16_t y);
////void LCD_DrawLine(uint16_t x1, uint16_t y1,
////				  uint16_t x2, uint16_t y2);
////void LCD_DrawRectangle(uint16_t x1, uint16_t y1,
////					   uint16_t x2, uint16_t y2);
////void LCD_SetWindows(uint16_t xStar, uint16_t yStar,
////					uint16_t xEnd, uint16_t yEnd);
////void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);
////void LCD_WR_DATA(uint8_t data);
////void LCD_WriteRAM_Prepare(void);
////void Lcd_WriteData_16Bit(uint16_t Data);
////void LCD_direction(uint8_t direction );
////
////#endif
