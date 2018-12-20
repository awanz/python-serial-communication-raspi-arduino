import serial
ser = serial.Serial('com10', 9600)
ser.write(b'3')
ser.write(b'5')
ser.write(b'7')