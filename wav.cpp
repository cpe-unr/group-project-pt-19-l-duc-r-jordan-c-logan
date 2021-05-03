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

/*
 * This class is designed to work with PCM 8-bit mono wavefiles.
 * It makes many assumptions about the format of the wave as a result.
 * It will NOT work with stereo files or any other bit-depth than 8 bits.
 */

#include <string>
#include <fstream>
#include <iostream>
#include "wav.h"


// //Setter 
// void Wav::setBitDepth(short b)
// {
//     b = bitDepth;
// }

//Getter
short Wav::getBitDepth(){
    // readFile(fileName);

    //std::cout << "The bit depth is: " << bitDepth << std::endl; 
    return bitDepth; 
}

void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new unsigned char[waveHeader.data_bytes];
        file.read((char*)buffer, waveHeader.data_bytes);
        file.close();

    }

	bitDepth = waveHeader.bit_depth;

    if (bitDepth == 16)
    {
        short* shortBuffer = reinterpret_cast<short*>(buffer);
    }
}

unsigned char *Wav::getBuffer(){
    return buffer;
}

void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();

}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

int Wav::getBufferSize(){
    return waveHeader.data_bytes;
}




