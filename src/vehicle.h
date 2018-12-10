#ifndef VEHICLE
#define VEHICLE

#include <vector>
#include <map>
#include <string>

using namespace std;

class Vehicle
{
public:
  double x;
  double y;
  double s;
  double d;
  double speed;
  double future_s;
  int lane;
  
  Vehicle();
  Vehicle(double x, double y, double s, double d, double speed, double future_s, int lane);
  
  virtual ~Vehicle();
};

#endif