// TODO: add header guard
#ifndef communication_Contact_H__
#define communication_Contact_H__

#include <iostream>

using namespace std;

// TODO: add namespace here
namespace communication {

	class Contact
	{
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
	public:
		// TODO: add the default constructor here
		Contact();

		// TODO: add the constructor with parameters here
		Contact(char* names, long long* phone, int num);

		// TODO: add the destructor here
		~Contact();

		// TODO: add the display function here
		void display() const;

		// TODO: add the isEmpty function here
		bool isEmpty() const;

	public:
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		void addPhoneNumber(long long phoneNumber);
	};

}

#endif