#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H
#include <cstdint>
#include <iostream>
#include "SensorReading.h"

class MemoryPool{
    private:
    static const int SENSOR_AMOUNT = 3;
    static const int bytesPerSlot = sizeof(SensorReading);
    uint8_t pool[bytesPerSlot*SENSOR_AMOUNT];  // 
    bool marked[SENSOR_AMOUNT];

    public:
    MemoryPool(): marked{} {}

    SensorReading* allocate(){
        for(int i = 0; i < SENSOR_AMOUNT; i++){
            if(!marked[i]){
                marked[i] = true;
                std::cout<<"Successfully allocated memory to slot "<<i<<"\n";
                return reinterpret_cast<SensorReading*>(pool + (bytesPerSlot*i));
            }
        }

        std::cerr<<"No free memory available. Return nullptr\n";
        return nullptr;
    }

    void deallocate(SensorReading*& ptr){
        bool wasAllocated = false;

        for(int i = 0; i<SENSOR_AMOUNT; i++){
            if(reinterpret_cast<uint8_t*>(ptr) == pool + (bytesPerSlot*i)){
                wasAllocated = true;
                marked[i] = false;
                ptr = nullptr;
                std::cout<<"Succesfully deallocated at slot "<<i<<". Pointer set to nullptr\n";
                break;
            }
        }

        if(!wasAllocated){
            std::cerr<<"This ptr was not allocated. Can't deallocate\n";
        }
        
    }

};




#endif