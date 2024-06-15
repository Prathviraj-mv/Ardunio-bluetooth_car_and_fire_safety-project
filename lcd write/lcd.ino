#include<LiquidCrystal.h>

// function in order 
const int D4 = 4, D5 = 5, D6 = 6, D7 = 7, RS = 12, E = 11;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
void setup() {

  lcd.begin(16, 2);

}


void loop() {

  lcd.setCursor(0, 0);
  lcd.print("hello");

}
