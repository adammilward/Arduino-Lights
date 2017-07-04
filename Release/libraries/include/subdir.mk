################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\include\pnew.cpp 

LINK_OBJ += \
.\libraries\include\pnew.cpp.o 

CPP_DEPS += \
.\libraries\include\pnew.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\include\pnew.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\include\pnew.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\include" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\include\utility" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\avr-stl" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


