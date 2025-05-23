/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TIM_FREQ 8000000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
uint8_t mode=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */
bool state = true;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */


  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  int Ref_time=2;

  /* Blue Start */
  HAL_GPIO_TogglePin(LED_Red_GPIO_Port, LED_Red_Pin);
  /* Eyes on*/
  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
  HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);

  /* Display OFF */
  DisplayNumber(0,10);

  /* Start PWM */
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  switch (mode){
	  case 0:
		  __HAL_TIM_SET_PRESCALER(&htim3, 0);

		  DisplayNumber(1,1);
		  HAL_Delay(Ref_time);
		  DisplayNumber(2,2);
		  HAL_Delay(Ref_time);
		  DisplayNumber(3,3);
		  HAL_Delay(Ref_time);
		  DisplayNumber(4,4);
		  HAL_Delay(Ref_time);
		  DisplayNumber(5,10);
		  HAL_Delay(Ref_time);

		  break;

	  case 1:
		  DisplayNumber(0,10);
		  __HAL_TIM_SET_PRESCALER(&htim3, presForFrequency(900));
		  HAL_Delay(150);
		  __HAL_TIM_SET_PRESCALER(&htim3, presForFrequency(500));
		  HAL_Delay(400);
		  __HAL_TIM_SET_PRESCALER(&htim3, 0);
		  HAL_Delay(1000);
		  break;

	  }

//	  HAL_GPIO_TogglePin(LED_Blue_GPIO_Port, LED_Blue_Pin);
//	  HAL_GPIO_TogglePin(LED_Red_GPIO_Port, LED_Red_Pin);
//	  __HAL_TIM_SET_PRESCALER(&htim3, presForFrequency(900));
//	  HAL_Delay(150);
//	  __HAL_TIM_SET_PRESCALER(&htim3, presForFrequency(500));
//	  HAL_Delay(400);
//	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 4000;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 50;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 100;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 50;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, LED_Blue_Pin|LED_Red_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|DispD_Pin|Display1_Pin
                          |Display2_Pin|DisplayL_Pin|Display3_Pin|Display4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DispDP_Pin|DispE_Pin|DispF_Pin|DispC_Pin
                          |DispA_Pin|DispG_Pin|DispB_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_Blue_Pin LED_Red_Pin */
  GPIO_InitStruct.Pin = LED_Blue_Pin|LED_Red_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED2_Pin DispD_Pin Display1_Pin
                           Display2_Pin DisplayL_Pin Display3_Pin Display4_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|DispD_Pin|Display1_Pin
                          |Display2_Pin|DisplayL_Pin|Display3_Pin|Display4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : B_Button_EXTI_Pin A_Button_EXTI_Pin */
  GPIO_InitStruct.Pin = B_Button_EXTI_Pin|A_Button_EXTI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : DispDP_Pin DispE_Pin DispF_Pin DispC_Pin
                           DispA_Pin DispG_Pin DispB_Pin */
  GPIO_InitStruct.Pin = DispDP_Pin|DispE_Pin|DispF_Pin|DispC_Pin
                          |DispA_Pin|DispG_Pin|DispB_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

int presForFrequency (int frequency)
{
	if (frequency == 0) return 0;
	return ((TIM_FREQ/(100*frequency))-1);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
	if(GPIO_Pin == A_Button_EXTI_Pin && state == true){
		HAL_TIM_Base_Start_IT(&htim1);
		state = false;
	}

	else if(GPIO_Pin == B_Button_EXTI_Pin && state == true){
		HAL_TIM_Base_Start_IT(&htim1);
		state = false;
	}

	else{
		__NOP();
	}

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if(HAL_GPIO_ReadPin(B_Button_EXTI_GPIO_Port, B_Button_EXTI_Pin) == GPIO_PIN_RESET){
		HAL_GPIO_TogglePin(LED_Blue_GPIO_Port, LED_Red_Pin);
		HAL_GPIO_TogglePin(LED_Blue_GPIO_Port, LED_Blue_Pin);
		state = true;
		HAL_TIM_Base_Stop_IT(&htim1);
	}
	else if(HAL_GPIO_ReadPin(A_Button_EXTI_GPIO_Port, A_Button_EXTI_Pin) == GPIO_PIN_RESET){
		mode=mode+1;
		if (mode>=2)
			mode=0;
		state = true;
		HAL_TIM_Base_Stop_IT(&htim1);
	}
}

/* 7seg display related from here */
void DisplayNumber(uint8_t Position, uint8_t Number){
	switch (Position){
		case 1:
			HAL_GPIO_WritePin(Display1_GPIO_Port, Display1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Display2_GPIO_Port, Display2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display3_GPIO_Port, Display3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display4_GPIO_Port, Display4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DisplayL_GPIO_Port, DisplayL_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(Display1_GPIO_Port, Display1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display2_GPIO_Port, Display2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Display3_GPIO_Port, Display3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display4_GPIO_Port, Display4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DisplayL_GPIO_Port, DisplayL_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(Display1_GPIO_Port, Display1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display2_GPIO_Port, Display2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display3_GPIO_Port, Display3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Display4_GPIO_Port, Display4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DisplayL_GPIO_Port, DisplayL_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(Display1_GPIO_Port, Display1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display2_GPIO_Port, Display2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display3_GPIO_Port, Display3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display4_GPIO_Port, Display4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DisplayL_GPIO_Port, DisplayL_Pin, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(Display1_GPIO_Port, Display1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display2_GPIO_Port, Display2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display3_GPIO_Port, Display3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display4_GPIO_Port, Display4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DisplayL_GPIO_Port, DisplayL_Pin, GPIO_PIN_RESET);
			break;
		case 0:
			//all off
			HAL_GPIO_WritePin(Display1_GPIO_Port, Display1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display2_GPIO_Port, Display2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display3_GPIO_Port, Display3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Display4_GPIO_Port, Display4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DisplayL_GPIO_Port, DisplayL_Pin, GPIO_PIN_SET);
			break;

	}

	switch (Number){
		//case 0:

		case 1:
			HAL_GPIO_WritePin(DispA_GPIO_Port, DispA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispB_GPIO_Port, DispB_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispC_GPIO_Port, DispC_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispD_GPIO_Port, DispD_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispE_GPIO_Port, DispE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispF_GPIO_Port, DispF_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispG_GPIO_Port, DispG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispDP_GPIO_Port, DispDP_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(DispA_GPIO_Port, DispA_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispB_GPIO_Port, DispB_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispC_GPIO_Port, DispC_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispD_GPIO_Port, DispD_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispE_GPIO_Port, DispE_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispF_GPIO_Port, DispF_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispG_GPIO_Port, DispG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispDP_GPIO_Port, DispDP_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(DispA_GPIO_Port, DispA_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispB_GPIO_Port, DispB_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispC_GPIO_Port, DispC_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispD_GPIO_Port, DispD_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispE_GPIO_Port, DispE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispF_GPIO_Port, DispF_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispG_GPIO_Port, DispG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispDP_GPIO_Port, DispDP_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(DispA_GPIO_Port, DispA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispB_GPIO_Port, DispB_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispC_GPIO_Port, DispC_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispD_GPIO_Port, DispD_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispE_GPIO_Port, DispE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispF_GPIO_Port, DispF_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispG_GPIO_Port, DispG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DispDP_GPIO_Port, DispDP_Pin, GPIO_PIN_SET);
			break;
		case 10:
			//all off
			HAL_GPIO_WritePin(DispA_GPIO_Port, DispA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispB_GPIO_Port, DispB_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispC_GPIO_Port, DispC_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispD_GPIO_Port, DispD_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispE_GPIO_Port, DispE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispF_GPIO_Port, DispF_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispG_GPIO_Port, DispG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DispDP_GPIO_Port, DispDP_Pin, GPIO_PIN_SET);
			break;
	}

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
