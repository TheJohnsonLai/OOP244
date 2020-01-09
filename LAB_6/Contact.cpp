#include "Contact.h"
#include <cstring>
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
	Contact::Contact(const char names[], long long phones[], int nums) {
		int ValidCount = 0;
		int count = 0;
		cout << "b. ";
		if (names == nullptr) {
			cout << "null -";
		}
		else {
			if (names[1] == '\0') {
				cout << "not null - ends 1; ";
			}
			else {
				cout << "not null - ends 0; ";
			}
		}
		if (names == nullptr || names[0] == '\0' || names[1] == '\0') {
			Contact();
		}
		else {
			for (int c = 0; c < nums; c++) {
				if (phones[c] >= 11001000000 && phones[c] <= 999999999999) {
					ValidCount++;
				}
				else {
				}
			}
			m_noOfPhoneNumbers = ValidCount;
			m_phoneNumbers = new long long[ValidCount];
			if (strlen(names) > 20){
				for(int c = 0; c < 20; c++){
					m_name[c] = names[c];
				}
				m_name[21] = '\0';
			}else{
				strcpy(m_name, names);
			}
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
				cout << "(+" << (m_phoneNumbers[c] % 10000000000000 - (m_phoneNumbers[c] % 10000000000)) / 10000000000 << ") ";
				cout << (m_phoneNumbers[c] % 10000000000 - (m_phoneNumbers[c] % 10000000)) / 10000000 <<" ";
				cout << (m_phoneNumbers[c] % 10000000 - (m_phoneNumbers[c] % 10000)) / 10000 << "-";
				cout << m_phoneNumbers[c] % 10000 << endl; 
			}
		}
	}
	// TODO: add the isEmpty function here
	bool Contact::isEmpty() const {
		return m_name[0] == '\0' ? true : false;
	}
	
}
