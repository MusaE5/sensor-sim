#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H
#include "Sensor.h"
#include "SensorReading.h"
#include<random>
#include<string>
using namespace std;

class UltrasonicSensor: public Sensor{
    const string label = "Ultrasonic";
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<float> dist;

  public:
    UltrasonicSensor(): gen(rd()), dist(0, 100){}

    SensorReading read() override{
        SensorReading result;
        result.label = label;
        result.value = dist(gen);
        return result;
    }
};


#endif