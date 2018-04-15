/*
 * I2CTask.c
 *
 *  Created on: 31 mar 2018
 *      Author: bartek
 */

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "i2c.h"
#include "dma.h"
#include "sensors.h"
#include "gpio.h"

void AccGyroTaskEntry(void const * argument)
{
	LSM6DS33_DATA accGyroData;
	while(1)
	{

		accGyroData = LSM6DS33_Read();

		xQueueSend(AccGyroDataQueueHandle,&accGyroData,1000);
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_15);
		vTaskDelay(50);
	}
}

void MagTaskEntry(void const * argument)
{
	LIS3MDL_DATA magData;
	while(1)
	{

		magData = LIS3MDL_Read();

		xQueueSend(MagDataQueueHandle,&magData,1000);
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_15);
		vTaskDelay(50);
	}
}

void MagTaskEntry(void const * argument)
{
	while(1)
	{
		vTaskDelay(50);
	}
}

void DebugLEDTaskEntry(void const * argument)
{
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);

		vTaskDelay(200);
	}
}
