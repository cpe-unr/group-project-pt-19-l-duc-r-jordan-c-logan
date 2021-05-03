#include "noiseGate.h"

NoiseGate::NoiseGate(int newUpperThreshold, int newLowerThreshold){
	upperThreshold = (uint8_t) newUpperThreshold;
	lowerThreshold = (uint8_t) newLowerThreshold;
}

void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize, short bitdepth){
	int zeroValue = (uint8_t) 128;

	for(int i = 1; i < bufferSize; i++){
		if(buffer[i] > upperThreshold && buffer[i] < lowerThreshold){
			buffer[i] = zeroValue;
		}
	}
}
