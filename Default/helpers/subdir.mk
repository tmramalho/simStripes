################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../helpers/SaveData.cpp \
../helpers/SettingsCont.cpp 

OBJS += \
./helpers/SaveData.o \
./helpers/SettingsCont.o 

CPP_DEPS += \
./helpers/SaveData.d \
./helpers/SettingsCont.d 


# Each subdirectory must supply rules for building sources it contributes
helpers/%.o: ../helpers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/tiago/workspace/libs/include -O2 -g -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

