// #ifndef NORMALIZATION_H
// #define NORMALIZATION_H

// #include <iostream>
// #include "processor.h"

// class Normalization : public Processor{
	
// 	public:
// 	void processBuffer(unsigned char* buffer, int bufferSize) override;
// 	int maxBuffer = 0;
// 	float multiplier; 
	

// };

// #endif

#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream>
#include "processor.h"
#include "waveHeader.h"
#include "wav.h"

class Normalization : public Processor{
	
	int maxBuffer = 0;
	float multiplier;

	
	public:
		//Normalization(int newMaxBuffer, float newMultiplier);
		Normalization();
		void processBuffer(unsigned char* buffer, int bufferSize, short bitdepth)override;
	

};

#endif

