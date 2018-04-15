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
LSM6DS33_DATA readData;
void AccGyroTaskEntry(void const * argument)
{

	while(1)
	{

		readData = LSM6DS33_Read();


		//xQueueSend(AccGyroDataQueueHandle,&readData,1000);
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
