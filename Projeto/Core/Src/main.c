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
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include <stdio.h>
#include <string.h>
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

/* USER CODE BEGIN PV */
extern screens xScreen;
extern screens xActualScreen;
extern TIM_HandleTypeDef *pTimerMatrixKeyboard;
extern TIM_HandleTypeDef *pTimDebouncer;
extern TIM_HandleTypeDef *pTimPressedTime;
extern TIM_HandleTypeDef *pCounterBuzzer;
extern TIM_HandleTypeDef *pBuzzer;
extern TIM_HandleTypeDef *pTachometerWindow;
extern TIM_HandleTypeDef *pTachometer;
extern unsigned int  uiCounterButtons[5]; //Time counter for each button, remember that each button is associated to a number (Enter = 0, Up = 1 ...)
extern ADC_HandleTypeDef hadc1;
extern char cFlagLongPressTimer;
extern float fSetPointTemperature;
extern unsigned char ucData;
unsigned int ui1sCounter = 0;
extern char cBackLight;
extern float fHeaterPWMDutyCycle;
extern float fCoolerPWMDutyCycle;
extern unsigned short int usCoolerSpeed;
extern uint16_t usTemperature;
unsigned char ucLcdAddress = 0x27;
float fCurrentTemperature;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
  MX_DMA_Init();
  MX_LPUART1_UART_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  MX_TIM16_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM5_Init();
  MX_TIM8_Init();
  MX_TIM20_Init();
  MX_TIM4_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
  vButtonsInit();
  //vMatrixKeyboardInit(&htim6);
  //vBuzzerConfig(1000, 100, &htim20);
  vTachometerInit(&htim4,500);
  vTemperatureSensorInit(&hadc1);
  vPidInit(600, 1, 0, 100, 100);
  HAL_UART_Receive_IT(&hlpuart1, (uint8_t*)&ucData, 1);
  vLcdInitLcd(&hi2c1,ucLcdAddress);
  vHeaterAndCoolerCoolerInit(&htim8);
  vHeaterAndCoolerHeaterInit(&htim1);
  vButtonsEventsInit(&htim7, &htim16);
  HAL_TIM_Base_Start_IT(&htim6);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //Updates the screen every 100ms or
	  //if the screen have been changed by a button
	  if(xActualScreen != xScreen || !(ui1sCounter%200)){
		  xActualScreen = xScreen;
		  vLcdUpdateScreen(xActualScreen);
	  }

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

/* USER CODE BEGIN 4 */

/* ***************************************************************** */
/* Method name:        HAL_TIM_PeriodElapsedCallback                 */
/* Method description: Call each callback related to the tim that    */
/*                     called the general callback                   */
/* Input params:       TIM_HandleTypeDef* htim: generic tim handler  */
/* Output params:                                                    */
/* ***************************************************************** */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(htim == &htim6){
		ui1sCounter ++;
		if(ui1sCounter == 10000)
			ui1sCounter = 0;
		vPIDPeriodicControlTask();
	}

	else if(htim == pTachometerWindow) {
		vTachometerUpdate();
		pTachometer->Instance->CNT = 0;
	}
	else {
		//pTimerButtonsEventsDebouncing = Pointer that holds the handler TIM7 address (&htim7)
		// Utilized by ButtonsEvents library
		if(htim == pTimDebouncer){
			vButtonsEventsDebouncingPeriodElapsedCallback();
		} else if(htim == pTimPressedTime) {
			//pTimerButtonsEventsLongPress = Pointer that holds the handler TIM16 address (&htim16)
			// Utilized by ButtonsEvents library
			vButtonsEventsLongPressPeriodElapsedCallback();
		}
	}

}

/* ***************************************************************** */
/* Method name:        vButtonsEventsCallbackPressedEvent            */
/* Method description: Calls change screen function                  */
/* Input params:  xBt buttons                                        */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventCallbackPressedEvent(buttons xBt){
	vButtonsEventChangeScreen(xBt);
}

/* ***************************************************************** */
/* Method name:        vButtonsEventsCallbackReleasedEvent           */
/* Method description: Stop pressed timer and reset its flag         */
/* Input params:  xBt buttons                                        */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventCallbackReleasedEvent(buttons xBt){
	if(uiCounterButtons[0] == 0 && uiCounterButtons[1] == 0 && uiCounterButtons[2] == 0 && uiCounterButtons[3] == 0 && uiCounterButtons[4] == 0){
		//Verify if all counters are 0, therefore all buttons are released and turns off the timer
		HAL_TIM_Base_Stop_IT(pTimPressedTime);
		cFlagLongPressTimer = 0;
	}
}

/* ***************************************************************** */
/* Method name:        vButtonsEventsCallback500msPressedEvent       */
/* Method description: Calls Pressed event callback if the button is */
/*                     continusly pressed every 500ms                */
/* Input params:  xBt buttons                                        */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventCallback500msPressedEvent(buttons xBt){
	vButtonsEventCallbackPressedEvent(xBt); // the events of 500 ms have the same effect as single press
}


/* ***************************************************************** */
/* Method name:        vPIDPeriodicControlTask                       */
/* Method description: Gets actual temperature, set point temperature*/
/*                     and calls the controller.                     */
/*                     Then takes the controller output and feed the */
/*                     actuator function                             */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vPIDPeriodicControlTask(){
	float fSensorValue, fSetPoint, fActuatorValue;
	fSensorValue = fTemperatureSensorGetTemperature();
	fSetPoint = fPIDGetSetPointTemperature();
	fActuatorValue = fPidUpdateData(fSensorValue,fSetPoint);
	vPIDActuatorSetValue(fActuatorValue);
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
