#define LED_1 13
#define LED_2 12
#define LED_3 11
#define LED_4 10
#define LED_5 9
#define LED_6 8
#define LED_7 6
#define LED_8 5
#define BUTTON 2
#define arraysize 8


byte array[arraysize] = {LED_1,LED_2,LED_3,LED_4,LED_5,LED_6,LED_7,LED_8};


void arrry_srtup()
{
  for (int i = 0; i<arraysize; i++){
    pinMode(array[i] ,OUTPUT );
  }
  
}

void led_low(){
  for(int i = 0; i<arraysize;i++){
   digitalWrite(array[i],LOW) ;
  }
  
}
void setup()
{
  pinMode(BUTTON, INPUT);
  led_low();
}

void loop()
{
  	if (digitalRead(BUTTON)==HIGH){
        for(int z = 0; z <100 ;z++){ 

    		digitalWrite(LED_1, HIGH);
    		delay(300);
    		digitalWrite(LED_1, LOW);
    		digitalWrite(LED_2, HIGH);
    		delay(300);
    		digitalWrite(LED_2, LOW);
    		digitalWrite(LED_3, HIGH);
    		delay(300);
    		digitalWrite(LED_3, LOW);
        digitalWrite(LED_4, HIGH);
    		delay(300);
    		digitalWrite(LED_4, LOW);
    		digitalWrite(LED_5, HIGH);
    		delay(300);
    		digitalWrite(LED_5, LOW);
    		digitalWrite(LED_6, HIGH);
    		delay(300);
    		digitalWrite(LED_6, LOW);
        digitalWrite(LED_7, HIGH);
    		delay(300);
    		digitalWrite(LED_7, LOW);
        digitalWrite(LED_8, HIGH);
    		delay(300);
    		digitalWrite(LED_8, LOW);
  
  	}
  }
}
