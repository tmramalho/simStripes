################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../gssmp/GSSMP.cpp 

OBJS += \
./gssmp/GSSMP.o 

CPP_DEPS += \
./gssmp/GSSMP.d 


# Each subdirectory must supply rules for building sources it contributes
gssmp/%.o: ../gssmp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/tiago/dev/workspace/libs/include -O2 -g -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


