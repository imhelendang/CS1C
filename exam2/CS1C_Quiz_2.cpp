//============================================================================
// Name        : CS1C_Quiz_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "account.h"
#include "stack.h"

void printAccount(const Account * act);

int main() {
	Account * basic_account = new Account("Bill's Account",101,500.00);
	LoanPlus * loan_account = new LoanPlus(*basic_account,1500,.0525);

	// print basic account info
	printAccount(basic_account);
	// print loan account info
	printAccount(loan_account);

	delete basic_account;
	delete loan_account;

	// create an instance of an int stack
	Stack<int> intStack;	 	// template instatiation - T = int
	Stack<float> floatStack;	// template instatiation - T = float
	Stack<Account> acctStack;


	floatStack.push(1.5);



	return 0;
}

void printAccount(const Account * act)
{
	act->ViewAcct();
}
