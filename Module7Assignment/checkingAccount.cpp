/*
Checking account class
Notes: I don't see why anyone would need to instantiate
an object of this class so I'm making it abstract
*/

#include "checkingAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//vector to track checks written
vector<double> checks;
vector<double> deposits;
vector<double> withdrawals;

//constructors and destructor
checkingAccount::checkingAccount()
{
}


checkingAccount::~checkingAccount()
{
}

//no getters and setters here

//methods
void writeCheck(double& money) {}
