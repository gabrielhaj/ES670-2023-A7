/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef hlpuart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_LPUART1_UART_Init(void);
/* USER CODE BEGIN PFP */
void buttonsInitButtons(void);
void ledInitLed(void);
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
	int count[6] = {0,0,0,0,0,0};
	buttons i;
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
  MX_LPUART1_UART_Init();
  /* USER CODE BEGIN 2 */
  buttonsInitButtons();
  ledInitLed();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  /*Testing functions implemented in lab03:*/
	  /*Button Up = Led Green 1, count[1]*/
	  /*Button Down = Led Yellow, count[2]*/
	  /*Button Left = Led Red*, count[3]*/
	  /*Button Right = Led Green2, count4]*/
	  /*Button Enter = Led Blue, count[5]*/
	  /*Pressing button 1x = Turn on Led*/
	  /*Pressing button 2x = Turn off Led*/
	  /*Pressing button 3x = Toggle Led*/
	  for(i = up; i<= enter; i++){
		  if(buttonsReadStatus(i) && (count[i] == 0)){
			  count[i]++;
			  ledOn(i);
		  }else if(buttonsReadStatus(i) && (count[i] == 1)){
			  count[i]++;
			  ledOff(i);
		  }else if(buttonsReadStatus(i) && (count[i] == 2)){
			  count[i] ++;
			  ledToggle(i);
		  }else if(buttonsReadStatus(i) && (count[i] == 3)){
			  count[i] = 0;
			  ledToggle(i);
		  }
		  /*For a better functionality, include the delay*/
		  /*HAL_Delay(50);*/
	  }


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

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief LPUART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_LPUART1_UART_Init(void)
{

  /* USER CODE BEGIN LPUART1_Init 0 */

  /* USER CODE END LPUART1_Init 0 */

  /* USER CODE BEGIN LPUART1_Init 1 */

  /* USER CODE END LPUART1_Init 1 */
  hlpuart1.Instance = LPUART1;
  hlpuart1.Init.BaudRate = 115200;
  hlpuart1.Init.WordLength = UART_WORDLENGTH_8B;
  hlpuart1.Init.StopBits = UART_STOPBITS_1;
  hlpuart1.Init.Parity = UART_PARITY_NONE;
  hlpuart1.Init.Mode = UART_MODE_TX_RX;
  hlpuart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  hlpuart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  hlpuart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  hlpuart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&hlpuart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&hlpuart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&hlpuart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&hlpuart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LPUART1_Init 2 */

  /* USER CODE END LPUART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */
void buttonsInitButtons(void){
	/*Initializing all the buttons registers, as knowns as: PC and PB*/
	RCC->AHB2ENR |= 0x2;
	RCC->AHB2ENR |= 0x4;
	/*Alternative way: SET_BIT(RCC->AHB2ENR,PB)*/
	/*Clock initialized*/

	/*Setting mode for BT_Enter - PB0 - positions 0 and 1 = 3dec*/
	CLEAR_BIT(BT_ENTER_PORT->MODER,3); /*00 = input mode*/
	/*Setting mode for BT_UP - PC1 - positions 2 and 3 = 12 (3*4)dec and 0xC*/
	CLEAR_BIT(BT_UP_PORT->MODER,(3<<(1*2))); /*00 = input mode*/
	/*Setting mode for BT_DOWN - PC2 - positions 4 and 5 = 48(3*4^2)dec and 0x30*/
	CLEAR_BIT(BT_DOWN_PORT->MODER,(3<<(2*2))); /*00 = input mode*/
	/*Setting mode for BT_LEFT - PC3 - positions 6 and 7 = 192(3*4^3)dec and  0xC0*/
	CLEAR_BIT(BT_LEFT_PORT->MODER,(3<<(3*2))); /*00 = input mode*/
	/*Setting mode for BT_RIGHT - PC4 - positions 8 and 9 = 192(3*4^4)dec and 0x300*/
	CLEAR_BIT(BT_RIGHT_PORT->MODER,(3<<(4*2))); /*00 = input mode*/

	/*Setting Pull-up Pull-down config (Same logic as before)*/
	CLEAR_BIT(BT_ENTER_PORT->PUPDR,3); /*00 = No pull-up or pull-down*/
	CLEAR_BIT(BT_UP_PORT->PUPDR,(3<<(1*2)));
	CLEAR_BIT(BT_DOWN_PORT->PUPDR,(3<<(2*2)));
	CLEAR_BIT(BT_LEFT_PORT->PUPDR,(3<<(3*2)));
	CLEAR_BIT(BT_RIGHT_PORT->PUPDR,(3<<(4*2)));
}

void ledInitLed(void){
	RCC->AHB2ENR |= 0x0; /*Enabling clock for GPIOA*/

	/*Setting operation mode for all the LEDS*/
	/*Output mode = 01*/
	/*Green Led 1 - Pin 5 */
	SET_BIT(LED_GREEN1_PORT->MODER,(1<<(5*2)));
	CLEAR_BIT(LED_GREEN1_PORT->MODER,(1<<((5*2)+1)));
	/*Yellow Led - Pin 4 */
	SET_BIT(LED_YELLOW_PORT->MODER,(1<<(4*2)));
	CLEAR_BIT(LED_YELLOW_PORT->MODER,(1<<((4*2)+1)));
	/*Green Led 2 - Pin 12*/
	SET_BIT(LED_GREEN2_PORT->MODER,(1<<(12*2)));
	CLEAR_BIT(LED_GREEN2_PORT->MODER,(1<<((12*2)+1)));
	/*Blue Led - Pin 5*/
	SET_BIT(LED_BLUE_PORT->MODER,(1<<(5*2)));
	CLEAR_BIT(LED_BLUE_PORT->MODER,(1<<((5*2)+1)));
	/*Red Led - Pino 14 */
	SET_BIT(LED_RED_PORT->MODER,(1<<(14*2)));
	CLEAR_BIT(LED_RED_PORT->MODER,(1<<((14*2)+1)));

	/*Setting Pull-up Pull-down config (Same logic as before)*/
	CLEAR_BIT(LED_GREEN1_PORT->PUPDR,3<<(5*2)); /*00 = No pull-up or pull-down*/
	CLEAR_BIT(LED_YELLOW_PORT->PUPDR,3<<(4*2));
	CLEAR_BIT(LED_RED_PORT->PUPDR,3<<(14*2));
	CLEAR_BIT(LED_GREEN2_PORT->PUPDR,3<<(12*2));
	CLEAR_BIT(LED_BLUE_PORT->PUPDR,3<<(5*2));

	/*Setting Speed config (Same logic as before)*/
	CLEAR_BIT(LED_GREEN1_PORT->OSPEEDR,3<<(5*2)); /*00 = Low Speed*/
	CLEAR_BIT(LED_YELLOW_PORT->OSPEEDR,3<<(4*2));
	CLEAR_BIT(LED_RED_PORT->OSPEEDR,3<<(15*2));
	CLEAR_BIT(LED_GREEN2_PORT->OSPEEDR,3<<(12*2));
	CLEAR_BIT(LED_BLUE_PORT->OSPEEDR,3<<(5*2));
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
