#include "fileIO.h"
#include "waveHeader.h"
#include "Metachunks.h"

FileIO::FileIO() {};

void FileIO::writeCsvFile(std::string file, int bufferSize){

	wav_header w;
	meta_header m;

	std::ofstream dataFile(file);
	
	//Columns showing what data layout is
	dataFile << "Filename, Chunk Size, Num Channels, Sample Rate, Bit Size, MetaData " << std::endl;

	//for(int i = 0; i < bufferSize; i++){
		dataFile << file << ", " << w.fmt_chunk_size << ", " << w.num_channels << ", " << w.sample_rate << "," << w.bit_depth << ", " << m.info << std::endl;
		
	//}	
	dataFile.close();
}
