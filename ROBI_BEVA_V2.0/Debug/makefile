################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Utilities/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Middle/serial/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Middle/sensor/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Middle/rtos/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Middle/motor/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Middle/led/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Middle/lcd/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Middle/buzzer/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Middle/button/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Drivers/STM32F10x_StdPeriph_Driver/src/subdir.mk
-include SDK_ROBI_STM32F1_1.0.0/shared/Drivers/CMSIS/Source/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ROBI_BEVA_V2.0
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ROBI_BEVA_V2.0.elf \

MAP_FILES += \
ROBI_BEVA_V2.0.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ROBI_BEVA_V2.0.list \


# All Target
all: main-build

# Main-build Target
main-build: ROBI_BEVA_V2.0.elf secondary-outputs

# Tool invocations
ROBI_BEVA_V2.0.elf ROBI_BEVA_V2.0.map: $(OBJS) $(USER_OBJS) D:\DH\Lumi\ROBIV2\ROBI_BEVA_V2.0\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "ROBI_BEVA_V2.0.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\DH\Lumi\ROBIV2\ROBI_BEVA_V2.0\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ROBI_BEVA_V2.0.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ROBI_BEVA_V2.0.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ROBI_BEVA_V2.0.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ROBI_BEVA_V2.0.elf ROBI_BEVA_V2.0.list ROBI_BEVA_V2.0.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
