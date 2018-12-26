import serial
import csv

ser = serial.Serial('/dev/ttyACM1',9600)
s = [0,1]
a = 0;
with open('compass.csv', 'w', newline='') as f:
    filednames = ['Heading', 'Derajat']
    thewriter = csv.DictWriter(f, fieldnames=filednames)
    thewriter.writeheader()
    while True:
        #s[0] = str(int(ser.readline(), 16))
        serialstring = ser.readline()        
        my_string = serialstring.decode('utf-8')
        result = [x.strip() for x in my_string.split(',')]
        print(result)
        thewriter.writerow({'Heading': result[0], 'Derajat': result[1]})
