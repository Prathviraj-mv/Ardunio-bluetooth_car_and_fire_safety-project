// Define the ultrasonic sensor pin connections
const int trigPin = 8;
const int echoPin = 9;

// Variables to store the time and distance
unsigned long time = 0;
int distance = 0;

// Motor control pins
const int motorPin1A = 3; // Motor 1 control pin A (IN1)
const int motorPin1B = 4; // Motor 1 control pin B (IN2)
const int motorPin2A = 5; // Motor 2 control pin A (IN3)
const int motorPin2B = 6; // Motor 2 control pin B (IN4)

int motorSpeed1 = 0; // Speed value for Motor 1
int motorSpeed2 = 0; // Speed value for Motor 2

void setup() {
  // Initialize Serial communication for Bluetooth
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT); // Set the trigPin as an output
  pinMode(echoPin, INPUT); // Set the echoPin as an input
  
  // Set motor pins as outputs
  pinMode(motorPin1A, OUTPUT);
  pinMode(motorPin1B, OUTPUT);
  pinMode(motorPin2A, OUTPUT);
  pinMode(motorPin2B, OUTPUT);
  
  // Initialize motors to stopped
  analogWrite(motorPin1A, 0);
  analogWrite(motorPin1B, 0);
  analogWrite(motorPin2A, 0);
  analogWrite(motorPin2B, 0);

  // Print initialization message
  Serial.println("Motor control initialized");
}

void moveForward(int speed1, int speed2) {
  if (distance > 20) {
    analogWrite(motorPin1A, speed1);
    analogWrite(motorPin1B, 0);
    analogWrite(motorPin2A, speed2);
    analogWrite(motorPin2B, 0);
    Serial.println("Command: Move forward");
  } else {
    stopMotors();
  }
  delay(100);
}

void moveBackward(int speed1, int speed2) {
    analogWrite(motorPin1A, 0);
    analogWrite(motorPin1B, speed1);
    analogWrite(motorPin2A, 0);
    analogWrite(motorPin2B, speed2);
    Serial.println("Command: Move backward");
    delay(100);
}

void turnLeft(int speed1) {
    analogWrite(motorPin1A, 0);
    analogWrite(motorPin1B, 0);
    analogWrite(motorPin2A, speed1);
    analogWrite(motorPin2B, 0);
    Serial.println("Command: Turn left");
    delay(100);
}

void turnRight(int speed2) {
    analogWrite(motorPin1A, speed2);
    analogWrite(motorPin1B, 0);
    analogWrite(motorPin2A, 0);
    analogWrite(motorPin2B, 0);
    Serial.println("Command: Turn right");
    delay(100);
}

void stopMotors() {
  analogWrite(motorPin1A, 0);
  analogWrite(motorPin1B, 0);
  analogWrite(motorPin2A, 0);
  analogWrite(motorPin2B, 0);
  Serial.println("Command: Stop");
  delay(100);
}

void updateDistance() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Send a 10 microsecond pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the time it takes for the echo to return
  time = pulseIn(echoPin, HIGH);
  // Calculate the distance in cm
  distance = time * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}

void loop() {
  updateDistance();
  
  if (Serial.available() > 0) {
    int command = Serial.read();
    
    if (command == 'F') { // Move forward
      moveForward(motorSpeed1, motorSpeed2);
    } else if (command == 'B') { // Move backward
      moveBackward(motorSpeed1, motorSpeed2);
    } else if (command == 'L') { // Turn left
      turnLeft(motorSpeed2);
    } else if (command == 'R') { // Turn right
      turnRight(motorSpeed1);
    } else if (command == 'S') { // Stop
      stopMotors();
    } else if (command >= 0 && command <= 255) {
        motorSpeed1 = command; // Set speed for Motor 1
        motorSpeed2 = command; // Set speed for Motor 2
        Serial.println("Command: Set speed to " + String(command));
    }
  }

  // Ensure the robot stops if an obstacle is detected
  if (distance < 20) {
    stopMotors();
  }
}
