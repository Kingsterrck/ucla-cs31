#include "PlaneFlight.h"
#include <iostream>
using namespace std;

// constructor
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
	setName(passengerName);
	if (fromCity == toCity) {
		mFromCity = "";
		mToCity = "";
	} else {
		setFromCity(fromCity);
		setToCity(toCity);
	}

	setCost(cost);
	setMileage(mileage);
}

// accessors
string PlaneFlight::getName() {
	return mName;
}
string PlaneFlight::getFromCity() {
	return mFromCity;
}
string PlaneFlight::getToCity() {
	return mToCity;
}
double PlaneFlight::getCost() {
	return mCost;
}
double PlaneFlight::getMileage() {
	return mMileage;
}

// Mutators
void PlaneFlight::setName(string name) {
	if (!name.empty()) {
		mName = name;
	}
}

void PlaneFlight::setFromCity(string fromCity) {
	if (!fromCity.empty() && fromCity != mToCity) {
		mFromCity = fromCity;
	}
}

void PlaneFlight::setToCity(string toCity) {
	if (!toCity.empty() && toCity != mFromCity) {
		mToCity = toCity;
	}
}

void PlaneFlight::setCost(double cost) {
	if (cost >= 0) {
		mCost = cost;
	} else {
		mCost = -1;
	}
}

void PlaneFlight::setMileage(double mileage) {
	if (mileage > 0) {
		mMileage = mileage;
	} else {
		mMileage = -1;
	}
}
