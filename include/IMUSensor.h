#ifndef IMU_H
#define IMU_H
#include "Sensor.h"
#include "SensorReading.h"
#include <random>
#include <unordered_map>
#include <cstring>
#include<iostream>

class IMUSensor: public Sensor{
    const char label[32] = "IMU";
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dist;

    const std::unordered_map<int, std::string> map = {
        {0, "ax"},
        {1, "ay"},
        {2, "az"},
        {3, "gx"},
        {4, "gy"},
        {5, "gz"}
    };
    


  public:
    IMUSensor(): gen(rd()), dist(-10.0, 10.0){}

    SensorReading read() override{
        SensorReading result;
        strncpy(result.label, label, 32);

        for(int i = 0; i<6; i++){
            result.values[i] = dist(gen);
        }
        
        return result;
    }
    
    void checkAnomaly(SensorReading& obj) override{

        for(int i = 0; i<6; i++){
            if(obj.values[i] >=8.0){
                std::cerr << "[ANOMALY] " << map.at(i) << " too high: " << obj.values[i] << "\n";
            }
            else if(obj.values[i] <= -8.0){
                std::cerr << "[ANOMALY] " << map.at(i) << " too low: " << obj.values[i] << "\n";
            }
            else{
                std::cout << "[OK] " << map.at(i) << ": " << obj.values[i] << "\n";
            }
        }
    }
};


#endif