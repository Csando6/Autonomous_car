char inputChar;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){//reads input from the tx device
    while(Serial.available() > 0)
      inputChar = char(Serial.read());
    Serial.write(inputChar);//sends value to kaylyns arduino
  }

  switch(inputChar){
    case 'O':
      break;
    case 'F':
      break;
  }

}
