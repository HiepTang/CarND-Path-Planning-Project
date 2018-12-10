#ifndef COSTFUNCTION_H
#define COSTFUNCTION_H

#include <vector>
#include <map>
#include <string>

using namespace std;

double calculateCost(double car_s, double car_d, double car_speed, vector<Vehicle> lane_vehicles);
double collisionCost(double car_s, double car_d, double car_speed, vector<Vehicle> lane_vehicles);
double effectiveCost(double car_s, double car_d, double car_speed, vector<Vehicle> lane_vehicles);

#endif