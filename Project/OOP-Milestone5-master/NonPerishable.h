#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__

#include <iostream>
#include "Item.h"
#include "Error.h"


namespace ict {
	class NonPerishable : public ict::Item {

	private:
		ict::Error m_err;

	protected:
		bool ok() const;
		void error(const char* message);
		virtual char signature()const;
	public:
		void spititout();
		std::fstream& save(std::fstream& file)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& ostr, bool linear)const;
		std::istream& read(std::istream& is);

	};

}




#endif