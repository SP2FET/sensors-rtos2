/*
 * sensors.h
 *
 *  Created on: 31 mar 2018
 *      Author: bartek
 */

#ifndef SENSORS_H_
#define SENSORS_H_

#include "Sensors/LIS3MDL.h"
#include "Sensors/LSM6DS33.h"
#include "cmsis_os.h"
#include "stdbool.h"
#include "iwdg.h"


extern void I2CTimeoutTimerCallback(TimerHandle_t xTimer);


xQueueHandle AccGyroDataQueueHandle;
xQueueHandle MagDataQueueHandle;
xSemaphoreHandle I2CMutex;
xTimerHandle I2CTimeoutTimerHandle;
bool connectionLost;

inline void SensorsInit(void)
{
	connectionLost = false;

	AccGyroDataQueueHandle = xQueueCreate(1,sizeof(LSM6DS33_DATA));
	MagDataQueueHandle = xQueueCreate(1,sizeof(LIS3MDL_DATA));

	I2CMutex = xSemaphoreCreateMutex();

	I2CTimeoutTimerHandle = xTimerCreate("I2C",1000,pdFALSE,NULL,I2CTimeoutTimerCallback);
	//xTimerStart(I2CTimeoutTimerHandle,10);
	LSM6DS33_Init(ODR_416HZ,ODR_416HZ);
	LIS3MDL_Init(ODR_80HZ);
	  __HAL_IWDG_START(&hiwdg);


}

inline void SensorsReInit(void)
{
	  connectionLost = false;

	  LSM6DS33_Init(ODR_416HZ,ODR_416HZ);
	  LIS3MDL_Init(ODR_80HZ);
}

#endif /* SENSORS_H_ */
