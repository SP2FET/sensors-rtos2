################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F407xx -I"/home/bartek/MEGAsync/sensors-rtos2/Inc" -I"/home/bartek/MEGAsync/sensors-rtos2/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/bartek/MEGAsync/sensors-rtos2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/bartek/MEGAsync/sensors-rtos2/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/bartek/MEGAsync/sensors-rtos2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/bartek/MEGAsync/sensors-rtos2/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/bartek/MEGAsync/sensors-rtos2/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/bartek/MEGAsync/sensors-rtos2/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


