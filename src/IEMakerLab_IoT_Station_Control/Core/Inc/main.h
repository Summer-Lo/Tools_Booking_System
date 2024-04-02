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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_RS_Pin GPIO_PIN_5
#define LCD_RS_GPIO_Port GPIOC
#define LCD_RW_Pin GPIO_PIN_0
#define LCD_RW_GPIO_Port GPIOB
#define LCD_E_Pin GPIO_PIN_1
#define LCD_E_GPIO_Port GPIOB
#define LCD_D0_Pin GPIO_PIN_7
#define LCD_D0_GPIO_Port GPIOE
#define LCD_D1_Pin GPIO_PIN_8
#define LCD_D1_GPIO_Port GPIOE
#define LCD_D2_Pin GPIO_PIN_9
#define LCD_D2_GPIO_Port GPIOE
#define LCD_D3_Pin GPIO_PIN_10
#define LCD_D3_GPIO_Port GPIOE
#define LCD_D4_Pin GPIO_PIN_11
#define LCD_D4_GPIO_Port GPIOE
#define LCD_D5_Pin GPIO_PIN_12
#define LCD_D5_GPIO_Port GPIOE
#define LCD_D6_Pin GPIO_PIN_13
#define LCD_D6_GPIO_Port GPIOE
#define LCD_D7_Pin GPIO_PIN_14
#define LCD_D7_GPIO_Port GPIOE
#define LOCK_C8_Pin GPIO_PIN_12
#define LOCK_C8_GPIO_Port GPIOB
#define LOCK_C7_Pin GPIO_PIN_13
#define LOCK_C7_GPIO_Port GPIOB
#define LOCK_C6_Pin GPIO_PIN_14
#define LOCK_C6_GPIO_Port GPIOB
#define LOCK_C5_Pin GPIO_PIN_15
#define LOCK_C5_GPIO_Port GPIOB
#define LOCK_C4_Pin GPIO_PIN_8
#define LOCK_C4_GPIO_Port GPIOD
#define LOCK_C3_Pin GPIO_PIN_9
#define LOCK_C3_GPIO_Port GPIOD
#define LOCK_R1_Pin GPIO_PIN_10
#define LOCK_R1_GPIO_Port GPIOD
#define LOCK_R2_Pin GPIO_PIN_11
#define LOCK_R2_GPIO_Port GPIOD
#define LOCK_R3_Pin GPIO_PIN_12
#define LOCK_R3_GPIO_Port GPIOD
#define LOCK_R4_Pin GPIO_PIN_13
#define LOCK_R4_GPIO_Port GPIOD
#define LOCK_R5_Pin GPIO_PIN_14
#define LOCK_R5_GPIO_Port GPIOD
#define LOCK_R6_Pin GPIO_PIN_15
#define LOCK_R6_GPIO_Port GPIOD
#define LOCK_R7_Pin GPIO_PIN_6
#define LOCK_R7_GPIO_Port GPIOC
#define LOCK_R8_Pin GPIO_PIN_7
#define LOCK_R8_GPIO_Port GPIOC
#define LOCK_R9_Pin GPIO_PIN_8
#define LOCK_R9_GPIO_Port GPIOC
#define LOCK_R10_Pin GPIO_PIN_9
#define LOCK_R10_GPIO_Port GPIOC
#define LOCK_OE_Pin GPIO_PIN_8
#define LOCK_OE_GPIO_Port GPIOA
#define LOCK_C10_Pin GPIO_PIN_4
#define LOCK_C10_GPIO_Port GPIOB
#define LOCK_C9_Pin GPIO_PIN_5
#define LOCK_C9_GPIO_Port GPIOB
#define LOCK_C2_Pin GPIO_PIN_6
#define LOCK_C2_GPIO_Port GPIOB
#define LOCK_C1_Pin GPIO_PIN_7
#define LOCK_C1_GPIO_Port GPIOB
#define LED_D15_Pin GPIO_PIN_8
#define LED_D15_GPIO_Port GPIOB
#define LED_D14_Pin GPIO_PIN_9
#define LED_D14_GPIO_Port GPIOB
#define LED_D12_Pin GPIO_PIN_0
#define LED_D12_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
