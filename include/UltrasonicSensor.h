#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H
#include "Sensor.h"

class UltrasonicSensor: public Sensor{
  public:
    float read() override{
        return 3.1;
    }
};


#endif