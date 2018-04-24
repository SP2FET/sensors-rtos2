/*
 * AHRSTask.c
 *
 *  Created on: 15 kwi 2018
 *      Author: bartek
 */

#include "AHRSTask.h"

void AHRSUpdateTaskEntry(void const * argument)
{

	while(1)
	{
		LIS3MDL_DATA magData;
		LSM6DS33_DATA accGyroData;
		float ax,ay,az,gx,gy,gz,mx,my,mz;

		xQueuePeek(AccGyroDataQueueHandle, &accGyroData,1000);
		xQueuePeek(MagDataQueueHandle, &magData,1000);


				ax = accGyroData.accX /ACC_SCALE;
				ay = accGyroData.accY  /ACC_SCALE;
				az = accGyroData.accZ / ACC_SCALE;
				gx = (accGyroData.gyroX / GYRO_SCALE) * M_PI/180.0;
				gy = (accGyroData.gyroY / GYRO_SCALE) * M_PI/180.0;
				gz = (accGyroData.gyroZ / GYRO_SCALE) * M_PI/180.0;
				mx = magData.magX ;
				my = magData.magY ;
				mz = magData.magZ ;
				MadgwickAHRSupdate(gx,gy,gz,ax,ay,az,my,mx,mz);



				//HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_14);

		vTaskDelay(10);
	}
}

