/*******************************************************************************
 *
 * Copyright (c) 2020
 * Lumi, JSC.
 * All Rights Reserved
 *
 *
 * Description:
 *
 * Author: HoangNH
 *
 * Last Changed By:  $Author: HoangNH $
 * Revision:         $Revision: 1.1 $
 * Last Changed:     $Date: 10/07/20 $
 *
 ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "stm32f10x_gpio.h"
#include "misc.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "serial.h"
#include "timer.h"
#include "buff.h"
#include "utilities.h"
#include "stdarg.h"
#include "string.h"
#include "stdio.h"
/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/
#define SIZE_BUFF_DATA_RX                 256

#if (SIZE_BUFF_DATA_RX & (SIZE_BUFF_DATA_RX - 1)) != 0
#error "SIZE_BUFF_DATA_RX must be a power of two"
#endif

#define SIZE_BUFF_DATA_TX                 256

#if (SIZE_BUFF_DATA_TX & (SIZE_BUFF_DATA_TX - 1)) != 0
#error "SIZE_BUFF_DATA_TX must be a power of two"
#endif
/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/
static uint8_t byRxBufState;
static uint8_t byIndexRxBuf;
static uint8_t byCheckXorRxBuf;
static uint32_t dwTimeoutRx;
static uint8_t bRxActive = 0;
uint16_t byReceiverData;

uint8_t byRxBuffer[RX_BUFFER_SIZE] = {0};

static buffqueue_t serialQueueRx;
static uint8_t pBuffDataRx[SIZE_BUFF_DATA_RX];

static void *g_pUartQueueRx[USART_COUNT] = { 0 };

static serial_handle_event pSerialHandleEvent;
/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/
/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
void UART_RegBufferRx(uint8_t byUartNumber, buffqueue_p pQueueRx);
void UART_Init(uint8_t byUartNumber, uint32_t dwBaudRate, uint8_t byParity, uint8_t byStopBit);
static void TimerGetCurrentTime(uint32_t *pdwTimerStartTick);
static uint32_t TimerGetElapsedTime(uint32_t dwTimerStartTick);
static uint8_t PollRxBuff(void);
static uint8_t CalculateCheckXOR(uint8_t *byRespFrame, uint8_t bySizeFrame);
/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

/**
 * @func   TimerGetCurrentTime   
 * @brief  Read the current time
 * @param  pdwTimerStartTick: current time
 * @retval None
 */
void TimerGetCurrentTime(
	uint32_t *pdwTimerStartTick
) {
    *pdwTimerStartTick = GetMilSecTick();
}

/**
 * @func   TimerGetElapsedTime   
 * @brief  Return the Time elapsed since a fix moment in Time
 * @param  dwTimerStartTick: fix moment in Time
 * @retval Elapsed Time in 10 ms ticks
 */
uint32_t TimerGetElapsedTime(
	uint32_t dwTimerStartTick
) {
    return (GetMilSecTick() - dwTimerStartTick);
}

/**
 * @func   Serial_Init
 * @brief  Initialize UART and receive buffer register
 * @param  None
 * @retval None
 */
void
Serial_Init(void) {
    /* Initializes receive register buffer  */
    bufInit(pBuffDataRx, &serialQueueRx, sizeof(pBuffDataRx[0]), SIZE_BUFF_DATA_RX);
	UART_RegBufferRx(USART1_IDX, &serialQueueRx);

    /* Initializes UART */
    UART_Init(USART1_IDX, BAUD9600, NO_PARITY, ONE_STOP_BIT);
	byRxBufState = (uint8_t)RX_STATE_START_BYTE;
}

/**
 * @func   SerialHandleEventCallback
 * @brief  None
 * @param  None
 * @retval None
 */
void
SerialHandleEventCallback(
	serial_handle_event pSerialEvent
) {
	pSerialHandleEvent = pSerialEvent;
}

/**
 * @func   PollRxBuff
 * @brief  Process received data
 * @param  None
 * @retval byUartState: uart state received
 */
uint8_t
PollRxBuff(void) {
    uint8_t byRxData;
    uint8_t byUartState = (uint8_t)UART_STATE_IDLE;
    
    while ((bufNumItems(&serialQueueRx) != 0) && (byUartState == UART_STATE_IDLE))
    {
        bufDeDat(&serialQueueRx, &byRxData);

        switch (byRxBufState) {
            case RX_STATE_START_BYTE:
                if (byRxData == FRAME_SOF) {
                    byIndexRxBuf = 0;
                    bRxActive = 1;
                    byCheckXorRxBuf = CXOR_INIT_VAL;
                    byRxBufState = RX_STATE_DATA_BYTES;
                    TimerGetCurrentTime(&dwTimeoutRx);
                }
                else if (byRxData == FRAME_ACK) {
                    byUartState = UART_STATE_ACK_RECEIVED;
                }
                else if (byRxData == FRAME_NACK) {
                    byUartState = UART_STATE_NACK_RECEIVED;
                }
                else {
                    bRxActive = 0;
                    byUartState= UART_STATE_ERROR;
                }
                break;
            
            case RX_STATE_DATA_BYTES:
                if (byIndexRxBuf < RX_BUFFER_SIZE) {
                    byRxBuffer[byIndexRxBuf] = byRxData;
                    if (byIndexRxBuf > 0) {
                        /* Calculate check xor */
                        byCheckXorRxBuf ^= byRxData;
                    }
                    if (++byIndexRxBuf == FlenBuf) {
                        byRxBufState = RX_STATE_CXOR_BYTE;
                    }
                }
                else {
                    byRxBufState = RX_STATE_START_BYTE;
                    byUartState = UART_STATE_ERROR;
                }
                TimerGetCurrentTime(&dwTimeoutRx);
                break;
                
            case RX_STATE_CXOR_BYTE:
                if (byRxData == byCheckXorRxBuf) {
                    byUartState = UART_STATE_DATA_RECEIVED;
                }
                else {
                    byUartState = UART_STATE_ERROR;
                }
                bRxActive = 0;
                
            default:
                byRxBufState = RX_STATE_START_BYTE;
                break;
        }
    }
    
    /* Check timeout rx */
    if (byUartState == UART_STATE_IDLE) {
        if (bRxActive && (TimerGetElapsedTime(dwTimeoutRx) >= RX_TIMEOUT)) {
            bRxActive = 0;
            byRxBufState = RX_STATE_START_BYTE;
            byUartState  = UART_STATE_RX_TIMEOUT;
        }
    }
    
    return byUartState;
}

/**
 * @func   SendACK
 * @brief  Send message ACK
 * @param  None
 * @retval None
 */
void
SendACK(void) {
}

/**
 * @func   SendNACK
 * @brief  Send message NACK
 * @param  None
 * @retval None
 */
void
SendNACK(void) {
}

/**
 * @func   procSerialReceiver
 * @brief  Process data received from uart
 * @param  None
 * @retval None
 */
void
processSerialReceiver(void) {
    uint8_t stateRx;

    stateRx = PollRxBuff();

    if (stateRx != UART_STATE_IDLE) {
        switch (stateRx) {
            case UART_STATE_ACK_RECEIVED:
            	SendACK();
                break;
                
            case UART_STATE_NACK_RECEIVED:
            	SendNACK();
                break;
                
            case UART_STATE_DATA_RECEIVED:
            	if (pSerialHandleEvent != NULL) {
					pSerialHandleEvent((void *)&byRxBuffer[2]);
				}
				break;
                
            case UART_STATE_ERROR:
            case UART_STATE_RX_TIMEOUT:
                SendNACK();
                break;
            
            default:
                break;
        }
    }
}

/**
 * @func   Serial_SendPacket
 * @brief  Process transmit message uart
 * @param  byOption: Option
 * @param  byCmdId: Identify
 * @param  byType: Type
 * @param  pPayload: Payload
 * @param  byLengthPayload: Length payload
 * @retval None
 */
void
Serial_SendPacket(
    uint8_t byOption,
    uint8_t byCmdId,
    uint8_t byType,
    uint8_t* pPayload,
    uint8_t byLengthPayload
) {
    static uint8_t bySeq = 0;
    uint8_t byOffset = 0;
    uint8_t byBufferTx[CMD_LENGTH_MAX];
    uint8_t checkxor;
    
    byBufferTx[byOffset++] = FRAME_SOF;
    byBufferTx[byOffset++] = byLengthPayload + 5; /* Include: opt + id + type + seq + cxor */
    byBufferTx[byOffset++] = byOption;
    byBufferTx[byOffset++] = byCmdId;
    byBufferTx[byOffset++] = byType;
    
    for (uint8_t i = 0; i < byLengthPayload; i++) {
        byBufferTx[byOffset++] = pPayload[i];
    }
    
    byBufferTx[byOffset++] = bySeq++;
    checkxor = CalculateCheckXOR(&byBufferTx[2], byOffset - 2);
    byBufferTx[byOffset++] = checkxor;
    
    /* Send frame to Host via UART */
    for (uint8_t i = 0; i < byOffset; i++) {
    	while(USART_GetFlagStatus(USARTx_INSTANCE, USART_FLAG_TXE) == RESET);
    	USART_SendData(USARTx_INSTANCE, byBufferTx[i]);
		while(USART_GetFlagStatus(USARTx_INSTANCE, USART_FLAG_TC) == RESET) {}
    }
}

/**
 * @func   CalculateCheckXOR
 * @brief  Calculate value XOR
 * @param  pbyTxBuffer:
           bySizeFrame: Size of frame
 * @retval check_XOR
 */
static uint8_t
CalculateCheckXOR(
    uint8_t *pbyTxBuffer,
    uint8_t bySizeFrame
) {
    uint8_t byCXOR = CXOR_INIT_VAL;
    for (uint8_t byCntSize = 0; byCntSize < bySizeFrame; byCntSize++)
    {
        byCXOR ^= *pbyTxBuffer;
        pbyTxBuffer++;
    }
    return byCXOR;
}

/**
 * @func   UART_RegBufferRx
 * @brief  Initializes register buffer receive
 * @param  byUartNumber: Select the UART peripheral
 *   This parameter can be one of the following values:
 *   UART0_IDX, UART1_IDX, UART2_IDX
 * @param  pQueueRx:
 * @retval None
 */
void
UART_RegBufferRx(
    uint8_t byUartNumber,
    buffqueue_p pQueueRx
) {
    g_pUartQueueRx[byUartNumber] = pQueueRx;
}

/**
 * @func   UART_Init
 * @brief  Initializes the UART object and MCU peripheral
 * @param  byUartNumber: Select the UART peripheral
 *   This parameter can be one of the following values:
 *   UART0_IDX, UART1_IDX, UART2_IDX
 * @param  dwBaudRate: Configures the UART communication baud rate
 * @param  byParity:  Specifies the number of stop bits transmitted
 * @param  byStopBit: Specifies the parity mode
 * @retval None
 */
void
UART_Init(
    uint8_t byUartNumber,
	uint32_t dwBaudRate,
	uint8_t byParity,
	uint8_t byStopBit
) {
    GPIO_InitTypeDef 	GPIO_InitStructure;
    USART_InitTypeDef 	USART_InitStructure;
    NVIC_InitTypeDef 	NVIC_InitStructure;

    /* Enable clock for FPIO and USART */
    RCC_AHBPeriphClockCmd(USARTx_TX_GPIO_CLK | USARTx_RX_GPIO_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(USARTx_CLK, ENABLE);

    /* USARTx Tx pin setup */
    GPIO_InitStructure.GPIO_Pin = USARTx_TX_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStructure);

    /* USARTx Rx pin setup */
	GPIO_InitStructure.GPIO_Pin = USARTx_RX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStructure);

    /* USART setup */
    USART_InitStructure.USART_BaudRate = dwBaudRate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USARTx_INSTANCE, &USART_InitStructure);

    /* Enable USARTx Receive and Transmit interrupts */
    USART_ITConfig(USARTx_INSTANCE, USART_IT_RXNE, ENABLE);
    USART_ITConfig(USARTx_INSTANCE, USART_IT_TXE, DISABLE);

	/* NVIC configuration */
    /* Configure the NVIC Preemption Priority Bits */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	/* Enable the USARTx Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable USART */
	USART_Cmd(USARTx_INSTANCE, ENABLE);
}

/**
 * @func   UART_DRIVER_IRQHandler
 * @brief  This function handles UART interrupt request
 * @param  byUartNumber: Select the UART peripheral
 *   This parameter can be one of the following values:
 *   UART1_IDX, UART2_IDX
 * @retval None
 */
void
USART1_IRQHandler(void) {
    if (USART_GetITStatus(USARTx_INSTANCE, USART_IT_RXNE) == SET) {
        buffqueue_p pUartBuffQueueRx = (buffqueue_p) g_pUartQueueRx[0];
        byReceiverData = USART_ReceiveData(USARTx_INSTANCE);
        if (bufEnDat(pUartBuffQueueRx, &byReceiverData) == ERR_BUF_FULL) {}
        USART_ClearITPendingBit(USARTx_INSTANCE, USART_IT_RXNE);
    }
}

/**
 * @func   DEBUG_Print
 * @brief
 * @param  None
 * @retval None
 */
void DEBUG_Print(const char* string,...) {

    char buf[100] = {0, };     // this should really be sized appropriately
                       // possibly in response to a call to vsnprintf()
    va_list vl;
    va_start (vl, string);

    vsnprintf( buf, sizeof( buf), string, vl);

    va_end ( vl);

    for(char i = 0; i < strlen(buf) ; i++) {
    	while(USART_GetFlagStatus(USARTx_INSTANCE, USART_FLAG_TXE) == RESET);
    	USART_SendData(USARTx_INSTANCE, (uint16_t)buf[i]);
		while(USART_GetFlagStatus(USARTx_INSTANCE, USART_FLAG_TC) == RESET) {}
    }
}

/* END FILE */
