/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    i2c.h
  * @brief   This file contains all the function prototypes for
  *          the i2c.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#ifndef __I2C_H__
#define __I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern I2C_HandleTypeDef hi2c1;

extern I2C_HandleTypeDef hi2c2;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_I2C1_Init(void);
void MX_I2C2_Init(void);

/* USER CODE BEGIN Prototypes */

HAL_StatusTypeDef I2C1_MemWrite(uint16_t _devAddr, uint16_t _memAddress, uint16_t _memAddSize, uint8_t *_pData, uint16_t _size, uint32_t _timeout);
HAL_StatusTypeDef I2C1_MemRead(uint16_t _devAddr, uint16_t _memAddress, uint16_t _memAddSize, uint8_t *_pData, uint16_t _size, uint32_t _timeout);
HAL_StatusTypeDef I2C1_Write(uint16_t _devAddr, uint8_t *_pData, uint16_t _size, uint32_t _timeout);
HAL_StatusTypeDef I2C1_Read(uint16_t _devAddr, uint8_t *_pData, uint16_t _size, uint32_t _timeout);
bool I2C1_IsNacked(void);
HAL_StatusTypeDef I2C1_IsDeviceReady(const uint8_t _devAddr, const uint32_t _trials, const uint16_t _timeout);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __I2C_H__ */

