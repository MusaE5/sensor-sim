#include "Sensor.h"
#include "IMUSensor.h"
#include "UltrasonicSensor.h"
#include "TemperatureSensor.h"
#include "SensorManager.h"
#include "SensorReading.h"
#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>

int main(){
    SensorManager manager;
    manager.addSensor(std::make_unique<IMUSensor>());
    manager.addSensor(std::make_unique<TemperatureSensor>());
    manager.addSensor(std::make_unique<UltrasonicSensor>());

    int counter = 0;

    while(counter < 5){
    manager.readAll();
    counter++;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    }

}