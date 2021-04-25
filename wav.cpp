#include "wav.h"

void Wav::readFile(const std::string &fileName){
	//reads in files & creates buffer to store data
/*
	std::ifstream file(fileName,std::ios::binary | std::ios::in);    
	if(file.is_open()){ 
		file.read((char*)&waveHeader, sizeof(wav_header));
		buffer = new unsigned char[waveHeader.data_bytes]; 
		file.read((char*)buffer, waveHeader.data_bytes);       
		file.close();
	}
	short* shortBuffer = reinterpret_cast<short*>(buffer);
*/
}
        
void Wav::writeFile(const std::string &outFileName){
	//writes back to file the processing and changes made

/*	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	outFile.write((char*)buffer, waveHeader.data_bytes);
	outFile.close();
*/
}
	
Wav::~Wav(){
	//deletes buffer from heap
	if(buffer != NULL){
		delete[] buffer;
	}
}

int Wav::getBufferSize() const {
	//getter for buffer size
	return waveHeader.data_bytes;
}

