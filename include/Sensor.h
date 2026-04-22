#ifndef SENSOR_H
#define SENSOR_H


class Sensor{
    public:
    virtual float read() = 0;

    virtual ~Sensor() = default;
};

#endif