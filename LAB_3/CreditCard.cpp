#include <iostream>
#include <cstring>
#include "CreditCard.h"

using namespace std;

namespace sict {
	

	void CreditCard::name(const char cardHolderName[]) {
		strcpy(m_cardHolderName, cardHolderName);
	};

	
	void CreditCard::initialize(unsigned long long creditCardNumber, int instCode, int expiryYear, int expiryMonth, int numberInTheBack) {
		m_cardNumber = creditCardNumber;
		m_institutionCode = instCode;
		m_expiryYear = expiryYear;
		m_expiryMonth = expiryMonth;
		m_numberInTheBack = numberInTheBack;

	};

	bool CreditCard::isValid() const {
		return ((m_cardHolderName[0] != '\0') &&
		(m_cardNumber >= MIN_CARD_NUMBER && m_cardNumber <= MAX_CARD_NUMBER) &&
		(m_institutionCode >= MIN_INST_NUMBER && m_institutionCode <= MAX_INST_NUMBER) &&
		(m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR) &&
		(m_expiryMonth >= 1 && m_expiryMonth <= 12) &&
		(m_numberInTheBack >= 0 && m_numberInTheBack <= 999));

	};

	void CreditCard::write() const {
		if (isValid()) {
			cout << "Cardholder: " << m_cardHolderName << endl;
			cout << "Card Number: " << m_cardNumber << endl;
			cout << "Institution: " << m_institutionCode << endl;
			cout << "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl;
			cout << "Number at the back: " << m_numberInTheBack;
		}
	};
}
