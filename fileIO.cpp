#include "fileIO.h"
#include "waveHeader.h"
#include "Metachunks.h"
#include "wav.h"
#include "print.h"

FileIO::FileIO() {};

void FileIO::writeCsvFile(std::string file, int bufferSize){

	meta_header m;

	std::ofstream dataFile(file);
	
	//Columns showing what data layout is
	dataFile << "Filename, Chunk Size, Num Channels, Sample Rate, Bit Size, MetaData " << std::endl;

	//dataFile << file << ", " << wav.getFmtHeader() << ", " << wav.getNumChannels() << ", " << wav.getSampleRate() << "," << wav.getBitDepth() << ", " << m.info << std::endl;
	
	dataFile.close();
}
