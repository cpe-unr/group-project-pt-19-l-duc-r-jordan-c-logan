//CS 202 Semester Project - PT 19

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
        void setBitDepth(short newBitDepth);
        //void setBitDepth(short b);

    private:
        unsigned char* buffer;
        wav_header waveHeader;
        short bitDepth;
        short* shortBuffer;

    public:
        virtual ~Wav();

    public:
        //short* shortBuffer = NULL;
        unsigned char *getBuffer();
        int getBufferSize();
        short *getShortBuffer();

};


#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
