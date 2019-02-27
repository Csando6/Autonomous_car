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

const int B1A = 8;//define pin 8 for B1A
const int B1B = 9;//define pin 9 for B1B

int value = 255;
String input;




void setup() {
  pinMode(B1A,OUTPUT);// define pin as output
  pinMode(B1B,OUTPUT);
  
  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT);    
  delay(3000);

  Serial.begin(9600);
}
void loop() {
  input = "";
  
  delay(100);
  if(Serial.available() > 0){
    bool negative = false;
    while(Serial.available() >0){
      char temp = Serial.read();
      if(temp == '-'){
        negative = true;  
      }
      if(isDigit(temp)){
        input+=temp;
      }
        
    }
    Serial.print(input);
    Serial.println();
    
    value = constrain(input.toInt(),0,255);
    if(negative)
      value = -1 * value;
    Serial.println(value);
  }

  if(value>=0)
    forward(value);
  else if(value<0){
    backward(value);
  }
}
 

void forward(int value){
  value = abs(value);
  analogWrite(A1A,value);
  analogWrite(A1B,LOW);
}

void backward(int value){
  value = abs(value);
  analogWrite(A1A,LOW);
  analogWrite(A1B,value);
}

void strToInt(String input){
  int value =0;
  for(unsigned int i=input.length()-1;i>=0;i--){
    value += input[i]* pow(10,i-(input.length()-1) );
    
  }
  Serial.println(value);
  
}
void motorA(char d)
{
  if(d =='R'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,HIGH); 
  }else if (d =='L'){
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW);    
  }else{
    //Robojax.com L9110 Motor Tutorial
    // Turn motor OFF
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);    
  }
}// motorA end


/*
 * @motorB
 * activation rotation of motor B
 * d is the direction
 * R = Right
 * L = Left
 */
 /*
void motorB(char d)
{

    if(d =='R'){
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,HIGH); 
    }else if(d =='L'){
      digitalWrite(B1A,HIGH);
      digitalWrite(B1B,LOW);    
    }else{
    //Robojax.com L9110 Motor Tutorial
    // Turn motor OFF      
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,LOW);     
    }

}// motorB end 
*/
