#include "swcoordinates.h"
#include "swreceiver.h"
#include "swdefinitions.h"
#include "swjsonprocessor.h"
#include <iostream>

int main()
{
  SwCoordinates coordinates(39.456, -79.234);
  std::string a(TESTADDRESS);
  std::string b(TESTKEY);
  std::string c;
  if(coordinates.isValid())
  {
    c = coordinates.getCoordinateString();
  }
  else
  {
    c = TESTOPTIONS;
  }
  std::cout << c <<std::endl;
  SwReceiver* rec = SwReceiver::getInstance(a,b,c);
  struct MemoryStruct *mem = rec->getData();
  SwJsonProcessor(mem->memory, mem->size);  
}

