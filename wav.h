//CS 202 Semester Project - PT 19

#ifndef WAV_H
#define WAV_H

#include <iostream>
#include <string>
#include <fstream>
#include "waveHeader.h"

class Wav{
	unsigned char* buffer = NULL;
	wav_header waveHeader;

public:
	void readFile(const std::string &fileName);
        void writeFile(const std::string &outFileName);

	//getter for 8 bit buffers
	unsigned char* getBuffer();

	//getter for 16 bit buffers
	//short getBuffer();

	//const getter for buffer size integer
	int getBufferSize() const;

	//destructor - deletes buffer from heap
	virtual ~Wav();
};

#endif
