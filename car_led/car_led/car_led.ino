char inputChar;
const int buzzer = 4; //buzzer to arduino pin 9
const int pot = A0;
int val;
int freq;
void setup(){
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(pot,INPUT);// Set buzzer - pin 9 as an output
  
}


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){//reads input from the tx device
    while(Serial.available() > 0)
      inputChar = char(Serial.read());
    Serial.println(inputChar);//sends value to kaylyns arduino
  }

  switch(inputChar){
    case 'O'://stop
    val = analogRead(pot);
  freq = digitalRead(buzzer);
  tone(buzzer, val); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
      break;
    case 'F'://go forward
      break;
  }

}
