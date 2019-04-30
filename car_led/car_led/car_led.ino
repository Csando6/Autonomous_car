char inputChar;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){//reads input from the tx device
    while(Serial.available() > 0)
      inputChar = char(Serial.read());
    Serial.println(inputChar);//sends value to kaylyns arduino
  }

  switch(inputChar){
    case 'O':
      break;
    case 'F':
      break;
  }

}
