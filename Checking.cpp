#include "Account.h"
#include "Checking.h"
#include <iostream>


Checking::Checking(std::string name, double start_bal) :
	Account(name, start_bal)
{
	std::cout << "\nChecking constructor called for " << name << "\n";
}

Checking::~Checking() {
	std::cout << "\nChecking destructor called for " << getName() << "\n";
}

bool Checking::has_debit_card() const {
	if (checking_card != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

DebitCard* Checking::get_checking_card() const {
	if (checking_card != nullptr) {
		return checking_card;
	}
	else {
		return nullptr;
	}
}

void Checking::issue_debit_card() {
	checking_card = new DebitCard(getName());
	checking_card->change_pin();
}