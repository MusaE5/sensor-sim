#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include "Sensor.h"
#include "SensorReading.h"
#include <string>
#include <random>
using namespace std;

class TemperatureSensor: public Sensor{
    const string label = "Temperature";
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<float> dist;
  public:
    TemperatureSensor() : gen(rd()), dist(-40.0, 40.0){}

    SensorReading read() override{
        SensorReading result;
        result.label = label;
        result.value = dist(gen);
        return result;
    }
};


#endif