// //CS 202 Semester Project - PT 19

// #ifndef WAV_H
// #define WAV_H

// #include <iostream>
// #include <string>
// #include <fstream>
// #include "waveHeader.h"

// class Wav{
// 	unsigned char* buffer = NULL;
// 	wav_header waveHeader;

// public:
// 	void readFile(const std::string &fileName);
//         void writeFile(const std::string &outFileName);

// 	//getter for 8 bit buffers
// 	unsigned char* getBuffer();

// 	//getter for 16 bit buffers
// 	//short getBuffer();

// 	//const getter for buffer size integer
// 	int getBufferSize() const;

// 	//destructor - deletes buffer from heap
// 	virtual ~Wav();
// };

// #endif

// //CS 202 Semester Project - PT 19

// #ifndef WAV_H
// #define WAV_H

// #include <iostream>
// #include <string>
// #include <fstream>
// #include "waveHeader.h"

// class Wav{
// 	unsigned char* buffer = NULL;
// 	wav_header waveHeader;
// 	short bitDepth = waveHeader.bit_depth; 

// public:
// 	void readFile(const std::string &fileName);
//     void writeFile(const std::string &outFileName);

// 	//getter for 8 bit buffers
// 	unsigned char* getBuffer();

// 	//getter for 16 bit buffers
// 	//short getBuffer();
	
// 	//short getBitDepth();

// 	//const getter for buffer size integer
// 	int getBufferSize() const;

// 	//destructor - deletes buffer from heap
// 	virtual ~Wav();
// };

// #endif

//
// Created by Keith Lancaster on 3/13/21.
// Modified by PT 19

#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#include <string>

#include "waveHeader.h"

class Wav {
    public:
        //short bitDepth; 
        void readFile(const std::string &fileName);
        void writeFile(const std::string &outFileName);
        short getBitDepth();
        //void setBitDepth(short b);
        

    private:
        unsigned char* buffer = NULL;
        wav_header waveHeader;
        short bitDepth; 

    public:
        virtual ~Wav();

    public:
        unsigned char *getBuffer();
        int getBufferSize();

};


#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H

