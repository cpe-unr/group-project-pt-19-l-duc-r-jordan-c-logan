#include "fileIO.h"

FileIO::FileIO(std::string file){
	writeCsvFile(file);
}

void FileIO::writeCsvFile(std::string file){

	std::ofstream dataFile(file);
	
	//Columns showing what data layout is
	dataFile << "Filename, Chunk Size, Num Channels, Sample Rate, Bit Size, MetaData " << std::endl;

	//for(int i = 0; i < bufferSize; i++){
		//dataFile << file << ", " << fmt_chunk_size << ", " << num_channels << ", " << sample_rate << "," << bit_depth << ", " << METADATA << std::endl;
		
	//}	
	dataFile.close();
}
