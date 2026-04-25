#ifndef SENSOR_H
#define SENSOR_H
#include "SensorReading.h"
using namespace std;

class Sensor{
    public:
    virtual SensorReading read() = 0;

    virtual ~Sensor() = default;
};

#endif