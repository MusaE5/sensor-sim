#include "Sensor.h"
#include "IMUSensor.h"
#include "UltrasonicSensor.h"
#include "TemperatureSensor.h"
#include "SensorManager.h"
#include "SensorReading.h"
#include <iostream>
#include <memory>
#include <vector>

int main(){
    SensorManager manager;
    manager.addSensor(std::make_unique<IMUSensor>());
    manager.addSensor(std::make_unique<TemperatureSensor>());
    manager.addSensor(std::make_unique<UltrasonicSensor>());

    std::vector<SensorReading> readings = manager.readAll();

    for(SensorReading& obj: readings){
        std::cout<<obj.label<<": ";
        for(float num: obj.values){
            std::cout<<num<<", ";
        }
        std::cout<<"\n";
    }
}