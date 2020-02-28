#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

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

	cout << "\nAccount Balance for James Dean: $" << accountE.getBalance() <<endl;
	accountE.withdraw(9999);
	cout << "\nAccount Balance for James Dean: $" << accountE.getBalance() << endl;
	accountE.withdraw(7000);
	cout << "\nAccount Balance for James Dean: $" << accountE.getBalance() << endl;
	accountE.withdraw(1000);
	cout << "\nAccount Balance for James Dean: $" << accountE.getBalance() << endl;

	accountE.accountInfo();

	system("pause");
}

