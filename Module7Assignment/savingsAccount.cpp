/*
Basic savings account class
*/

#include "savingsAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


//constructors and destructor
savingsAccount::savingsAccount()
{
}

savingsAccount::savingsAccount(double& rate, int& number, string& name, double& balance) {

	interestRate = rate;
	accountNumber = number;
	holderName = name;
	accountBalance = balance;
	minBalance = 0;
}


savingsAccount::~savingsAccount()
{
}

//getters and setters
double& savingsAccount::getInterestRate() {
	return interestRate;
}

void savingsAccount::setInterestRate(double& rate) {
	interestRate = rate;
}

//methods
void savingsAccount::depositMoney(double& money) {
	accountBalance += money;

	deposits.push_back(money); //adding transaction to vector
}//depositMoney method

void savingsAccount::withdrawMoney(double& money) {
	accountBalance -= money;

	withdrawals.push_back(money);
}//withdrawMoney method

void savingsAccount::createStatement() {
	interestRate *= 100; //to make it a cleaner rate for printing

	//header
	cout << "Savings Account Statement" << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Holder: " << holderName << endl << endl;

	//setting precision to two decimal places for dollars
	cout << fixed;
	cout << setprecision(2);

	//account details
	cout << setw(25) << "Account Balance:" << setw(12) << accountBalance << endl;
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
