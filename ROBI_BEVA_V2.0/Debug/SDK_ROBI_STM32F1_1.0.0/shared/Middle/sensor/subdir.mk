################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.c 

OBJS += \
./SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.o 

C_DEPS += \
./SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.o: D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.c SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F10X_MD -c -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Drivers/CMSIS/Source" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Drivers/STM32F10x_StdPeriph_Driver/inc" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Drivers/STM32F10x_StdPeriph_Driver/src" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/button" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/buzzer" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/lcd" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/led" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/motor" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/rtos" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Middle/serial" -I"D:/DH/Lumi/ROBIV2/SDK_ROBI_STM32F1_1.0.0/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SDK_ROBI_STM32F1_1-2e-0-2e-0-2f-shared-2f-Middle-2f-sensor

clean-SDK_ROBI_STM32F1_1-2e-0-2e-0-2f-shared-2f-Middle-2f-sensor:
	-$(RM) ./SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.cyclo ./SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.d ./SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.o ./SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/optical_sensor.su

.PHONY: clean-SDK_ROBI_STM32F1_1-2e-0-2e-0-2f-shared-2f-Middle-2f-sensor

