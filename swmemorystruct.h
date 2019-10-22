#ifndef MEMORYSTRUCT_H
#define MEMORYSTRUCT_H

#include <cstdlib>

struct MemoryStruct
{
  char * memory;
  size_t size;
  
  MemoryStruct() 
  : memory((char*)malloc(1)), 
  size(0)
  {

  }
};

#endif /*  MEMORYSTRUCT_H */
