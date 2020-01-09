#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	Account::Account() {
		balance = 1.0;
	}

	Account::Account(double gBal) {
		if (gBal < 0)
			balance = 1.0;
		else
			balance = gBal;
	}
	

	// credit (add) an amount to the account balance
	void Account::credit(double anAmount) {
		balance += anAmount;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double withdraw) {
		if (withdraw > balance) {
			return false;
		}
		else {
			balance -= withdraw;
			return true;
		}
		
	}


	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}