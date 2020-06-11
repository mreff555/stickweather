#ifndef JSONPROCESSOR_H
#define JSONPROCESSOR_H
#include "swdata.h"
#include <json-c/json.h>

class SwJsonProcessor
{
  public:
  SwJsonProcessor();  

  virtual ~SwJsonProcessor();
  
  void process(const char*, size_t);  

  private:
  // TODO: get rid of all these JSON objects.  put them in the data
  // and figure out how to pair them or easily translate them.
  Data *weatherData;

  struct json_object *parsedJson;
  
  struct json_object *latitude;
  struct json_object *longitude;
  struct json_object *timezone;
  struct json_object *currently;
  struct json_object *minutely;
  struct json_object *hourly;
  struct json_object *daily;
  struct json_object *flags;
  struct json_object *offset;
};

#endif /* JSONPROCESSOR_H */

