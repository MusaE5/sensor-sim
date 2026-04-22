#include "Sensor.h"
#include "IMUSensor.h"
#include "UltrasonicSensor.h"
#include "TemperatureSensor.h"
#include <iostream>
using namespace std;

int main(){
IMUSensor IMU;
float x = IMU.read();
UltrasonicSensor Ultrasonic;
float y = Ultrasonic.read();
TemperatureSensor Temperature;
float z = Temperature.read();

cout<<x<<y<<z;
}