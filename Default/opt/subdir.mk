################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../opt/BayesScore.cpp \
../opt/ProfileScore.cpp \
../opt/TestFunction.cpp 

OBJS += \
./opt/BayesScore.o \
./opt/ProfileScore.o \
./opt/TestFunction.o 

CPP_DEPS += \
./opt/BayesScore.d \
./opt/ProfileScore.d \
./opt/TestFunction.d 


# Each subdirectory must supply rules for building sources it contributes
opt/%.o: ../opt/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/tiago/workspace/libs/include -O2 -g -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


