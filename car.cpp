#include <iostream>
#include "car.h"

// define custom constructor


    Car::Car(double mpg, double fuelCapacity){}


// define get information functions

    double Car::getMileage() const{return mileage;}
    double Car::getAvailableFuel() const{return availableFuel;}
    double Car::getFuelCapacity() const{return fuelCapacity;}





// define change information functions
	bool Car::drive(double miles) { if (miles/availableFuel > mpg) { return false; } 
									else { addMiles(miles); useFuel(miles); return true; } }
    void Car::refuel(){availableFuel=fuelCapacity;}


// define private helper functions
	void Car::addMiles(double miles) { mileage+=miles; }
	void Car::useFuel(double miles) { availableFuel-=miles/mpg; }
