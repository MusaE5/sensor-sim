#ifndef SENSOR_H
#define SENSOR_H
#include "SensorReading.h"

class Sensor{
    public:
    virtual SensorReading read() = 0;
    virtual void checkAnomaly(SensorReading& obj) = 0;
    virtual ~Sensor() = default;
};

#endif