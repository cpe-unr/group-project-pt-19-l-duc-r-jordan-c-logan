//CS 202 Semester Project - PT 19

#ifndef SUBCHUNKS_H
#define SUBCHUNKS_H

	/**
	 * Struct to contain subchunk and subchunk size from audio files
	 */
typedef struct sub_chunk {
	/**
	* sub chunk
	*/
    char subChunk[4]; //Sub chunk
    /**
    * size of chunk
    */
    int subChunkSize; //Size
    
    
} list;

#endif //SUBCHUNKS_H 
