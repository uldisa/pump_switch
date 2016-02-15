include Arduino.mk

LIBS=core SPI DallasTemperature OneWire
#PORT=/dev/ttyUSB0
PORT=COM26
CPU=atmega328p
BR=57600
CPPFLAGS+=-DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR
VARIANT=standard
PROGRAMMER=arduino

#USER_LIB_PATH=$(CURDIR)/libraries
WIRE_LIB_PATH=$(ARD_HOME)/hardware/arduino/avr/libraries/Wire
include lib.mk

#ifeq ($(filter %-pc-cygwin,$(MAKE_HOST)),)
#CPPFLAGS+=-I$(WIRE_LIB_PATH) -I$(WIRE_LIB_PATH)/utility
#else
#CPPFLAGS+=-I$(shell cygpath -m $(WIRE_LIB_PATH)) -I$(shell cygpath -m $(WIRE_LIB_PATH)/utility)
#endif

#CPPFLAGS+=-Wall -Wextra -I. -Os -fno-exceptions -ffunction-sections -fdata-sections
CPPFLAGS+=-I. -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD

font5x8.o:font5x8.h
main.o:PCD8544.o BIGSERIF.o font5x8.o libcore.a libDallasTemperature.a libOneWire.a libSPI.a
main.elf: main.o PCD8544.o BIGSERIF.o font5x8.o libcore.a libDallasTemperature.a libOneWire.a libSPI.a

