import serial
import csv

ser = serial.Serial('/dev/ttyACM1',9600)
s = [0,1]
a = 0;
while True:
	serialstring = ser.readline()        
	print(serialstring);
	#my_string = serialstring.decode('utf-8')
        #result = [x.strip() for x in my_string.split(',')]
        #print(result)
