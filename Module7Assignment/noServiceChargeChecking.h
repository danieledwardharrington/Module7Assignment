#pragma once
#include "checkingAccount.h"
class noServiceChargeChecking : public checkingAccount
{

protected:
	//properties
	double interestRate;
	double minBalance;

public:
	
	//constructors and destructor
	noServiceChargeChecking();
	noServiceChargeChecking(double rate, double minimum, int number, string name, double balance);
	~noServiceChargeChecking();

	//getters and setters
	double getInterestRate();
	void setInterestRate(double rate);

	double getMinBalance();
	void setMinBalance(double minimum);

	//methods
	void depositMoney(double money) override;
	void withdrawMoney(double money) override;
	void writeCheck(double money) override;
	void createStatement() override;
};

