#include "Controller.h"
#include <M5Stack.h>
#include "PinConfig.h"

void Controller::initialize()
{
  pinMode(FAN, OUTPUT);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);

  this->neutral();
}
void Controller::neutral()
{
  this->state = "neutral";
  digitalWrite(FAN, LOW);
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);
}

void Controller::hot()
{
  this->state = "hot";
  digitalWrite(FAN, HIGH);
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);
}

void Controller::cool()
{
  this->state = "cool";
  digitalWrite(FAN, HIGH);
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, HIGH);
}

void Controller::receive()
{
  if (M5.BtnA.wasPressed())
  {
    this->cool();
    this->displayState();
  }
  if (M5.BtnB.wasPressed())
  {
    this->hot();
    this->displayState();
  }
  if (M5.BtnC.wasPressed())
  {
    this->neutral();
    this->displayState();
  }
}

void Controller::displayState()
{
  M5.Lcd.setCursor(0, 40);
  M5.Lcd.print(this->state);
  M5.Lcd.print("    ");
}
