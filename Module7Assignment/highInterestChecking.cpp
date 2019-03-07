/*
High interest rate checking class
As far as I can tell, I don't have to actually do anything with this class.
I think the legwork for deciding which account to use, the high interest checking
and no service checking, will come down to the main.cpp file with certain rules set
up there. If it's taking user input, then there would have to be if statements to handle
which account to choose.
*/

#include "highInterestChecking.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//constructors and destructor
highInterestChecking::highInterestChecking()
{
}

highInterestChecking::highInterestChecking(double& rate, double& minimum, int& number, string& name, double& balance) {
	interestRate = rate;
	minBalance = minimum;
	accountNumber = number;
	holderName = name;
	accountBalance = balance;
}

highInterestChecking::~highInterestChecking()
{
}

//createStatement method
void highInterestChecking::createStatement() {
	accountBalance = (accountBalance * interestRate) + accountBalance;

	interestRate *= 100; //for cleaner printing

	//header
	cout << "High Interest No Service Charge Checking Statement" << endl;
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