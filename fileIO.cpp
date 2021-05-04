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

	std::ofstream dataFile(file);
	
	dataFile << "Filename, Format Header, Num Channels, Sample Rate, Bit Size";

	for (std::string x : w.getSubChunk()){
	    dataFile << ", " << x;
	}
	dataFile << "\n";

	dataFile << p1.getFile() << ", " << w.getFmtHeader() << ", " << w.getNumChannels() << ", " << w.getSampleRate() << "," << w.getBitDepth();

	for (std::string s : w.getActualData()){
	   dataFile << ", " << s;
	}
	dataFile << "\n";
	
	dataFile << p1.getFileTwo() << ", " << w2.getFmtHeader() << ", " << w2.getNumChannels() << ", " << w2.getSampleRate() << "," << w2.getBitDepth();

	for (std::string s : w2.getActualData()){
	   dataFile << ", " << s;
	}
	dataFile << "\n";

	dataFile << p1.getFileThree() << ", " << w3.getFmtHeader() << ", " << w3.getNumChannels() << ", " << w3.getSampleRate() << "," << w3.getBitDepth();

	for (std::string s : w3.getActualData()){
	   dataFile << ", " << s;
	}
	dataFile << "\n";

	dataFile << p1.getFileFour() << ", " << w4.getFmtHeader() << ", " << w4.getNumChannels() << ", " << w4.getSampleRate() << "," << w4.getBitDepth();


	for (std::string s : w4.getActualData()){
	   dataFile << ", " << s;
	}

	dataFile.close();
}
