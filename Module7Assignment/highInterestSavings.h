#pragma once
#include "savingsAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


class highInterestSavings : public savingsAccount
{

public:

	//constructors and destructor
	highInterestSavings();
	highInterestSavings(double& minimum, double& rate, int& number, string& name, double& balance);
	~highInterestSavings();

	//getters and setters
	double& getMinBalance();
	void setMinBalance(double& minimum);

	//methods
	void depositMoney(double& money) override;
	void withdrawMoney(double& money) override;
	void createStatement() override;
};

