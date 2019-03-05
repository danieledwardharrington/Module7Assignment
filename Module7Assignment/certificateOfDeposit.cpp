/*
Class for the certificate of deposit accounts. For the penalty, I couldn't
find very much super specific information on the penalty for withdrawing
before the maturity date, so I made the penalty equal to the interest rate
times the account balance, times half the total maturity months. The book's
instructions were vague for how they wanted to calculate the penalty so I feel
this sufficiently matches the book's definition of a "stiff" penalty.
*/

#include "certificateOfDeposit.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


//properties
int maturityMonths;
double interestRate;
int currentCDMonth;

//vectors to track deposits, withdrawals, and penalties for the statement
vector<double> withdrawals;
vector<double> deposits;
vector<double> penalties;

//constructor and destructor
certificateOfDeposit::certificateOfDeposit()
{
}

certificateOfDeposit::certificateOfDeposit(int matMonths, double rate, int curMonth, int number, string name, double balance) {
	maturityMonths = matMonths;
	interestRate = rate;
	currentCDMonth = curMonth;
	accountNumber = number;
	holderName = name;
	accountBalance = balance;
}


certificateOfDeposit::~certificateOfDeposit()
{
}

//getters and setters
int certificateOfDeposit::getMaturityMonths() {
	return maturityMonths;
}

void certificateOfDeposit::setMaturityMonths(int months) {
	maturityMonths = months;
}

double certificateOfDeposit::getInterestRate() {
	return interestRate;
}

void certificateOfDeposit::setInterestRate(double rate) {
	interestRate = rate;
}

int certificateOfDeposit::getCurrentCDMonth() {
	return currentCDMonth;
}

void certificateOfDeposit::setCurrentCDMonth(int month) {
	currentCDMonth = month;
}

//methods
void certificateOfDeposit::depositMoney(double money) {
	accountBalance += money;

	deposits.push_back(money);
}//depositMoney method

void certificateOfDeposit::withdrawMoney(double money) {
	
	double penalty;

	if (currentCDMonth < maturityMonths) {

		penalty = (interestRate * accountBalance) * (maturityMonths / 2);

	}
	else {
		penalty = 0;
	}//if/else

	accountBalance -= (money + penalty);

	withdrawals.push_back(money);
	penalties.push_back(penalty);

}//withdrawMoney method

void certificateOfDeposit::createStatement() {

	interestRate *= 100; //to make it a cleaner rate for printing

	//header
	cout << "Certificate of Deposit Statement" << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Holder: " << holderName << endl << endl;

	//setting precision to two decimal places for dollars
	cout << fixed;
	cout << setprecision(2);

	//account details
	cout << setw(25) << "Account Balance:" << setw(12) << accountBalance << endl;
	cout << setw(25) << "CD Maturity" << setw(12) << maturityMonths << endl;
	cout << setw(25) << "Current CD Month:" << setw(12) << currentCDMonth << endl;
	cout << setw(25) << "Interest Rate:" << setw(12) << interestRate << endl;

	cout << endl;

	//transactions and penalties

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

	//for each for to print penalties
	cout << "Penalties" << endl << endl;
	for (double pen : penalties) {
		cout << pen << endl;
	}//for each

}//createStatement method