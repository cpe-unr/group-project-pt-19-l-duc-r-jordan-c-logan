#include "fileIO.h"
#include "waveHeader.h"
#include "Metachunks.h"
#include "wav.h"
#include "print.h"

FileIO::FileIO() {};

void FileIO::writeCsvFile(std::string file, int bufferSize){
	
	Wav w;
	Wav w2;
	Wav w3;
	Wav w4;
	Print p1;
	w.readFile(p1.getFile());
	w2.readFile(p1.getFileTwo());
	w3.readFile(p1.getFileThree());
	w4.readFile(p1.getFileFour());
	meta_header m;

	std::ofstream dataFile(file);
	
	//Columns showing what data layout is
	dataFile << "Filename, Chunk Size, Num Channels, Sample Rate, Bit Size, MetaData " << std::endl;

	dataFile << p1.getFile() << ", " << w.getFmtHeader() << ", " << w.getNumChannels() << ", " << w.getSampleRate() << "," << w.getBitDepth() << ", " << m.info << std::endl;
	
	dataFile << p1.getFileTwo() << ", " << w2.getFmtHeader() << ", " << w2.getNumChannels() << ", " << w2.getSampleRate() << "," << w2.getBitDepth() << ", " << m.info << std::endl;

	dataFile << p1.getFileThree() << ", " << w3.getFmtHeader() << ", " << w3.getNumChannels() << ", " << w3.getSampleRate() << "," << w3.getBitDepth() << ", " << m.info << std::endl;

	dataFile << p1.getFileFour() << ", " << w4.getFmtHeader() << ", " << w4.getNumChannels() << ", " << w4.getSampleRate() << "," << w4.getBitDepth() << ", " << m.info << std::endl;

	dataFile.close();
}
