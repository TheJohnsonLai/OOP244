#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "Error.h"

namespace ict {
	char Perishable::signature()const {
		return 'P';
	}
	
	Perishable::Perishable() {
		m_expiry.dateOnly(true);
	}

	void Perishable::spititout() {
		NonPerishable::spititout();
	}

	std::fstream& Perishable::save(std::fstream& file)const {
		NonPerishable::save(file);
		file << ',' << m_expiry;
		return file;
	}
	std::fstream& Perishable::load(std::fstream& file) {

		NonPerishable::load(file);
		file.ignore();
		file >> m_expiry;
		return file;
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear)const {
		NonPerishable::write(os, linear);
		if (ok() && linear == false) {
			os << "Expiry date: " << m_expiry << std::endl;
		}
		return os;
	}
	std::istream& Perishable::read(std::istream& is) {
		std::cout << "Perishable ";
		NonPerishable::read(is);
		//Date TempDate;
		if (ok()) {
			std::cout << "Expiry date (YYYY/MM/DD): ";
			is >> m_expiry;
			//std::cout << TempDate.errCode() << std::endl;
			if (m_expiry.bad()) {
				if (m_expiry.errCode() == CIN_FAILED) {
					error("Invalid Date Entry");
				}
				else if (m_expiry.errCode() == YEAR_ERROR) {
					error("Invalid Year in Date Entry");
				}
				else if (m_expiry.errCode() == MON_ERROR) {
					error("Invalid Month in Date Entry");
				}
				else if (m_expiry.errCode() == DAY_ERROR) {
					error("Invalid Day in Date Entry");
				}
				//is.setstate(std::ios::failbit);
			}
			else {
				//m_expiry = TempDate;
			}
		}else if (is.fail()) {
			//error("Invalid Input!!!");
		}
		//std::cin.ignore(1000, '\n');
		return is;
	}

}

