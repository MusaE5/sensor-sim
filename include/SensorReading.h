#ifndef SENSOR_READING_H
#define SENSOR_READING_H

#include<string>
#include<vector>

struct SensorReading{
    std::vector<float> values;
    std::string label;
};

#endif