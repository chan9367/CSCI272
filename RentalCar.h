#include "Car.h"
#include "Rental.h"

class RentalCar : public Car, public Rental {

public:
	RentalCar() {};
	RentalCar(std::string, std::string, std::string, unsigned int, std::string, std::string);
	std::string get_agency() const;
	std::string get_location() const;
	std::string get_license() const;
	void print_renter_summary();

private:
	std::string agency;
	std::string location;
	std::string license;

};


#pragma once
