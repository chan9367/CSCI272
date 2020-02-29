#include <iostream>
#include <string>
#include <limits>
#include "Account.h"

using namespace std;


void processDeposit(Account*acct) {
	int depositAmt;
	cout << "\nEnter deposit amount for " << acct->getName() << endl;
	cin >> depositAmt;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "\nEnter a number: ";
		cin >> depositAmt;
	}
	acct->deposit(depositAmt);
}

void processWithdraw(Account*acct) {
	int withdrawAmt;
	cout << "\nEnter withdraw amount for " << acct->getName() << endl;
	cin >> withdrawAmt;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "\nEnter a number: ";
		cin >> withdrawAmt;
	}
	acct->withdraw(withdrawAmt);
}


int main() {

	/*
	Account accountA;

	
	string name;
	cout << "\n set your name: ";
	getline(cin, name);
	accountA.setName(name);
	cout << accountA.getName() << endl;

	Account accountB{"Kay Miller"};
	cout << accountB.getName() << endl;
	

	Account accountC{ "Kacy Hudson", 100 };
	Account accountD{ "Nami Kurosawa", -100 };

	cout << "\nAccount C Name: " << accountC.getName() << endl
		<< "Account C Balance: $" << accountC.getBalance();
	cout << "\nAccount D Name: " << accountD.getName() << endl
		<< "Account D money: $" << accountD.getBalance() <<endl;

	int depositAmount;
	cout << "Deposit how much into account C:";
	cin >> depositAmount;

	accountC.deposit(depositAmount);
	
	
	cout << "\nDeposit how much into account D:";
	cin >> depositAmount;

	accountD.deposit(depositAmount);


	cout << "\nAccount C Name: " << accountC.getName() << endl
		<< "Account C Balance: $" << accountC.getBalance();
	cout << "\nAccount D Name: " << accountD.getName() << endl
		<< "Account D money: $" << accountD.getBalance();
		*/

	Account accountE{ "James Dean", 8000 };

	accountE.accountInfo();

	processDeposit(&accountE);

	accountE.accountInfo();

	processDeposit(&accountE);

	accountE.accountInfo();

	processDeposit(&accountE);



	accountE.accountInfo();

	processWithdraw(&accountE);

	accountE.accountInfo();

	processWithdraw(&accountE);

	accountE.accountInfo();

	processWithdraw(&accountE);



	accountE.accountStatement();

	system("pause");
}

