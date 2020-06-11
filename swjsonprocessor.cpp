#include "swjsonprocessor.h"
#include "swdata.h"
#include <cstdio>


SwJsonProcessor::SwJsonProcessor() : weatherData(new Data)
{
}

SwJsonProcessor::~SwJsonProcessor(){}

void SwJsonProcessor::process(const char *buffer, size_t size)
{
  if(!buffer)
  {

  }
  else
  {
    parsedJson = json_tokener_parse(buffer);
    
    json_object_object_get_ex(parsedJson, "latitude", &latitude);    
    json_object_object_get_ex(parsedJson, "longitude", &longitude);    
    json_object_object_get_ex(parsedJson, "timezone", &timezone);    

    printf("latitude: %f\n", json_object_get_double(latitude));
    printf("latitude: %f\n", json_object_get_double(longitude));
    printf("latitude: %s\n", json_object_get_string(timezone));
    
  }
}
