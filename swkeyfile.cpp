#include "swkeyfile.h"
#include "swdefinitions.h"
#include <iostream>

Keyfile::Keyfile()
{
  keyBuffer.open(DEFAULT_KEYFILE_NAME);
  if(!keyBuffer.is_open())
  {
    std::cout << "unable to open keyfile.\n";
  }
  else
  {
    std::getline(keyBuffer, key);
  }
  keyBuffer.close();
}

Keyfile::~Keyfile()
{

}

std::string Keyfile::getKey()
{
  return key;
}
