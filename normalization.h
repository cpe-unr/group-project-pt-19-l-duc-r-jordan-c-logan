#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream>
#include "processor.h"
#include "waveHeader.h"
#include "wav.h"

	/**
	* This is the Normalization class.
	*/

template <class T>
class Normalization : public Processor<T>
{
	
	//int maxBuffer = 0;
	//float multiplier;
	
	public:
		//Normalization(int newMaxBuffer, float newMultiplier);
		//Normalization(){}

	/**
	 * Overrides abstract class/interface processBuffer to manipulate the wav buffer by amplifying the audio by a caluculated distance
	 * @param buffer - buffer array from the audio read in, in template data type T
	 * @param bufferSize - size of buffer from wav files, in integers
	 * @param bitdepth - bit size/length from read in wav files, in short integers
	 * @param numchannels - number of channels in the read in wav files to determine mono or stereo, int short integers
	 */
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
