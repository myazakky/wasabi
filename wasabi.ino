#include <M5Stack.h>
#include "WiFiConnection.h"

void setup()
{
  M5.begin();
  M5.Lcd.println("Wasabi!");

  connectWiFi();
}

void loop()
{
}
