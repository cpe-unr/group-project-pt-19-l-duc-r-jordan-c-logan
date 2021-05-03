#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <iostream>
#include "processor.h"


template<class T>
class NoiseGate : public Processor<T>
{

	public:
		int gateLimitPercent; 
		NoiseGate(int newPercent): gateLimitPercent(newPercent){}
        
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
