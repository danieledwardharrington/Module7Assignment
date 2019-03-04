#pragma once
#include "bankAccount.h"
class certificateOfDeposit : public bankAccount
{
//properties
protected:
	int maturityMonths;
	double interestRate;
	int currentCDMonth;

//methods
public:
	//constructors and destructor
	certificateOfDeposit();
	certificateOfDeposit(int matMonths, double rate, int curMonth, int number, string name, double balance);
	~certificateOfDeposit();

	//getters and setters
	int getMaturityMonths();
	void setMaturityMonths(int months);

	double getInterestRate();
	void setInterestRate(double rate);

	int getCurrentCDMonth();
	void setCurrentCDMonth(int month);
};

