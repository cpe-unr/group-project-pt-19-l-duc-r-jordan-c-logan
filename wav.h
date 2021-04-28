//CS 202 Semester Project - PT 19

#ifndef WAV_H
#define WAV_H

#include <iostream>
#include <string>
#include <fstream>
#include "waveHeader.h"

template<typename T>
class Wav{
	T* buffer = NULL;
	wav_header waveHeader;

public:
	void readFile(const std::string &fileName){
		std::ifstream file(fileName,std::ios::binary | std::ios::in);    
		if(file.is_open()){ 
			file.read((char*)&waveHeader, sizeof(wav_header));
			buffer = new T[waveHeader.data_bytes]; 
			file.read((char*)buffer, waveHeader.data_bytes);       
			file.close();
		}
		T* shortBuffer = reinterpret_cast<T*>(buffer);
	}

        void writeFile(const std::string &outFileName){
		std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
		outFile.write((char*)&waveHeader,sizeof(wav_header));
		outFile.write((char*)buffer, waveHeader.data_bytes);
		outFile.close();
	}

	//const getter for type T buffer
	T* getBuffer(){
		return buffer;
	}

	//const getter for buffer size integer
	int getBufferSize() const{
		return waveHeader.data_bytes;
	}

	//destructor - deletes buffer from heap
	virtual ~Wav(){
		if(buffer != NULL){
			delete[] buffer;
		}
	}
};

#endif
