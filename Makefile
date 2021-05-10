PROJECT_DIR = $(shell pwd)

ARDMK_DIR = $(shell pwd)
ARDUINO_DIR = /usr/share/arduino
ARDUINO_LIB_PATH = $(ARDUINO_DIR)/hardware/arduino/avr/libraries
ARDUINO_VERSION = 150

USER_LIB_PATH := $(realpath $(PROJECT_DIR)/lib)

###### Board Configuration
BOARD_TAG = uno
ARCHITECTURE = avr

MONITOR_PORT = /dev/tty/USB*
MONITOR_BAUDRATE = 9600

CFLAGS_STD = -std=gnu11
CXXFLAGS_STD = -std=gnu++17

CXXFLAGS += -pedantic -Wall -Wextra
LDFLAGS += -fdiagnostics-color

CURRENT_DIR = $(shell basename $(CURDIR))
OBJDIR = $(PROJECT_DIR)/build/$(CURRENT_DIR)/$(BOARD_TAG)

####### Project configuration

NO_CORE_MAIN_CPP = 1
ARDUINO_LIBS = SoftwareSerial Arduino_AVRSTL
LOCAL_INO_SRCS ?= $(wildcard src/*.ino)
LOCAL_CPP_SRCS ?= $(wildcard src/*.cpp)

include ./Arduino.mk
