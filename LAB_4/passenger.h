//TODO: add header guards here
#ifndef passenger_h
#define passenger_h
// !passenger_h

// TODO: holiday namespace here
namespace holiday {

	// TODO: declare the class Passenger here
	class Passenger {
	public :
		Passenger();
		Passenger(char sName[], char sDestination[]);

		// TODO: add the class the attributes,
		private :
			char m_name[32];
			char m_destination[32];
			int m_departure, m_departureMonth, m_departureDay;
		//       the member function already provided,
		public : 
			void display(bool nameOnly) const;
		//       and the member functions that you must implement
			bool canTravelWith(const Passenger& secondP) const;
			bool isEmpty() const;
	};

}
#endif 