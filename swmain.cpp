#include "swcoordinates.h"
#include "swreceiver.h"
#include "swdefinitions.h"
#include "swjsonprocessor.h"
#include "swkeyfile.h"
#include <iostream>

int main()
{
  std::string webAddress(DEFAULT_ADDRESS);

  Keyfile keyfile;
  std::cout << "key: " << keyfile.getKey() << std::endl;
  std::string key(keyfile.getKey());

  SwCoordinates coordinates(36.456, -79.234);
  std::string coords;
  if(coordinates.isValid())
  {
    coords = coordinates.getCoordinateString();
  }
  else
  {
    coords = TESTOPTIONS;
  }
  SwReceiver* rec = SwReceiver::getInstance(
    webAddress,
    key,
    coords);

  rec->runQuery();
  struct MemoryStruct *mem = rec->getData();
  SwJsonProcessor jProc;
  jProc.process(mem->memory, mem->size);  
}

