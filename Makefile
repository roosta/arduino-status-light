
### BOARD_TAG & BOARD_SUB
BOARD_TAG = uno
MONITOR_PORT = /dev/ttyUSB0
# ARDUINO_LIBS  = Adafruit_NeoPixel Adafruit_NeoMatrix Adafruit_GFX

### USER_LIB_PATH
### Path to where the your project's libraries are stored.
USER_LIB_PATH = ./lib

ARDMK_DIR = ./lib/Arduino-Makefile

### Do not touch - the path to Arduino.mk, inside the ARDMK_DIR
include $(ARDMK_DIR)/Arduino.mk

install:
	./script/update-or-clone.sh deps.txt
