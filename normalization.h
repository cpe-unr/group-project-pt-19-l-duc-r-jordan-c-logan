#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream>
#include "processor.h"
#include "waveHeader.h"
#include "wav.h"

template <class T>
class Normalization : public Processor<T>
{
	
	//int maxBuffer = 0;
	//float multiplier;

	
	public:
		//Normalization(int newMaxBuffer, float newMultiplier);
		//Normalization(){}

		void processBuffer(T* buffer, int bufferSize, short bitdepth, short numchannels)
		{

			//process that increases the level of a recording by a constant amount so that it reaches a target or a norm
			double maxDistance = 0;
			double multiplier;
			T MID;
			T MAXDISTANCE = (pow(2, bitdepth-1));
			if (bitdepth == 8)
			{
				MID = 128;
			}

			if (bitdepth == 16)
			{
				MID = 0;
			}


			if (numchannels == 1)
			{

				//Find the maximum buffer
				for (int i = 0; i < bufferSize; i++)
				{
					if (abs(buffer[i]-MID) > maxDistance)
					{
						maxDistance = abs(buffer[i]-MID);
					} 
				}

				//Find Multiplier
				multiplier = (MAXDISTANCE/maxDistance);

				//Set all the buffers into the multiplier
				for (int j = 0; j < bufferSize; j++)
				{
					buffer[j] = buffer[j] * multiplier; 
				}
			}

			if (numchannels == 2)
			{
				//Find the maximum buffer for BOTH sides of headphone
				for (int i = 0; i < bufferSize; i++)
				{
					if (abs(buffer[i]-MID) > maxDistance)
					{
						maxDistance = abs(buffer[i]-MID);
					} 
				}

				//Find Multiplier
				multiplier = (MAXDISTANCE/maxDistance);


				//Set all the buffers into the multiplier
				for (int i = 0; i < bufferSize; i+=2)
				{
					buffer[i] = buffer[i] * multiplier;
				}

				for (int j = 0; j < bufferSize; j+=2)
				{
					buffer[j] = buffer[j] * multiplier; 
				}
			}
			
		}
	

};

#endif //NORMALIZATION_H
