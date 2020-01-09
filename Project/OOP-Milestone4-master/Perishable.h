#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__

#include <iostream>
#include "Date.h"
#include "NonPerishable.h"

namespace ict {

	class Perishable : public ict::NonPerishable {
	private: 
		ict::Date m_expiry;
	protected:
		char signature()const;
	public:
		Perishable();
		std::fstream& save(std::fstream& file)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& is);

	};

}

#endif
