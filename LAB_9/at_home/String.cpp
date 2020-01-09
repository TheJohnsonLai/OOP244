#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict{
    
    
    //////////////////////////////////////////////////////
    //
    // Default Constructor
    // String::String(int capacity);
    //
    // initialize the string with an internal buffer capacity of 
    // "capacity." 
    // default capacity is 1 (minimum needed for an empty string)
    //
    // 
    String::String(int capacity){
		m_capacity = capacity;
		m_pString = new char[capacity];
		m_pString[0] = '\0';
    }

    //////////////////////////////////////////////////////
    //
    // String::String(const char* p, int capacity);
    //
    // Construct a String from a char array
    // Should initialize the internal buffer to at least 
    // the length of the string need to hold pSource, 
    // or capacity, whichever is greater.
    //
    // 
    String::String(const char* pSource, int capacity){
		int aa = 0;
		if ((int)strlen(pSource) >= capacity) {
			aa = (int)strlen(pSource);
		}
		else {
			aa = capacity;
		}
		/*
		m_pString = new char[aa];
		for (int i = 0; i < (int)strlen(pSource); i++) {
			m_pString[i] = pSource[i];
		}
		m_pString[aa - 1] = '\0'; */
		m_pString = new char[aa + 1];
		strcpy(m_pString, pSource);
        
    }

    //////////////////////////////////////////////////////
    //
    // String::String(const String &s, int capacity);
    //
    // Copy constructor
    //
    // Construct a String from another String
    //
    // 
    String::String(const String& other) 
    {
		m_capacity = other.m_capacity;
		m_pString = new char[strlen(other) + 1];
		strcpy(m_pString, (const char*)other);
    }

    
    
    //////////////////////////////////////////////////////
    //
    // String::resize(int newsize)
    //
    // resize the internal buffer to the value given
    // do NOT shrink the string buffer smaller than 
    // that needed to hold the existing string!
    // (length + 1);
    //    
    void String::resize(int newsize)
    {
		if (newsize < (int)strlen(m_pString) + 1) {
			m_capacity = (int)strlen(m_pString) + 1;
		}
		else {
			m_capacity = newsize;
		}
    }

	int String::capacity() { 
		return m_capacity; 
	}

  
    //////////////////////////////////////////////////////
    //
    // String::operator=(const String& other)
    // 
    // Assignment operator
    // copy string "other" to this object
    //   
    // 
    String& String::operator=(const String& other)
    {
		if (this != &other)
		{
			delete[] m_pString;
			m_pString = nullptr;
			m_capacity = 0;
			m_capacity = other.m_capacity;
			m_pString = new char[strlen(other) + 1];
			strcpy(m_pString, other.m_pString);
			return *this;
		}
		return *this;    
    }


    //////////////////////////////////////////////////////
    //
    // String::~String
    // 
    // destructor
    // 
    // clean up the internal string buffer  
    // 
    String::~String()
    {
		delete[] m_pString;
		m_pString = nullptr;
		m_capacity = 0;
    }

    //////////////////////////////////////////////////////
    //
    // String::length()
    // 
    // return the length of the string
    // 
    // 
    int String::length() const
    {
		return (int)strlen(m_pString);
    }


    //////////////////////////////////////////////////////
    //
    // String::operator const char*() const
    // 
    // convert the String to a char*
    // 
    // 
    String::operator const char *() const
    {
		return m_pString;
    }


    //////////////////////////////////////////////////////
    //
    // String::empty()
    // 
    // 
    // returns true if the string is empty
    // i.e. either the first char is \0, or 
    // length is 0.
    bool String::empty() const
    {
		return(strlen(m_pString) == 0);
    }
    
    //////////////////////////////////////////////////////
    //
    // String::operator bool()
    // 
    // same as empty(), just wrapped in an operator
    // 
    //     
    String::operator bool() const
    {
		return (m_pString[0] != 0);
    }
     
     
    //////////////////////////////////////////////////////
    //
    // String::operator==(const String& s2) const
    // 
    // returns true if *this == s2.
    // You can use the strcmp function to check if 
    // two strings are equal, or write your own
    // treating the string as a char-array
    //      
    bool String::operator==(const String& s2) const
    {
		if (strcmp(m_pString, s2.m_pString) == 0) {
			return true;
		}
		else
			return false;
    }
    
    
    //////////////////////////////////////////////////////
    //
    // String::operator+=(const String& s2)
    // 
    // Concatenates s2 to the end of *this
    //
    // implements *this = (*this + s2)
    // return *this
    // 
    // 
    String& String::operator+=(const String& s2)
    {
		char* oldboi = new char[strlen(m_pString) + strlen(s2) + 1];
		strcpy(oldboi, this->m_pString);

		delete[] m_pString;
		m_pString = nullptr;
		m_capacity = 0;

		m_pString = new char[strlen(oldboi)];
		strcat(oldboi, (const char*)s2);
		strcpy(m_pString, oldboi);

		delete[] oldboi;
		oldboi = nullptr;
		return *this;
    }
    
    
    
    //////////////////////////////////////////////////////
    //
    // String::operator+(const String& s2) const
    // 
    // implements the operator (*this + s2)
    // returns the expression
    // DOES NOT MODIFY *this
    // 
    // 
    String String::operator+(const String& s2) const
    {
		//std::cout << "1. " << m_pString << endl;
		String s;
		s.m_pString = new char [((int)strlen(m_pString) + (int)strlen(s2.m_pString) + 1)];
		//s.m_pString = new char[strlen(m_pString) + strlen(s2.m_pString) + 1];
		strcpy(s.m_pString, m_pString);
		strcat(s.m_pString, (const char*)s2);
		//std::cout << "2. " << s.m_pString << " -- 3. "<< s2.m_pString << s.length() <<endl;
		return (String)s;
    }
    
    //////////////////////////////////////////////////////
    //
    // String::operator+=(char c)

    // 
    // Adds a single char c to the end of the string in *this
    // Grows the string buffer if necessary.
    //  
    String& String::operator+= (char c)
    {
		char Catt[2];
		Catt[0] = c;
		Catt[1] = '\0';

		char* Oldboi = new char[strlen(m_pString) + strlen(Catt) + 1];
		strcpy(Oldboi, m_pString);

		delete[] m_pString;
		m_pString = nullptr;
		m_capacity = 0;

		m_pString = new char[strlen(Oldboi)];
		strcat(Oldboi, Catt);
		strcpy(m_pString, Oldboi);
		delete[] Oldboi;
		Oldboi = nullptr;

		//std::cout << "1. " << m_pString << ":W: "<< endl;
		return *this;
    }
    

    
    //////////////////////////////////////////////////////
    //
    // String::substr
    // 
    // Returns a substring of the current string. In case of error
    // return an empty String() object instead.
    // 
    // return the string slice starting at index, at most len characters
    // 
    // both index and len have to lie inside the string. If they do not, then 
    // that is an error
    // 
    String String::substr(int index, int len) const
    {
		if (index > (int)strlen(m_pString) || len > (int)strlen(m_pString) || index + len > (int)strlen(m_pString)) {
			return String();
		}
		else {
			char* Hasbeen = new char[len + 1];
			for (int i = 0; i < len; i++) {
				Hasbeen[i] = m_pString[index + i];
			}
			Hasbeen[len] = '\0';
			String HB(Hasbeen);
			return HB;
		}
    }

    //////////////////////////////////////////////////////
    //
    // operator<<
    // 
    // Print the string to the output stream
    // 
    // clean up the internal string buffer  
    // 
    std::ostream& operator<<(std::ostream& ostream, const String &s)
    {
		ostream << (const char*)s;
		return ostream;  
    }

    //////////////////////////////////////////////////////
    //
    // operator>>
    // 
    // Input a string from an input stream into the String s
    // 
    // Note: the input can be ANY length in character. You will need to 
    // read it one char at a time. 
    // 
    std::istream& operator>>(std::istream& istream, String &s)
    {
		char text[100];
		cin.get(text, 100);
		s = text;
		/* s = "";
		char tempC = 0;
		do
		{
		tempC = istream.get();
		if (tempC != '\n')
		{
		s += tempC;
		}
		else
		break;
		} while(1); */
		return istream;
    }

  
}
