#pragma once
#include "savingsAccount.h"
class highInterestSavings : public savingsAccount
{
protected:
	//properties
	double minBalance;

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

