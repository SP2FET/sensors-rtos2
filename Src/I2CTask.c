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

void AccGyroTaskEntry(void const * argument)
{
	LSM6DS33_DATA accGyroData;
	while(1)
	{

		accGyroData = LSM6DS33_Read();

		xQueueOverwrite(AccGyroDataQueueHandle,&accGyroData);
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_15);
		vTaskDelay(60);
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
		vTaskDelay(60);
	}
}



void DebugLEDTaskEntry(void const * argument)
{
	while(1)
	{
		//float compass;
		roll = atan2f(q0*q1 + q2*q3, 0.5f - q1*q1 - q2*q2) *180/M_PI;
		pitch = asinf(-2.0f * (q1*q3 - q0*q2))*180/M_PI;
		yaw = atan2f(q1*q2 + q0*q3, 0.5f - q2*q2 - q3*q3)*180/M_PI;
		//compass = atan2(magData.magY,magData.magX)*180/M_PI;
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);

		vTaskDelay(200);
	}
}
