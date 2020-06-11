#ifndef SWKEYFILE_H_
#define SWKEYFILE_H_

#include <string>
#include <fstream>

class Keyfile
{
  public:
  Keyfile();

  virtual ~Keyfile();

  std::string getKey();

  private:
  std::ifstream keyBuffer;
  std::string key;
};

#endif /* SWKEYFILE_H_ */
