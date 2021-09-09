#include "WiFiConnection.h"
#include "WiFiConfig.h"
#include <M5Stack.h>
#include <WiFi.h>

void connectWiFi()
{
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    M5.Lcd.print(".");
    delay(500);
  }
  M5.Lcd.clear(0);
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.print("\nIP: ");
  M5.Lcd.println(WiFi.localIP());
}
