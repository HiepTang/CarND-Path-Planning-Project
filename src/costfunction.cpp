#include "vehicle.h"

#include <fstream>
#include <iostream>
#include <math.h>

double effectiveCost(double car_s, double car_d, double car_speed, vector<Vehicle> lane_vehicles)
{
  Vehicle nearest_front_vehicle;
  bool has_front_vehicle = false;
  for(int i = 0; i < lane_vehicles.size(); i++)
  {
    Vehicle check_vehicle = lane_vehicles[i];
    if(check_vehicle.s > car_s)
    {
      if(has_front_vehicle)
      {
        if(check_vehicle.s < nearest_front_vehicle.s)
        {
          nearest_front_vehicle = check_vehicle;
        }
      }
      else
      {
        nearest_front_vehicle = check_vehicle;
        has_front_vehicle = true;
      }
    }
  }
  // Has front vehicle now - calculate the cost based on the speed
  // If the front car's speed moves faster, the cost is smaller
  if(has_front_vehicle)
  {
    if(nearest_front_vehicle.speed < 5.0)
    {
      return 1.0;
    }
    else{
      return (double)3.00/nearest_front_vehicle.speed;
    }
    
  }
  else
  {
    return (double)0.0; // No front car, the cost is 0
  }
}

double collisionCost(double car_s, double car_d, double car_speed, vector<Vehicle> lane_vehicles)
{
  Vehicle nearest_front_vehicle;
  bool has_front_vehicle = false;
  Vehicle nearest_after_vehicle;
  bool has_after_vehicle = false;
  int car_lane = (int)floor(car_d/4);
  for(int i = 0; i < lane_vehicles.size(); i++)
  {
    Vehicle check_vehicle = lane_vehicles[i];
    if(check_vehicle.s > car_s)
    {
      if(has_front_vehicle)
      {
        if(check_vehicle.s < nearest_front_vehicle.s)
        {
          nearest_front_vehicle = check_vehicle;
        }
      }
      else
      {
        nearest_front_vehicle = check_vehicle;
        has_front_vehicle = true;
      }
    }
    else
    {
      if(has_after_vehicle)
      {
        if(check_vehicle.s >= nearest_after_vehicle.s)
        {
          nearest_after_vehicle = check_vehicle;
        }
      }
      else
      {
        nearest_after_vehicle = check_vehicle;
        has_after_vehicle = true;
      }
    }
  }
  double cost = 0.0;
  
  if(has_front_vehicle && ((nearest_front_vehicle.s - car_s) <= 30))
  {
    if((nearest_front_vehicle.s - car_s) < 20)
    {
      cost += 0.5;
    }
    else
    {
      cost += (10/(nearest_front_vehicle.s - car_s));
      
    }
  }
  // Don't add cost for the following car if it is the same lane of car
  if(has_after_vehicle && (car_lane != nearest_after_vehicle.lane) && ((car_s - nearest_after_vehicle.s) <= 30))
  {
    if((car_s - nearest_after_vehicle.s) < 20)
    {
      cost += 0.5;
    }
    else
    {
      cost += (10/(car_s - nearest_after_vehicle.s));
    }
  }
  return cost;
}

double calculateCost(double car_s, double car_d, double car_speed, vector<Vehicle> lane_vehicles)
{
  return (effectiveCost(car_s, car_d, car_speed, lane_vehicles) + collisionCost(car_s, car_d, car_speed, lane_vehicles));
}