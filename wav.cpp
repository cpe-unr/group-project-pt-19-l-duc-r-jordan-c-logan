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
	
	//This is what I wanted to implement after the vector of strings did not work out
	//I  wanted to avoid segmentation faults with writing the file back so I instead made a vector to contain char[4]
	//And instead of file.eof, I used the calculation of a number to compare the sizes (This way I can cut of id3 from the metadata file which is useless)
	//Metadata header reading
        //file.read((char*)&metaHeader, sizeof(meta_header));

        //std::cout << metaHeader.chunkSize << std::endl; 
        //Read in the metadata
        //while (num < metaHeader.chunkSize)
        //{
          //std::array<char, 4> subChunkHeader;
          //char subChunkHeader[4];
          //file.read((char*)&subChunkHeader, 4);
          //subChunk.push_back(subChunkHeader[0], subChunkHeader[1], subChunkHeader[2], subChunkHeader[3]);
          //subChunk.push_back(subChunkHeader);

          // for (std::array<char, 4> x : subChunk)
          // {
          //   for (int i =0; i < x.size() ; i++) 
          //   {
          //     std::cout<< x[i];
          //   }
          // }

          //std::cout << std::endl;

          //int subChunkSize; 
          //file.read((char*)&subChunkSize, 4);
          //std::cout << "The sub-chunk size: " << subChunkSize << std::endl;  


          //char actual[subChunkSize];
          //file.read((char*)&actual, subChunkSize);
          //actualData.push_back(actual);
          //std::cout << "The actual data: " << actualData[i] << std::endl; 
          
          //i = i+1;
          //num = num + 8 + subChunkSize;

         //std::cout << num << std::endl;
        //}

        //file.close();

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
	
	//Write in the starting metadata
//    outFile.write((char*)&metaHeader, sizeof(metaHeader));
	
	//Write in the subchunks
//    for (std::string x : subChunk)
//    {
//      int index = 0;
//      outFile.write(&subChunk[index][0], subChunk[index].size());
//      outFile.write((char *)actualData[index].size(), sizeof(int));
//      outFile.write(&actualData[index][0], actualData[index].size());
//    }
	
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

