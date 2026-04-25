#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H
#include "Sensor.h"
#include "SensorReading.h"
#include<memory>
#include<unordered_map>
#include<string>
#include<vector>

class SensorManager{
    std::vector<std::unique_ptr<Sensor>> sensors;
    public:

    void addSensor(std::unique_ptr<Sensor> sensor){
        sensors.push_back(std::move(sensor));
    }

    std::vector<SensorReading> readAll(){
        std::vector<SensorReading> measurments;
        for(std::unique_ptr<Sensor>& ptr: sensors){
            SensorReading obj = ptr->read();
            measurments.push_back(obj);
        }
        return measurments;
    }
    
};


#endif