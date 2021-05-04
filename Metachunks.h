//CS 202 Semester Project - PT 19

#ifndef METACHUNKS_H
#define METACHUNKS_H
#include <vector>
#include "Subchunks.h"

    /**
     * Struct to contain metadata info management
     */

typedef struct meta_header {

	/**
	* list
	*/

    char list[4]; //LIST
    /**
    *chunk size
    */
    int chunkSize; //Chunk Size
    /**
    * info
    */
    char info[4]; //INFO

    /**
    *vector subchunks
    */
    
    std::vector<sub_chunk> subChunks; 
    
} meta_header;

#endif //LISTHEADER_H
