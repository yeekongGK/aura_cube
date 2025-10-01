################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/crc.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/lptim.c \
../Core/Src/main.c \
../Core/Src/rtc.c \
../Core/Src/spi.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c \
../Core/Src/usart.c \
../Core/Src/wwdg.c 

OBJS += \
./Core/Src/crc.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/lptim.o \
./Core/Src/main.o \
./Core/Src/rtc.o \
./Core/Src/spi.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o \
./Core/Src/usart.o \
./Core/Src/wwdg.o 

C_DEPS += \
./Core/Src/crc.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/lptim.d \
./Core/Src/main.d \
./Core/Src/rtc.d \
./Core/Src/spi.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d \
./Core/Src/usart.d \
./Core/Src/wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L443xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/network/NB_IoT/LWM2M/cbor/src" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/network/NB_IoT/LWM2M/objects" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/network/NB_IoT/LWM2M" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/system" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/Src" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/logger" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/diagnosis" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/failsafe" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/config" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/drivers/Pulser" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/drivers/Src" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/network/NB_IoT" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/network/NB_IoT/BC66" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/network/NB_IoT/GKCOAP" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/drivers/FuelGauge" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/drivers/ST25_NFC" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/drivers/ST25_NFC/Src" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/massage" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/security" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/security/SECURITY_HW" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/alarm" -I"C:/Users/yee-kong.chong/STM32CubeIDE/workspace_U031/AURA_Temp/miu_library/ioctrl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/crc.cyclo ./Core/Src/crc.d ./Core/Src/crc.o ./Core/Src/crc.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/lptim.cyclo ./Core/Src/lptim.d ./Core/Src/lptim.o ./Core/Src/lptim.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/rtc.cyclo ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/rtc.su ./Core/Src/spi.cyclo ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32l4xx_hal_msp.cyclo ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_it.cyclo ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.cyclo ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su ./Core/Src/wwdg.cyclo ./Core/Src/wwdg.d ./Core/Src/wwdg.o ./Core/Src/wwdg.su

.PHONY: clean-Core-2f-Src

