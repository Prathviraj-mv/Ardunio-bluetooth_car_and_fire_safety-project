
char command = 0;
int LED = 13;


void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0)
  {
    command = Serial.read();

    if (command == '1') {
      digitalWrite(LED, HIGH);
    }

    else if (command == '0') {
      digitalWrite(LED, LOW);
    }
  }

}
