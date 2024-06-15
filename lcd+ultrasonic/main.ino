 #define ECHOPIN 2
 #define TRIGPIN 3 
 long distance;
 long duration;
 void setup() {
  pinMode(ECHOPIN,INPUT);
  pinMode(TRIGPIN,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,LOW);

  duration = pulseIn(ECHOPIN,HIGH);
  distance = (duration * 0.0345)/2;

  Serial.println("The object is at ");
  Serial.println(distance);
  Serial.print(" cm");
  
  delay(100);
  

}
