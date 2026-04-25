#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H
#include "Sensor.h"
#include<memory>
#include<vector>
using namespace std;

class SensorManager{
    vector<unique_ptr<Sensor>> sensors;
    public:

    void addSensor(unique_ptr<Sensor> sensor){
        sensors.push_back(move(sensor));
    }

    vector<float> readAll(){
        vector<float> results;
        for(unique_ptr<Sensor>& ptr: sensors){
            results.push_back(ptr->read());
        }
        return results;
    }
};






#endif

