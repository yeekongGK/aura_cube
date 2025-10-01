/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Aura V2
  ******************************************************************************
  * @attention
  * @PIC: CYK
  * @Created: 25 Sep 2025
  * @Git link: https://github.com/yeekongGK/aura_cube.git
  * @TODO
  * 	*
  *
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "i2c.h"
#include "lptim.h"
#include "usart.h"
#include "rtc.h"
#include "spi.h"
#include "wwdg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "max17260.h"
#include "max1726x.h"

#include "sys.h"
#include "cfg.h"
#include "nfctag.h"
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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void UART_Printf(char *format, ...);
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
  MX_LPTIM1_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_LPUART1_UART_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  MX_RTC_Init();
  MX_WWDG_Init();
  MX_CRC_Init();
  /* USER CODE BEGIN 2 */


  BatteryMonitor_Init();

  for (uint16_t addr = 1; addr < 128; addr++)
  {
	  if (HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(addr << 1), 2, 10) == HAL_OK)
	  {
		  UART_Printf("Found device at 0x%02X\r\n", addr);
	  }
  }

//  CFG_ApplyDefaults(&config);
  UART_Printf("test %d\n\r", config.system.mcuFrequency);
  // if (maxim_max1726x_check_por()) {
  //     UART_Printf("POR detected. Initializing MAX1726x with EZ Config...\r\n");
  //     maxim_max1726x_wait_dnr();                // Wait for the chip to be ready
  //     maxim_max1726x_initialize_ez_config();    // Load your battery parameters
  //     maxim_max1726x_clear_por();               // Clear the POR flag
  //     UART_Printf("Initialization complete.\r\n");
  // } else {
  //     UART_Printf("No POR detected. MAX1726x already configured.\r\n");
  // }
  MAX17260_Register_printout();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  // uint16_t value = BatteryMonitor_GetQH();
	  // UART_Printf("1test %d\r\n",value);
    // HAL_Delay(1000);
	  NFCTAG_Task();
	  //-----------------------------------------------------------------
//    float soc_percentage;
//    float voltage_f;
//    float current_f;
//
//    uint16_t vcell_raw;
//    int16_t current_raw; // Current can be negative (discharging)
//
//    // Read State of Charge (%) using the library's helper function
//    soc_percentage = maxim_max1726x_get_repsoc();
//
//    // Read raw register values for Voltage and Current
//    maxim_max1726x_read_reg(MAX1726X_VCELL_REG, &vcell_raw);
//    maxim_max1726x_read_reg(MAX1726X_CURRENT_REG, (uint16_t*)&current_raw);
//
//    // Convert raw values to human-readable format
//    // Datasheet: VCell LSB = 78.125 uV
//    voltage_f = vcell_raw * 78.125f / 1000.0f; // Result in mV
//
//    // Datasheet: Current LSB = 1.5625 uV / Rsense. Assuming Rsense = 10mOhm (0.01 Ohm)
//    // LSB = 1.5625uV / 0.01Ohm = 156.25 uA = 0.15625 mA
//    current_f = current_raw * 0.15625f; // Result in mA
//
//    // Print the results
//    UART_Printf("SOC: %.2f%%, Voltage: %.0f mV, Current: %.2f mA\r\n",
//            soc_percentage, voltage_f, current_f);
//
//    // Wait for a couple of seconds before the next reading
//    HAL_Delay(2000);
    //-----------------------------------------------------------------

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  while (LL_PWR_IsActiveFlag_VOS() != 0)
  {
  }
  LL_RCC_MSI_Enable();

   /* Wait till MSI is ready */
  while(LL_RCC_MSI_IsReady() != 1)
  {

  }
  LL_RCC_MSI_EnableRangeSelection();
  LL_RCC_MSI_SetRange(LL_RCC_MSIRANGE_6);
  LL_RCC_MSI_SetCalibTrimming(0);
  LL_PWR_EnableBkUpAccess();
  LL_RCC_LSE_SetDriveCapability(LL_RCC_LSEDRIVE_LOW);
  LL_RCC_LSE_Enable();

   /* Wait till LSE is ready */
  while(LL_RCC_LSE_IsReady() != 1)
  {

  }
  LL_RCC_MSI_EnablePLLMode();
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_MSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_MSI)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_SetSystemCoreClock(4000000);

   /* Update the time base */
  if (HAL_InitTick (TICK_INT_PRIORITY) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void UART_Printf(char *format, ...)
{
  char str[256];
  va_list args;
  va_start(args, format);
  vsnprintf(str, sizeof(str), format, args);
  va_end(args);

  HAL_UART_Transmit(&huart1, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
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
#ifdef USE_FULL_ASSERT
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
