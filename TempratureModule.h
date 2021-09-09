#ifndef TempratureModule_h
#define TempratureModule_h
#include <OneWire.h>
#include <DallasTemperature.h>

class TempratureModule
{
public:
  OneWire oneWire;
  DallasTemperature sensors;

  TempratureModule();
  void initialize();
  float waterTemprature();
};

#endif
