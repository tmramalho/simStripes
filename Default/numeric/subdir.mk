################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../numeric/Interpolate.cpp \
../numeric/Profile.cpp \
../numeric/dvec.cpp 

OBJS += \
./numeric/Interpolate.o \
./numeric/Profile.o \
./numeric/dvec.o 

CPP_DEPS += \
./numeric/Interpolate.d \
./numeric/Profile.d \
./numeric/dvec.d 


# Each subdirectory must supply rules for building sources it contributes
numeric/%.o: ../numeric/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/tiago/workspace/libs/include -O2 -g -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


