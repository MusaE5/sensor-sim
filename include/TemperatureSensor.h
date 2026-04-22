#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include "Sensor.h"

class TemperatureSensor: public Sensor{
  public:
    float read() override{
        return 39.2;
    }
};


#endif