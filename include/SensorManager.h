#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H
#include "Sensor.h"
#include "SensorReading.h"
#include "MemoryPool.h"
#include<memory>
#include<unordered_map>
#include<string>
#include<vector>

class SensorManager{
    MemoryPool pool;
    std::vector<std::unique_ptr<Sensor>> sensors;
    public:

    void addSensor(std::unique_ptr<Sensor> sensor){
        sensors.push_back(std::move(sensor));
    }

    void readAll(){
        for(std::unique_ptr<Sensor>& ptr: sensors){
            SensorReading* obj = pool.allocate();
            *obj = ptr->read();
            ptr->checkAnomaly(*obj);
            pool.deallocate(obj);
        }
    }
    
};


#endif