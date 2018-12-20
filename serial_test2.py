import serial
import os
from time import sleep

ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
	ser.write(b'1')
	serialstring = ser.readline()
	print(serialstring)
	sleep(2)
	ser.write(b'0')
	sleep(2)
