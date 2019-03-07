#pragma once
#include "bankAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


class savingsAccount : public bankAccount
{
protected:

	//properties
	double interestRate;
	vector<double> deposits;
	vector<double> withdrawals;

public:

	//constructors and destructor
	savingsAccount();
	savingsAccount(double& rate, int& number, string& name, double& balance);
	~savingsAccount();

	//getters and setters
	double& getInterestRate();
	void setInterestRate(double& rate);

	//methods
	void depositMoney(double& money) override;
	void withdrawMoney(double& money) override;
	void createStatement() override;
};

