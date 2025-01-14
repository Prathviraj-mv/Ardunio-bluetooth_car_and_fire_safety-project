//include library

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal.h>

//define pins

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 2
Servo myservo;
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
const int D4 = 4, D5 = 5, D6 = 6, D7 = 7, RS = 8, E = 3;

//code lcd

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

//setup code

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("ENTER CARD.");
  Serial.begin(9600);  // Initiate a serial communication
  SPI.begin();         // Initiate SPI bus
  mfrc522.PCD_Init();  // Initiate MFRC522
  myservo.attach(SERVO_PIN);
  myservo.write(0);
  delay(2000);
  myservo.write(90);
  Serial.println("Put your card to the reader...");
  Serial.println("REGISTERED ACCESS ID'S:");
  Serial.println("43 A6 E0 FD");
  Serial.println("32 AD P5 SP");
  Serial.println("53 X6 F7 D8");

  Serial.println();
}

//looping statements

void loop() {

  // Look for new cards

  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  //Show UID on serial monitor
  
  Serial.print("ur entered UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();


  //conditions

  if (content.substring(1) == "43 A6 E0 FD")  //change here the UID of the card
  {
    lcd.setCursor(0, 0);
    lcd.print("Access granted.");
    digitalWrite(A1, HIGH);
    delay(2000);
    Serial.println("REGISTERED ACCESS ID'S:");
    Serial.println("43 A6 E0 FD");
    Serial.println("32 AD P5 SP");
    Serial.println("53 X6 F7 D8");
    Serial.print("Message : ");

    Serial.println("Authorized access");
    Serial.println();
    myservo.write(0);
    delay(4000);
    lcd.clear();
    digitalWrite(A1, LOW);
    lcd.print("ENTER CARD.");
    myservo.write(90);


  } else {
    digitalWrite(A0, HIGH);
    lcd.print("Access denied.");
    delay(2000);
    digitalWrite(A0, LOW);
    lcd.clear();
    lcd.print("ENTER CARD.");

    lcd.setCursor(0, 0);
    Serial.println("REGISTERED ACCESS ID'S:");
    Serial.println("43 A6 E0 FD");
    Serial.println("32 AD P5 SP");
    Serial.println("53 X6 F7 D8");
    Serial.print("Message : ");

    Serial.println(" Access denied");
    delay(DENIED_DELAY);
  }
}
