#include <string>
#include <vector>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

public:

	Account(std::string accountName);
	Account(std::string accountName, int startingBalance);
	Account();
	void setName(std::string accountName);
	std::string getName() const;
	void deposit(int depositAmount);
	void withdraw(int withdrawAmount);
	int getBalance() const;
	void accountInfo() const;
	void accountStatement();

private:

	std::string name;
	int balance{ 0 };
	std::vector <int> transactions;
	void addTransaction(int);
};

#endif