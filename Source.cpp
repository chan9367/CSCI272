#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include <iostream>

using namespace std;

int main() {

	Savings savingsA{ "John Doe", 400, .05 };

	savingsA.accountInfo();

	cout << "Interest rate: " << savingsA.get_interest_rate() << "\n";

	savingsA.set_interest_rate(25);
	cout << savingsA.get_interest_rate() << "\n";

	double y;
	y = savingsA.calculate_interest();
	cout << "$" << y << " is the interest rate for " << savingsA.getName() << endl;

	Checking checkingB{ "Jane Doe", 345.60 };
	if (checkingB.has_debit_card()) {
		cout << checkingB.getName() << " does not have a card.\n";
	}
	else {
		cout << checkingB.getName() << " has a card.\n";
	}

	checkingB.accountInfo();

	checkingB.get_checking_card();

	checkingB.issue_debit_card();
}

