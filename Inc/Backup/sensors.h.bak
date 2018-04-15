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

xQueueHandle AccGyroDataQueueHandle;
xQueueHandle MagDataQueueHandle;

xSemaphoreHandle I2CMutex;

inline void SensorsInit(void)
{
	AccGyroDataQueueHandle = xQueueCreate(2,sizeof(LSM6DS33_DATA));
	MagDataQueueHandle = xQueueCreate(2,sizeof(LIS3MDL_DATA));
	I2CMutex = xSemaphoreCreateMutex();

	  LSM6DS33_Init(ODR_416HZ,ODR_416HZ);
	  LIS3MDL_Init(ODR_80HZ);
}


#endif /* SENSORS_H_ */
