/*******************************************************************************
 *
 * Copyright (c) 2020
 * Lumi, JSC.
 * All Rights Reserved
 *
 * Description: Assignment 1
 *
 * Author: Developer embedded team
 *
 * Last Changed By:  $Author: ThaiHM $
 * Revision:         $Revision: 1.0.5 $
 * Last Changed:     $Date: 23/11/2020 $
 *
 ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "system_stm32f10x.h"
#include "timer.h"
#include "eventman.h"
#include "led.h"
#include "melody.h"
#include "eventbutton.h"
#include "button.h"
#include "gui.h"
#include "lcd.h"
#include "optical_sensor.h"
#include "motor.h"
#include "pid.h"
#include "encoder.h"
#include "serial.h"
#include "utilities.h"
#include "stm32f10x_gpio.h"
/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/
/*! @brief Events APIs */
typedef enum {
    EVENT_EMPTY,
    EVENT_APP_INIT,
    EVENT_APP_FLUSHMEM_READY,
} event_api_t, *event_api_p;

typedef enum {
    STATE_APP_STARTUP,
    STATE_APP_IDLE,
    STATE_APP_RESET
} state_app_t;

/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/
static state_app_t eCurrentState;

/*@brief BlinkLed values */
static SSwTimer idTimerLedRed = NO_TIMER;
static SSwTimer idTimerLedGreen = NO_TIMER;
static SSwTimer idTimerLedBlue = NO_TIMER;

/*@brief Encoder values */
volatile uint32_t encoderL_speed;
volatile uint32_t encoderR_speed;

/*@brief PID state values */
bool statePID = true;
uint32_t TimeStart = 0;

/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/
/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
static void AppInitCommon(void);
static void SetStateApp(state_app_t state);
static state_app_t GetStateApp(void);
static void AppStateManager(uint8_t event);
static void DeviceStateMachine(uint8_t event);
void SetLed_Red(void *arg);
void SetLed_Green(void *arg);
void SetLed_Blue(void *arg);
void BlinkLed(void);
uint32_t CalculatorTime(uint32_t dwTimeInit, uint32_t dwTimeCurrent);
void delay_mls(uint32_t milisecond);
static void LineFollow_Process(void);

void PrintfDebug(void *arg);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

int timeBuffer = 0;
int ADC_Read[5];
int chothang = 0;
int main(void)
{
    // Initialize modules
    AppInitCommon();
//    SetStateApp(STATE_APP_STARTUP);
//    EventSchedulerAdd(EVENT_APP_INIT);

    while (1)
    {
        /* Process tasks */
//        processTimerScheduler();
//        processEventScheduler();
    		LineFollow_Process();

//        DEBUG_Print("Cho thang SHIBAL: %d\n",chothang);
//        chothang++;
//        delay_ms(100);
//        LedControl_SetColorGeneral(LED_KIT_ID, LED_COLOR_RED, 100);
//        BuzzerControl_SetMelody(pbeep);
//        GPIO_SetBits(GPIOB, GPIO_Pin_11);
//        delay_mls(500);
//        LedControl_SetColorGeneral(LED_KIT_ID, LED_COLOR_RED, 0);
//        BuzzerControl_SetMelody(0);
//        GPIO_ResetBits(GPIOB, GPIO_Pin_11);
//		delay_mls(500);
//        MotorControl_ForwardRotating(MOTOR_ID_L, 100);
//        MotorControl_ReverseRotating(MOTOR_ID_R, 100);
    }
}

/**
 * @func   AppInitCommon
 * @brief  Initialize common application
 * @param  None
 * @retval None
 */
static
void AppInitCommon(void)
{
    // Initializes system clock 48 MHz
	SystemInit();
    SystemCoreClockUpdate();

    // Initializes system tick
    TimerInit();

    // Initializes scheduler event
    EventSchedulerInit(AppStateManager);

    // Initializes buttons
    EventButton_Init();

    // Initializes buzzer
    BuzzerControl_Init();

    // Initializes led
    LedControl_Init();

    // Initializes IR sensor
    OpticalSensor_Init(ADC_READ_MODE_DMA);

    // Initializes lcd
//    LCD_Init();
//    LCD_direction(1);

    // Initializes motor
    MotorControl_Init();

    // Initializes encoder
    Encoder_Init();

    // Initializes UART peripheral
	Serial_Init();

//	BlinkLed();

//	LCD_Init();
//	LCD_direction(1);

//	LCD_ClearCursor(50, 210, 200, 240, WHITE);
//	Gui_StrCenter(100, 100, BLACK, WHITE, (uint8_t*)"I Love Embedded Programming", 16, 1);
}

/**
 * @func   LoadConfiguration
 * @brief  Event start up of application
 * @param  None
 * @retval None
 */
void
LoadConfiguration(void)
{

}

/**
 * @func   AppStateManager
 * @brief  Manager state application
 * @param  None
 * @retval None
 */
static
void AppStateManager(
    uint8_t event)
{
    switch (GetStateApp())
    {
        case STATE_APP_STARTUP:
            if (event == EVENT_APP_INIT)
            {
            	// Load configuration
                LoadConfiguration();
                SetStateApp(STATE_APP_IDLE);
            }
            break;

        case STATE_APP_IDLE:
            DeviceStateMachine(event);
            break;

        case STATE_APP_RESET:
            break;

        default:
            break;
    }
}

/**
 * @func   SetStateApp
 * @brief  Set state of application
 * @param  state: State of application
 * @retval None
 */
static
void SetStateApp(
    state_app_t state
) {
    /* Set state of application */
    eCurrentState = state;
}

/**
 * @func   GetStateApp
 * @brief  Get state of application
 * @param  None
 * @retval State of application
 */
static
state_app_t GetStateApp(void) {
    /* Return state of application */
    return eCurrentState;
}

/**
 * @func   DeviceStateMachine
 * @brief  State machine of the device
 * @param  event
 * @retval None
 */
void
DeviceStateMachine(
    uint8_t event
) {
    switch (event)
    {
		case EVENT_OF_BUTTON_BACK_PRESS_LOGIC:
			SamplingBlack();
			break;

        case EVENT_OF_BUTTON_NEXT_PRESS_LOGIC:
        	SamplingWhite();
            break;

        case EVENT_OF_BUTTON_OK_PRESS_LOGIC:
        	Calculate_AdcThreshold();
            break;

        case EVENT_OF_BUTTON_OK_PRESS_2_TIMES:
        	statePID = true;
			break;

        case EVENT_OF_BUTTON_OK_PRESS_3_TIMES:
        	statePID = false;
			break;

        case EVENT_OF_BUTTON_OK_PRESS_4_TIMES:
        	break;

        case EVENT_OF_BUTTON_BACK_PRESS_2_TIMES:
        	break;

        case EVENT_OF_BUTTON_NEXT_PRESS_2_TIMES:
			break;

        default:
            break;
    }
}

/**
 * @func   SetLed_Red
 * @brief  Set Red Led Color
 * @param  None
 * @retval None
 */
void SetLed_Red(void *arg)
{
	LedControl_SetColorGeneral(LED_KIT_ID, LED_COLOR_RED, 100);
}

/**
 * @func   SetLed_Green
 * @brief  Set Green Led Color
 * @param  None
 * @retval None
 */
void SetLed_Green(void *arg)
{
	LedControl_SetColorGeneral(LED_KIT_ID, LED_COLOR_GREEN, 100);
}

/**
 * @func   SetLed_Blue
 * @brief  Set Blue Led Color
 * @param  None
 * @retval None
 */
void SetLed_Blue(void *arg)
{
	LedControl_SetColorGeneral(LED_KIT_ID, LED_COLOR_BLUE, 100);
}

/**
 * @func   BlinkLed
 * @brief  Blink led R-G-B color
 * @param  None
 * @retval None
 */
void BlinkLed(void)
{
	if (idTimerLedRed != NO_TIMER) {
		TimerStop(idTimerLedRed);
		idTimerLedRed = NO_TIMER;
	}

	idTimerLedRed = TimerStart("BlinkLed_Red",
							   500,
							   TIMER_REPEAT_FOREVER,
							   SetLed_Red,
							   NULL);

	if (idTimerLedGreen != NO_TIMER) {
		TimerStop(idTimerLedGreen);
		idTimerLedGreen = NO_TIMER;
	}

	idTimerLedGreen = TimerStart("idTimerLedGreen",
							     1000,
							     TIMER_REPEAT_FOREVER,
								 SetLed_Green,
							     NULL);

	if (idTimerLedBlue != NO_TIMER) {
		TimerStop(idTimerLedBlue);
		idTimerLedBlue = NO_TIMER;
	}

	idTimerLedBlue = TimerStart("idTimerLedBLue",
								1500,
								TIMER_REPEAT_FOREVER,
								SetLed_Blue,
								NULL);
}

/*
 *@func		CalculatorTime
 *@brief	Calculator time button
 *@param	None
 *@retval	None
 */
uint32_t CalculatorTime(uint32_t dwTimeInit, uint32_t dwTimeCurrent)
{
	uint32_t dwTimeTotal;

	if(dwTimeCurrent >= dwTimeInit){

		dwTimeTotal = dwTimeCurrent - dwTimeInit;
	}
	else{
		dwTimeTotal = 0xFFFFFFFFU + dwTimeCurrent - dwTimeInit;
	}

	return dwTimeTotal;
}

/*
 *@func		delay_ms
 *@brief	delay milisecond
 *@param	None
 *@retval	None
 */
void delay_mls(uint32_t milisecond)
{
	uint32_t startTime = GetMilSecTick(); //Luu lai thoi gian hien tai.

	while (CalculatorTime(startTime, GetMilSecTick()) <= milisecond);
}

static
void LineFollow_Process(void)
{
	if (CalculatorTime(TimeStart, GetMilSecTick()) > 10) {
		if(statePID == true) {
			MotorControl_PID();
		}

		TimeStart = GetMilSecTick();
	}
}

/* END_FILE */
