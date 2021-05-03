//CS 202 Semester Project - PT 19

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>
#include <cmath>

class Processor{
public:

    virtual void processBuffer(unsigned char* buffer, int bufferSize, short bitdepth) = 0;

};

#endif
