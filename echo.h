#ifndef ECHO_H
#define ECHO_H

#include "processor.h"
#include <iostream>


template<class T>
class Echo : public Processor<T>
{
	public:

        int delay; 
	
	/**
	 * Constructor for Echo class that sets the value for the echo delay given
	 * @param newDelay - delay scale for echoeing, in integers
	 */        
	Echo(int newDelay): delay(newDelay){}

	/**
	 * Overrides abstract class/interface processBuffer to manipulate the wav buffer by echoing the audio
	 * @param buffer - buffer array from the audio read in, in template data type T
	 * @param bufferSize - size of buffer from wav files, in integers
	 * @param bitdepth - bit size/length from read in wav files, in short integers
	 * @param numchannels - number of channels in the read in wav files to determine mono or stereo, int short integers
	 */
	void processBuffer(T* buffer, int bufferSize, short bitdepth, short numchannels)
        {       
                static const T MID = (pow(2, bitdepth)/2);
                static const float scaleFactor = 0.5f;
                float echoLevel = 0.5f;
                float adj_n;
                float adj_delayed_n;
                float finalEcho;

                if (numchannels == 1)
                {
                        for(int i = 0; i < bufferSize - delay; i++){
                                adj_n = (float)(buffer[i] - MID);
                                adj_delayed_n = (float)(buffer[i + delay] - MID);
                                finalEcho = adj_n * echoLevel + adj_delayed_n * scaleFactor + MID;
                                buffer[i + delay] = (T)(round(finalEcho));
                        }
                }

                if (numchannels == 2)
                {
                        for(int i = 0; i < bufferSize - delay; i+=2){
                                adj_n = (float)(buffer[i] - MID);
                                adj_delayed_n = (float)(buffer[i + delay] - MID);
                                finalEcho = adj_n * echoLevel + adj_delayed_n * scaleFactor + MID;
                                buffer[i + delay] = (T)(round(finalEcho));
                        }

                        for (int j = 0; j < bufferSize-delay; j+=2)
                        {
                                adj_n = (float)(buffer[j] - MID);
                                adj_delayed_n = (float)(buffer[j + delay] - MID);
                                finalEcho = adj_n * echoLevel + adj_delayed_n * scaleFactor + MID;
                                buffer[j + delay] = (T)(round(finalEcho));
                        }
                }
        }
};

#endif //ECHO_H
