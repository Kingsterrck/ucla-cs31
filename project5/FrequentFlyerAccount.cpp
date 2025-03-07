#include "FrequentFlyerAccount.h"
#include <iostream>
using namespace std;

FrequentFlyerAccount::FrequentFlyerAccount (string name) {
	if (!name.empty()) {
          mName = name;
          mBalance = 0;
	} else {
          throw;
	}
}

double FrequentFlyerAccount::getBalance() {
	return mBalance;
}
string FrequentFlyerAccount::getName() {
	return mName;
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
	if (flight.getName() == mName) {
          mBalance += flight.getMileage();
          return true;
	} else {
          return false;
	}
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
	return (mileage <= mBalance && mileage != 0);
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight) {
	if (canEarnFreeFlight(flight.getMileage())) {
        if (from != to && !from.empty() && !to.empty() && mileage > 0) {
        	flight.setName(mName);
    		flight.setFromCity(from);
            flight.setToCity(to);
            flight.setCost(0);
            flight.setMileage(mileage);
            mBalance -= mileage;
            return true;
        }
	} else {
        return false;
	}
    return false;
}