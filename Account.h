#include <string>

class Account {

public:

	Account(std::string accountName)
		:name{ accountName }
	{}

	Account(std::string accountName, int startingBalance)
		:name{accountName}
	{
		if (startingBalance > 0) { 
			balance = startingBalance;
		}
	}

	Account() {}

	void setName(std::string accountName) { 
		name = accountName;
	}

	std::string getName() const { return name;}

	void deposit(int depositAmount) {
		if (depositAmount > 0) { 
			balance += depositAmount;
		}
	}
	void withdraw(int withdrawAmount) {
		if (withdrawAmount <= balance) {
			balance -= withdrawAmount;
		}
		else {std::cout << "\nWithdrawal amount is greater than the balance" << std::endl;
	}
	}

	int getBalance() const { return balance; }
	
	void accountInfo() {
		std::cout << "\nAccount Name: " << getName() << "\t" << "Account Balance: " << getBalance() <<std::endl;
	}

private:
	std::string name;
	int balance{ 0 };

};
