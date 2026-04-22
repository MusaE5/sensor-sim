#ifndef IMU_H
#define IMU_H
#include "Sensor.h"

class IMUSensor: public Sensor{
  public:
    float read() override{
        return 2.93;
    }
};


#endif