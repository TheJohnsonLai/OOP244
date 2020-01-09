#include "Contact.h"
#include <string>
#include <iostream>

using namespace std;

namespace communication {


	// TODO: add the default constructor here
	Contact::Contact() {
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;
	}

	// TODO: add the constructor with parameters here
	Contact::Contact(char names[], long long phones[], int nums) {
		int ValidCount = 0;
		int count = 0;
		if (names != nullptr && names[0] != '\0' && nums > 0) {
			for (int c = 0; c < nums; c++) {
				if (phones[c] >= 11001000000 && phones[c] <= 999999999999) {
					ValidCount++;
				}
				else {
				}
			}
			m_noOfPhoneNumbers = ValidCount;
			m_phoneNumbers = new long long[ValidCount];
			if (strlen(names) > 21) {
				names[21] = '\0';
			}
			strcpy(m_name, names);
			for (int c = 0; c < nums; c++) {
				if (phones[c] >= 11001000000 && phones[c] <= 999999999999) {
					m_phoneNumbers[count] = phones[c];
					count++;
				}
				else {
				}

			}
		}
	}

	// TODO: add the destructor here
	Contact::~Contact() {
		delete[] m_phoneNumbers;
	}

	// TODO: add the display function here
	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << m_name << endl;
			for (int c = 0; c < m_noOfPhoneNumbers; c++) {
				//char bleh[13] = "14161234567a";
				//char cpybleh[13] = to_string(m_phoneNumbers[c]);
				int size = 11;
				long long bleh = m_phoneNumbers[c];
				if (m_phoneNumbers[c] > 99999999999) {
					size = 12;
				}
				int displayAr[12];
				for (int i = (size-1); i >= 0; i--) {
					displayAr[i] = bleh % 10;
					bleh /= 10;
				}
				if (size >= 12) {
					cout << "(+" << displayAr[0] << displayAr[1] << ") " << displayAr[2] << displayAr[3] << displayAr[4] << " " << displayAr[5] << displayAr[6] << displayAr[7] << "-" << displayAr[8] << displayAr[9] << displayAr[10] << displayAr[11] << endl;
				}
				else {
					cout << "(+" << displayAr[0] << ") " << displayAr[1] << displayAr[2] << displayAr[3] << " " << displayAr[4] << displayAr[5] << displayAr[6] << "-" << displayAr[7] << displayAr[8] << displayAr[9] << displayAr[10] << endl;
				}
				//if (isdigit(bleh[12])) {
				//	cout << "(+" << bleh[1] << bleh[2] << ") " << bleh[3 - 5] << " " << bleh[6 - 8] << "-" << bleh[9 - 12] << endl;
				//}
				//else {
				//	cout << "(+" << bleh[1] << ") " << bleh[2-4] << " " << bleh[5-7] << "-"<< bleh[8-11]<< endl;
				//}
				
			}
		}
	}

	// TODO: add the isEmpty function here
	bool Contact::isEmpty() const {
		if (m_name[0] == '\0' && m_phoneNumbers == nullptr && m_noOfPhoneNumbers == 0){
			return true;
		}
		else {
			return false;
		}

	}

	Contact::Contact(const Contact& other) {
		strcpy(m_name, other.m_name);
		for (int i = 0; i < other.m_noOfPhoneNumbers, i++) {
			m_phoneNumbers[i] = other.m_phoneNumbers[i]
		}
		m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
	}

	Contact::Contact& operator=(const Contact& other) {
		//needless check this != &other
			return &other;
	}


	void Contact::addPhoneNumber(long long phoneNumber) {
		m_noOfPhoneNumbers++;
		temp_Arr = new long long[m_noOfPhoneNumbers];
		for (int cC = 0; cC < m_noOfPhoneNumbers - 1, cC++) {
			temp_Arr[cC] = m_phoneNumbers[cC];
		}
		temp_Arr[m_noOfPhoneNumbers - 1] = m_phoneNumbers[m_noOfPhoneNumbers - 1];
		delete[] m_phoneNumbers;
		m_phoneNumbers = new long long[m_noOfPhoneNumbers];
		m_phoneNumbers = temp_Arr;

	}
	
}