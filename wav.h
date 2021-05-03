//CS 202 Semester Project - PT 19

#ifndef WAV_H
#define WAV_H
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

#endif
