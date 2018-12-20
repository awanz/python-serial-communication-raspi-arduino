char dataString[50] = {0};
int a =0; 

#include <math.h>
#include <Servo.h>
Servo irservo;
#define Svo_Pin 9
String d1 = "";
String d2 = "";
String d3 = "";
String d4 = "";

int posnow;

int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;     //M1 Direction Control
int M2 = 7;     //M1 Direction Control

const byte encoder0pinA = 3;
const byte encoder0pinB = 10;
byte encoder0PinALast;
int duration;
boolean Direction;

const byte encoder0pinA2 = 2;
const byte encoder0pinB2 = 8;
byte encoder0PinALast2;
int duration2;
boolean Direction2;

void stop(void)                    //Stop
{
  digitalWrite(E1,0); 
  digitalWrite(M1,LOW);    
  digitalWrite(E2,0);   
  digitalWrite(M2,LOW);    
}  
void advance(char a,char b)          //Move forward
{
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}  
void back_off (char a,char b)          //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)             //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_L (char a,char b)             //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void setup(){  
  Serial.begin(57600);                       //Initialize the serial port
  digitalWrite(E1,0); 
  digitalWrite(M1,LOW);    
  digitalWrite(E2,0);   
  digitalWrite(M2,LOW);   
  EncoderInit();                              //Initialize the module
  EncoderInit2();
}

int pos=0;                                        // variable to store the servo position 
float distance;

float jarakkanan = 0.0;
float jarakkiri = 0.0;
float rotasikanan = 0.0;
float rotasikiri = 0.0;

float convertToMeter(int a){
  return a * 0.00523333;
}
void EncoderInit(){
  Direction = true;                            //default -> Forward  
  pinMode(encoder0pinB,INPUT);  
  attachInterrupt(0, wheelSpeed, CHANGE);
}
void EncoderInit2(){
  Direction2 = true;                            //default -> Forward  
  pinMode(encoder0pinB2,INPUT);  
  attachInterrupt(1, wheelSpeed2, CHANGE);
}

 
void wheelSpeed(){
  int Lstate = digitalRead(encoder0pinA);
  if((encoder0PinALast == LOW) && Lstate==HIGH){
    int val = digitalRead(encoder0pinB);
    if(val == LOW && Direction){
      Direction = false;                       //Reverse
    }
    else if(val == HIGH && !Direction){
      Direction = true;                        //Forward
    }
  }
  encoder0PinALast = Lstate;
  if(!Direction)  duration++;
  else  duration--;
}
void wheelSpeed2(){
  int Lstate = digitalRead(encoder0pinA2);
  if((encoder0PinALast2 == LOW) && Lstate==HIGH){
    int val = digitalRead(encoder0pinB2);
    if(val == LOW && Direction2){
      Direction2 = false;                       //Reverse
    }
    else if(val == HIGH && !Direction2){
      Direction2 = true;                        //Forward
    }
  }
  encoder0PinALast2 = Lstate;
  if(!Direction2)  duration2++;
  else  duration2--;
}
  
//void loop() {
  //a = a + 15;                    // a value increase every loop
  //sprintf(dataString,"%02X",a); // convert a value to hexa 
  //Serial.println(dataString);  // send the data
  //delay(1000);                 // give the loop some break
//}

void loop(){
  advance(255,235);
  jarakkanan = convertToMeter(duration);
  jarakkiri = convertToMeter(duration2);
  
  d1 = String(duration);
  d2 = String(duration2);
  d3 = String(jarakkanan);
  d4 = String(jarakkiri);
  Serial.println(d1 + "," + d2 + "," + d3 + "," + d4);
  
  delay(100);
}
