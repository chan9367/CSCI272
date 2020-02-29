#include "Account.h"
#include "Savings.h"
#include <string>
#include <iostream>

Savings::Savings(std::string name, double start_bal, double start_rate) :
	Account(name, start_bal)
{
	if (start_rate > 0 && start_rate < 1) {
		interest_rate = start_rate;
	}
	std::cout << "\nSavings constructor called for " << name << "\n";
}

Savings::~Savings() {
	std::cout << "\nSavings destructor called for " << getName() << "\n";
}

double Savings::get_interest_rate() const {
	return interest_rate;
}

void Savings::set_interest_rate(double start_rate) {
	if (start_rate > 0 && start_rate < 1) {
		interest_rate = start_rate;
	}
}

double Savings::calculate_interest() const {
	double x = getBalance();
	return x*interest_rate;

}