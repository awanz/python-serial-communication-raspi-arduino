import serial
import csv

ser = serial.Serial('/dev/ttyACM0',9600)
s = [0,1]
a = 0;
with open('hasil.csv', 'w', newline='') as f:
    filednames = ['column1', 'column2']
    thewriter = csv.DictWriter(f, fieldnames=filednames)
    thewriter.writeheader()
    while True:
        #s[0] = str(int(ser.readline(), 16))
        serialstring = ser.readline()        
        my_string = serialstring.decode('utf-8')
        result = [x.strip() for x in my_string.split(',')]
        print(result)
        thewriter.writerow({'column1': s[0], 'column2': "tes"})
