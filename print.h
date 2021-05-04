//CS 202 Semester Project - PT 19

#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>
#include "wav.h"
#include "processor.h"
#include "normalization.h"
#include "noiseGate.h"
#include "echo.h"

/**
 * This is the Print class.
 */

class Print{
	const std::string testfile = "yes-8-bit-stereo.wav";
	const std::string normalizedfile = "yes-8bit-mono-normalized.wav";
	const std::string echofile = "yes-8bit-mono-echo.wav";
	const std::string gateFile = "yes-8-bit-stereo-gated.wav";
	
public:

	/**
	 * User Interaction - prompts if user wants to modify a file's metadata and calls function to do so
	 */
 	void modifyPrinter();

	/**
	 * User Interaction - prompts user for processing that they want done and calls functions to do so
	 */
	void processingPrinter();

	/**
	 * User Interaction - prompts user for  if they want an CSV file exported containing all the technical 
	 * info and metadata of all the files filtered through and if so, calls the function to do so
	 */
 	void csvFilePrinter();
};

#endif
