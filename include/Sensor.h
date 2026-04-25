#ifndef SENSOR_H
#define SENSOR_H
#include "SensorReading.h"

class Sensor{
    public:
    virtual SensorReading read() = 0;
    virtual void checkAnomaly() = 0;
    virtual ~Sensor() = default;
};

#endif