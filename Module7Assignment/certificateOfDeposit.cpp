#include "certificateOfDeposit.h"
#include <iostream>
#include <string>

using namespace std;


//properties
int maturityMonths;
double interestRate;
int currentCDMonth;

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
