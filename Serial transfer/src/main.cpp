#include <Arduino.h>
#include <SerialTransfer.h>
#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
SerialTransfer myTransfer;

struct STRUCT {
  char z;
  float y;
} testStruct;

char arr[6];


void setup()
{
  Serial.begin(9600);
  BTSerial.begin(38400);
  myTransfer.begin(BTSerial);
}


void loop()
{
  if(myTransfer.available())
  {
    // use this variable to keep track of how many
    // bytes we've processed from the receive buffer
    uint16_t recSize = 0;

    recSize = myTransfer.rxObj(testStruct, recSize);
    Serial.print(testStruct.z);
    Serial.print(testStruct.y);
    Serial.print(" | ");

    recSize = myTransfer.rxObj(arr, recSize);
    Serial.println(arr);
  }
}