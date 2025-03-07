#ifndef PLANEFLIGHT_H
#define PLANEFLIGHT_H

#include <iostream>
using namespace std;

class PlaneFlight {
private:
	double mCost;
	string mFromCity;
	string mToCity;
	string mName;
	double mMileage;

public:
	PlaneFlight (string passengerName, string fromCity, string toCity, double cost, double mileage);

	string getName();
	string getFromCity();
	string getToCity();
	double getCost();
	double getMileage();

	void setName(string name);
	void setFromCity(string fromCity);
	void setToCity(string toCity);
	void setCost(double cost);
	void setMileage(double mileage);

};

#endif
