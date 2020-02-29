#include "RentalCar.h"
#include <iostream>
#include <string>
using namespace std;


int main() {

	// agency, location, model, length, renter name
	string agency = "ABC Rentals";
	string location = "Airport";
	string model = "Ford";
	unsigned int days = 8;
	string renter = "Joe";
	string license;

	RentalCar carA{ agency, location, model, days, renter, license };

	cout << carA.getMileage() << "\n";
	cout << carA.get_renter_name() << "\n";
	cout << carA.get_agency() << "\n";
	cout << carA.get_license() << "\n";

	carA.print_renter_summary();

	system("pause");
}