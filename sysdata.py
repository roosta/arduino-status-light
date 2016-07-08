#!/usr/bin/python
# -*- coding: utf-8 -*-

import serial
import time
import sys

ser = serial.Serial("/dev/ttyUSB0", 9600)
ser.write("2".encode())
