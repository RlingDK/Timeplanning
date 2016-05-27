################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/Main.cpp \
../Src/Period.cpp \
../Src/Plan.cpp \
../Src/Player.cpp \
../Src/TestPlan.cpp \
../Src/Timer.cpp 

OBJS += \
./Src/Main.o \
./Src/Period.o \
./Src/Plan.o \
./Src/Player.o \
./Src/TestPlan.o \
./Src/Timer.o 

CPP_DEPS += \
./Src/Main.d \
./Src/Period.d \
./Src/Plan.d \
./Src/Player.d \
./Src/TestPlan.d \
./Src/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/gtest -O0 -g3 -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


