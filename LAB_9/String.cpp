#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict{
    
    
    //////////////////////////////////////////////////////
    //
    // Default Constructor
    // String::String();
    //
    // initialize the string to ""
    //
    // 
    String::String(){
       // initialize the string to ""
		m_pString = new char[1];
		m_pString[0] = '\0';
		//for (int i = 0; i < STRING_BUFFERSIZE; i++) {
		//	m_pString[i] = '\0';
		//}
		//m_pString[STRING_BUFFERSIZE] = '\0';
    }


    //////////////////////////////////////////////////////
    //
    // String::String(const char* p);
    //
    // Construct a String from a char array
    // You may assume the input string pSource 
    // has a length of < 50, and the internal buffer has enough
    // space to hold it.
    //
    // 
    String::String(const char* pSource){
		m_pString = new char[strlen(pSource) + 1]
		//for (int i = 0; i < STRING_BUFFERSIZE; i++) {
		//	m_pString[i] = pSource[i];
		//}
		//m_pString[STRING_BUFFERSIZE] = '\0';

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
		~String();
		m_capacity = other.m_capacity
		m_pString = new char[strlen(other) + 1];
		strcpy(m_pString, other.m_pString);  
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
		~String();
		m_capacity = other.m_capacity
		m_pString = new char[strlen(other) + 1];
		strcpy(m_pString, other.m_pString);
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
		if (strlen(m_pString) == 0) {
			return true;
		}
		else {
			return false;
		}
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
		return (m_pString[0]);
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
		}else
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
		char* oldboi = new char[strlen(m_pString) + strlen(s2) + 1]
		strcpy(oldboi, this->m_pString);
		~String();

		m_pString = new char[strlen(oldboi)]
		strcat(oldboi, (const char*)s2);
		strcpy (m_pString, oldboi);

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
		//String db2 (*this.m_pString);
		//return db2+s2;
		String db2;
		db2.m_pString = new char[strlen(m_pString) + strlen(s2.m_pString) + 1]
		strcpy(db2.m_pString, m_pString);
		strcat(db2.m_pString, s2.m_pString);
		return db2;
    }
      
    //////////////////////////////////////////////////////
    //
    // String::operator+=(char c)
    // 
    // Adds a single char c to the end of the string in *this
    // 
    //        
    String& String::operator+= (char c)
    {
		//m_pString[strlen(m_pString) + 0] = c;
		//m_pString[strlen(m_pString) + 1] = '\0';
		//std::cout << strlen(m_pString) << std::endl;
		char Catt[2];
		Catt[0] = c;
		Catt[1] = '\0';

		char* Oldboi = new char[strlen(m_pString) + strlen(Catt) + 1];
		strcpy(Oldboi, m_pString);
		~String();

		m_pString = new char[strlen(Oldboi)];
		strcat(Oldboi, Catt);
		strcpy(m_pString, Oldboi);
		delete[] Oldboi;
		Oldboi = nullptr;

		return *this;

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
		ostream << (const char*)s << flush;
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
		cin.get(text,100);
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
