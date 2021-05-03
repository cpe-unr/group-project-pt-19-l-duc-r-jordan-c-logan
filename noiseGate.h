#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <iostream>
#include "processor.h"


template<class T>
class NoiseGate : public Processor<T>
{

	public:
		int gateLimitPercent; 

	/**
	 * NoiseGate constructor to obtain gates limit percent
	 * @param newPercent - percent that the noise amp. will be scaled to, in integers
	 */
	NoiseGate(int newPercent): gateLimitPercent(newPercent){}
        
	/**
	 * Overrides abstract class/interface processBuffer to manipulate wav file by eliminating sound between a threshold
	 * @param buffer - array holding audio buffer, in Templated type T data type
	 * @param bufferSize - size of wav files buffer, in integers
	 * @param bitdepth - bit size of wav file, in short integers 
	 */
	void processBuffer(T* buffer, int bufferSize, short bitdepth)
	{
		int upperThreshold, lowerThreshold; 

		T zeroValue;

		if (bitdepth == 8)
		{
			zeroValue = pow(2, bitdepth);
			upperThreshold = zeroValue + (pow(2, bitdepth)*gateLimitPercent);
			lowerThreshold = zeroValue - (pow(2, bitdepth)*gateLimitPercent);
		}

		if (bitdepth == 16)
		{
			zeroValue = 0;
			upperThreshold = zeroValue + (pow(2, bitdepth-1)*gateLimitPercent);
			lowerThreshold = zeroValue + (pow(2, bitdepth-1)*gateLimitPercent);
		}

		for(int i = 1; i < bufferSize; i++){
			if(buffer[i] > upperThreshold && buffer[i] < lowerThreshold){
				buffer[i] = zeroValue;
			}
		}
	}

};

#endif //NOSIEGATE_H
