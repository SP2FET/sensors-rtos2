################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AHRSTask.c \
../Src/I2CTask.c \
../Src/MadgwickAHRS.c \
../Src/dma.c \
../Src/eeprom.c \
../Src/freertos.c \
../Src/gpio.c \
../Src/i2c.c \
../Src/main.c \
../Src/sensors.c \
../Src/spi.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_hal_timebase_TIM.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/AHRSTask.o \
./Src/I2CTask.o \
./Src/MadgwickAHRS.o \
./Src/dma.o \
./Src/eeprom.o \
./Src/freertos.o \
./Src/gpio.o \
./Src/i2c.o \
./Src/main.o \
./Src/sensors.o \
./Src/spi.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_hal_timebase_TIM.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/AHRSTask.d \
./Src/I2CTask.d \
./Src/MadgwickAHRS.d \
./Src/dma.d \
./Src/eeprom.d \
./Src/freertos.d \
./Src/gpio.d \
./Src/i2c.d \
./Src/main.d \
./Src/sensors.d \
./Src/spi.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_hal_timebase_TIM.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F407xx -I"/home/bartek/MEGAsync/sensors-rtos2/Inc" -I"/home/bartek/MEGAsync/sensors-rtos2/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/bartek/MEGAsync/sensors-rtos2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/bartek/MEGAsync/sensors-rtos2/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/bartek/MEGAsync/sensors-rtos2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/bartek/MEGAsync/sensors-rtos2/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/bartek/MEGAsync/sensors-rtos2/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/bartek/MEGAsync/sensors-rtos2/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


