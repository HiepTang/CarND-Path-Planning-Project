#include "vehicle.h"

#include <fstream>
#include <iostream>
#include <math.h>

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(double x, double y, double s, double d, double speed, double future_s, int lane)
{
  this -> x = x;
  this -> y = y;
  this -> s = s;
  this -> d = d;
  this -> speed = speed;
  this -> future_s = future_s;
  this -> lane = lane;
}

Vehicle::~Vehicle() {}