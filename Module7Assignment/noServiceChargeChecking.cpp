/*
No service charge checking class.
Like the other checking accounts, I'm assuming there is
no overdraft or "check bouncing" fee. I'm assuming this is
just a super generous bank. Instead, I'm just adding a warning
on the account statement if the balance is below 0. Also, the
instructions for this account says it allows the account holder
to "write checks". I'm assuming this means it's an unlimited amount
of checks.
*/

#include "noServiceChargeChecking.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//properties
double interestRate;
double minBalance;

//constructors and destructor
noServiceChargeChecking::noServiceChargeChecking()
{
}

noServiceChargeChecking::noServiceChargeChecking(double& rate, double& minimum, int& number, string& name, double& balance) {
	interestRate = rate;
	minBalance = minimum;
	accountNumber = number;
	holderName = name;
	accountBalance = balance;
}

noServiceChargeChecking::~noServiceChargeChecking()
{
}

//getters and setters
double& noServiceChargeChecking::getInterestRate() {
	return interestRate;
}

void noServiceChargeChecking::setInterestRate(double& rate) {
	interestRate = rate;
}

double& noServiceChargeChecking::getMinBalance() {
	return minBalance;
}

void noServiceChargeChecking::setMinBalance(double& minimum) {
	minBalance = minimum;
}

//methods
void noServiceChargeChecking::depositMoney(double& money) {
	accountBalance += money;

	deposits.push_back(money);
}//depositMoney method

void noServiceChargeChecking::withdrawMoney(double& money) {
	if (accountBalance <= 0) {
		cout << "No money to withdraw" << endl;
		money = 0;
	}
	else {
		accountBalance -= money;
		withdrawals.push_back(money);
	}
}//withdrawMoney method

void noServiceChargeChecking::writeCheck(double& money) {
	accountBalance -= money;
	checks.push_back(money);
}//writeCheck method

void noServiceChargeChecking::createStatement() {
	accountBalance = (accountBalance * interestRate) + accountBalance;

	interestRate *= 100; //for cleaner printing

	//header
	cout << "No Service Charge Checking Statement" << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Holder: " << holderName << endl << endl;

	//setting precision to two decimal places for dollars
	cout << fixed;
	cout << setprecision(2);

	//account details
	cout << setw(25) << "Account Balance:" << setw(12) << accountBalance << endl;
	cout << setw(25) << "Minimum Balance:" << setw(12) << minBalance << endl;
	cout << setw(25) << "Interest Rate:" << setw(12) << interestRate << endl;
	cout << setw(25) << "Checks Written:" << setw(12) << checks.size() << endl;

	cout << endl; //spacing

	//transactions and checks

	//for each to print deposits
	cout << "Deposits" << endl << endl;
	for (double dep : deposits) {
		cout << dep << endl;
	}//for each

	cout << endl; //spacing

	//for each to print withdrawals
	cout << "Withdrawals" << endl << endl;
	for (double w : withdrawals) {
		cout << w << endl;
	}//for each

	cout << endl; //spacing

	//for each for to print checks
	cout << "Checks" << endl << endl;
	for (double check : checks) {
		cout << check << endl;
	}//for each

	if (accountBalance < minBalance) {
		cout << "YOUR ACCOUNT BALANCE HAS FALLEN BELOW THE MINIMUM. PLEASE DEPOSIT FUNDS AS SOON AS POSSIBLE AT RISK OF ACCOUNT CLOSURE." << endl;
	}//if
}//createStatement method