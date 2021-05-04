#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include <string>
#include "wav.h"
#include "print.h"

/**
 * This is the FileIO class.
 */

class FileIO{
public:
	/**
	 * FileIO constructor
	 */
	FileIO();
	//void loadFile(std::string file);

	/**
	 * Writes the CSV file containing all the tech. info and metadata of the wav files
	 * @param file - name of file, in a string
	 * @param bufferSize - size of wav files buffer array, in integers
	 */
	void writeCsvFile(std::string file, int bufferSize);
};

#endif
