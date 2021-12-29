#include <Arduino.h>
#include <LiquidCrystal.h>

// LCD pins <--> Arduino pins
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("COURS DE ");
  lcd.setCursor(0, 1);         
  lcd.print("ROBOTIQUE");
}
void loop()
{
}