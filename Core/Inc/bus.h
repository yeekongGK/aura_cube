/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    bus.h
  * @brief   -
  ******************************************************************************
  * @attention
  *
  *  Created on: Sep 30, 2025
  *      Author: CYK
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BUS_H__
#define __BUS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

#if defined(STM32L443xx)
	#include "stm32l4xx_ll_bus.h"
#elif defined(STM32L443xx)
//	#include "stm32l4xx_hal_BUS.h"
//	#include "stm32l4xx_ll_BUS.h"
#endif

/* USER CODE END Includes */



/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */



/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __BUS_H__ */


