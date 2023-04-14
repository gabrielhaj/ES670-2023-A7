/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "buttons.h"
#include "led.h"
#include "help.h"
#include "matrixKeyboard.h"
#include "buttonsEvents.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BT_Up_Pin GPIO_PIN_1
#define BT_Up_GPIO_Port GPIOC
#define BT_Up_EXTI_IRQn EXTI1_IRQn
#define BT_Down_Pin GPIO_PIN_2
#define BT_Down_GPIO_Port GPIOC
#define BT_Down_EXTI_IRQn EXTI2_IRQn
#define BT_Left_Pin GPIO_PIN_3
#define BT_Left_GPIO_Port GPIOC
#define BT_Left_EXTI_IRQn EXTI3_IRQn
#define LPUART1_TX_Pin GPIO_PIN_2
#define LPUART1_TX_GPIO_Port GPIOA
#define LPUART1_RX_Pin GPIO_PIN_3
#define LPUART1_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define BT_Right_Pin GPIO_PIN_4
#define BT_Right_GPIO_Port GPIOC
#define BT_Right_EXTI_IRQn EXTI4_IRQn
#define BT_Enter_Pin GPIO_PIN_0
#define BT_Enter_GPIO_Port GPIOB
#define BT_Enter_EXTI_IRQn EXTI0_IRQn
#define KB_Lin4_Pin GPIO_PIN_11
#define KB_Lin4_GPIO_Port GPIOB
#define KB_Lin3_Pin GPIO_PIN_12
#define KB_Lin3_GPIO_Port GPIOB
#define KB_Lin2_Pin GPIO_PIN_13
#define KB_Lin2_GPIO_Port GPIOB
#define KB_Lin1_Pin GPIO_PIN_15
#define KB_Lin1_GPIO_Port GPIOB
#define KB_Col4_Pin GPIO_PIN_7
#define KB_Col4_GPIO_Port GPIOC
#define KB_Col3_Pin GPIO_PIN_8
#define KB_Col3_GPIO_Port GPIOC
#define KB_Col2_Pin GPIO_PIN_9
#define KB_Col2_GPIO_Port GPIOC
#define KB_Col1_Pin GPIO_PIN_10
#define KB_Col1_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define T_SWO_Pin GPIO_PIN_3
#define T_SWO_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

#define BT_ENTER_PORT          GPIOB
#define BT_ENTER_PIN           GPIO_PIN_0
#define BT_UP_PORT             GPIOC
#define BT_UP_PIN              GPIO_PIN_1
#define BT_DOWN_PORT           GPIOC
#define BT_DOWN_PIN            GPIO_PIN_2
#define BT_LEFT_PORT           GPIOC
#define BT_LEFT_PIN            GPIO_PIN_3
#define BT_RIGHT_PORT          GPIOC
#define BT_RIGHT_PIN           GPIO_PIN_4
#define LED_GREEN1_PORT        GPIOA
#define LED_GREEN1_PIN         GPIO_PIN_5
#define LED_YELLOW_PORT		   GPIOA
#define LED_YELLOW_PIN         GPIO_PIN_4
#define LED_RED_PORT           GPIOB
#define LED_RED_PIN            GPIO_PIN_14
#define LED_GREEN2_PORT        GPIOA
#define LED_GREEN2_PIN         GPIO_PIN_12
#define LED_BLUE_PORT		   GPIOB
#define LED_BLUE_PIN           GPIO_PIN_5

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
