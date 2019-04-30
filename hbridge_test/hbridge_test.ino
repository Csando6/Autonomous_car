/*
 * Display number on seven segment display with Arduino
 * Written by Ahmad Shamshiri for Robojax.com
Date modified: Jun 11, 2018 at 17:20 at Ajax, Ontario, Canada
watch video instruction for this code:https://youtu.be/-g6Q9lSHDzg

Code is provided for free AS IS without warranty. 
You can share this acode as long as you keep the above note intact.
 */

const int A1A = 5;//define pin 2 for A1A
const int A1B = 6;//define pin 3 for A1B

const int B1A = 9;//define pin 8 for B1A
const int B1B = 10;//define pin 9 for B1B

int value = 255;
String input;
char inputChar = 'O';

void setup() {
  pinMode(B1A,OUTPUT);
  pinMode(B1B,OUTPUT);
  
  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT);
  delay(3000);

  Serial.begin(9600);
}
void loop() {
  if(Serial.available()>0){
    inputChar = char(Serial.read());
    Serial.println(inputChar);
  }
    
  
  switch(inputChar){
    case 'O':
      digitalWrite(7,LOW);
      break;
    case 'F':
      digitalWrite(7,HIGH);
      break;
  }
}
 
void backward(int valueA, int valueB){
  analogWrite(A1A,valueA);
  analogWrite(A1B,LOW);
  
  analogWrite(B1A,valueB);
  analogWrite(B1B,LOW);
}

void forward(int valueA,int valueB){
  analogWrite(A1A,LOW);
  analogWrite(A1B,valueA);

  analogWrite(B1A,LOW);
  analogWrite(B1B,valueB);
}

void turnLeft(int value){
  analogWrite(A1A,LOW);
  analogWrite(A1B,value);

  analogWrite(B1A,value);
  analogWrite(B1B,LOW);
}

void turnRight(int value){
  analogWrite(A1A, value);
  analogWrite(A1B,LOW);

  analogWrite(B1A,LOW);
  analogWrite(B1B,value);
}

void strToInt(String input){
  int value =0;
  for(unsigned int i=input.length()-1;i>=0;i--){
    value += input[i]* pow(10,i-(input.length()-1) );
    
  }
  Serial.println(value);
  
}
