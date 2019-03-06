#pragma once
#include "noServiceChargeChecking.h"
class highInterestChecking : public noServiceChargeChecking
{
public:
	
	//constructors and destructor
	highInterestChecking();
	highInterestChecking(double rate, double minimum, int number, string name, double balance);
	~highInterestChecking();

	//methods
	void createStatement() override;
};

