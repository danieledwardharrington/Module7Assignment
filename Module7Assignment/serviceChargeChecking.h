#pragma once
#include "checkingAccount.h"
class serviceChargeChecking : public checkingAccount
{

protected:
	int maxChecks;

public:
	
	//constructors and destructor
	serviceChargeChecking();
	serviceChargeChecking(int checks, int number, string name, double balance);
	~serviceChargeChecking();

	//getters and setters
	int getMaxChecks();
	void setMaxChecks(int maximum);

	//methods
	void depositMoney(double money) override;
	void withdrawMoney(double money) override;
	void writeCheck(double money) override;
	void createStatement() override;
};

