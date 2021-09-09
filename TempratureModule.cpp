#include "TempratureModule.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "PinConfig.h"

TempratureModule::TempratureModule()
{
  OneWire oneWire(ONE_WIRE_BUS);
  this->oneWire = oneWire;

  DallasTemperature sensors(&(this->oneWire));
  this->sensors = sensors;
}

void TempratureModule::initialize()
{
  sensors.begin();
}

float TempratureModule::waterTemprature()
{
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}
