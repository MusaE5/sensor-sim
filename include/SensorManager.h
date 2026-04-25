#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H
#include "Sensor.h"
#include<memory>
#include<vector>

class SensorManager{
    std::vector<std::unique_ptr<Sensor>> sensors;
    public:

    void addSensor(std::unique_ptr<Sensor> sensor){
        sensors.push_back(std::move(sensor));
    }

    std::vector<float> readAll(){
        std::vector<float> results;
        for(std::unique_ptr<Sensor>& ptr: sensors){
            results.push_back(ptr->read());
        }
        return results;
    }
};


#endif