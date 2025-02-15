/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Blue_Pin GPIO_PIN_0
#define LED_Blue_GPIO_Port GPIOF
#define LED_Red_Pin GPIO_PIN_1
#define LED_Red_GPIO_Port GPIOF
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOA
#define B_Button_EXTI_Pin GPIO_PIN_5
#define B_Button_EXTI_GPIO_Port GPIOA
#define B_Button_EXTI_EXTI_IRQn EXTI4_15_IRQn
#define Timer3_PWM_Pin GPIO_PIN_6
#define Timer3_PWM_GPIO_Port GPIOA
#define A_Button_EXTI_Pin GPIO_PIN_7
#define A_Button_EXTI_GPIO_Port GPIOA
#define A_Button_EXTI_EXTI_IRQn EXTI4_15_IRQn
#define DispDP_Pin GPIO_PIN_0
#define DispDP_GPIO_Port GPIOB
#define DispE_Pin GPIO_PIN_1
#define DispE_GPIO_Port GPIOB
#define DispD_Pin GPIO_PIN_8
#define DispD_GPIO_Port GPIOA
#define Display1_Pin GPIO_PIN_9
#define Display1_GPIO_Port GPIOA
#define Display2_Pin GPIO_PIN_10
#define Display2_GPIO_Port GPIOA
#define DisplayL_Pin GPIO_PIN_11
#define DisplayL_GPIO_Port GPIOA
#define Display3_Pin GPIO_PIN_12
#define Display3_GPIO_Port GPIOA
#define Display4_Pin GPIO_PIN_15
#define Display4_GPIO_Port GPIOA
#define DispF_Pin GPIO_PIN_3
#define DispF_GPIO_Port GPIOB
#define DispC_Pin GPIO_PIN_4
#define DispC_GPIO_Port GPIOB
#define DispA_Pin GPIO_PIN_5
#define DispA_GPIO_Port GPIOB
#define DispG_Pin GPIO_PIN_6
#define DispG_GPIO_Port GPIOB
#define DispB_Pin GPIO_PIN_7
#define DispB_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
