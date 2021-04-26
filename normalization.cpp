#include "normalization.h"

void Normalization::processBuffer(unsigned char* buffer, int bufferSize){

	//process that increases the level of a recording by a constant amount so that it reaches a target or a norm
	float sumBuffer = 0; 
	float averageBuffer = 0; 

	//Calculate the average buffer 
	for (int i = 0; i < bufferSize; i++)
	{
		sumBuffer = buffer[i] + sumBuffer;
		averageBuffer = (sumBuffer/i);  
	}

	//Adjust the buffers appropriately
	for (int j = 0; j < bufferSize; j++)
	{
		buffer[j] = ((256*.8)/(averageBuffer))*buffer[j]; 
	}
}
