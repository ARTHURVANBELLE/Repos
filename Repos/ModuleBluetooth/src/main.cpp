#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

// LCD pins <--> Arduino pins
const int RS = 6, EN = 5, D4 = 4, D5 = 3, D6 = 2, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
 
void setup() 
{
  lcd.begin(16,2);
  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  lcd.setCursor(0,0);
  lcd.print("KEY :");
  String content= "";
  
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     content.toUpperCase();
     lcd.setCursor(4,0);
     lcd.print(content);
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "A7 FE 76 B5") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    lcd.setCursor(0,1);
    lcd.write("WELCOME ARTHUR ");
    delay(3000);
  }
 
 else   {
    Serial.println(" Access denied");
    lcd.setCursor(0,1);
    lcd.write(" ACCESS  DENIED");
    delay(3000);
  }
} 
