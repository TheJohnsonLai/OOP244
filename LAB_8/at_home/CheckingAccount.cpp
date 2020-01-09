#include "CheckingAccount.h"
#include <iomanip>
using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here  
	CheckingAccount::CheckingAccount() {
		transactionFee = 0;
	}
	CheckingAccount::CheckingAccount(double iBal, double iTra) {
		setBalance(iBal);
		if (iTra < 0) {
			transactionFee = 0;
		}else
			transactionFee = iTra;
	}
	void CheckingAccount::chargeFee() {
		setBalance(getBalance() - transactionFee);
	}


	// TODO: Write a function prototype to override credit function
	void CheckingAccount::credit(double anAmount) {
		chargeFee();
		Account::credit(anAmount);
	}

	// TODO: Write a function prototype to override debit function
	bool CheckingAccount::debit(double anAmount) {
		chargeFee();
		if (Account::debit(anAmount))
			return true;
		else
			return false;
	}

	// TODO: Write a function prototype to  override display function
		void CheckingAccount::display(ostream& ostr) {
			ostr << "Account type: Checking" << endl;
			ostr << "Balance: $" << setprecision(2) << fixed << getBalance() << endl;
			ostr << "Transaction Fee: " << transactionFee << endl;
	}

}