#ifndef SENSOR_READING_H
#define SENSOR_READING_H

#include<string>
#include<vector>

struct SensorReading{
    vector<float> values;
    string label;
};

#endif