<<<<<<< HEAD
=======
// #include "wav.h"

// void Wav::readFile(const std::string &fileName){
// 	//reads in files & creates buffer to store data

// 	std::ifstream file(fileName,std::ios::binary | std::ios::in);    
// 	if(file.is_open()){ 
// 		file.read((char*)&waveHeader, sizeof(wav_header));
// 		buffer = new unsigned char[waveHeader.data_bytes]; 
// 		file.read((char*)buffer, waveHeader.data_bytes);       
// 		file.close();
// 	}

// 	if(bitDepth == 16){
// 		short* shortBuffer = reinterpret_cast<short*>(buffer);
// 	}
// }
        
// void Wav::writeFile(const std::string &outFileName){
// 	//writes back to file the processing and changes made

// 	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
// 	outFile.write((char*)&waveHeader,sizeof(wav_header));
// 	outFile.write((char*)buffer, waveHeader.data_bytes);
// 	outFile.close();

// }


// unsigned char* Wav::getBuffer(){
// 	return buffer;
// }
// /*
// short* Wav::getBuffer(){
// 	return buffer;
// }
// */

// int Wav::getBufferSize() const{
// 	//getter for buffer size
// 	return waveHeader.data_bytes;
// }

// Wav::~Wav(){
// 	//deletes buffer from heap
// 	if(buffer != NULL){
// 		delete[] buffer;
// 	}
// }


>>>>>>> e35af725492486ec242c8b475000f049ba3f225e
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

void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    setBitDepth(waveHeader.bit_depth);

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
<<<<<<< HEAD
    // if(buffer != NULL)
    //     delete[] buffer;
=======
    if(buffer != NULL){
        delete[] buffer;
    }
>>>>>>> e35af725492486ec242c8b475000f049ba3f225e
}

int Wav::getBufferSize(){
    return waveHeader.data_bytes;
}

<<<<<<< HEAD




=======
>>>>>>> e35af725492486ec242c8b475000f049ba3f225e
