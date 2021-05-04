#include "fileIO.h"
#include "waveHeader.h"
#include "Metachunks.h"
#include "wav.h"
#include "print.h"

FileIO::FileIO() {};

void FileIO::writeCsvFile(std::string file, int bufferSize){
	
	Wav wav;
	Wav wav2;
	Print p1;
	wav.readFile(p1.getFile());
	wav2.readFile(p1.getFileTwo());
	meta_header m;

	std::ofstream dataFile(file);
	
	//Columns showing what data layout is
	dataFile << "Filename, Chunk Size, Num Channels, Sample Rate, Bit Size, MetaData " << std::endl;

	dataFile << file << ", " << wav.getFmtHeader() << ", " << wav.getNumChannels() << ", " << wav.getSampleRate() << "," << wav.getBitDepth() << ", " << m.info << std::endl;
	
	dataFile << file << ", " << wav2.getFmtHeader() << ", " << wav2.getNumChannels() << ", " << wav2.getSampleRate() << "," << wav2.getBitDepth() << ", " << m.info << std::endl;
	dataFile.close();
}
