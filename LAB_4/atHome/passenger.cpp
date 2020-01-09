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
	Passenger::Passenger(const char sName[32], const  char sDestination[32]) {
		//if (sName != "" && Name[0] != '\0' && sDestination != "" && sDestination[0] != '\0') {
		if (sName == NULL || sDestination == NULL || *sName == '\0' || *sDestination == '\0') {
			Passenger();
		}
		else {
			strcpy(m_name, sName);
			strcpy(m_destination, sDestination);
			m_departure = 2017;
			m_departureMonth = 7;
			m_departureDay = 1;
		}
	};


	Passenger::Passenger(const char sName[], const  char sDestination[], int sY, int sM, int sD) {
		if (sName == NULL || sDestination == NULL || *sName == '\0' || *sDestination == '\0' ||
			sY < 2017 || sY > 2020 || sM < 1 || sM > 12 || sD < 1 || sD > 31) {
			Passenger();
		}
		else {
			strcpy(m_name, sName);
			strcpy(m_destination, sDestination);
			m_departure = sY;
			m_departureMonth = sM;
			m_departureDay = sD;
		}	
	};

	// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger& secondP) const {
		if (strcmp(m_destination, secondP.m_destination) == 0 &&
			m_departure == secondP.m_departure &&
			m_departureMonth == secondP.m_departureMonth &&
			m_departureDay == secondP.m_departureDay) {
			return true;
		}
		else {
			return false;
		}
	};

	// Can Travel with array of passengers? 
	void Passenger::travelWith(const Passenger* arrPassengers, int size) {
		int iCanTravelWith = 0;
		for (int i = 0; i < size; i++) {
			if (strcmp(m_destination, arrPassengers[i].m_destination) == 0 &&
				m_departure == arrPassengers[i].m_departure &&
				m_departureMonth == arrPassengers[i].m_departureMonth &&
				m_departureDay == arrPassengers[i].m_departureDay) {
				iCanTravelWith++ ;
			}
		}
		if (iCanTravelWith <= 0) {
			cout << "Nobody can join " << m_name << " on vacation!" << endl;
		}
		else if (iCanTravelWith == size) {
			cout << "Everybody can join " << m_name << " on vacation!" << endl;
			cout << m_name << " will be accompanied by ";
			for (int i = 0; i < size; i++) {
				if (i < (size - 1)) {
					cout << arrPassengers[i].m_name << ", ";
				}
				else {
					cout << arrPassengers[i].m_name << "." << endl;
				}
			}
		}
		else {
			cout << m_name << " will be accompanied by ";
			for (int i = 0; i < size; i++) {
				if (strcmp(m_destination, arrPassengers[i].m_destination) == 0 &&
					m_departure == arrPassengers[i].m_departure &&
					m_departureMonth == arrPassengers[i].m_departureMonth &&
					m_departureDay == arrPassengers[i].m_departureDay) {
						if (i < (size - 1)) {
							cout << arrPassengers[i].m_name << ", ";
						}
						else {
							cout << arrPassengers[i].m_name << "." << endl;
						}
				}
			}
		}
	};

	// TODO: add the isEmpty() function here
	bool Passenger::isEmpty() const {
		//if (m_name == NULL || m_name == '\0' || m_destination == NULL || m_departure != 0 || m_departureMonth != 0 || m_departureDay != 0) {
		if(m_name == NULL || m_name == NULL || m_destination == '\0' || m_destination == '\0' ||
			m_departure < 2017 || m_departure > 2020 || m_departureMonth < 1 || m_departureMonth > 12 || m_departureDay < 1 || m_departureDay > 31){
			return true;
		}
		else {
			return false;
		}
/*		if (m_name[0] == '\0' &&
			m_destination[0] == '\0' &&
			m_departure == 0 &&
			m_departureMonth == 0 &&
			m_departureDay == 0) {
			return true;
		}
		else {
			return false;
		} */
	};

	// below is the member function already provided
	// TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly) const
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
