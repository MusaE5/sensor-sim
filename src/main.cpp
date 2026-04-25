#include "Sensor.h"
#include "IMUSensor.h"
#include "UltrasonicSensor.h"
#include "TemperatureSensor.h"
#include "SensorManager.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main(){
    SensorManager manager;
    manager.addSensor(make_unique<IMUSensor>());
    manager.addSensor(make_unique<UltrasonicSensor>());
    manager.addSensor(make_unique<TemperatureSensor>());

    vector<float> readings = manager.readAll();
    for(float reading: readings){
        cout<<reading<<endl;
    }

}