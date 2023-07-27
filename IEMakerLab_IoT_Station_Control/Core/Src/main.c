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
#include "usart.h"
#include "gpio.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd16x2.h"
#include <string.h>
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
unsigned char Rx_data[10];  //  creating a buffer of 10 bytes
unsigned char LCD_msg[16];

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
//{

//		lcd16x2_clear();
//		//HAL_UART_Transmit(&huart1,(uint8_t *)123,3,10);
//		HAL_GPIO_TogglePin(LED_D14_GPIO_Port,LED_D14_Pin);
//		HAL_Delay(300);
//		lcd16x2_1stLine();
//		lcd16x2_printf(Rx_data);
//		HAL_UART_Receive_IT(&huart2, Rx_data, sizeof(Rx_data)); 
//	
//}

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
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
	// <-------------- LED Config -------------->

	HAL_GPIO_WritePin(LED_D12_GPIO_Port,LED_D12_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_D14_GPIO_Port,LED_D14_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D15_GPIO_Port,LED_D15_Pin,GPIO_PIN_SET);
	// <-------------- LED Config -------------->

	// <-------------- LOCK Config -------------->
	// Column: SET->OPEN RESET->CLOSE
	// Row: SET->OPEN RESET->CLOSE
	HAL_GPIO_WritePin(LOCK_R1_GPIO_Port,LOCK_R1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R2_GPIO_Port,LOCK_R2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R3_GPIO_Port,LOCK_R3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R4_GPIO_Port,LOCK_R4_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R5_GPIO_Port,LOCK_R5_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R6_GPIO_Port,LOCK_R6_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R7_GPIO_Port,LOCK_R7_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R8_GPIO_Port,LOCK_R8_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R9_GPIO_Port,LOCK_R9_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_R10_GPIO_Port,LOCK_R10_Pin,GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LOCK_OE_GPIO_Port,LOCK_OE_Pin,GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LOCK_C1_GPIO_Port,LOCK_C1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C2_GPIO_Port,LOCK_C2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C3_GPIO_Port,LOCK_C3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C4_GPIO_Port,LOCK_C4_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C5_GPIO_Port,LOCK_C5_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C6_GPIO_Port,LOCK_C6_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C7_GPIO_Port,LOCK_C7_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C8_GPIO_Port,LOCK_C8_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C9_GPIO_Port,LOCK_C9_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LOCK_C10_GPIO_Port,LOCK_C10_Pin,GPIO_PIN_RESET);
	// <-------------- LOCK Config -------------->


	// <-------------- LCD Config -------------->
	lcd16x2_init_8bits(LCD_RS_GPIO_Port, LCD_RS_Pin, LCD_E_GPIO_Port, LCD_E_Pin,
											GPIOE, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10,
											GPIOE, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14);
	lcd16x2_printf("Starting");
	HAL_Delay(1000);
	// <-------------- LCD Config -------------->
	
	// <-------------- HUART Config -------------->
	//	HAL_UART_Receive_IT(&huart2, Rx_data, 5);
	// <-------------- HUART Config -------------->
	
	// <-------------- LOCK Port&Pin Config -------------->
	char msg[10];
	int esp2gd_row, esp2gd_col;
	int rowNum = 10;
	int colNum = 10;
	
	GPIO_TypeDef* lock_row_port[10] = {
	LOCK_R1_GPIO_Port,
	LOCK_R2_GPIO_Port,
	LOCK_R3_GPIO_Port,
	LOCK_R4_GPIO_Port,
	LOCK_R5_GPIO_Port,
	LOCK_R6_GPIO_Port,
	LOCK_R7_GPIO_Port,
	LOCK_R8_GPIO_Port,
	LOCK_R9_GPIO_Port,
	LOCK_R10_GPIO_Port};
	
	uint16_t lock_row_pin[10] = {
	LOCK_R1_Pin,
	LOCK_R2_Pin,
	LOCK_R3_Pin,
	LOCK_R4_Pin,
	LOCK_R5_Pin,
	LOCK_R6_Pin,
	LOCK_R7_Pin,
	LOCK_R8_Pin,
	LOCK_R9_Pin,
	LOCK_R10_Pin};
	
	GPIO_TypeDef* lock_col_port[10] = {
	LOCK_C1_GPIO_Port,
	LOCK_C2_GPIO_Port,
	LOCK_C3_GPIO_Port,
	LOCK_C4_GPIO_Port,
	LOCK_C5_GPIO_Port,
	LOCK_C6_GPIO_Port,
	LOCK_C7_GPIO_Port,
	LOCK_C8_GPIO_Port,
	LOCK_C9_GPIO_Port,
	LOCK_C10_GPIO_Port};
	
	uint16_t lock_col_pin[10] = {
	LOCK_C1_Pin,
	LOCK_C2_Pin,
	LOCK_C3_Pin,
	LOCK_C4_Pin,
	LOCK_C5_Pin,
	LOCK_C6_Pin,
	LOCK_C7_Pin,
	LOCK_C8_Pin,
	LOCK_C9_Pin,
	LOCK_C10_Pin};
	


	//HAL_GPIO_WritePin(lock_row_port[0],lock_row_pin[0],GPIO_PIN_SET);
	// <-------------- LOCK Port&Pin Config -------------->
	

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		
		//lcd16x2_clear();
		HAL_UART_Receive(&huart2, Rx_data, 10,10);
		for (int i=0;i<sizeof(Rx_data);i++){
			if(Rx_data[i] == 0xFF && Rx_data[(i + 1) % 10] == 0xFF && Rx_data[(i + 4) % 10] == 0xAA){
				esp2gd_row = Rx_data[(i + 2) % 10] - 48;
				esp2gd_col = Rx_data[(i + 3) % 10] - 48;
				sprintf(LCD_msg, "Row: %d Col: %d",esp2gd_row,esp2gd_col);
				lcd16x2_clear();
				lcd16x2_1stLine();
				lcd16x2_printf(LCD_msg);
				lcd16x2_2ndLine();
				lcd16x2_printf(Rx_data);
				HAL_GPIO_WritePin(lock_row_port[esp2gd_row],lock_row_pin[esp2gd_row],GPIO_PIN_SET);
				HAL_GPIO_WritePin(lock_col_port[esp2gd_col],lock_col_pin[esp2gd_col],GPIO_PIN_SET);
				HAL_Delay(200);
				HAL_GPIO_WritePin(lock_row_port[esp2gd_row],lock_row_pin[esp2gd_row],GPIO_PIN_RESET);
				HAL_GPIO_WritePin(lock_col_port[esp2gd_col],lock_col_pin[esp2gd_col],GPIO_PIN_RESET);
				HAL_Delay(100);
				memset(LCD_msg, 0, sizeof(LCD_msg));
				memset(Rx_data, 0, sizeof(Rx_data));
				break;
			}
		}
		//sprintf(Rx_data,"%d",Rx_data);
//		lcd16x2_clear();
//		lcd16x2_2ndLine();
//		lcd16x2_printf(Rx_data);
//		for(int i = 0;i<rowNum;++i){
//			lcd16x2_clear();
//			sprintf(msg, "Row: %d", i+1);
//			lcd16x2_1stLine();
//			lcd16x2_printf(msg);
//			HAL_Delay(2000);
//			for(int j = 0;j<rowNum;++j){
//				sprintf(msg, "Col: %d", j+1);
//				HAL_GPIO_WritePin(lock_row_port[i],lock_row_pin[i],GPIO_PIN_SET);
//				HAL_GPIO_WritePin(lock_col_port[j],lock_col_pin[j],GPIO_PIN_SET);
//				HAL_Delay(200);
//				HAL_GPIO_WritePin(lock_row_port[i],lock_row_pin[i],GPIO_PIN_RESET);
//				HAL_GPIO_WritePin(lock_col_port[j],lock_col_pin[j],GPIO_PIN_RESET);
//				lcd16x2_2ndLine();
//				lcd16x2_printf(msg);
//				HAL_Delay(1000);
//			}
//		}
//		HAL_GPIO_WritePin(LOCK_R1_GPIO_Port,LOCK_R1_Pin,GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LOCK_C1_GPIO_Port,LOCK_C1_Pin,GPIO_PIN_SET);
//		lcd16x2_clear();
//		lcd16x2_1stLine();
//		lcd16x2_printf("1&1");
//		HAL_Delay(200);
//		HAL_GPIO_WritePin(LOCK_R1_GPIO_Port,LOCK_R1_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LOCK_C1_GPIO_Port,LOCK_C1_Pin,GPIO_PIN_RESET);
//		HAL_Delay(2000);
//		HAL_GPIO_WritePin(LOCK_R2_GPIO_Port,LOCK_R2_Pin,GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LOCK_C2_GPIO_Port,LOCK_C2_Pin,GPIO_PIN_SET);
//		lcd16x2_1stLine();
//		lcd16x2_printf("2&2");
//		HAL_Delay(200);
//		HAL_GPIO_WritePin(LOCK_R2_GPIO_Port,LOCK_R2_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LOCK_C2_GPIO_Port,LOCK_C2_Pin,GPIO_PIN_RESET);
//		HAL_Delay(2000);
//		HAL_GPIO_WritePin(LOCK_R3_GPIO_Port,LOCK_R3_Pin,GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LOCK_C3_GPIO_Port,LOCK_C3_Pin,GPIO_PIN_SET);
//		lcd16x2_1stLine();
//		lcd16x2_printf("3&3");
//		HAL_Delay(200);
//		HAL_GPIO_WritePin(LOCK_R3_GPIO_Port,LOCK_R3_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LOCK_C3_GPIO_Port,LOCK_C3_Pin,GPIO_PIN_RESET);
//		HAL_Delay(2000);
//		HAL_GPIO_WritePin(LOCK_R4_GPIO_Port,LOCK_R4_Pin,GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LOCK_C4_GPIO_Port,LOCK_C4_Pin,GPIO_PIN_SET);
//		lcd16x2_1stLine();
//		lcd16x2_printf("4&4");
//		HAL_Delay(200);
//		HAL_GPIO_WritePin(LOCK_R4_GPIO_Port,LOCK_R4_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LOCK_C4_GPIO_Port,LOCK_C4_Pin,GPIO_PIN_RESET);
//		HAL_Delay(2000);
//		HAL_GPIO_WritePin(LOCK_R5_GPIO_Port,LOCK_R5_Pin,GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LOCK_C5_GPIO_Port,LOCK_C5_Pin,GPIO_PIN_SET);
//		lcd16x2_1stLine();
//		lcd16x2_printf("5&5");
//		HAL_Delay(200);
//		HAL_GPIO_WritePin(LOCK_R5_GPIO_Port,LOCK_R5_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LOCK_C5_GPIO_Port,LOCK_C5_Pin,GPIO_PIN_RESET);
//		HAL_Delay(2000);

//    lcd16x2_2ndLine();
//    lcd16x2_printf("%.2f C", 25.7824);
//    HAL_Delay(1000);
//		HAL_GPIO_TogglePin(LED_D12_GPIO_Port,LED_D12_Pin);
//		HAL_Delay(500);
//		HAL_GPIO_TogglePin(LOCK_R1_GPIO_Port,LOCK_R1_Pin);
//		HAL_Delay(500);
//		HAL_GPIO_TogglePin(LED_D14_GPIO_Port,LED_D14_Pin);
//		HAL_Delay(500);
//		HAL_GPIO_TogglePin(LOCK_R2_GPIO_Port,LOCK_R2_Pin);
//		HAL_Delay(500);
//		HAL_GPIO_TogglePin(LED_D15_GPIO_Port,LED_D15_Pin);
//		HAL_Delay(500);
//		HAL_GPIO_TogglePin(LOCK_C1_GPIO_Port,LOCK_C1_Pin);
//		HAL_Delay(500);
//		
//		
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
