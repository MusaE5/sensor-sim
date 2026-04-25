#ifndef IMU_H
#define IMU_H
#include "Sensor.h"
#include "SensorReading.h"
#include <random>
#include <string>
#include <unordered_map>

class IMUSensor: public Sensor{
    const std::string label = "IMU";
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
        result.label = label;

        for(int i = 0; i<6; i++){
            result.values.push_back(dist(gen));
        }
        
        return result;
    }
    
    void checkAnomaly(SensorReading& obj) override{

        for(int i = 0; i<obj.values.size(); i++){
            if(obj.values[i] >=8.0){
                // log map[i] too high
            }
            else if(obj.values[i] <= -8.0){
                // log map[i] too low
            }
            else{
                // log normal map[i]
            }
        }
    }
};


#endif