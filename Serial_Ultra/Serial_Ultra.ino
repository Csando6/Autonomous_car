#define trigPin 13
#define echoPin 12
#define led 11

void sendOnData();
void sendOffData();
long Dist;

void setup(){
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT); 
 pinMode(led, OUTPUT);
}

void loop()
{ 
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //distance = (duration/2) / 29.1;
  distance= duration*0.034/2;
  Dist = distance;
  if (distance < 10)
  { 
     digitalWrite(led,LOW);
     sendOffData();
  }

  else 
  {
    digitalWrite(led,HIGH);
    sendOnData();
  }
  //Serial.print(distance);
  //Serial.println(" cm");
  delay(50);
  
}//end of loop


void sendOnData()
{
   Serial.write('F');
}//end of sendData function

void sendOffData()
{
   Serial.write('O');
}//end of sendData function
