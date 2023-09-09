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
#include "usart_ring.h"
#include "gsm.h"

#include "nokia5110_LCD.h"
#include "string.h"
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
TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
volatile uint8_t flag_alarm = 0; //peremennaya dlya trevogi
//volatile uint8_t flag_armdis = 0; //peremennaya dlya postanovki snyatiya
//volatile uint8_t flag_aconoff = 0; //peremennaya dlya vklucheniya otklucheniya pitaniya

volatile uint8_t flag_signal = 0; //peremennaya dlya proverki signala
volatile uint8_t status_counter = 10; //peremennaya schetchika minut do proverki statusa

char dbi[7] = {0,}; //sozdaem masiv simvolov nujnoy dlini i inicaliziruem nulyami
char operator[14] = {0,}; //sozdaem masiv simvolov nujnoy dlini i inicaliziruem nulyami
char bat[4] = {0,}; //sozdaem masiv simvolov nujnoy dlini i inicaliziruem nulyami
char sig[4] = {0,}; //sozdaem masiv simvolov nujnoy dlini i inicaliziruem nulyami

uint32_t numbers[10] = {0,}; //nomera sim karte
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/////////////////// удалить символы \r и \n из строки //////////////////////
static void clear_string(char *src)
{
	char *dst = NULL;
	if(!src) return;
	uint8_t i = 0;

	for(dst = src; *src; src++)
	{
		if(i < 2 && (*src == '\n' || *src == '\r'))
		{
			i++;
			continue;
		}
		else if(*src == '\n' || *src == '\r') *src = ' ';

		*dst++ = *src;
	}

	*dst = 0;
}

///////////////////// колбек таймера //////////////////////
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM1)
	{
		flag_signal = 1;
	}
}

//////////////// проверка и установка скорости 19200, нужна один раз /////////////////
void chek_speed(void)
{
  for(uint8_t i = 0; i < 7; i++)
  {
	  uint32_t sp = 0;

	  if(i == 0) sp = 2400;
	  else if(i == 1) sp = 4800;
	  else if(i == 2) sp = 9600;
	  else if(i == 3) sp = 19200;
	  else if(i == 4) sp = 38400;
	  else if(i == 5) sp = 57600;
	  else if(i == 6) sp = 115200;

	  huart1.Instance = USART1;
	  huart1.Init.BaudRate = sp;
	  huart1.Init.WordLength = UART_WORDLENGTH_8B;
	  huart1.Init.StopBits = UART_STOPBITS_1;
	  huart1.Init.Parity = UART_PARITY_NONE;
	  huart1.Init.Mode = UART_MODE_TX_RX;
	  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	  huart1.Init.OverSampling = UART_OVERSAMPLING_16;

	  if (HAL_UART_Init(&huart1) != HAL_OK)
	  {
		  Error_Handler();
	  }

	  char str[16] = {0,};
	  HAL_UART_Transmit(GSM, (uint8_t*)"AT\r\n", strlen("AT\r\n"), 1000);
	  HAL_Delay(300);

	  if(gsm_available()) //если модуль что-то прислал
	  {
		  uint16_t i = 0;

		  while(gsm_available())
		  {
			  str[i++] = gsm_read();
			  if(i > 15) break;
			  HAL_Delay(1);
		  }

		  if(strstr(str, "OK") != NULL)
		  {
			  char buf[64] = {0,};
			  snprintf(buf, 64, "Uart modem was %lu, switched to 57600\n", huart1.Init.BaudRate);
			  HAL_UART_Transmit(DEBUG, (uint8_t*)buf, strlen(buf), 100);
			  HAL_UART_Transmit(GSM, (uint8_t*)"AT+IPR=57600\r\n", strlen("AT+IPR=57600\r\n"), 1000);
			  HAL_Delay(250);
			  MX_USART1_UART_Init();
			  break;
		  }
	  }
  }
}

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
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  welcome();


  __HAL_UART_ENABLE_IT(GSM, UART_IT_RXNE);
  __HAL_UART_ENABLE_IT(DEBUG, UART_IT_RXNE);

  starting();






  char buf[GSM_RX_BUFFER_SIZE] = {0,};
  char str[GSM_RX_BUFFER_SIZE] = {0,};


  for (int var = 0; var < 10; ++var)
  {
		if(numbers[var] != 0)
		{
		snprintf(str, 15, "Num%i 0%lu", var, numbers[var]);
		HAL_UART_Transmit(DEBUG, (uint8_t*)str, strlen(str), 1000);
		HAL_UART_Transmit(DEBUG, (uint8_t*)"\n", strlen("\n"), 1000);
		LCD_print(str, 0, 2);
		HAL_Delay(1000);
		}
  }
  LCD_clrScr(); // очистить экран
  LCD_invertText(false);
  HAL_GPIO_WritePin(ERR_LED_GPIO_Port, ERR_LED_Pin, GPIO_PIN_RESET);

  HAL_TIM_Base_Start_IT(&htim1); // запуск таймера
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    if(flag_alarm == 1)
	  {
		  HAL_GPIO_WritePin(ERR_LED_GPIO_Port, ERR_LED_Pin, GPIO_PIN_SET);
		  HAL_TIM_Base_Stop_IT(&htim1); // остановка таймера
		  alarm();
		  flag_alarm = 0;
		  HAL_TIM_Base_Start_IT(&htim1); // запуск таймера
		  HAL_GPIO_WritePin(ERR_LED_GPIO_Port, ERR_LED_Pin, GPIO_PIN_RESET);
	  }

		if(flag_signal == 1)
		{
			flag_signal = 0;
			LCD_clrScr(); // очистить экран
			HAL_GPIO_WritePin(ERR_LED_GPIO_Port, ERR_LED_Pin, GPIO_PIN_SET);
			set_comand(ATCSQ); // уровень сигнала. Может быть в диапазоне 0..31, чем больше тем лучше. 99 значит отсутствие сигнала.
			set_comand(ATCBC); // // naprijenie pitaniya
			LCD_print("LABIRINT", 18, 0);
			LCD_print("ELECTRIC", 18, 1);
			LCD_print(operator, 0, 3); //vivodim na ekran soobshenie iz masiva operator po ukazannim koordinatam
			LCD_print("NET          %", 0, 4);
			LCD_print(sig, 60, 4); //vivodim na ekran soobshenie iz masiva dbi po ukazannim koordinatam
			LCD_print("BAT          %", 0, 5);
			LCD_print(bat, 60, 5);

			status_counter--;
			if(status_counter == 0)
			{
				status_counter = 10;
				LCD_invertText(true);
				LCD_print(" status check ", 0, 2);
				HAL_Delay(500);
				set_comand(ATCPAS);  // проверка статуса модема
				LCD_print("registr  check", 0, 2);
				HAL_Delay(500);
				set_comand(ATCREG);  // проверка регистрации в сети - должен вернуть  +CREG: 0,1
				LCD_clrScr(); // очистить экран
				LCD_invertText(false);
				get_date_time(); // будет раз в секунду выводить время
				LCD_print("LABIRINT", 18, 0);
				LCD_print("ELECTRIC", 18, 1);
				LCD_print(operator, 0, 3); //vivodim na ekran soobshenie iz masiva operator po ukazannim koordinatam
				LCD_print("NET          %", 0, 4);
				LCD_print(sig, 60, 4); //vivodim na ekran soobshenie iz masiva dbi po ukazannim koordinatam
				LCD_print("BAT          %", 0, 5);
				LCD_print(bat, 60, 5);
			}
			HAL_GPIO_WritePin(ERR_LED_GPIO_Port, ERR_LED_Pin, GPIO_PIN_RESET);
		}




		if(gsm_available()) //если модуль что-то прислал
		{
			uint16_t i = 0;
			uint8_t fdbg = 1;
			memset(buf, 0, GSM_RX_BUFFER_SIZE);
			HAL_Delay(50);

			while(gsm_available())
			{
				buf[i++] = gsm_read();
				if(i > GSM_RX_BUFFER_SIZE - 1) break;
				HAL_Delay(1);
			}

			clear_string(buf); // очищаем строку от символов \r и \n

			/////////////////// НАЧ�?НАЕМ РАСПОЗНАВАТЬ ЧТО ПР�?СЛАЛ МОДУЛЬ /////////////////////
			if(strstr(buf, "RING") != NULL) // ЕСЛ�? ЭТО ЗВОНОК
			{

			}
			else if(strstr(buf, "+CMT:") != NULL) // ЕСЛ�? ЭТО SMS
			{
				if(strstr(buf, "77057066") != NULL) // проверяем от кого смс
				{
					HAL_UART_Transmit(DEBUG, (uint8_t*)"Sms my number\n", strlen("Sms my number\n"), 1000);
					LCD_invertText(true);
					LCD_print("SMS           ", 0, 2);
					//LCD_print(num_1, 30, 2);
					LCD_invertText(false);
					// что-то делаем или ищем какую-то строку, которую мы послали в смс, например слово "Hello"
					if(strstr(buf, "Hello") != NULL)
					{
						HAL_UART_Transmit(DEBUG, (uint8_t*)"Reciv Hello\n", strlen("Reciv Hello\n"), 1000);
						// что-то делаем
					}
					else if(strstr(buf, "Call") != NULL) // если прилетело слово "Call" то звоним
					{
						call(); // номер указать в файле gsm.c
					}
					else if(strstr(buf, "Money") != NULL) // если отпрвить sms со словом "Money", то в ответ придёт смс с балансом (деньги) на модеме
					{
						balance(); // посылаем команду узнать баланс (мтс)
					}
				}
				else
				{
					HAL_UART_Transmit(DEBUG, (uint8_t*)"Unknow number sms\n", strlen("Unknow number sms\n"), 1000);
				}
			}
			else if(strstr(buf, "+CUSD") != NULL)  // ЕСЛ�? ЭТО СТРОКА С БАЛАНСОМ
			{
				char *p = NULL;

				if((p = strstr(buf, "Balance")) != NULL) // ищем слово "Balance"
				{
					// отправляем смс с балансом на указанный телефон, укажите нужный номер и раскомментируйте этот блок
					/*snprintf(str, GSM_RX_BUFFER_SIZE, "AT+CMGS=\"+79839655557\"\r\n"); // номер
					HAL_UART_Transmit(GSM, (uint8_t*)str, strlen(str), 1000);
					HAL_Delay(100);
					snprintf(str, GSM_RX_BUFFER_SIZE, "%s", p); // текст смс
					HAL_UART_Transmit(GSM, (uint8_t*)str, strlen(str), 1000);
					p = 0;
					HAL_Delay(100);
					snprintf(str, GSM_RX_BUFFER_SIZE, "%c", (char)26); // символ ctrl-z
					HAL_UART_Transmit(GSM, (uint8_t*)str, strlen(str), 1000);*/
					// блок закомментирован чтоб модуль не слал смски пока тестируете
				}
			}
			else if(strstr(buf, "+DTMF") != NULL)  //ЕСЛ�? ЭТО DTMF С�?ГНАЛ
			{
				if(strstr(buf, "0") != NULL) // если пришёл сигнал кнопки 0
				{
					// что-то делаем
					HAL_UART_Transmit(DEBUG, (uint8_t*)"DTMF Button 0\n", strlen("DTMF Button 0\n"), 1000);
				}
				else if(strstr(buf, "1") != NULL) // если пришёл сигнал кнопки 1
				{
					// что-то делаем
					HAL_UART_Transmit(DEBUG, (uint8_t*)"DTMF Button 1\n", strlen("DTMF Button 1\n"), 1000);
				}
				// и т.д.

				disable_connection(); // разрываем соединение, или не разрываем (в зависимости от того, что вам нужно)
			}
			else if(strstr(buf, "+CCLK") != NULL)  // ЕСЛ�? ЭТО ДАТА/ВРЕМЯ
			{
				replac_string(buf);
				char res[32] = {0,};

				for(uint8_t i = 0; i < GSM_RX_BUFFER_SIZE; i++)
				{
					if(buf[i] == '"')
					{
						i++;
						for(uint8_t j = 0; j < 20; i++, j++)
						{
							if(buf[i] == '+')
							{
								buf[i] = 0;
								break;
							}

							if(buf[i] == ',') buf[i] = ' ';
							res[j] = buf[i];
						}

						break;
					}
				}

				snprintf(str, GSM_RX_BUFFER_SIZE, "DateTime %s\n", res);
				HAL_UART_Transmit(DEBUG, (uint8_t*)str, strlen(str), 1000);
				fdbg = 0;
			}

			if(fdbg)
			{
				snprintf(str, GSM_RX_BUFFER_SIZE, "%s\n", buf);
				HAL_UART_Transmit(DEBUG, (uint8_t*)str, strlen(str), 1000);
			}
		}


		////////////////////////////////////// DEBUG ////////////////////////////////////////
		if(dbg_available()) //если послали в терминал какую-то команду, то она перенаправиться в модем
		{
			uint16_t i = 0;
			memset(buf, 0, GSM_RX_BUFFER_SIZE);

			while(dbg_available())
			{
				buf[i++] = dbg_read();
				if(i > GSM_RX_BUFFER_SIZE - 1) break;
				HAL_Delay(1);
			}

			clear_string(buf);
			snprintf(str, GSM_RX_BUFFER_SIZE, "%s\r\n", buf);
			HAL_UART_Transmit(GSM, (uint8_t*)str, strlen(str), 1000);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
  htim1.Init.Prescaler = 65535;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
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
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 57600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 57600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ERR_LED_GPIO_Port, ERR_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, CLK_Pin|DIN_Pin|DC_Pin|CE_Pin
                          |RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GSM_RESET_GPIO_Port, GSM_RESET_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : ERR_LED_Pin */
  GPIO_InitStruct.Pin = ERR_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ERR_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : CLK_Pin DIN_Pin DC_Pin CE_Pin
                           RST_Pin */
  GPIO_InitStruct.Pin = CLK_Pin|DIN_Pin|DC_Pin|CE_Pin
                          |RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : GSM_RESET_Pin */
  GPIO_InitStruct.Pin = GSM_RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GSM_RESET_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
