#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict {
	class SavingsAccount : public Account {
	private:
		double interestRate; // interest rate (percentage)
	public:

		// TODO: put prototypes here
		SavingsAccount();
		SavingsAccount(double iBal, double iInt);
		double calculateInterest();
		void display(ostream& ostr);
	};
};
#endif
