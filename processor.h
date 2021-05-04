//CS 202 Semester Project - PT 19

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>
#include <cmath>

/**
 * This is the templated processor interface/abstract class.
 */

template<typename T>
class Processor{
public:
	
	/**
	 * Abstract class/interface which allows processors to inherit and override to manipulate wav file buffers
	 * @param buffer - array holding audio buffer, in Templated type T data type
	 * @param bufferSize - size of wav files buffer, in integers
	 * @param bitdepth - bit size of wav file, in short integers
	 */ 
    virtual void processBuffer(T* buffer, int bufferSize, short bitdepth) = 0;

};

#endif //PROCESSOR_H
