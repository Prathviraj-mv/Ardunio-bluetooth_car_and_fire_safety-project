#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

int MS1 = 0;
int MS2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);

  Serial.println("motor control initialization");


}

void loop() {
  if (Serial.available() > 0)
  {
    int command = Serial.read();

    if (command == 'F') {
      analogWrite(IN1, MS1);
      analogWrite(IN2, 0);
      analogWrite(IN3, MS2);
      analogWrite(IN4, 0);
      Serial.println("motor control forward");


    }

    else if (command == 'B') {
      analogWrite(IN1, 0);
      analogWrite(IN2, MS1);
      analogWrite(IN3, 0);
      analogWrite(IN4, MS2);
      Serial.println("motor control backwards");

    }
    else if (command == 'L') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, MS2);
      analogWrite(IN4, 0);
      Serial.println("motor control left");

    }
    else if (command == 'R') {
      analogWrite(IN1, MS1);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
      Serial.println("motor control right");

    }
    else if (command == 'S') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
      Serial.println("stooooooped");

    }
    else {
      if (command >= 0 && command <= 255)
      {
        MS1 = command;
        MS2 = command;
        Serial.println("command set speed to " + String(command));

      }
    }
  }
}

