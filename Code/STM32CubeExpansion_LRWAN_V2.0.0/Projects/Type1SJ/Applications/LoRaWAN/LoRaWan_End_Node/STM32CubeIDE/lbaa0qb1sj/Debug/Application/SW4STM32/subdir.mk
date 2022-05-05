################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/Enventys/Desktop/Milan/stm-wearable/Code/en.i-cube_lrwan_v2.0.0/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Projects/Type1SJ/Applications/LoRaWAN/LoRaWan_End_Node/STM32CubeIDE/startup_stm32l072xx.s 

C_SRCS += \
C:/Users/Enventys/Desktop/Milan/stm-wearable/Code/en.i-cube_lrwan_v2.0.0/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Projects/Type1SJ/Applications/LoRaWAN/LoRaWan_End_Node/STM32CubeIDE/syscalls.c 

OBJS += \
./Application/SW4STM32/startup_stm32l072xx.o \
./Application/SW4STM32/syscalls.o 

S_DEPS += \
./Application/SW4STM32/startup_stm32l072xx.d 

C_DEPS += \
./Application/SW4STM32/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32l072xx.o: C:/Users/Enventys/Desktop/Milan/stm-wearable/Code/en.i-cube_lrwan_v2.0.0/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Projects/Type1SJ/Applications/LoRaWAN/LoRaWan_End_Node/STM32CubeIDE/startup_stm32l072xx.s Application/SW4STM32/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"
Application/SW4STM32/syscalls.o: C:/Users/Enventys/Desktop/Milan/stm-wearable/Code/en.i-cube_lrwan_v2.0.0/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Projects/Type1SJ/Applications/LoRaWAN/LoRaWan_End_Node/STM32CubeIDE/syscalls.c Application/SW4STM32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DUSE_MURATA_SX126X -DMURATA_SENSOR_ENABLE -c -I../../../LoRaWAN/App -I../../../LoRaWAN/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/MurataSx126xModule -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/packages -I../../../../../../../../Drivers/BSP/IKS01A2 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Drivers/BSP/Components/lsm303agr -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-SW4STM32

clean-Application-2f-SW4STM32:
	-$(RM) ./Application/SW4STM32/startup_stm32l072xx.d ./Application/SW4STM32/startup_stm32l072xx.o ./Application/SW4STM32/syscalls.d ./Application/SW4STM32/syscalls.o

.PHONY: clean-Application-2f-SW4STM32

