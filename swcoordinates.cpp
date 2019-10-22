#include "swcoordinates.h"
#include <iostream>

SwCoordinates::SwCoordinates(const float &lat, const float &lon) 
: latitude(0), 
longitude(0), 
valid(0)
{
  setCoordinates(lat, lon);
}

SwCoordinates::~SwCoordinates()
{

}

void SwCoordinates::setCoordinates(const float &lat, const float &lon)
{
  if(lat >= -90 && lon >= -90 && lat <= 90 && lon <= 90)
  {
    this->latitude = lat;
    this->longitude = lon;
    this->valid = true;
  }
}

std::string SwCoordinates::getCoordinateString()
{
  std::string lat, lon;
  lat = std::to_string(latitude);
  lon = std::to_string(longitude);
  return(lat + ',' + lon);
}

bool SwCoordinates::isValid()
{
  return valid;
}
