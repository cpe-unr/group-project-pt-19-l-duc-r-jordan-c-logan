// #include "normalization.h"

// //#define 16_BIT_MAX 32767;
// //#define 8_BIT_MAX 255;

// // Normalization::Normalization(int newMaxBuffer, float newMultiplier)
// // {
// // 	maxBuffer = newMaxBuffer; 
// // 	multiplier = newMultiplier; 
// // }

// Normalization::Normalization(){}

// void Normalization::processBuffer(unsigned char* buffer, int bufferSize, short bitdepth){

// 	//process that increases the level of a recording by a constant amount so that it reaches a target or a norm

// 	//Access bit depth attribute of wav class

// 	std::cout << "Bit Depth: " << bitdepth << std::endl; 


// 	//Find the maximum buffer
// 	for (int i = 0; i < bufferSize; i++)
// 	{
// 		if (buffer[i] > maxBuffer)
// 		{
// 			maxBuffer = buffer[i];
// 		} 
// 	}

// 	//Adjust the buffers appropriately
// 	if (bitdepth == 8)
// 	{
// 		multiplier = 255/maxBuffer;
// 	}

// 	else if (bitdepth == 16)
// 	{
// 		multiplier = 32767/maxBuffer;
// 	}

// 	else
// 	{
// 		multiplier = 0; 
// 	}



// 	//Set all the buffers into the multiplier
// 	for (int j = 0; j < bufferSize; j++)
// 	{
// 		buffer[j] = buffer[j] * multiplier; 
// 	}
// }
