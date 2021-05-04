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
	 * Constructor for NoiseGate class the sets the scale the the amplitude will be scaled by
	 * @param newPercent - scaling factor, in integers
	 */
		NoiseGate(int newPercent): gateLimitPercent(newPercent){}
        
	/**
	 * Overrides abstract class/interface processBuffer to manipulate the wav buffer by deleting any sound within a threshold
	 * @param buffer - buffer array from the audio read in, in template data type T
	 * @param bufferSize - size of buffer from wav files, in integers
	 * @param bitdepth - bit size/length from read in wav files, in short integers
	 * @param numchannels - number of channels in the read in wav files to determine mono or stereo, int short integers
	 */
		void processBuffer(T* buffer, int bufferSize, short bitdepth, short numchannels)
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

			if (numchannels == 1)
			{
				for(int i = 0; i < bufferSize; i++)
				{
					if(buffer[i] < upperThreshold && buffer[i] > lowerThreshold)
					{
						buffer[i] = zeroValue;
					}
				}

			}

			if (numchannels == 2)
			{
				for(int i = 0; i < bufferSize; i+=2){
					if(buffer[i] < upperThreshold && buffer[i] > lowerThreshold){
						buffer[i] = zeroValue;
					}
				}

				for (int j = 1; j < bufferSize; j+=2)
				{
					if (buffer[j] < upperThreshold && buffer[j] > lowerThreshold)
					{
						buffer[j] = zeroValue;
					}
				}
			}


		}

};

#endif //NOSIEGATE_H
