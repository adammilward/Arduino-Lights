################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\IRremote.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\irPronto.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\irRecv.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\irSend.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Aiwa.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Denon.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Dish.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_JVC.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_LG.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Lego_PF.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Mitsubishi.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_NEC.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Panasonic.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_RC5_RC6.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Samsung.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Sanyo.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Sharp.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Sony.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Template.cpp \
C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Whynter.cpp 

LINK_OBJ += \
.\libraries\Arduino-IRremote-master\IRremote.cpp.o \
.\libraries\Arduino-IRremote-master\irPronto.cpp.o \
.\libraries\Arduino-IRremote-master\irRecv.cpp.o \
.\libraries\Arduino-IRremote-master\irSend.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Aiwa.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Denon.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Dish.cpp.o \
.\libraries\Arduino-IRremote-master\ir_JVC.cpp.o \
.\libraries\Arduino-IRremote-master\ir_LG.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Lego_PF.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Mitsubishi.cpp.o \
.\libraries\Arduino-IRremote-master\ir_NEC.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Panasonic.cpp.o \
.\libraries\Arduino-IRremote-master\ir_RC5_RC6.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Samsung.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Sanyo.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Sharp.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Sony.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Template.cpp.o \
.\libraries\Arduino-IRremote-master\ir_Whynter.cpp.o 

CPP_DEPS += \
.\libraries\Arduino-IRremote-master\IRremote.cpp.d \
.\libraries\Arduino-IRremote-master\irPronto.cpp.d \
.\libraries\Arduino-IRremote-master\irRecv.cpp.d \
.\libraries\Arduino-IRremote-master\irSend.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Aiwa.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Denon.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Dish.cpp.d \
.\libraries\Arduino-IRremote-master\ir_JVC.cpp.d \
.\libraries\Arduino-IRremote-master\ir_LG.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Lego_PF.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Mitsubishi.cpp.d \
.\libraries\Arduino-IRremote-master\ir_NEC.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Panasonic.cpp.d \
.\libraries\Arduino-IRremote-master\ir_RC5_RC6.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Samsung.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Sanyo.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Sharp.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Sony.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Template.cpp.d \
.\libraries\Arduino-IRremote-master\ir_Whynter.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Arduino-IRremote-master\IRremote.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\IRremote.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\irPronto.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\irPronto.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\irRecv.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\irRecv.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\irSend.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\irSend.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Aiwa.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Aiwa.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Denon.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Denon.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Dish.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Dish.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_JVC.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_JVC.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_LG.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_LG.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Lego_PF.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Lego_PF.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Mitsubishi.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Mitsubishi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_NEC.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_NEC.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Panasonic.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Panasonic.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_RC5_RC6.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_RC5_RC6.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Samsung.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Samsung.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Sanyo.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Sanyo.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Sharp.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Sharp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Sony.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Sony.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Template.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Template.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Arduino-IRremote-master\ir_Whynter.cpp.o: C:\Users\Adam\ Milward\Documents\Arduino\libraries\Arduino-IRremote-master\ir_Whynter.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Adam Milward\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\cores\arduino" -I"C:\Users\Adam Milward\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.15\variants\standard" -I"C:\Users\Adam Milward\Documents\Arduino\libraries\Arduino-IRremote-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


