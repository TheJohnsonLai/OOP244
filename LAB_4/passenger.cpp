// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "passenger.h"

// TODO: add the namespaces that you will be using here
using namespace std;

// TODO: holiday namespace here
namespace holiday {
	// TODO: add the default constructor here
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_departure = 0;
		m_departureMonth = 0;
		m_departureDay = 0;
	};

	// TODO: add the constructor with 2 parameters here
	Passenger::Passenger(char sName[32], char sDestination[32]) {
		//if (sName != "" && Name[0] != '\0' && sDestination != "" && sDestination[0] != '\0') {
		if (sName == NULL || sDestination == NULL || *sName == '\0' || *sDestination == '\0') {
			m_name[0] = '\0';
			m_destination[0] = '\0';
			m_departure = 0;
			m_departureMonth = 0;
			m_departureDay = 0;
		}
		else {
			strcpy(m_name, sName);
			strcpy(m_destination, sDestination);
			m_departure = 2017;
			m_departureMonth = 7;
			m_departureDay = 1;
		}
	};

	// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger& secondP) const {
		if (strcmp (m_destination, secondP.m_destination) == 0  &&
			m_departure == secondP.m_departure &&
			m_departureMonth == secondP.m_departureMonth &&
			m_departureDay == secondP.m_departureDay) {
			return true;
		}
		else {
			return false;
		}
	};

	// TODO: add the isEmpty() function here
	bool Passenger::isEmpty() const {
		if (m_name[0] == '\0' &&
			m_destination[0] == '\0' &&
			m_departure == 0 &&
			m_departureMonth == 0 &&
			m_departureDay == 0) {
			return true;
		}
		else {
			return false;
		}
	};

	// below is the member function already provided
	// TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly = false) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
					<< "The journey will start on "
					<< this->m_departure << "-"
					<< this->m_departureMonth << "-"
					<< this->m_departureDay
					<< "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}
	};
}
