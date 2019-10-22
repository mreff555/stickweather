#ifndef SWRECEIVER_H
#define SWRECEIVER_H

#include "swmemorystruct.h"
#include <curl/curl.h>
#include <string>

class SwReceiver
{
  public:
  static SwReceiver *getInstance(
    std::string&, 
    std::string&, 
    std::string&);

  virtual ~SwReceiver();

  bool runQuery();

  struct MemoryStruct *getData();

  private:
  
  SwReceiver(
    std::string&, 
    std::string&, 
    std::string&);

  static size_t writeMemoryCallback(
    void *contents, size_t size, size_t nmemb, void *userp);

  static SwReceiver* instance;
  CURL *data;
  char errorBuffer[CURL_ERROR_SIZE];
  CURLcode result;
  struct MemoryStruct chunk;
  const std::string address;
  const std::string key;
  const std::string options;

};

#endif /* SWRECEIVER_H */
