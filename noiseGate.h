#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <iostream>
#include "processor.h"

class NoiseGate : public Processor{
	int upperThreshold, lowerThreshold;

public:
	NoiseGate(int newUpperThreshold, int newLowerThreshold);
        void processBuffer(unsigned char* buffer, int bufferSize, short bitdepth) override;

};

#endif
