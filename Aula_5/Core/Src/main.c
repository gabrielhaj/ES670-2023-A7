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
#include <string.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include <stdio.h>
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
extern TIM_HandleTypeDef *pTimerMatrixKeyboard;
extern TIM_HandleTypeDef *pTimDebouncer;
extern TIM_HandleTypeDef *pTimPressedTime;
extern TIM_HandleTypeDef *pCounterBuzzer;
extern TIM_HandleTypeDef *pBuzzer;
extern TIM_HandleTypeDef *pTachometerWindow;
extern TIM_HandleTypeDef *pTachometer;
extern unsigned int  uiCounterButtons[5]; //Time counter for each button, remember that each button is associated to a number (Enter = 0, Up = 1 ...)
extern ADC_HandleTypeDef hadc1;
int iLedValue = 0;
extern char cFlagLongPressTimer;
extern unsigned short int usBuzzerPeriod;
float fCurrentTemperature = 36.5;
float fSetPointTemperature = 80;
unsigned char ucButtonsBlocked = 0;
unsigned char ucDutyHeater  = 10;
unsigned char ucDutyCooler = 20;
unsigned char ucData = 0;
unsigned int ui1sCounter = 0;
unsigned int uiTimeCounter = 0;
unsigned int uiTimeCounterBuzzer = 0;
extern char cBackLight;
char cTestLine2[16];
char cFlagLcd = 0;
char cFlagLcdTachometer = 0;
char cFlag500ms = 0;
char *cTestString;
char cFlag100ms = 0;
char *pDummy = {0};
unsigned int uiMask;
unsigned int uiMasked;
unsigned int uiBit;
unsigned char ucLcdAddress = 0x27;
float fHeaterPWMDutyCycle = 0;
float fCoolerPWMDutyCycle = 0;
extern unsigned short int usCoolerSpeed;
uint16_t usTemperature;
float fTemp;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void vInitButtons(void);
void vInitLed(void);

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
  vLedInit();
  vLcdInitLcd(&hi2c1,ucLcdAddress);
  vMatrixKeyboardInit(&htim6);
  vButtonsEventsInit(&htim7, &htim16);
  vHeaterAndCoolerCoolerInit(&htim8);
  vHeaterAndCoolerHeaterInit(&htim1);
  vBuzzerConfig(1000, 100, &htim20);
  vTachometerInit(&htim4,500);
  vTemperatureSensorInit(&hadc1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_UART_Receive_IT(&hlpuart1, (uint8_t*)&ucData, 1);
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  fTemp = fTemperatureSensorGetTemperature();
	  if(cFlag100ms){
		  vCommunicationStateMachineProcessStateMachine('-');
		  vCommunicationStateMachineProcessStateMachine('g');
		  vCommunicationStateMachineProcessStateMachine('t');
		  vCommunicationStateMachineProcessStateMachine('!');
		  cFlag100ms = 0;
	  }
	  if(cFlag500ms){
		  vLcdSendCommand(CMD_CLEAR);
		  vLcdBackLightOn();
		  vLcdSetCursor(0,1);
		  vLcdWriteString("Temperatura:");
		  vLcdSetCursor(1,0);
		  cTestString = vFtoa(fTemp,'0');
		  strcat(cTestString,"C");
		  vLcdWriteString(cTestString);
		  cFlag500ms = 0;
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


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	//pTimerMatrixKeyboard = Pointer that holds the handler TIM6 address (&htim6)
	// Utilized by MatrixKeyboard Library
	if(htim == pTimerMatrixKeyboard){
		vMatrixKeyboardPeriodElapsedCallback();
		ui1sCounter ++;
		if(!(ui1sCounter % 10)) {
			cFlag100ms = 1;
		}
		if(ui1sCounter % 50 == 0) {
			cFlag500ms = 1;
		}
		if(ui1sCounter == 100) {
		  cFlagLcd = 1;
		  ui1sCounter = 0;
		  uiTimeCounter ++;
		  if(cBackLight) {
			  vLcdBackLightOff();
		  } else {
			  vLcdBackLightOn();
		  }
		}

	}
	else if(htim == pCounterBuzzer){
		uiTimeCounterBuzzer ++;

		if(uiTimeCounterBuzzer == 10) {
			uiTimeCounterBuzzer = 0;
			HAL_TIM_Base_Stop_IT(pCounterBuzzer);
			HAL_TIM_PWM_Stop(pBuzzer, TIM_CHANNEL_1);
		}
	}
	else if(htim == pTachometerWindow) {
		vTachometerUpdate();
		pTachometer->Instance->CNT = 0;
		cFlagLcdTachometer = 1;

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

void vButtonsEventCallbackPressedEvent(buttons xBt){
	if(xBt == up){
		if(fCoolerPWMDutyCycle < 1) {
			fCoolerPWMDutyCycle = fCoolerPWMDutyCycle + 0.1;
			if(fCoolerPWMDutyCycle > 1) {
				fCoolerPWMDutyCycle = 1;
			}
			vHeaterAndCoolerCoolerfanPWMDuty(fCoolerPWMDutyCycle);
		}
		vBuzzerPlay();
	} else if(xBt == down){
		if(fCoolerPWMDutyCycle > 0){
			fCoolerPWMDutyCycle = fCoolerPWMDutyCycle - 0.1;
			if(fCoolerPWMDutyCycle < 0) {
				fCoolerPWMDutyCycle = 0;
			}
			vHeaterAndCoolerCoolerfanPWMDuty(fCoolerPWMDutyCycle);
		}
		vBuzzerPlay();
	} else if(xBt == right) {
		if(fHeaterPWMDutyCycle < 1) {
			fHeaterPWMDutyCycle = fHeaterPWMDutyCycle + 0.1;
			if(fHeaterPWMDutyCycle > 1) {
				fHeaterPWMDutyCycle = 1;
			}
			vHeaterAndCoolerHeaterPWMDuty(fHeaterPWMDutyCycle);
		}
		vBuzzerPlay();
	} else if(xBt == left) {
		if(fHeaterPWMDutyCycle > 0) {
			fHeaterPWMDutyCycle = fHeaterPWMDutyCycle - 0.1;
			if(fHeaterPWMDutyCycle < 0) {
				fHeaterPWMDutyCycle = 0;
			}
			vHeaterAndCoolerHeaterPWMDuty(fHeaterPWMDutyCycle);
		}
		vBuzzerPlay();
	} else if(xBt == enter) {
		vBuzzerPlay();
	}
}
void vButtonsEventCallbackReleasedEvent(buttons xBt){
	if(uiCounterButtons[0] == 0 && uiCounterButtons[1] == 0 && uiCounterButtons[2] == 0 && uiCounterButtons[3] == 0 && uiCounterButtons[4] == 0){
		//Verify if all counters are 0, therefore all buttons are released and turns off the timer
		HAL_TIM_Base_Stop_IT(pTimPressedTime);
		cFlagLongPressTimer = 0;
	}
}
void vButtonsEventCallback500msPressedEvent(buttons xBt){
	vButtonsEventCallbackPressedEvent(xBt); // the events of 500 ms have the same effect as single press
}
void vButtonsEventCallback3sPressedEvent(buttons xBt){
	if(xBt == enter){
		iLedValue = 0;
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
