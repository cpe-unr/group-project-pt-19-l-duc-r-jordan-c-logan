#include "fileIO.h"
#include "waveHeader.h"

FileIO::FileIO() {};

void FileIO::writeCsvFile(std::string file, int bufferSize){

	wav_header w;

	std::ofstream dataFile(file);
	
	//Columns showing what data layout is
	dataFile << "Filename, Chunk Size, Num Channels, Sample Rate, Bit Size, MetaData " << std::endl;

	for(int i = 0; i < bufferSize; i++){
		dataFile << file << ", " << w.fmt_chunk_size << ", " << w.num_channels << ", " << w.sample_rate << "," << w.bit_depth << ", " << "METADATA" << std::endl;
		
	}	
	dataFile.close();
}
