#include "RentalCar.h"
#include <iostream>


RentalCar::RentalCar(std::string ag, std::string loc, std::string model, unsigned int days, std::string renter, std::string lic) :
	agency{ ag }, location{ loc }, Rental(renter, days), Car{ model }, license{lic}

{
	std::cout << "\nEnter license number: ";
	std::cin >> license; //Lab 8
	std::cout << "\nRental Car created for " << agency << " at " << location <<std::endl;

}


std::string RentalCar::get_agency() const { return agency; }
std::string RentalCar::get_location() const { return location; }

//Lab 8

std::string RentalCar::get_license() const { return license; }

void RentalCar::print_renter_summary(){
	std::cout << "\nAgency: " << agency
		<< "\nLocation: " << location
		<< "\nContract Number: " << Rental::get_contract_number()
		<< "\nRenter Name and Driver's License: " << Rental::get_renter_name() << " " << license
		<< "\nCar Model and Starting Mileage: " << Car::getModel() << " " << Car::getMileage()
		<< "\nRental Length: " << Rental::get_rental_length() <<"\n";

}