################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DIO_program.c \
../SERVO_program.c \
../SPI_program.c \
../TIM0_program.c \
../TIM1_program.c \
../main.c 

OBJS += \
./ADC_program.o \
./DIO_program.o \
./SERVO_program.o \
./SPI_program.o \
./TIM0_program.o \
./TIM1_program.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./DIO_program.d \
./SERVO_program.d \
./SPI_program.d \
./TIM0_program.d \
./TIM1_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


