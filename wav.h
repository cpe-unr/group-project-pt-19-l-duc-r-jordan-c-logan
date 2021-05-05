//CS 202 Semester Project - PT 19

#ifndef WAV_H
#define WAV_H
#include <string>

#include "waveHeader.h"
#include "metaChunksHeader.h"
#include "Metachunks.h"

/**
 * This is the Wav class.
 */

class Wav {
    public:
        //short bitDepth;

	/**
	 * Reads in wav file 
	 * @param fileName - constant output audio file
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
        unsigned char* buffer = NULL;
        wav_header waveHeader;
	meta_header metaHeader;
        
	short bitDepth;
        short* shortBuffer = NULL;
	short numChannels;
	char* fmtHeader;
	int sampleRate;
	
	std::vector<std::string> subChunk; 
	std::vector<int> numChar;
        std::vector<std::string> actualData;
	
	//What I wanted for the subChunk instead
	//std::vector<std::array<char, 4> > subChunk;


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

	/**
	 * Getter for number of Channels in wav files
	 */
	short getNumChannels();

	/**
	 * Setter for number of channels in wav files
	 */
	void setNumChannels(short newNumChannels);

	/**
	 * Getter for format header from wav files
	 */
	char* getFmtHeader();

	/**
	 * Setter for format header from wav files
	 */
	void setFmtHeader(char* newFmtHeader);

	/**
	 * Getter for sample rate of wav files 
	 */
	int getSampleRate();

	/**
	 * Setter for sample rate of wav files
	 */
	void setSampleRate(int newSampleRate);

	/**
	 * Getter for metadata subchunk
	 */
	std::vector<std::string> getSubChunk();

	/**
	 * Getter for actual metadata (i.e. Title, artist)
	 */
        std::vector<std::string> getActualData();
};

#endif //WAV_H
