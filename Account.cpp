#include <string>
#include <iostream>
#include "Account.h"


	Account::Account(std::string accountName)
		:name{ accountName }
	{}

	Account::Account(std::string accountName, int startingBalance)
		:name{ accountName }
	{
		if (startingBalance > 0) {
			balance = startingBalance;
		}
	}

	Account::Account() {}

	void Account::setName(std::string accountName) {
		name = accountName;
	}

	std::string Account::getName() const { return name; }

	void Account::deposit(int depositAmount) {
		if (depositAmount > 0) {
			balance += depositAmount;
			addTransaction(depositAmount);
		}
	}
	void Account::withdraw(int withdrawAmount) {
		if (withdrawAmount <= balance) {
			balance -= withdrawAmount;
			addTransaction(withdrawAmount*-1);
		}
		else {
			std::cout << "\nWithdrawal amount is greater than the balance" << std::endl;
		}
	}

	int Account::getBalance() const { return balance; }

	void Account::accountInfo() const {
		std::cout << "\nAccount Name: " << getName() << "\t" << "Account Balance: " << getBalance() << std::endl;
	}

	void Account::addTransaction(int Transaction) {
		transactions.push_back(Transaction);
	}

	void Account::accountStatement() {
		std::cout << "\nAccount Name: " << getName() << std::endl
					<< "\nAccount Statement: " << std::endl;
		for (int i = 0; i < transactions.size(); i++) { 
			std::cout << transactions[i] << "\t"; 
			if(transactions[i]>0)std::cout <<"Depositted" << std::endl; 
			else if (transactions[i]<0)std::cout << "Withdrawn" << std::endl;
		}
	}