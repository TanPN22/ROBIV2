/*******************************************************************************
 *
 * Copyright (c) 2023
 * Lumi, JSC.
 * All Rights Reserved
 *
 *
 * Description:
 *
 * Author: ThaiHM
 *
 * Last Changed By:  $Author: ThaiHM $
 * Revision:         $Revision: 2.0 $
 * Last Changed:     $Date:  28/11/23 $
 *
 ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "buzzer.h"
#include "serial.h"
#include "timer.h"
#include "utilities.h"

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/
#define BUZZ_TIMER_PRESCALE    36
#define BUZZ_TIMER_PERIOD      200
#define BUZZ_TIMER_RCC_FREQ    36000000

#define BUZZ_PWM_FREQUENCY     (BUZZ_TIMER_RCC_FREQ / (BUZZ_TIMER_PRESCALE * BUZZ_TIMER_PERIOD)) // 5 kHz
/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/
static uint8_t bBuzzInit = 0;
static uint8_t idBuzz = NO_TIMER;
static tone_p gpToneList;
/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
static void BuzzPlay(uint16_t freq, uint16_t duration);
static void BuzzOff(void *arg);
static void BUZZTIM_InitTimer(void);
static void BUZZTIM_InitPWMChannel(void);
/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

/**
 * @func   BuzzerControl_Init
 * @brief  Initialize module buzzer
 * @param  None
 * @retval None
 */
void
BuzzerControl_Init(void) {
	BUZZTIM_InitTimer();
	BUZZTIM_InitPWMChannel();
	bBuzzInit = 1;
}

/**
 * @func   BuzzOff
 * @brief  None
 * @param  None
 * @retval None
 */
static void
BuzzOff(
    void *arg
) {
    idBuzz = NO_TIMER;
    gpToneList++;  /* Next Element */
    if ((gpToneList->freq == 0) && (gpToneList->duration == 0)) {
    	BuzzerControl_SetDutyCycle(0);
    }
    else {
        BuzzPlay(gpToneList->freq, gpToneList->duration);
    }
}

/**
 * @func   BuzzOff
 * @brief  None
 * @param  None
 * @retval None
 */
static void
BuzzPlay(
    uint16_t freq,
	uint16_t duration
) {
    if (freq == 0) {
    	BuzzerControl_SetDutyCycle(0);
    }
    else if (freq == 0xFFFFU) {
    	BuzzerControl_SetPreriod(BUZZ_TIMER_PERIOD);
    	BuzzerControl_SetDutyCycle(100);
    }
    else {
        BuzzerControl_SetPreriod(BUZZ_TIMER_RCC_FREQ / (BUZZ_TIMER_PRESCALE * freq));
        BuzzerControl_SetDutyCycle(20);
    }

    if (idBuzz != NO_TIMER) {
        TimerStop(idBuzz);
        idBuzz = NO_TIMER;
    }

    idBuzz = TimerStart("buzz", duration, TIMER_REPEAT_ONE_TIME, BuzzOff, NULL);
}

/**
 * @func   BuzzerControl_SetMelody
 * @brief  Buzzer set melody
 * @param  pListTone
 * @retval None
 */
void 
BuzzerControl_SetMelody(
    tone_p pListTone   
) {
    if (!bBuzzInit) return;
    gpToneList = pListTone;
    BuzzPlay(gpToneList->freq, gpToneList->duration);
}

/**
 * @func   BuzzerControl_SetDutyCycle
 * @brief  Set duty cycle PWM
 * @param  dutycycle
 * @retval None
 */
void
BuzzerControl_SetDutyCycle(
    uint8_t dutycycle
) {
	uint32_t value;
	uint32_t period = TIM1->ARR; // Get period of timer

	if (dutycycle > 100) return;

	value = (dutycycle * period) / 100;

	TIM_SetCompare4(TIM1, value);
}

/**
 * @func   BUZZTIM_SetPreriod
 * @brief  Set period PWM
 * @param  period
 * @retval None
 */
void
BuzzerControl_SetPreriod(
	uint32_t period
) {
	if (period == 0) period = 1;
    TIM1->ARR = period - 1;
}

/**
 * @func   BuzzerControl_SendPacketRespond
 * @brief  Respond frame status of buzzer
 * @param  buzzer_state: times beep
 * @retval None
 */
void
BuzzerControl_SendPacketRespond(
	uint8_t buzzer_state
) {
	uint8_t byPayload[CMD_SIZE_OF_PAYLOAD_BUZZER];

	byPayload[0] = buzzer_state;

	/* Send message uart button press 1 time */
	Serial_SendPacket(CMD_OPT_NOT_USE,
					  CMD_ID_BUZZER,
					  CMD_TYPE_RES,
					  byPayload,
					  sizeof(byPayload));
}

/**
 * @func   BUZZTIM_InitTimer
 * @brief  Initialize peripheral timer
 * @param  [prescale]
 *         [period]
 * @retval None
 */
static void
BUZZTIM_InitTimer(void) {
    TIM_TimeBaseInitTypeDef TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	/* Time base configuration */
    TimeBaseStructure.TIM_Prescaler = BUZZ_TIMER_PRESCALE - 1;
    TimeBaseStructure.TIM_Period = BUZZ_TIMER_PERIOD - 1;
    TimeBaseStructure.TIM_ClockDivision = 0;
    TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TimeBaseStructure);

    /* TIM1 enable counter */
    TIM_Cmd(TIM2, ENABLE);
}

/**
 * @func   TIMPWM_InitChannel
 * @brief  None
 * @param  None
 * @retval None
 */
static void
BUZZTIM_InitPWMChannel(void) {
    GPIO_InitTypeDef 	GPIO_InitStructure;
    TIM_OCInitTypeDef 	TIM_OCInitStructure;

    /* GPIO Peripheral clock enable */
    RCC_APB2PeriphClockCmd(BUZZER_GPIO_CLK, ENABLE);

    /* Configure pin in output push-pull mode */
    GPIO_InitStructure.GPIO_Pin = BUZZER_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(BUZZER_GPIO_PORT, &GPIO_InitStructure);

    GPIO_PinRemapConfig(BUZZER_GPIO_REMAP, ENABLE);

    /* Output Compare Timing Mode configuration: Channel 4 */
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; /* PWM1 Mode */
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_Pulse = 0;

    TIM_OC4Init(TIM2, &TIM_OCInitStructure);

    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM2, ENABLE);
}

/* END_FILE */
