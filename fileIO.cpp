#include "fileIO.h"

FileIO::FileIO(std::string file){
	writeCsvFile(file);
}

void FileIO::writeCsvFile(std::string file){

	//std::ofstream dataFile(file);
	
	//dataFile << "Sample Rate" << std::endl; - example how to make column title
	//dataFile.close();
}
