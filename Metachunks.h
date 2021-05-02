//CS 202 Semester Project - PT 19

#ifndef METACHUNKS_H
#define METACHUNKS_H
#include <vector>
#include "Subchunks.h"

typedef struct meta_header {
    char list[4]; //LIST
    int chunkSize; //Chunk Size
    char info[4]; //INFO
    
    std::vector<sub_chunk> subChunks; 
    
} meta_header;

#endif //LISTHEADER_H
