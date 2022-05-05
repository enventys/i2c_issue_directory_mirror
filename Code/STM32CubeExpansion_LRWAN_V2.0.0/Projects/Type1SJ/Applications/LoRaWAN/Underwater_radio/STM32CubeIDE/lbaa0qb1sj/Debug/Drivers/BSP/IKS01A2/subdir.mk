################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Projects/Upwork/Benjamin/muRata-LoRa-stm/downloads/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Drivers/BSP/IKS01A2/iks01a2_env_sensors.c \
C:/Projects/Upwork/Benjamin/muRata-LoRa-stm/downloads/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Drivers/BSP/IKS01A2/iks01a2_env_sensors_ex.c \
C:/Projects/Upwork/Benjamin/muRata-LoRa-stm/downloads/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Drivers/BSP/IKS01A2/iks01a2_motion_sensors.c \
C:/Projects/Upwork/Benjamin/muRata-LoRa-stm/downloads/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Drivers/BSP/IKS01A2/iks01a2_motion_sensors_ex.c 

OBJS += \
./Drivers/BSP/IKS01A2/iks01a2_env_sensors.o \
./Drivers/BSP/IKS01A2/iks01a2_env_sensors_ex.o \
./Drivers/BSP/IKS01A2/iks01a2_motion_sensors.o \
./Drivers/BSP/IKS01A2/iks01a2_motion_sensors_ex.o 

C_DEPS += \
./Drivers/BSP/IKS01A2/iks01a2_env_sensors.d \
./Drivers/BSP/IKS01A2/iks01a2_env_sensors_ex.d \
./Drivers/BSP/IKS01A2/iks01a2_motion_sensors.d \
./Drivers/BSP/IKS01A2/iks01a2_motion_sensors_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/IKS01A2/iks01a2_env_sensors.o: C:/Projects/Upwork/Benjamin/muRata-LoRa-stm/downloads/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Drivers/BSP/IKS01A2/iks01a2_env_sensors.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DUSE_MURATA_SX126X -DMURATA_SENSOR_ENABLE -c -I../../../LoRaWAN/App -I../../../LoRaWAN/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/MurataSx126xModule -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/packages -I../../../../../../../../Drivers/BSP/IKS01A2 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Drivers/BSP/Components/lsm303agr -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/IKS01A2/iks01a2_env_sensors.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/IKS01A2/iks01a2_env_sensors_ex.o: C:/Projects/Upwork/Benjamin/muRata-LoRa-stm/downloads/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Drivers/BSP/IKS01A2/iks01a2_env_sensors_ex.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DUSE_MURATA_SX126X -DMURATA_SENSOR_ENABLE -c -I../../../LoRaWAN/App -I../../../LoRaWAN/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/MurataSx126xModule -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/packages -I../../../../../../../../Drivers/BSP/IKS01A2 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Drivers/BSP/Components/lsm303agr -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/IKS01A2/iks01a2_env_sensors_ex.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/IKS01A2/iks01a2_motion_sensors.o: C:/Projects/Upwork/Benjamin/muRata-LoRa-stm/downloads/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Drivers/BSP/IKS01A2/iks01a2_motion_sensors.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DUSE_MURATA_SX126X -DMURATA_SENSOR_ENABLE -c -I../../../LoRaWAN/App -I../../../LoRaWAN/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/MurataSx126xModule -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/packages -I../../../../../../../../Drivers/BSP/IKS01A2 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Drivers/BSP/Components/lsm303agr -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/IKS01A2/iks01a2_motion_sensors.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/IKS01A2/iks01a2_motion_sensors_ex.o: C:/Projects/Upwork/Benjamin/muRata-LoRa-stm/downloads/en.i-cube_lrwan_v2.0.0/STM32CubeExpansion_LRWAN_V2.0.0/Drivers/BSP/IKS01A2/iks01a2_motion_sensors_ex.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DUSE_MURATA_SX126X -DMURATA_SENSOR_ENABLE -c -I../../../LoRaWAN/App -I../../../LoRaWAN/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/MurataSx126xModule -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/packages -I../../../../../../../../Drivers/BSP/IKS01A2 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Drivers/BSP/Components/lsm303agr -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/IKS01A2/iks01a2_motion_sensors_ex.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

