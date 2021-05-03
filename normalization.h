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

		void processBuffer(T* buffer, int bufferSize, short bitdepth)
		{
			//process that increases the level of a recording by a constant amount so that it reaches a target or a norm
			double maxDistance = 0;
			double multiplier;
			std::cout << "Bit Depth: " << bitdepth << std::endl;
			T MID;
			T MAXDISTANCE = (pow(2, bitdepth)/2)-1;
			
			if (bitdepth == 8)
			{
				MID = pow(2, bitdepth);
			}

			if (bitdepth == 16)
			{
				MID = 0;
			}

			int test;
			

			//Find the maximum buffer
			for (int i = 0; i < bufferSize; i++)
			{
				if (abs(buffer[i]-MID) > maxDistance)
				{
					maxDistance = abs(buffer[i]-MID);
					if(maxDistance > 32767)
					{
						maxDistance = 32767;
					}

					std::cout << "Max Distance Progression: " << maxDistance<< std::endl;
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

				// if (buffer[j] == NULL)
				// {
				// 	std::cout << "Somthing's wrong" << std::endl;
				// }

				// else 
				// {
				// 	test = abs(buffer[j]-0);
				// 	std::cout << "Buffer being written: " << std::endl;
				// }
			}
		}
	

};

#endif //NORMALIZATION_H
