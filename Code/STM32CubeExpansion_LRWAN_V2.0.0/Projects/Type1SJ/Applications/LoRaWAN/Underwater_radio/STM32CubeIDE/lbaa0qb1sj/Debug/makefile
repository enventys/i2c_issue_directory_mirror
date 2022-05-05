################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/subdir.mk
-include Middlewares/SubGHz_Phy/subdir.mk
-include Middlewares/LoRaWAN/Utilities/subdir.mk
-include Middlewares/LoRaWAN/Mac/Region/subdir.mk
-include Middlewares/LoRaWAN/Mac/subdir.mk
-include Middlewares/LoRaWAN/LmHandler/subdir.mk
-include Middlewares/LoRaWAN/Crypto/subdir.mk
-include Drivers/STM32L0xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/MurataSx126xModule/subdir.mk
-include Drivers/BSP/IKS01A2/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include Drivers/BSP/B-L072Z-LRWAN1/subdir.mk
-include Application/Target/subdir.mk
-include Application/SW4STM32/subdir.mk
-include Application/Core/subdir.mk
-include Application/App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LoRaWan_End_Node.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LoRaWan_End_Node.list \

OBJCOPY_BIN += \
LoRaWan_End_Node.bin \


# All Target
all: LoRaWan_End_Node.elf secondary-outputs

# Tool invocations
LoRaWan_End_Node.elf: $(OBJS) $(USER_OBJS) ../STM32L072CZTx_FLASH.ld
	arm-none-eabi-gcc -o "LoRaWan_End_Node.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"../STM32L072CZTx_FLASH.ld" --specs=nosys.specs -Wl,-Map="LoRaWan_End_Node.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LoRaWan_End_Node.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LoRaWan_End_Node.list"
	@echo 'Finished building: $@'
	@echo ' '

LoRaWan_End_Node.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "LoRaWan_End_Node.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
