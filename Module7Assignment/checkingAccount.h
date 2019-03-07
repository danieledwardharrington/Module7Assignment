#pragma once
#include "bankAccount.h"
class checkingAccount : public bankAccount
{

protected:
	vector<double> checks;
	vector<double> deposits;
	vector<double> withdrawals;

protected:

	//constructors and destructor
	//making this class abstract
	checkingAccount();
	~checkingAccount();

public:

	//methods
	virtual void writeCheck(double& money) = 0;
};

