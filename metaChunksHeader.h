//CS 202 Semester Project - PT 19

#ifndef METACHUNKS_H
#define METACHUNKS_H
#include <vector>

    /**
     * Struct to contain metadata info management
     */  

typedef struct meta_header {
    //Not needed for actual data. Just for finding the metadata
    char list[4]; //LIST
    int chunkSize; //Chunk Size
    char info[4]; //INFO

  
} meta_header;

#endif //LISTHEADER_H
