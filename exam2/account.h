/*
 * account.h
 *
 *  Created on: Apr 11, 2016
 *      Author: jjkath
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
using namespace std;

// Account Class
class Account
{
private:
    string fullName;
    long acctNum;
    double balance;
public:
    Account(const std::string & s = "Nullbody", long an = -1,double bal = 0.0)
	{
    	fullName = s;
    	acctNum = an;
    	balance = bal;
	}
    double Balance() const { return balance; }
    virtual void ViewAcct() const
    {
    	cout << "Basic account: " << endl;
    	cout << "Client name: " << fullName << endl;
    	cout << "Account number: " << acctNum << endl;
    	cout << "Balance: "<< balance << endl;
    }
    virtual ~Account() {}
};

// Loan Plus Account Class
class LoanPlus : public Account
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    LoanPlus(const Account & act, double ml = 500, double r = 0.11125) :
    	Account(act), maxLoan(ml), rate(r)
	{
    	owesBank = Amount_owed();
	}
	virtual void ViewAcct()const
    {
		Account::ViewAcct();
    	cout << "Loan account: " << endl;
    	cout << "Loan amount: "<< maxLoan << endl;
    	cout << "Rate: "<< rate << endl;
    	cout << "Amount owed to bank: "<< owesBank << endl;
    }
private:
    double Amount_owed() { return (maxLoan * rate); }
};

#endif /* ACCOUNT_H_ */
