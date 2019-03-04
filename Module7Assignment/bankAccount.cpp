#include "bankAccount.h"
#include <string>
#include <iostream>

using namespace std;

//properties
int accountNumber;
string holderName;
double accountBalance;


//constructor
bankAccount::bankAccount()
{
}

//destructor
bankAccount::~bankAccount()
{
}

//getters and setters
void setAccountNumber(int number) {
	accountNumber = number;
}

int getAccountNumber() {
	return accountNumber;
}

void setHolderName(string name) {
	holderName = name;
}

string getHolderName() {
	return holderName;
}

void setAccountBalance(double balance) {
	accountBalance = balance;
}

double getAccountBalance() {
	return accountBalance;
}