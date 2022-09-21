int distance=0;

long readUltrasonicDistance(int triggerPin,int echoPin)
{
  pinMode(triggerPin,OUTPUT);
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  pinMode(echoPin,INPUT);
  
  return pulseIn(echoPin,HIGH);
}
void setup()
{
  Serial.begin(9600);
  pinMode(1,OUTPUT);
}
void loop()
{
  distance=0.01723*readUltrasonicDistance(2,3);
  Serial.println(distance);
  
  if(distance<30)
  {
    digitalWrite(1,HIGH);
  }
  if(distance >=30)
  {
    digitalWrite(1,LOW);
  }
}
  
  