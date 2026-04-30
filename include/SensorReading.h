#ifndef SENSOR_READING_H
#define SENSOR_READING_H

#include<string>
#include<vector>

struct SensorReading{
    float values[6];
    char label[32];
};

#endif