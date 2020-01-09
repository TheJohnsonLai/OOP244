#include "SavingsAccount.h"
#include <iomanip>

using namespace std;

namespace ict {

	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount() {
		interestRate = 0;
	}
	SavingsAccount::SavingsAccount(double iBal, double iInt) {
		setBalance(iBal);
		if (iInt < 0) {
			interestRate = 0;
		}
		else {
			interestRate = iInt;
		}
	}

	double SavingsAccount::calculateInterest() {
		return getBalance() * interestRate;
	}

	void SavingsAccount::display(ostream& ostr) {
		ostr << "Account type: Saving" << endl;
		ostr << "Balance: $" << setprecision(2) << fixed << getBalance() << endl;
		ostr << "Interest Rate (%): " << interestRate * 100 << endl;

	}
}