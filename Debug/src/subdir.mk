################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/main.o 

CPP_SRCS += \
../src/Bartendr.cpp \
../src/Green.cpp \
../src/Hush.cpp 

OBJS += \
./src/Bartendr.o \
./src/Green.o \
./src/Hush.o 

CPP_DEPS += \
./src/Bartendr.d \
./src/Green.d \
./src/Hush.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


