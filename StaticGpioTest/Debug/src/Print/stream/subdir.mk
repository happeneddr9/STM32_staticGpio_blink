################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Print/stream/istream.cpp 

OBJS += \
./src/Print/stream/istream.o 

CPP_DEPS += \
./src/Print/stream/istream.d 


# Each subdirectory must supply rules for building sources it contributes
src/Print/stream/%.o: ../src/Print/stream/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -std=c++1y -DSTM32 -DSTM32F0 -DSTM32F030C8Tx -DDEBUG -DSTM32F030 -DUSE_STDPERIPH_DRIVER -I"C:/Users/user/Desktop/happeneddr9/Github/Static_GPIO_cpp/StaticGpioTest/StdPeriph_Driver/inc" -I"C:/Users/user/Desktop/happeneddr9/Github/Static_GPIO_cpp/StaticGpioTest/src" -I"C:/Users/user/Desktop/happeneddr9/Github/Static_GPIO_cpp/StaticGpioTest/inc" -I"C:/Users/user/Desktop/happeneddr9/Github/Static_GPIO_cpp/StaticGpioTest/CMSIS/device" -I"C:/Users/user/Desktop/happeneddr9/Github/Static_GPIO_cpp/StaticGpioTest/CMSIS/core" -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


