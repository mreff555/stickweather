#ifndef JSONPROCESSOR_H
#define JSONPROCESSOR_H

#include <json-c/json.h>

class SwJsonProcessor
{
  public:
  SwJsonProcessor(const char*, size_t);  

  private:
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

