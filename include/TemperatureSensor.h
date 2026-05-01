#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include "Sensor.h"
#include "SensorReading.h"
#include <cstring>
#include <random>
#include<iostream>

class TemperatureSensor: public Sensor{
    static const char label[32] = "Temperature";
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dist;
  public:
    TemperatureSensor() : gen(rd()), dist(-40.0, 40.0){}

    SensorReading read() override{
        SensorReading result;
        strncpy(result.label, label, 32);
        result.values[0] = dist(gen);
        return result;
    }

    void checkAnomaly(SensorReading &obj) override{
        if(obj.values[0] > 30 ){
            std::cerr << "[ANOMALY] " << label << " too high: " << obj.values[0] << "\n";
        }
        else if(obj.values[0] < 0){
            std::cerr << "[ANOMALY] " << label << " too low: " << obj.values[0] << "\n";
        }
        else{
            std::cout << "[OK] " << label << obj.values[0] << "\n";
        }
    }

};


#endif