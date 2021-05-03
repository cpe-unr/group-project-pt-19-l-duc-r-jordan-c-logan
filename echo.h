#ifndef ECHO_H
#define ECHO_H

#include <iostream>
#include "processor.h"


class Echo : public Processor{
	int delay;
public:
	explicit Echo(int delay);

        void processBuffer(unsigned char* buffer, int bufferSize, short bitdepth) override;

	//Need to change processors to templates so different files can be processed!!
};

#endif
