/*
High interest savings account class
*/

#include "highInterestSavings.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


//constructors and destructor
highInterestSavings::highInterestSavings()
{
}

highInterestSavings::highInterestSavings(double& minimum, double& rate, int& number, string& name, double& balance) {
	minBalance = minimum;
	interestRate = rate;
	accountNumber = number;
	holderName = name;
	accountBalance = balance;
}


highInterestSavings::~highInterestSavings()
{
}

//getters and setters
double& highInterestSavings::getMinBalance() {
	return minBalance;
}

void highInterestSavings::setMinBalance(double& minimum) {
	minBalance = minimum;
}

//methods
void highInterestSavings::depositMoney(double& money) {
	accountBalance += money; //adjusting balance

	deposits.push_back(money); //adding to deposits
}//depositMoney method

void highInterestSavings::withdrawMoney(double& money) {
	if (accountBalance <= minBalance) {
		cout << "Cannot withdraw below minimum balance." << endl;
		
		money = 0; //putting withdrawal amount at 0 and not adding to list

	}
	else {
		accountBalance -= money; //adjusting balance
		withdrawals.push_back(money); //adding to withdrawals
	}
}//withdrawMoney method

void highInterestSavings::createStatement() {
	accountBalance = (accountBalance * interestRate) + accountBalance;

	interestRate *= 100; //to make it a cleaner rate for printing

	//header
	cout << "High Interest Savings Account Statement" << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Holder: " << holderName << endl << endl;

	//setting precision to two decimal places for dollars
	cout << fixed;
	cout << setprecision(2);

	//account details
	cout << setw(25) << "Account Balance:" << setw(12) << accountBalance << endl;
	cout << setw(25) << "Minimum Balance:" << setw(12) << minBalance << endl;
	cout << setw(25) << "Interest Rate:" << setw(12) << interestRate << endl;

	cout << endl; //spacing

	//transactions

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
}//createStatement method