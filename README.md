# Drone Sensor Simulation System

A real-time sensor monitoring system written in C++ simulating IMU, ultrasonic, and temperature sensors for a drone platform.

## Overview

This project models a drone's sensor suite using object-oriented C++. Each sensor runs continuously, generates realistic randomized readings, and checks values against configurable thresholds. Anomalies are logged to stderr, normal readings to stdout, following Unix conventions.

## Architecture

- `Sensor` — abstract base class with pure virtual `read()` and `checkAnomaly()`
- `IMUSensor` — models MPU6050, generates 6-axis accelerometer and gyroscope data
- `UltrasonicSensor` — models HC-SR04, generates distance readings in cm
- `TemperatureSensor` — generates temperature readings in Celsius
- `SensorReading` — fixed-size POD struct (`float values[6]`, `char label[32]`)
- `SensorManager` — owns sensors via `unique_ptr`, polls and checks anomalies each cycle
- `MemoryPool` — custom fixed-slot allocator for `SensorReading` objects

## Running

```bash
g++ -o main src/main.cpp -I include
./main >> logs/sensor.log 2>&1
```

Monitor live:
```bash
tail -f logs/sensor.log
```

## Key Concepts Demonstrated

- OOP: abstract classes, polymorphism, virtual dispatch
- Smart pointers and RAII
- Fixed-size structs for embedded compatibility
- Custom memory pool with pointer arithmetic
- Unix logging via stderr/stdout redirection
