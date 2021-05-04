#ifndef ECHO_H
#define ECHO_H

#include "processor.h"
#include <iostream>

/**
 * This is the templated Echo class that inherits from the Processor class.
 */

template<class T>
class Echo : public Processor<T>
{
	public:

        int delay; 

	/**
	 * Parameterized Constructor for Echo class that that takes in the delay needed to echo the given wav file
         * @param newDelay - delay scale, in integers
	 */
        Echo(int newDelay): delay(newDelay){}
	
	/**
	 * overrides abstract function processBuffer() and uses delay to make echoed wav file 
	 * @param buffer - array holding audio buffer, in Templated type T data type
	 * @param bufferSize - size of wav files buffer, in integers
	 * @param bitdepth - bit size of wav file, in short integers
	 */
	void processBuffer(T* buffer, int bufferSize, short bitdepth)
        {
            std::cout << delay << std::endl; 
            static const T MID = (pow(2, bitdepth)/2);
            static const float scaleFactor = 0.5f;
            float echoLevel = 0.5f;
            float adj_n;
            float adj_delayed_n;
            float finalEcho;

                for(int i = 0; i < bufferSize - delay; i++){
                        adj_n = (float)(buffer[i] - MID);
                        adj_delayed_n = (float)(buffer[i + delay] - MID);
                        finalEcho = adj_n * echoLevel + adj_delayed_n * scaleFactor + MID;
                        buffer[i + delay] = (T)(round(finalEcho));
                }
        }
};

#endif //ECHO_H
