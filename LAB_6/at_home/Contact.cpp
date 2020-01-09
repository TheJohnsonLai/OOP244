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
		if (names != nullptr && names[0] != '\0' ) {
			cout << names << endl;
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
		else {
			Contact();
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
				cout << "(+" << (m_phoneNumbers[c] % 10000000000000 - (m_phoneNumbers[c] % 10000000000)) / 10000000000 << ") ";
				cout << (m_phoneNumbers[c] % 10000000000 - (m_phoneNumbers[c] % 10000000)) / 10000000 << " ";
				cout << (m_phoneNumbers[c] % 10000000 - (m_phoneNumbers[c] % 10000)) / 10000 << "-";
				cout << m_phoneNumbers[c] % 10000 << endl;
				//char bleh[13] = "14161234567a";
				//char cpybleh[13] = to_string(m_phoneNumbers[c]);
				/*int size = 11;
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
				}*/
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
		return m_name[0] == '\0' ? true : false;

	}

	Contact::Contact(const Contact& other) {
		strcpy(m_name, other.m_name);
		m_phoneNumbers = new long long[other.m_noOfPhoneNumbers];
		for (int i = 0; i < other.m_noOfPhoneNumbers; i++) {
			m_phoneNumbers[i] = other.m_phoneNumbers[i];
		}
		m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
	}

	Contact& Contact::operator=(const Contact& other) {
		//needless check this != &other
		//if (this == &other) {
		//	return *this;
		//}else
		//	*this = other;
		//	return *this;
		if (this != &other) {
			delete[] m_phoneNumbers;
			m_phoneNumbers = new long long[other.m_noOfPhoneNumbers];
			for (int i = 0; i < other.m_noOfPhoneNumbers; i++)
				m_phoneNumbers[i] = other.m_phoneNumbers[i];
			m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
		}
		return *this;
	}


	void Contact::addPhoneNumber(long long phoneNumber) {
		if (phoneNumber >= 11001000000 && phoneNumber <= 999999999999) {
			m_noOfPhoneNumbers++;
			long long* temp_Arr;
			temp_Arr = new long long[m_noOfPhoneNumbers];
			for (int c = 0; c < m_noOfPhoneNumbers - 1; c++) {
				temp_Arr[c] = m_phoneNumbers[c];
			}
			temp_Arr[m_noOfPhoneNumbers - 1] = phoneNumber;
			delete[] m_phoneNumbers;
			m_phoneNumbers = new long long[m_noOfPhoneNumbers];
			m_phoneNumbers = temp_Arr;
		}
	}
	
}