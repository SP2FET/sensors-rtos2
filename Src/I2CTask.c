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
#include "MadgwickAHRS.h"
#include "I2CTask.h"


void I2CTimeoutTimerCallback(TimerHandle_t xTimer)
{
	HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
	HAL_I2C_DeInit(&hi2c1);
	HAL_I2C_MspInit(&hi2c1);


//	connectionLost = true;

}

void AccGyroTaskEntry(void const * argument)
{
	LSM6DS33_DATA accGyroData;
	while(1)
	{
		accGyroData = LSM6DS33_Read();

		if(HAL_GPIO_ReadPin(B1_GPIO_Port,B1_Pin) == 1)
			xTimerStart(I2CTimeoutTimerHandle,10);

		xQueueOverwrite(AccGyroDataQueueHandle,&accGyroData);
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

		xQueueOverwrite(MagDataQueueHandle,&magData);
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12);
		vTaskDelay(50);
	}
}

void I2CWatchdogTaskEntry(void const * argument)
{
	uint8_t attempts = 0;
	while(1)
	{
		if(connectionLost)
		{
			attempts++;
			SensorsReInit();

			if(!connectionLost)
				attempts = 0;
		}

		if(attempts > MAX_CONNECTIONS_ATTEMPTS)
		{
			attempts = 0;
		}

		vTaskDelay(200);
	}
}

void DebugLEDTaskEntry(void const * argument)
{
	while(1)
	{
		HAL_IWDG_Refresh(&hiwdg);
		//float compass;
		roll = atan2f(q0*q1 + q2*q3, 0.5f - q1*q1 - q2*q2) *180/M_PI;
		pitch = asinf(-2.0f * (q1*q3 - q0*q2))*180/M_PI;
		yaw = atan2f(q1*q2 + q0*q3, 0.5f - q2*q2 - q3*q3)*180/M_PI;
		//compass = atan2(magData.magY,magData.magX)*180/M_PI;
		//HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);

		vTaskDelay(200);
	}
}
