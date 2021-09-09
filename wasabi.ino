#include <M5Stack.h>
#include "WiFiConnection.h"
#include "TempratureModule.h"
#include "Ambient.h"
#include "AmbientConfig.h"

TempratureModule tempModule;
WiFiClient client;
Ambient ambient;

void setup()
{
  M5.begin();
  M5.Lcd.println("Wasabi!");

  connectWiFi();
  tempModule.initialize();
  ambient.begin(channelId, writeKey, &client);
}

void loop()
{
  float temp = tempModule.waterTemprature();
  displayTemprature(temp);
  sendTemprature(temp);
}

void displayTemprature(float temp)
{
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.print("temp: ");
  M5.Lcd.println(temp);
}

void sendTemprature(float temp)
{
  ambient.set(1, temp);
  ambient.send();
}
