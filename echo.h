#ifndef ECHO_H
#define ECHO_H
#include "processor.h"
#include <iostream>


template<class T>
class Echo : public Processor<T>
{
	public:

        int delay; 
        Echo(int newDelay): delay(newDelay){}



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
                //std::cout << "Buffer value: " << buffer[i+delay]*1 << std::endl; 
		    }
        }
};

#endif //NOISE_GATE_H
