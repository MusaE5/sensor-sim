#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include "Sensor.h"
#include "SensorReading.h"
#include <string>
#include <random>

class TemperatureSensor: public Sensor{
    const std::string label = "Temperature";
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dist;
  public:
    TemperatureSensor() : gen(rd()), dist(-40.0, 40.0){}

    SensorReading read() override{
        SensorReading result;
        result.label = label;
        result.values.push_back(dist(gen));
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