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
#ifndef _BUZZER_H_
#define _BUZZER_H_
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include <stdint.h>
/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/
#define BUZZER_GPIO_CLK         RCC_APB2Periph_GPIOB
#define BUZZER_GPIO_PORT		GPIOB
#define BUZZER_GPIO_PIN			GPIO_Pin_11
#define BUZZER_GPIO_SOURCE      GPIO_PinSource11
#define BUZZER_GPIO_REMAP       GPIO_FullRemap_TIM2

/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/
typedef struct _tone_buzz_ {
    uint16_t freq;
    uint16_t duration;
} tone_t, *tone_p;
/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/

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
BuzzerControl_Init(void);

/**
 * @func   BuzzerControl_SetMelody
 * @brief  Buzzer set melody
 * @param  pListTone
 * @retval None
 */
void 
BuzzerControl_SetMelody(
    tone_p pListTone
);

/**
 * @func   BuzzerControl_SetDutyCycle
 * @brief  Set duty cycle PWM
 * @param  dutycycle
 * @retval None
 */
void
BuzzerControl_SetDutyCycle(
    uint8_t dutycycle
);

/**
 * @func   BUZZTIM_SetPreriod
 * @brief  Set period PWM
 * @param  period
 * @retval None
 */
void
BuzzerControl_SetPreriod(
	uint32_t period
);

/**
 * @func   BuzzerControl_SendPacketRespond
 * @brief  Respond frame status of buzzer
 * @param  buzzer_state: 0 - 100 %
 * @retval None
 */
void
BuzzerControl_SendPacketRespond(
	uint8_t buzzer_state
);

#endif /* END FILE */
