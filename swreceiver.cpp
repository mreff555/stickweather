#include "swreceiver.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <curl/curl.h>

SwReceiver* SwReceiver::instance;

SwReceiver *SwReceiver::getInstance(
  std::string &address, 
  std::string &key, 
  std::string &options)
{
  if(!instance)
  {
    instance = new SwReceiver(address, key, options);
    return instance;
  }  
}

SwReceiver::SwReceiver(
  std::string &address, 
  std::string &key, 
  std::string &options)
{
  curl_global_init(CURL_GLOBAL_ALL);
  data = curl_easy_init();
  if(data)
  { 
    std::string addrstr = address + '/' + key + '/' + options;
    // std::cout << "Address = " << addrstr << std::endl;
    curl_easy_setopt(data, CURLOPT_URL, addrstr.c_str());  
    curl_easy_setopt(data, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(data, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_setopt(data, CURLOPT_ERRORBUFFER, errorBuffer);
    curl_easy_setopt(data, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
    memset(errorBuffer, 0, sizeof(CURL_ERROR_SIZE));
  }
  else
  {
    // TODO add to error buffer
  }
}

SwReceiver::~SwReceiver()
{
  curl_easy_cleanup(data);
  delete(instance);
  instance = 0;
}

bool SwReceiver::runQuery()
{
  bool returnValue = false;
  result = curl_easy_perform(data);
  if(result != CURLE_OK)
  {
    size_t len = strlen(errorBuffer);
    fprintf(stderr, "\nlibcurl: (%d) ", result); 
    if(len)
    {
      fprintf(stderr, "%s%s", errorBuffer, 
        ((errorBuffer[len - 1] != '\n') ? "\n" : ""));
    }
    else
    {
      fprintf(stderr, "%s\n", curl_easy_strerror(result));
    }
    // returnValue = true;  // Force value to see what is going on
  }
  else
  {
    returnValue = true;
  }
}

MemoryStruct *SwReceiver::getData()
{
  return &chunk;
}

size_t SwReceiver::writeMemoryCallback(
  void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realSize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  char *ptr = (char*)realloc(mem->memory, mem->size + realSize + 1);
  if(ptr == NULL)
  {
    //TODO This should write to the error buffer
    std::cout << "Not enought memory!\n";
    return 0;
  }
  
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realSize);
  mem->size += realSize;
  mem->memory[mem->size] = 0;  
  return realSize;
}
