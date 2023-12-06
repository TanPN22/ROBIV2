///*******************************************************************************
// *
// * Copyright (c) 2023
// * Lumi, JSC.
// * All Rights Reserved
// *
// * Description: Include file for application
// *
// * Author: HoangNH
// *
// * Last Changed By:  $Author: HoangNH $
// * Revision:         $Revision: $
// * Last Changed:     $Date: 21/07/2023 $
// *
//*******************************************************************************/
///******************************************************************************/
///*                              INCLUDE FILES                                 */
///******************************************************************************/
//#include "lcd.h"
//#include "utilities.h"
//
//#include "stm32f10x_gpio.h"
//#include "stm32f10x_rcc.h"
//#include "stm32f10x_spi.h"
///******************************************************************************/
///*                     EXPORTED TYPES and DEFINITIONS                         */
///******************************************************************************/
///******************************************************************************/
///*                              PRIVATE DATA                                  */
///******************************************************************************/
//_lcd_dev lcddev;
//uint16_t POINT_COLOR = 0x0000, BACK_COLOR = 0xFFFF;
///******************************************************************************/
///*                              EXPORTED DATA                                 */
///******************************************************************************/
///******************************************************************************/
///*                            PRIVATE FUNCTIONS                               */
///******************************************************************************/
//static void LCDGPIO_Config(void);
//static void LCDSPI_Config(void);
//static uint8_t LCDSPI_WriteByte(SPI_TypeDef* SPIx, uint8_t data);
///******************************************************************************/
///*                            EXPORTED FUNCTIONS                              */
///******************************************************************************/
//
///**
// * @func	LCD_WR_REG
// * @brief	Write an 8-bit command to the LCD screen
// * @param	Command value to be written
// * @retval  None
//*/
//void LCD_WR_REG(uint8_t data)
//{
//	GPIO_ResetBits(LCD_PORT, DC_PIN);
//	GPIO_ResetBits(LCD_PORT, CS_PIN);
//	LCDSPI_WriteByte(LCD_SPI, data);
//	GPIO_SetBits(LCD_PORT, CS_PIN);
//}
//
///**
// * @func	LCD_WR_DATA
// * @brief	Write an 8-bit data to the LCD screen
// * @param	data value to be written
// * @retval  None
//*/
//void LCD_WR_DATA(uint8_t data)
//{
//	GPIO_SetBits(LCD_PORT, DC_PIN);
//	GPIO_ResetBits(LCD_PORT, CS_PIN);
//	LCDSPI_WriteByte(LCD_SPI, data);
//	GPIO_SetBits(LCD_PORT, CS_PIN);
//}
//
///**
// * @func   	LCD_WriteReg
// * @brief	Write data into registers
// * @param 	LCD_Reg:Register address
//            LCD_RegValue: Data to be written
// * @retval  None
//*/
//void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue)
//{
//	LCD_WR_REG(LCD_Reg);
//	LCD_WR_DATA(LCD_RegValue);
//}
//
///**
// * @func	LCD_WriteRAM_Prepare
// * @brief	Write GRAM
// * @param	None
// * @retval	None
//*/
//void LCD_WriteRAM_Prepare(void)
//{
//	LCD_WR_REG(lcddev.wramcmd);
//}
//
///**
// * @func	Lcd_WriteData_16Bit
// * @param   Write an 16-bit command to the LCD screen
// * @param	Data to be written
// * @retval	None
//*/
//void Lcd_WriteData_16Bit(uint16_t data)
//{
//	GPIO_SetBits(LCD_PORT, DC_PIN);
//	GPIO_ResetBits(LCD_PORT, CS_PIN);
//	LCDSPI_WriteByte(LCD_SPI, data >> 8);
//	LCDSPI_WriteByte(LCD_SPI, data);
//	GPIO_SetBits(LCD_PORT, CS_PIN);
//}
//
///**
// * @func	LCD_SetColorPoint
// * @brief	Set color of point
// * @param	color
// * @retval	None
//******************************************************************************/
//void LCD_SetColorPoint(uint16_t color)
//{
//	POINT_COLOR = color;
//}
//
///**
// * @func	LCD_DrawPoint
// * @brief	Write a pixel data at a specified location
// * @param	x:the x coordinate of the pixel
//            y:the y coordinate of the pixel
// * @retval	None
//*/
//void LCD_DrawPoint(uint16_t x,uint16_t y)
//{
//	LCD_SetCursor(x, y);
//	Lcd_WriteData_16Bit(POINT_COLOR);
//}
//
///**
// * @func	LCD_Clear
// * @brief	Full screen filled LCD screen
// * @param	color:Filled color
// * @retval	None
//*/
//void LCD_Clear(uint16_t Color)
//{
//    unsigned int i, m;
//	LCD_SetWindows(0, 0, lcddev.width - 1, lcddev.height - 1);
//	GPIO_SetBits(LCD_PORT, DC_PIN);
//	GPIO_ResetBits(LCD_PORT, CS_PIN);
//	for(i = 0; i < lcddev.height; i++)
//	{
//        for(m = 0; m < lcddev.width; m++)
//        {
//			Lcd_WriteData_16Bit(Color);
//		}
//	}
//	GPIO_SetBits(LCD_PORT, CS_PIN);
//}
//
///**
// * @func	LCD_ClearCursor
// * @brief	Full screen filled LCD screen
// * @param	wColor:Filled color
// * 			wXs:the bebinning x coordinate of the specified area
//            wYs:the bebinning y coordinate of the specified area
//			wXe:the ending x coordinate of the specified area
//			wYe:the ending y coordinate of the specified area
// * @retval	None
//*/
//void LCD_ClearCursor(uint16_t wXs, uint16_t wYs,
//					 uint16_t wXe, uint16_t wYe,
//					 uint16_t wColor)
//{
//	unsigned int i, m;
//	uint16_t width = wXe - wXs - 1;
//	uint16_t height = wYe - wYs - 1;
//	LCD_SetWindows(wXs, wYs, wXe, wYe);
//	GPIO_SetBits(LCD_PORT, DC_PIN);
//	GPIO_ResetBits(LCD_PORT, CS_PIN);
//	for(i = 0; i < height; i++)
//	{
//		for(m = 0; m < width; m++)
//		{
//			Lcd_WriteData_16Bit(wColor);
//		}
//	}
//	GPIO_SetBits(LCD_PORT, CS_PIN);
//	LCD_SetWindows(0, 0, lcddev.width - 1, lcddev.height - 1);
//}
//
///**
// * @func	LCD_RESET
// * @brief	Reset LCD screen
// * @param	None
// * @retval	None
//*/
//void LCD_RESET(void)
//{
//	GPIO_ResetBits(LCD_PORT, RST_PIN);
//	delay_ms(100);
//	GPIO_SetBits(LCD_PORT, RST_PIN);
//	delay_ms(50);
//}
//
///**
// * @func	LCD_Init
// * @brief	Initialization LCD screen
// * @param	None
// * @retval	None
//*/
//void LCD_Init(void)
//{
//	LCDSPI_Config();
//	LCDGPIO_Config();
// 	LCD_RESET();
//
// 	//*************2.2inch ILI9341****************//
//	LCD_WR_REG(0xCF);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0xD9); //C1
//	LCD_WR_DATA(0X30);
//	LCD_WR_REG(0xED);
//	LCD_WR_DATA(0x64);
//	LCD_WR_DATA(0x03);
//	LCD_WR_DATA(0X12);
//	LCD_WR_DATA(0X81);
//	LCD_WR_REG(0xE8);
//	LCD_WR_DATA(0x85);
//	LCD_WR_DATA(0x10);
//	LCD_WR_DATA(0x7A);
//	LCD_WR_REG(0xCB);
//	LCD_WR_DATA(0x39);
//	LCD_WR_DATA(0x2C);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x34);
//	LCD_WR_DATA(0x02);
//	LCD_WR_REG(0xF7);
//	LCD_WR_DATA(0x20);
//	LCD_WR_REG(0xEA);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x00);
//	LCD_WR_REG(0xC0);  //Power control
//	LCD_WR_DATA(0x21); //VRH[5:0]  //1B
//	LCD_WR_REG(0xC1);  //Power control
//	LCD_WR_DATA(0x12); //SAP[2:0];BT[3:0] //01
//	LCD_WR_REG(0xC5);  //VCM control
//	LCD_WR_DATA(0x39); //3F
//	LCD_WR_DATA(0x37); //3C
//	LCD_WR_REG(0xC7);  //VCM control2
//	LCD_WR_DATA(0XAB); //B0
//	LCD_WR_REG(0x36);  // Memory Access Control
//	LCD_WR_DATA(0x48);
//	LCD_WR_REG(0x3A);
//	LCD_WR_DATA(0x55);
//	LCD_WR_REG(0xB1);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x1B); //1A
//	LCD_WR_REG(0xB6);  // Display Function Control
//	LCD_WR_DATA(0x0A);
//	LCD_WR_DATA(0xA2);
//	LCD_WR_REG(0xF2);  // 3Gamma Function Disable
//	LCD_WR_DATA(0x00);
//	LCD_WR_REG(0x26);  //Gamma curve selected
//	LCD_WR_DATA(0x01);
//
//	LCD_WR_REG(0xE0);  //Set Gamma
//	LCD_WR_DATA(0x0F);
//	LCD_WR_DATA(0x23);
//	LCD_WR_DATA(0x1F);
//	LCD_WR_DATA(0x0B);
//	LCD_WR_DATA(0x0E);
//	LCD_WR_DATA(0x08);
//	LCD_WR_DATA(0x4B);
//	LCD_WR_DATA(0XA8);
//	LCD_WR_DATA(0x3B);
//	LCD_WR_DATA(0x0A);
//	LCD_WR_DATA(0x14);
//	LCD_WR_DATA(0x06);
//	LCD_WR_DATA(0x10);
//	LCD_WR_DATA(0x09);
//	LCD_WR_DATA(0x00);
//	LCD_WR_REG(0XE1); //Set Gamma
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x1C);
//	LCD_WR_DATA(0x20);
//	LCD_WR_DATA(0x04);
//	LCD_WR_DATA(0x10);
//	LCD_WR_DATA(0x08);
//	LCD_WR_DATA(0x34);
//	LCD_WR_DATA(0x47);
//	LCD_WR_DATA(0x44);
//	LCD_WR_DATA(0x05);
//	LCD_WR_DATA(0x0B);
//	LCD_WR_DATA(0x09);
//	LCD_WR_DATA(0x2F);
//	LCD_WR_DATA(0x36);
//	LCD_WR_DATA(0x0F);
//	LCD_WR_REG(0x2B);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x01);
//	LCD_WR_DATA(0x3f);
//	LCD_WR_REG(0x2A);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0xef);
//	LCD_WR_REG(0x11); //Exit Sleep
//	delay_ms(120);
//	LCD_WR_REG(0x29); //Display on
//
//	LCD_direction(USE_HORIZONTAL);
//	LCD_Clear(WHITE);
//}
//
///**
// * @func	LCD_SetWindows
// * @brief	Setting LCD display window
// * @param	xStar:the bebinning x coordinate of the LCD display window
//			yStar:the bebinning y coordinate of the LCD display window
//			xEnd:the endning x coordinate of the LCD display window
//			yEnd:the endning y coordinate of the LCD display window
// * @retval	None
//*/
//void LCD_SetWindows(uint16_t xStar, uint16_t yStar,
//					uint16_t xEnd,  uint16_t yEnd)
//{
//	LCD_WR_REG(lcddev.setxcmd);
//	LCD_WR_DATA(xStar >> 8);
//	LCD_WR_DATA(0x00FF & xStar);
//	LCD_WR_DATA(xEnd >> 8);
//	LCD_WR_DATA(0x00FF & xEnd);
//
//	LCD_WR_REG(lcddev.setycmd);
//	LCD_WR_DATA(yStar >> 8);
//	LCD_WR_DATA(0x00FF & yStar);
//	LCD_WR_DATA(yEnd >> 8);
//	LCD_WR_DATA(0x00FF & yEnd);
//
//	LCD_WriteRAM_Prepare();
//}
//
///**
// * @func	LCD_SetCursor
// * @brief	Set coordinate value
// * @param	Xpos:the  x coordinate of the pixel
//			Ypos:the  y coordinate of the pixel
// * @retval	None
//*/
//void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos)
//{
//	LCD_SetWindows(Xpos, Ypos, Xpos, Ypos);
//}
//
///**
// * @func	LCD_direction
// * @brief	Setting the display direction of LCD screen
// * @param	direction: 0-0 degree
//                       1-90 degree
//					   2-180 degree
//					   3-270 degree
// * @retval	None
//*/
//void LCD_direction(uint8_t direction)
//{
//	lcddev.setxcmd = 0x2A;
//	lcddev.setycmd = 0x2B;
//	lcddev.wramcmd = 0x2C;
//
//	switch(direction){
//		case 0:
//			lcddev.width = LCD_W;
//			lcddev.height = LCD_H;
//			LCD_WriteReg(0x36, (1 << 3) | (0 << 6)| (0 << 7));// BGR == 1, MY == 0, MX == 0, MV == 0
//		    break;
//		case 1:
//			lcddev.width = LCD_H;
//			lcddev.height = LCD_W;
//			LCD_WriteReg(0x36, (1 << 3) | (0 << 7)| (1 << 6) | (1 << 5));// BGR == 1, MY == 1, MX == 0, MV == 1
//		    break;
//		case 2:
//			lcddev.width = LCD_W;
//			lcddev.height = LCD_H;
//			LCD_WriteReg(0x36, (1 << 3) | (1 << 6) | (1 << 7));// BGR == 1, MY == 0, MX == 0, MV == 0
//		    break;
//		case 3:
//			lcddev.width = LCD_H;
//			lcddev.height = LCD_W;
//			LCD_WriteReg(0x36, (1 << 3) | (1 << 7) | (1 <<5 ));// BGR == 1, MY == 1, MX == 0, MV == 1
//		    break;
//		default:
//			break;
//	}
//}
//
///**
// * @func	LCDGPIO_Config
// * @brief	Initialization LCD screen GPIO
// * @param	None
// * @retval	None
//*/
//static void LCDGPIO_Config(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//
//	RCC_AHBPeriphClockCmd(LCD_RCC, ENABLE);
//
//	GPIO_InitStructure.GPIO_Pin = RST_PIN | DC_PIN | CS_PIN;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(LCD_PORT, &GPIO_InitStructure);
//
//	GPIO_SetBits(LCD_PORT, CS_PIN);
//}
//
///**
// * @func   LCDSPI_Config
// * @brief  Initializes peripheral SPI
// * @param  None
// * @retval None
// */
//static void LCDSPI_Config(void)
//{
//	GPIO_InitTypeDef 	GPIO_InitStructure;
//	SPI_InitTypeDef 	SPI_InitStructure;
//
//	/* Enable the SPI periph */
//	RCC_APB1PeriphClockCmd(LCD_SPI_RCC, ENABLE);
//
//	/* Enable SCK, MOSI and NSS GPIO clocks */
//	RCC_AHBPeriphClockCmd(LCD_GPIO_RCC, ENABLE);
//
//	// Connect LCD_SPI pins to SPI Alternate Function
//	GPIO_PinAFConfig(LCD_SPI_PORT, GPIO_PinSource5, LCD_SPI_AF);
//	GPIO_PinAFConfig(LCD_SPI_PORT, GPIO_PinSource6, LCD_SPI_AF);
//	GPIO_PinAFConfig(LCD_SPI_PORT, GPIO_PinSource7, LCD_SPI_AF);
//
//	// Initializes GPIO Use For SPI
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//
//	GPIO_InitStructure.GPIO_Pin = LCD_SPI_GPIO_SCK | LCD_SPI_GPIO_MOSI | LCD_SPI_GPIO_MISO;
//	GPIO_Init(LCD_SPI_PORT, &GPIO_InitStructure);
//
//	/* SPI configuration -----------------------------------------------------*/
//	SPI_I2S_DeInit(LCD_SPI);
//
//	// Set to full duplex mode, separate MOSI and MISO lines
//	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
//
//	// Transmit in master mode
//	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
//
//	// One packet of data is 8 bits wide
//	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
//
//	// Clock is low when idle
//	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
//
//	// Data sampled at first edge
//	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
//
//	// Set NSS us software
//	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
//
//	// SPI frequency is APB2 frequency / 2
//	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
//
//	// Data is transmitted MSB first
//	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
//
//	SPI_InitStructure.SPI_CRCPolynomial = 7;
//
//	SPI_Init(LCD_SPI, &SPI_InitStructure);
//
//	// Enable LCD_SPI
//	SPI_Cmd(LCD_SPI, ENABLE);
//}
//
///**
// * @func   LCDSPI_WriteByte
// * @brief  Write a byte of data using STM32's hardware SPI
// * @param  None
// * @retval None
// */
//static uint8_t LCDSPI_WriteByte(SPI_TypeDef* SPIx, uint8_t data)
//{
//	/* Wait until the transmit buffer is empty */
////	while(SPI_I2S_GetFlagStatus(LCD_SPI, SPI_I2S_FLAG_TXE) != SET)
////	{
////	}
//	/* Send the byte */
//	SPI_SendData8(LCD_SPI, data);
//
////	while(SPI_I2S_GetFlagStatus(LCD_SPI, SPI_I2S_FLAG_RXNE) != SET)
////	{
////	}
////	SPI_ReceiveData8(LCD_SPI);
////
////	while(SPI_I2S_GetFlagStatus(LCD_SPI, SPI_I2S_FLAG_BSY) != RESET)
////	{
////	}
//
//	return 1;
//}
//
///* END_FILE */
