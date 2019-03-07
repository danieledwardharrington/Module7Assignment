#pragma once
#include "checkingAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


class serviceChargeChecking : public checkingAccount
{

protected:
	//properties
	int maxChecks;
	double monthlyFee;

public:
	
	//constructors and destructor
	serviceChargeChecking();
	serviceChargeChecking(int& checks, double& fee, int& number, string& name, double& balance);
	~serviceChargeChecking();

	//getters and setters
	int& getMaxChecks();
	void setMaxChecks(int& maximum);

	double& getMonthlyFee();
	void setMonthlyFee(double& fee);

	//methods
	void depositMoney(double& money) override;
	void withdrawMoney(double& money) override;
	void writeCheck(double& money) override;
	void createStatement() override;
};

