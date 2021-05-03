//CS 202 Semester Project - PT 19

<<<<<<< HEAD
#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H
=======
#ifndef WAV_H
#define WAV_H
>>>>>>> e35af725492486ec242c8b475000f049ba3f225e
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

<<<<<<< HEAD

#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
=======
#endif
>>>>>>> e35af725492486ec242c8b475000f049ba3f225e
