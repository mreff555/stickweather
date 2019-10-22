 #ifndef SWCOORDINATES_H
 #define SWCOORDINATES_H

#include <string>

class SwCoordinates
{
  public:
  SwCoordinates(const float&, const float&);

  virtual ~SwCoordinates();

  void setCoordinates(const float&, const float&);

  std::string getCoordinateString();

  bool isValid();

  private:
  float latitude;

  float longitude;

  bool valid;
};

#endif /* SWCOORDINATES_H */
