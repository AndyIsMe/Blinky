################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC.c \
../Src/DMA.c \
../Src/Flash.c \
../Src/GPIO.c \
../Src/I2C.c \
../Src/IWDG.c \
../Src/Rcc.c \
../Src/Rng.c \
../Src/Timer.c \
../Src/USART.c \
../Src/main.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/ADC.o \
./Src/DMA.o \
./Src/Flash.o \
./Src/GPIO.o \
./Src/I2C.o \
./Src/IWDG.o \
./Src/Rcc.o \
./Src/Rng.o \
./Src/Timer.o \
./Src/USART.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/ADC.d \
./Src/DMA.d \
./Src/Flash.d \
./Src/GPIO.d \
./Src/I2C.d \
./Src/IWDG.d \
./Src/Rcc.d \
./Src/Rng.d \
./Src/Timer.d \
./Src/USART.d \
./Src/main.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx -I"C:/Students/Poh/Blinky/Inc" -I"C:/Students/Poh/Blinky/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Students/Poh/Blinky/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Students/Poh/Blinky/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Students/Poh/Blinky/Drivers/CMSIS/Include" -I"C:/Students/Poh/Blinky/Inc"  -Og -g3 -Wall -specs=nosys.specs -specs=nano.specs -specs=rdimon.specs -lc -lrdimon -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


