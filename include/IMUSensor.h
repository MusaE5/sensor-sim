#ifndef IMU_H
#define IMU_H
#include "Sensor.h"
#include "SensorReading.h"
#include <random>
#include <string>
using namespace std;

class IMUSensor: public Sensor{
    const string label = "IMU";
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<float> dist;

  public:
    IMUSensor(): gen(rd()), dist(-10.0, 10.0){}

    SensorReading read() override{
        SensorReading result;
        result.label = label;

        for(int i = 0; i<6; i++){
            result.values.push_back(dist(gen));
        }
        
        return result;
    }
};


#endif