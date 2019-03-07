#pragma once
#include "noServiceChargeChecking.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


class highInterestChecking : public noServiceChargeChecking
{
public:
	
	//constructors and destructor
	highInterestChecking();
	highInterestChecking(double& rate, double& minimum, int& number, string& name, double& balance);
	~highInterestChecking();

	//methods
	void createStatement() override;
};

