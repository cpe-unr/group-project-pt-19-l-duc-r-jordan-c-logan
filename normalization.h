#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream>
#include "processor.h"

class Normalization : public Processor{
public:

	void processBuffer(unsigned char* buffer, int bufferSize) override;

};

#endif
