#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H
#include "Sensor.h"
#include "SensorReading.h"
#include<random>
#include<string>
#include<iostream>

class UltrasonicSensor: public Sensor{
    const std::string label = "Ultrasonic";
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dist;

  public:
    UltrasonicSensor(): gen(rd()), dist(0, 100){}

    SensorReading read() override{
        SensorReading result;
        result.label = label;
        result.values.push_back(dist(gen));
        return result;
    }

    void checkAnomaly(SensorReading& obj) override{
    if(obj.values[0] < 10.0){
        std::cerr << "[ANOMALY] " << label << " obstacle detected: " << obj.values[0] << "cm\n";
    }
    else{
        std::cout << "[OK] " << label << ": " << obj.values[0] << "cm\n";
    }
}
};


#endif