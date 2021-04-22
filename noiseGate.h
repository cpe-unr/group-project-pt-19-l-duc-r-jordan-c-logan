#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <iostream>
#include "processor.h"

class NoiseGate : public Processor{
	int upperThreshold, lowerThreshold;

public:
	NoiseGate(int newUpperThreshold, int newLowerThreshold);
	virtual void processBuffer(unsigned char* buffer, int bufferSize) override;

	//Need to change this to templatized also!
};

#endif
