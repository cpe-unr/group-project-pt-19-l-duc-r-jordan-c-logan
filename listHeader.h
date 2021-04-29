//CS 202 Semester Project - PT 19

#ifndef LISTHEADER_H
#define LISTHEADER_H
#include <vector>
#include "list.h"

typedef struct list_header {
    char list[4]; //LIST
    int chunkSize; //Chunk Size
    char info[4]; //INFO
    
    std::vector<list> subChunks; 
    
} list_header;

#endif //LISTHEADER_H
