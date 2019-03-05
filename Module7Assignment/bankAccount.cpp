#include "bankAccount.h"
#include <string>
#include <iostream>

using namespace std;

//properties
int accountNumber;
string holderName;
double accountBalance;


//constructors
bankAccount::bankAccount()
{
}

//destructor
bankAccount::~bankAccount()
{
}

//getters and setters
void bankAccount::setAccountNumber(int number) {
	accountNumber = number;
}

int bankAccount::getAccountNumber() {
	return accountNumber;
}

void bankAccount::setHolderName(string name) {
	holderName = name;
}

string bankAccount::getHolderName() {
	return holderName;
}

void bankAccount::setAccountBalance(double balance) {
	accountBalance = balance;
}

double bankAccount::getAccountBalance() {
	return accountBalance;
}

//virtual functions
void bankAccount::depositMoney(double money) {};

void bankAccount::withdrawMoney(double money) {};

void bankAccount::createStatement() {};