#pragma once
#include "bankAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


class certificateOfDeposit : public bankAccount
{
//properties
protected:
	int maturityMonths;
	double interestRate;
	int currentCDMonth;

	vector<double> withdrawals;
	vector<double> deposits;
	vector<double> penalties;

//methods
public:
	//constructors and destructor
	certificateOfDeposit();
	certificateOfDeposit(int& matMonths, double& rate, int& curMonth, int& number, string& name, double& balance);
	~certificateOfDeposit();

	//getters and setters
	int& getMaturityMonths();
	void setMaturityMonths(int& months);

	double& getInterestRate();
	void setInterestRate(double& rate);

	int& getCurrentCDMonth();
	void setCurrentCDMonth(int& month);

	//methods
	void depositMoney(double& money) override;
	void withdrawMoney(double& money) override;
	void createStatement() override;

};

