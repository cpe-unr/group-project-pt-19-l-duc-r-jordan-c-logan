//CS 202 Semester Project - PT 19

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>
#include <cmath>

template<typename T>

class Processor{
public:

    virtual void processBuffer(T* buffer, int bufferSize, short bitdepth) = 0;

};

#endif //PROCESSOR_H
