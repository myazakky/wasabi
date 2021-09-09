#include <M5Stack.h>
#include "WiFiConnection.h"
#include "TempratureModule.h"

TempratureModule tempModule;

void setup()
{
  M5.begin();
  M5.Lcd.println("Wasabi!");

  connectWiFi();
  tempModule.initialize();
}

void loop()
{
  float temp = tempModule.waterTemprature();
  displayTemprature(temp);
}

void displayTemprature(float temp)
{
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.print("temp: ");
  M5.Lcd.println(temp);
}
