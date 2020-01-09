#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict{
	
  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  void Date::errCode(int errCode)
  {
	  m_readErrorCode = errCode;
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }

  void Date::set() {
	  time_t t = time(NULL);
	  tm lt = *localtime(&t);
	  m_day = lt.tm_mday;
	  m_mon = lt.tm_mon + 1;
	  m_year = lt.tm_year + 1900;
	  if (dateOnly()) {
		  m_hour = m_min = 0;
	  }
	  else {
		  m_hour = lt.tm_hour;
		  m_min = lt.tm_min;
	  }
  }
  
  void Date::set(int year, int mon, int day, int hour, int min) {
	   m_year = year;
	   m_mon = mon;
	   m_day = day;
	   m_hour = hour;
	   m_min = min;
	   m_readErrorCode = NO_ERROR;
  }
  // CONSTRUCTORS
  Date::Date() {
	  m_dateOnly = false;
	  set();
  }
  Date::Date(int year, int mon, int day) {
	  m_dateOnly = true;
	  m_year = year;
	  m_mon = mon;
	  m_day = day;
	  m_hour = 0;
	  m_min = 0;
	  m_readErrorCode = NO_ERROR;
  }
  Date::Date(int year, int mon, int day, int hour, int min) {
	  m_dateOnly = false;
	  set(year, mon, day, hour, min);
  }

  // operator ovERloads
  bool Date::operator==(const Date &D) const { return this->value() == D.value(); }
  bool Date::operator!=(const Date &D) const { return this->value() != D.value(); }
  bool Date::operator<(const Date &D) const { return this->value() < D.value(); }
  bool Date::operator>(const Date &D) const { return this->value() > D.value(); }
  bool Date::operator<=(const Date &D) const { return this->value() <= D.value(); }
  bool Date::operator>=(const Date &D) const { return this->value() >= D.value(); }

  // methods
  int Date::errCode()const {	return m_readErrorCode;  }
  bool Date::bad()const { return m_readErrorCode != 0;  }
  bool Date::dateOnly()const { return m_dateOnly;  }
  void Date::dateOnly(bool value) {
	m_dateOnly = value;
	if (value) {
		m_hour = 0;
		m_min = 0;
	}
  }

  //int mdays()const {}
  // istream  and ostream read and write methods
  std::istream& Date::read(std::istream& is) {

	  errCode(NO_ERROR);
	  is >> m_year;
	  if (is.get() != '/') {
		  errCode(CIN_FAILED);
		  //is.setstate(std::ios::failbit);
		  return is;
	  }
	  is >> m_mon;
	  if (is.get() != '/') {
		  errCode(CIN_FAILED);
		  //is.setstate(std::ios::failbit);
		  return is;
	  }
	  is >> m_day;

	  if (m_dateOnly == true) {

	  }
	  else {
		  is.ignore(2);
		  is >> m_hour;
		  is.ignore(1);
		  is >> m_min;
	  }
		  if (m_year < MIN_YEAR || m_year > MAX_YEAR) {
			  errCode(YEAR_ERROR);
			 // is.setstate(std::ios::failbit);
		  }
		  else if (m_mon < 1 || m_mon > 12) {
			  errCode(MON_ERROR);
			 // is.setstate(std::ios::failbit);
		  }
		  else if (m_day <= 0 || mdays() <= m_day || ((m_day == 29 && (m_year % 4) != 0) && m_mon == 2)) {
			  errCode(DAY_ERROR);
			 // is.setstate(std::ios::failbit);
		  }else if (m_dateOnly == false){
			  if(m_hour < 1 || m_hour > 24) {
				 errCode(HOUR_ERROR);
				//is.setstate(std::ios::failbit);
			 }
			  else if (m_min < 0 || m_min > 59) {
				  errCode(MIN_ERROR);
				//  is.setstate(std::ios::failbit);
			  }
		  }
		  //std::cout << "TALY HO" << m_year << '/' << m_mon << '/' << m_day << "__FAILED?>>> " << m_readErrorCode << std::endl;
	  return is;
  }

  std::ostream& Date::write(std::ostream& ostr)const {
	  ostr << m_year << "/";
	  if (m_mon < 10) {
		  ostr << "0";
	  }
	  ostr << m_mon << "/";
	  if (m_day < 10) {
		  ostr << "0";
	  }
	  ostr << m_day;
	  //ostr << m_year << "/" << m_mon << "/" << m_day;

	  if (m_dateOnly) {
	  }
	  else {
		  ostr << ", " << m_hour << ":" << m_min;
	  }
	  return ostr;
   }


  // operator<< and >> overload prototypes for cout and cin
  std::istream& operator >> (std::istream& istr, Date& D) { return D.read(istr); }
  std::ostream& operator<<(std::ostream& ostr, const Date& D) { return D.write(ostr); }

}
