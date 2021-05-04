#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream>
#include "processor.h"
#include "waveHeader.h"
#include "wav.h"

/**
 * This is the templated Normalization class that inherits from the Processor class.
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
	 * Overrides the abstract function/interface to manipulate the wav file buffer by amplifying amplitude by a certain scale
	 * @param buffer - array holding audio buffer, in Templated type T data type
	 * @param bufferSize - size of wav files buffer, in integers
	 * @param bitdepth - bit size of wav file, in short integers
	 */	
	void processBuffer(T* buffer, int bufferSize, short bitdepth)
	{
		//process that increases the level of a recording by a constant amount so that it reaches a target or a norm
		double maxDistance = 0;
		double multiplier;
		std::cout << "Bit Depth: " << bitdepth << std::endl;
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

		std::cout << "MID: " << MID << std::endl;

		//Find the maximum buffer
		for (int i = 0; i < bufferSize; i++)
		{
			if (abs(buffer[i]-MID) > maxDistance)
			{
				maxDistance = abs(buffer[i]-MID);
				//std::cout << "Max Distance Progression: " << maxDistance<< std::endl;
			} 
		}

		//Adjust the buffers appropriately
		std::cout << "Max Distance: " << maxDistance << std::endl;
		std:: cout << "MAX BOUNDS: " << MAXDISTANCE << std::endl;
		multiplier = (MAXDISTANCE/maxDistance);
		std::cout << "Multiplier: " << multiplier << std::endl;




		//Set all the buffers into the multiplier
		for (int j = 0; j < bufferSize; j++)
		{
			buffer[j] = buffer[j] * multiplier; 
		}
	}
	

};

#endif //NORMALIZATION_H
