#include <string>
#include <fstream>
#include <iostream>
#include "wav.h"

//Getter
short Wav::getBitDepth(){
    return bitDepth; 
}

//Setter
void Wav::setBitDepth(short newBitDepth)
{
    bitDepth = newBitDepth;   
}

void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        setBitDepth(waveHeader.bit_depth);
	setNumChannels(waveHeader.num_channels);
	setFmtHeader(waveHeader.fmt_header);
	setSampleRate(waveHeader.sample_rate);

        if (bitDepth == 8)
        {
            buffer = new unsigned char[waveHeader.data_bytes];
            file.read((char*)buffer, waveHeader.data_bytes);
        }

        if (bitDepth == 16)
        {
            shortBuffer = new short[waveHeader.data_bytes];
            file.read(reinterpret_cast<char*>(shortBuffer), waveHeader.data_bytes);
        }
		
		//Metadata header reading
        file.read((char*)&metaHeader, sizeof(meta_header));

        //Read in the metadata
        while (!file.eof())
        {
          char subChunkHeader[4];
          file.read((char*)&subChunkHeader, 4);
          subChunk.push_back(subChunkHeader);
          
          int subChunkSize; 
          file.read((char*)&subChunkSize, 4);

          char actual[subChunkSize];
          file.read((char*)&actual, subChunkSize);

          actualData.push_back(actual);
        }

        file.close();

        //Erase useless ID 3 that is for other programs
        subChunk.erase(subChunk.end()-2, subChunk.end());
        actualData.erase(actualData.end()-2, actualData.end());
		
        file.close();

    }

}

unsigned char *Wav::getBuffer(){
    return buffer;
}

short *Wav::getShortBuffer()
{
    return shortBuffer;
}

std::vector<std::string> Wav::getSubChunk()
{
  return subChunk;
}

std::vector<std::string> Wav::getActualData()
{
  return actualData;
}

void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    setBitDepth(waveHeader.bit_depth);
    setNumChannels(waveHeader.num_channels);
    setFmtHeader(waveHeader.fmt_header);
    setSampleRate(waveHeader.sample_rate);

    if (bitDepth == 8)
    {
        outFile.write((char*)buffer, waveHeader.data_bytes);
        std::cout << "test" << std::endl;
    }

    if (bitDepth == 16)
    {
        outFile.write(reinterpret_cast<char*>(shortBuffer), waveHeader.data_bytes);
    }
	
    outFile.close();

}

Wav::~Wav() {
    if(buffer != NULL){
        delete[] buffer;
    }	
}

int Wav::getBufferSize(){
    return waveHeader.data_bytes;
}

short Wav::getNumChannels(){
	return numChannels;
}

void Wav::setNumChannels(short newNumChannels){
	numChannels = newNumChannels;
}

char* Wav::getFmtHeader(){
	return fmtHeader;
}

void Wav::setFmtHeader(char* newFmtHeader){
	fmtHeader = newFmtHeader;
}

int Wav::getSampleRate(){
	return sampleRate;
}

void Wav::setSampleRate(int newSampleRate){
	sampleRate = newSampleRate;
}

