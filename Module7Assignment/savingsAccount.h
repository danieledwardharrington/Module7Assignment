#pragma once
#include "bankAccount.h"
class savingsAccount : public bankAccount
{

public:

	//constructors and destructor
	savingsAccount();
	savingsAccount(double rate, int number, string name, double balance);
	~savingsAccount();

	//getters and setters
	double getInterestRate();
	void setInterestRate(double rate);

	//methods
	void depositMoney(double money) override;
	void withdrawMoney(double money) override;
	void createStatement() override;
};

