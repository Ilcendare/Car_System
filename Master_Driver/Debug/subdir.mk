################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../GINT_program.c \
../LCD_program.c \
../SPI_program.c \
../USART_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./GINT_program.o \
./LCD_program.o \
./SPI_program.o \
./USART_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./GINT_program.d \
./LCD_program.d \
./SPI_program.d \
./USART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


