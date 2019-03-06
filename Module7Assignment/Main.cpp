/*
CIS 269
Daniel Harrington
March 3, 2019
Module 7 Assignment: Bank accounts
Notes: The instructions are not telling me to do anything with
the interest rates so for this assignment, I am just doing a one
month statement and showing the statement as if it has been one month
from the creation of the account (AKA the instantiation of the object).
Additionally, the instructions don't say what interest rate constitutes
high interest and what falls under standard interest, so the numbers I'm
using here for interest rates are (somewhat) arbitrary. I did a super
cursory Google search but didn't want to blow too much time researching
those types of details. This main class is going to do a lot of the legwork
for deciding which accounts are for when. I'm just treating this as a test
of the classes and their functionality, not necessarily like a mock customer
scenario. Minimum balance numbers are also made up for this assignment since
the instructions didn't specify.
*/

#include "bankAccount.h"
#include "certificateOfDeposit.h"
#include "savingsAccount.h"
#include "highInterestSavings.h"
#include "checkingAccount.h"
#include "serviceChargeChecking.h"
#include "noServiceChargeChecking.h"
#include "highInterestChecking.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//constants for high and standard interest rates and minimukm balances;
//I'm using these numbers across all types of accounts
const double HIGH_RATE = 0.0135;
const double STANDARD_RATE = 0.0001;
const double COD_RATE = 0.03; //pretty much just for certificate of deposit
const double STANDARD_MIN_BALANCE = 100;
const double HIGH_MIN_BALANCE = 300;

int main() {


}//main method

//******Method Bodies*******

//method to get input from the user
void selectBaseAccount() {

	//vector for the rudimentary menu
	vector<string> choices;
	choices.push_back("[1] Savings");
	choices.push_back("[2] Checking");
	choices.push_back("[3] Certificate of Deposit");

	int accountType;
	cout << "Test Bank Account OOP" << endl << endl; //header

	cout << "Enter the type of account you'd like to create:" << endl;
	
	//for loop to print my basic menu
	for (string choice : choices) {
		cout << choice << endl;
	}//for

	cin >> accountType;

	//switch to go to a different method to create the accounts
	switch (accountType) {
	case 1:
		selectSavings(accountType);
		break;
	case 2:
		selectChecking(accountType);
		break;
	case 3:
		createCoD();
		break;
	default:
		cout << "Invalid option. Starting over." << endl << endl;
		selectBaseAccount();
		break;
	}//switch

}//getInput method

/*
I'm passing the accountType variable to these methods so that
I can use it again to track user input for what specific kind of
account they want to create.
*/

//method for handling savings accounts
void selectSavings(int& accountType) {
	
	accountType = 0; //resetting the value

	vector<string> choices;
	choices.push_back("[1] Standard Savings");
	choices.push_back("[2] High Interest Savings");

	cout << endl; //spacing

	cout << "Savings Accounts" << endl << endl; //header
	cout << "Select which savings account you'd like:" << endl;
	for (string choice : choices) {
		cout << choice << endl;
	}//for

	cin >> accountType; //getting user choice

	//switch again
	switch (accountType)
	{
	case 1:
		createStandardSavings();
		break;
	case 2:

		break;
	default:
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount(); //like from the beginning
		break;
	}//switch

}//createSavings method

//method for handling checking accounts
void selectChecking(int& accountType) {
	accountType = 0; //resetting the value

	vector<string> choices;
	choices.push_back("[1] Standard Service Charge Checking");
	choices.push_back("[2] Standard No Service Charge Checking");
	choices.push_back("[3] High Interest No Service Charge Checking");

	cout << endl; //spacing

	cout << "Checking Accounts" << endl << endl; //header
	cout << "Select which checking account you'd like:" << endl;
	for (string choice : choices) {
		cout << choice << endl;
	}//for

	cin >> accountType; //getting user choice

	//switch again
	switch (accountType)
	{
	case 1:
		createServiceChargeChecking();
		break;
	case 2:
		createNoServiceChargeChecking();
		break;
	case 3:
		createHighInterestChecking();
		break;
	default:
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount(); //like from the beginning
		break;
	}//switch
}//createChecking method

void createStandardSavings() {
	
	cout << "Standard Savings" << endl << endl; //header

	//variables for do/while loops later
	char loopResponse;
	char answer;
	double deposit;
	double withdrawal;

	//variables for the account
	int accountNumber;
	string holderName;
	double startingBalance;

	savingsAccount standardSavings; //creating object

	standardSavings.setInterestRate(STANDARD_RATE); //can automatically set this rate
	accountNumber = rand() % 100 + 1; //automatically setting random account number
	standardSavings.setAccountNumber(accountNumber);

	//getting user input for the rest
	cout << "Enter the account holder name:" << endl;
	cin >> holderName;
	standardSavings.setHolderName(holderName);

	cout << "Set initial account balance:" << endl;
	cin >> startingBalance;
	//in case the input is negative
	if (startingBalance < 0) {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if
	standardSavings.setAccountBalance(startingBalance);

	//loops for testing withdrawals and deposits
	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		deposit = 0;

		cout << "Would you like to make a deposit? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y'){
			cout << "Enter the amount you'd like to deposit:" << endl;
			cin >> deposit;
			if (deposit > 0) {
				standardSavings.depositMoney(deposit);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another deposit? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	}while(loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		withdrawal = 0;

		cout << "Would you like to make a withdrawal? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to withdraw:" << endl;
			cin >> withdrawal;
			if (withdrawal < standardSavings.getAccountBalance && withdrawal > 0) {
				standardSavings.withdrawMoney(withdrawal);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another withdrawal? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	cout << endl; //spacing
	cout << "Showing statement:" << endl << endl; //telling the user the statement is being shown

	standardSavings.createStatement();

	cout << endl; //spacing
}//standardSavings method



void createHighInterestSavings() {

	cout << "High Interest Savings" << endl << endl; //header

	//variables for do/while loops later
	char loopResponse;
	char answer;
	double deposit;
	double withdrawal;

	//variables for the account
	int accountNumber;
	string holderName;
	double startingBalance;

	highInterestSavings highSavings; //creating object

	//automatically setting some values
	highSavings.setInterestRate(HIGH_RATE);
	highSavings.setMinBalance(STANDARD_MIN_BALANCE);
	accountNumber = rand() % 100 + 1; //automatically setting random account number
	highSavings.setAccountNumber(accountNumber);

	//getting user input for the rest
	cout << "Enter the account holder name:" << endl;
	cin >> holderName;
	highSavings.setHolderName(holderName);

	cout << "Set initial account balance (Starting balance must be AT LEAST " << STANDARD_MIN_BALANCE << "):" << endl;
	cin >> startingBalance;
	//in case input is less than the minimum balance
	if (startingBalance < STANDARD_MIN_BALANCE) {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if
	highSavings.setAccountBalance(startingBalance);

	//loops for testing withdrawals and deposits
	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		deposit = 0;

		cout << "Would you like to make a deposit? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to deposit:" << endl;
			cin >> deposit;
			if (deposit > 0) {
				highSavings.depositMoney(deposit);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another deposit? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		withdrawal = 0;

		cout << "Would you like to make a withdrawal? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to withdraw:" << endl;
			cin >> withdrawal;
			if (withdrawal < highSavings.getAccountBalance && withdrawal > 0) {
				highSavings.withdrawMoney(withdrawal);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another withdrawal? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	cout << endl; //spacing
	cout << "Showing statement:" << endl << endl; //telling the user the statement is being shown

	highSavings.createStatement();

	cout << endl; //spacing

}//createHighInterestSavings method

void createServiceChargeChecking() {
	
	cout << "Standard Service Charge Checking" << endl << endl; //header

	//account variables
	int maxChecks;
	double monthlyFee;
	int accountNumber;
	string holderName;
	double startingBalance;

	//variables for do/while loops later
	char loopResponse;
	char answer;
	double deposit;
	double withdrawal;

	serviceChargeChecking serviceAccount; //creating object

	//setting some values automatically
	accountNumber = rand() % 100 + 1;
	serviceAccount.setAccountNumber(accountNumber);

	//getting user input for the rest
	cout << "Enter the account holder name:" << endl;
	cin >> holderName;
	serviceAccount.setHolderName(holderName);

	cout << "Set initial account balance:" << endl;
	cin >> startingBalance;
	//in case the input is negative
	if (startingBalance < 0) {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if
	serviceAccount.setAccountBalance(startingBalance);

	cout << "Enter the maximum number of checks:" << endl;
	cin >> maxChecks;
	//in case max checks is less than 1
	if (maxChecks < 1) {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if
	serviceChargeChecking.setMaxChecks(maxChecks);

	cout << "Enter the monthly fee:" << endl;
	cin >> monthlyFee;
	//in case the user doesn't enter a monthly fee
	if (monthlyFee <= 0) {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if
	serviceAccount.setMonthlyFee(monthlyFee);

	//loops for testing withdrawals, checks, and deposits
	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		deposit = 0;

		cout << "Would you like to make a deposit? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to deposit:" << endl;
			cin >> deposit;
			if (deposit > 0) {
				serviceAccount.depositMoney(deposit);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another deposit? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		withdrawal = 0;

		cout << "Would you like to make a withdrawal? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to withdraw:" << endl;
			cin >> withdrawal;
			if (withdrawal < serviceAccount.getAccountBalance && withdrawal > 0) {
				serviceAccount.withdrawMoney(withdrawal);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another withdrawal? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	//for the sake of brevity, I'm not making the user fill in who the check is for and the date and all of that
	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		withdrawal = 0; //just gonna re-use this variable since it fills basically the same function for checks

		cout << "Would you like to write a check? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount for the check:" << endl;
			cin >> withdrawal;
			if (withdrawal < serviceAccount.getAccountBalance && withdrawal > 0) {
				serviceAccount.writeCheck(withdrawal);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to write another check? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	cout << endl; //spacing

	cout << "Showing statement:" << endl << endl; //telling the user the statement is being shown

	serviceAccount.createStatement();

	cout << endl; //spacing

}//createServiceChargeChecking method

void createNoServiceChargeChecking() {
	cout << "Standard Service Charge Checking" << endl << endl; //header

	//account variables
	int maxChecks;
	double monthlyFee;
	int accountNumber;
	string holderName;
	double startingBalance;

	//variables for do/while loops later
	char loopResponse;
	char answer;
	double deposit;
	double withdrawal;

	serviceChargeChecking serviceAccount; //creating object

	//setting some values automatically
	accountNumber = rand() % 100 + 1;
	serviceAccount.setAccountNumber(accountNumber);

	//getting user input for the rest
	cout << "Enter the account holder name:" << endl;
	cin >> holderName;
	serviceAccount.setHolderName(holderName);

	cout << "Set initial account balance:" << endl;
	cin >> startingBalance;
	//in case the input is negative
	if (startingBalance < 0) {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if
	serviceAccount.setAccountBalance(startingBalance);


	//loops for testing withdrawals, checks, and deposits
	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		deposit = 0;

		cout << "Would you like to make a deposit? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to deposit:" << endl;
			cin >> deposit;
			if (deposit > 0) {
				serviceAccount.depositMoney(deposit);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another deposit? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		withdrawal = 0;

		cout << "Would you like to make a withdrawal? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to withdraw:" << endl;
			cin >> withdrawal;
			if (withdrawal < serviceAccount.getAccountBalance && withdrawal > 0) {
				serviceAccount.withdrawMoney(withdrawal);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another withdrawal? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	//for the sake of brevity, I'm not making the user fill in who the check is for and the date and all of that
	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		withdrawal = 0; //just gonna re-use this variable since it fills basically the same function for checks

		cout << "Would you like to write a check? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount for the check:" << endl;
			cin >> withdrawal;
			if (withdrawal < serviceAccount.getAccountBalance && withdrawal > 0) {
				serviceAccount.writeCheck(withdrawal);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to write another check? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	cout << endl; //spacing

	cout << "Showing statement:" << endl << endl; //telling the user the statement is being shown

	serviceAccount.createStatement();

	cout << endl; //spacing
}//createNoServiceChargeChecking method

void createHighInterestChecking() {

}//createHighInterestChecking method

//method for handling certificate of deposit
void createCoD() {
	cout << "Certificate of Deposit" << endl << endl; //header

	//variables for do/while loops later
	char loopResponse;
	char answer;
	double deposit;
	double withdrawal;
	double fee;

	//variables for account
	int matMonths;
	int currentMonth;
	int accountNumber;
	string holderName;
	double startingBalance;

	certificateOfDeposit codAccount; //creating object

	//setting some values automatically
	codAccount.setInterestRate(COD_RATE);
	accountNumber = rand() % 100 + 1; //automatically setting random account number
	codAccount.setAccountNumber(accountNumber);

	//getting user input for the rest
	cout << "Enter the account holder name:" << endl;
	cin >> holderName;
	codAccount.setHolderName(holderName);

	cout << "Set initial account balance:" << endl;
	cin >> startingBalance;
	//in case the input is negative
	if (startingBalance < 0) {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if
	codAccount.setAccountBalance(startingBalance);

	cout << "Set the maturity duration of the account:" << endl;
	cin >> matMonths;
	//can't do it for less than a month
	if (matMonths < 1) {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}
	codAccount.setMaturityMonths(matMonths);

	cout << "Set the current month:" << endl;
	cin >> currentMonth;
	codAccount.setCurrentCDMonth(currentMonth);

	//loops for testing withdrawals and deposits
	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		deposit = 0;

		cout << "Would you like to make a deposit? (Y/N)" << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to deposit:" << endl;
			cin >> deposit;
			if (deposit > 0) {
				codAccount.depositMoney(deposit);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another deposit? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	do {
		loopResponse = 'N'; //resetting
		answer = ' ';
		withdrawal = 0;
		fee = 0;

		cout << "Would you like to make a withdrawal? (Y/N)" << endl;
		cout << "NOTE: Withdrawing before account maturity incurs an additional fee." << endl;
		cin >> answer;
		answer = toupper(answer); //making it capital
		if (answer == 'N') {
			break;
		}
		else if (answer == 'Y') {
			cout << "Enter the amount you'd like to withdraw:" << endl;
			cin >> withdrawal;
			fee = (codAccount.getAccountBalance() * COD_RATE) * (matMonths / 2);
			if (withdrawal + fee <= codAccount.getAccountBalance && withdrawal > 0) {
				codAccount.withdrawMoney(withdrawal);
			}
			else {
				cout << "Invalid input. Starting over." << endl << endl;
				selectBaseAccount();
			}//nested if
		}
		else {
			cout << "Invalid input. Starting over." << endl << endl;
			selectBaseAccount();
		}//if

		cout << "Would you like to make another withdrawal? (Y/N)" << endl;
		cin >> loopResponse;
		loopResponse = toupper(loopResponse); //making it capital

	} while (loopResponse == 'Y');

	//for invalid input
	if (loopResponse != 'N') {
		cout << "Invalid input. Starting over." << endl << endl;
		selectBaseAccount();
	}//if

	cout << endl; //spacing
	cout << "Showing statement:" << endl << endl; //telling the user the statement is being shown

	codAccount.createStatement();

	cout << endl; //spacing

}//createCoD method