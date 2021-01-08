################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SEGGER/SEGGER/SEGGER_RTT.c \
../SEGGER/SEGGER/SEGGER_SYSVIEW.c 

OBJS += \
./SEGGER/SEGGER/SEGGER_RTT.o \
./SEGGER/SEGGER/SEGGER_SYSVIEW.o 

C_DEPS += \
./SEGGER/SEGGER/SEGGER_RTT.d \
./SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
SEGGER/SEGGER/%.o: ../SEGGER/SEGGER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -flto -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"C:\freeRTOS_blink\SEGGER\Config" -I"C:\freeRTOS_blink\SEGGER\OS" -I"C:\freeRTOS_blink\SEGGER\SEGGER" -I"C:\freeRTOS_blink\FreeRTOS\Source\include" -I"C:\freeRTOS_blink\FreeRTOS\Source\portable\GCC\ARM_CM3" -I"C:\freeRTOS_blink\FreeRTOS\Config" -I"C:\freeRTOS_blink\FreeRTOS" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


