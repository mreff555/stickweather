#ifndef SWDATA_H_
#define SWDATA_H_

#include <string>

// predeclarations for clarity
struct Currently;
struct Minutely;
struct Hourly;
struct Daily;
struct Alerts;
struct Flags;

struct Data
{
  float latitude;
  float longitude;
  std::string timezone;
  struct Currently;
  struct Minutely;
  struct Hourly;
  struct Daily;
  struct Alerts;
  struct Flags;
};

struct Currently
{
  size_t time;
  std::string summary;
  std::string icon;
  unsigned nearestStormDistance;
  float precipIntensity;
  /* ...  */
  float temperature;
  float appearentTemperature;
  float dewPoint;
  float humidity;
  float windSpeed;
  float windGust;
  float windBearing;
  float cloudCover;
  unsigned uvIndex;
  float visibility;
  float ozone;
};

#endif /* SWDATA_H_ */
