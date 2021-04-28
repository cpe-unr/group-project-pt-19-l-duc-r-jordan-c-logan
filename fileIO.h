#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include <string>
#include "waveHeader.h"
#include "wav.h"
#include "print.h"

class FileIO{
public:
	//methods to make CSV file should be implemented in this class
	FileIO(std::string file);
	void writeCsvFile(std::string file);
};

#endif
