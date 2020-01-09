#define _CRT_SECURE_NO_WARNINGS 

#include "Error.h"
#include <iostream>
#include <cstring>

namespace ict{
	Error::Error() {
		m_message = nullptr;
	}
	Error::Error(const char* errorMessage) {
		m_message = nullptr;
		message(errorMessage);
	}
	// destructor
	Error::~Error() { delete[] m_message; }
	// deleted constructor and operator=
	// operator= for c-style strings
	void Error::operator=(const char* errorMessage) {
		//m_message = errorMessage;
		clear();
		message(errorMessage);
	}
	// methods
	void Error::clear() { delete[] m_message; m_message = nullptr; }
	bool Error::isClear() const {
		if (m_message == nullptr) {
			return true;
		}
		else
			return false;
	}
	void Error::message(const char* value) {
		clear();
		m_message = new char[strlen(value) + 1];
		strcpy(m_message, value);
	}
	// cast overloads
	Error::operator const char* () const {
		//std::cout << m_message; 
		return m_message;  
	}
	void Error::spitout() {
		//std::cout << m_message; 
		std::cout << m_message << std::endl;
	}
	Error::operator bool () const { return m_message == nullptr; }

// operator << overload prototype for cout
	std::ostream& ict::operator<<(std::ostream& ostr, const Error& em) {
		if (em.isClear()) {
			return ostr;
		}
		else {
			ostr << static_cast<const char*>(em);
			return ostr;
		}
	}
};