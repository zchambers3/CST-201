################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../IndevidualAssignment/DoublyPalindrome.cpp \
../IndevidualAssignment/SinglyPalindrome.cpp 

OBJS += \
./IndevidualAssignment/DoublyPalindrome.o \
./IndevidualAssignment/SinglyPalindrome.o 

CPP_DEPS += \
./IndevidualAssignment/DoublyPalindrome.d \
./IndevidualAssignment/SinglyPalindrome.d 


# Each subdirectory must supply rules for building sources it contributes
IndevidualAssignment/%.o: ../IndevidualAssignment/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


