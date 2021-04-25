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
	virtual ~Wav();

	//const getter for unsigned 8 bit buffer
	//const getter for short 16 bit buffer

	int getBufferSize() const;
};

#endif
