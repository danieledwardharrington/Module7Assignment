#pragma once

#include <string>
#include <iostream>

using namespace std;

class bankAccount
{
//properties
protected:
	int accountNumber;
	string holderName;
	double accountBalance;
	
//methods
protected:
	//making these protected so user can't create these objects directly
	//constructor and destructor
	bankAccount();
	virtual ~bankAccount();

public:
	//getters and setters
	void setAccountNumber(int number);
	int getAccountNumber();

	void setHolderName(string name);
	string getHolderName();

	void setAccountBalance(double balance);
	double getAccountBalance();

	//virtual functions
	virtual void depositMoney(double money) = 0;
	virtual void withdrawMoney(double money) = 0;
	virtual void createStatement() = 0;

}; //bankAccount class

