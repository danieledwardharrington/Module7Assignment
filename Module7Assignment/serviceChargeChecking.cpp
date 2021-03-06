/*
Service charge checking account class.
The instructions do not say anything about overdraft fees when
writing checks so I am going to assume this is a super generous
bank and they don't have overdraft fees. Further building on this
would be to put in overdraft fees or stop the account holder from
writing checks when they don't have the money. Though I'm not sure how
this is handled exactly with physical checks, my knowledge is only
with debit and credit cards.
*/

#include "serviceChargeChecking.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//variable for maximum checks written
int maxChecks;
double monthlyFee;

//constructors and destructor
serviceChargeChecking::serviceChargeChecking()
{
}


serviceChargeChecking::serviceChargeChecking(int& checks, double& fee, int& number, string& name, double& balance) {
	maxChecks = checks;
	monthlyFee = fee;
	accountNumber = number;
	holderName = name;
	accountBalance = balance;
	minBalance = 0;
	interestRate = 0;

}

serviceChargeChecking::~serviceChargeChecking()
{
}

//getters and setters
int& serviceChargeChecking::getMaxChecks() {
	return maxChecks;
}

void serviceChargeChecking::setMaxChecks(int& maximum) {
	maxChecks = maximum;
}

double& serviceChargeChecking::getMonthlyFee() {
	return monthlyFee;
}

void serviceChargeChecking::setMonthlyFee(double& fee) {
	monthlyFee = fee;
}

//methods
void serviceChargeChecking::depositMoney(double& money) {
	accountBalance += money;

	deposits.push_back(money);
}//depositMoney method

void serviceChargeChecking::withdrawMoney(double& money) {
	if (accountBalance <= 0) {
		cout << "No money to withdraw" << endl;
		money = 0;
	}
	else {
		accountBalance -= money;
		withdrawals.push_back(money);
	}
}//withdrawMoney method

void serviceChargeChecking::writeCheck(double& money) {
	
	if (static_cast<int>(checks.size()) < maxChecks) {
		accountBalance -= money;
		checks.push_back(money);
	}
	else {
		cout << "Maximum checks reached. Cannot write another check." << endl;
	}

}//writeCheck method

void serviceChargeChecking::createStatement() {
	
	accountBalance -= monthlyFee;

	//header
	cout << "Service Charge Checking Statement" << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Holder: " << holderName << endl << endl;

	//setting precision to two decimal places for dollars
	cout << fixed;
	cout << setprecision(2);

	//account details
	cout << left << setw(25) << "Account Balance:" << setw(12) << accountBalance << endl;
	cout << left << setw(25) << "Maximum Checks:" << setw(12) << maxChecks << endl;
	cout << left << setw(25) << "Checks Written:" << setw(12) << checks.size() << endl;
	cout << left << setw(25) << "Monthly Fee:" << setw(12) << monthlyFee << endl;

	cout << endl;

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

	if (accountBalance < 0) {
		cout << "YOUR ACCOUNT BALANCE HAS FALLEN BELOW $0. PLEASE DEPOSIT FUNDS AS SOON AS POSSIBLE AT RISK OF ACCOUNT CLOSURE." << endl;
	}//if

}//createStatement method