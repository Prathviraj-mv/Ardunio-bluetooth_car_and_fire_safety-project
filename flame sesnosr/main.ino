
#define SENSOR_PIN 2
#define BUZZER_PIN 3
#define RELAY_PIN 4
#define SPRINKLER_START_DELAY 2000 
#define SPRINKLER_ON_TIME 1000

unsigned long previousTime = millis();

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);  
}

void loop() 
{
  
  int sensorValue = digitalRead(SENSOR_PIN);

  
  if (sensorValue == LOW)
  {
    analogWrite(BUZZER_PIN, 50);                          

    if (millis() - previousTime > SPRINKLER_START_DELAY)  
    {
      digitalWrite(RELAY_PIN, LOW);                       
      delay(SPRINKLER_ON_TIME);                           
    }
  }
  else
  {
    analogWrite(BUZZER_PIN, 0);    
    digitalWrite(RELAY_PIN, HIGH); 
    previousTime = millis();  
  }
} 
