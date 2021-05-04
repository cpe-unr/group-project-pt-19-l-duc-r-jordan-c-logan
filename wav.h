//CS 202 Semester Project - PT 19

#ifndef WAV_H
#define WAV_H
#include <string>

#include "waveHeader.h"

/**
 * This is the Wav class.
 */

class Wav {
    public:
        //short bitDepth;

	/**
	 * Reads in wav file 
	 * @param filename - constant audio file name, in a string
	 */ 
        void readFile(const std::string &fileName);

	/**
	 * Writes manipulation done by processors to output wav file
	 * @param outFileName - constant output audio file containing overwritten audio, in a string
	 */
        void writeFile(const std::string &outFileName);

	/**
	 * Getter for a wav file's bit depth, or bit capacity
	 */
        short getBitDepth();

	/**
	 * Setter for a wav file's bit depth, or bit capacity
	 * @param newBitDepth - a new file's bit size, in short integers
	 */
        void setBitDepth(short newBitDepth);
        //void setBitDepth(short b);

    private:
        unsigned char* buffer;
        wav_header waveHeader;
        short bitDepth;
        short* shortBuffer;

    public:

	/**
	 * Destructor for the wav buffer that was added to the heap
	 */
        virtual ~Wav();

    public:
        //short* shortBuffer = NULL;

	/**
	 * Getter for 8 bit wav file's unsigned char buffer
	 */
        unsigned char *getBuffer();

	/**
	 * Getter for the buffersize of audio files
	 */
        int getBufferSize();

	/**
	 * Getter for 16 bit wav file's short buffer
	 */
        short *getShortBuffer();

};


#endif //WAV_H
