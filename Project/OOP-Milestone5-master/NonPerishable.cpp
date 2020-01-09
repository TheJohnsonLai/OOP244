#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "NonPerishable.h"



namespace ict {
	// Protected Functions
	bool NonPerishable::ok() const {
		if (m_err.isClear()) {
			return true;
		}
		else
			return false;
	}
	void NonPerishable::error(const char* message) {
		m_err = message;
	}
	char NonPerishable::signature()const {
		return 'N';
	}

	// Public Functions

	void NonPerishable::spititout() {
		m_err.spitout();
	}

	std::fstream& NonPerishable::save(std::fstream& file)const {
		file << signature() << ',';
		file << sku() << ',';
		file << name() << ',';
		file << price() << ',';
		file << taxed() << ',';
		file << quantity();
		return file;
	}
	std::fstream& NonPerishable::load(std::fstream& file) {
		char D_SKU[MAX_SKU_LEN];
		char D_NAME[20];
		double D_PRICE;
		bool D_TAXED;
		int D_QUANTITY;

		file.getline(D_SKU,MAX_SKU_LEN, ',');
		file.getline(D_NAME,20,',');
		file >> D_PRICE;
		file.ignore();
		file >> D_TAXED;
		file.ignore();
		file >> D_QUANTITY;
		//file.ignore();

		sku(D_SKU);
		name(D_NAME);
		price(D_PRICE);
		if (D_TAXED)
			taxed(true);
		else
			taxed(false);
		quantity(D_QUANTITY);

		return file;
	}
	std::ostream& NonPerishable::write(std::ostream& ostr, bool linear)const {
		if (ok()) {
			if (linear) {
				ostr << std::setfill(' ') << std::left << std::setw(MAX_SKU_LEN) << sku() << '|';
				ostr << std::setw(20) << name() << '|';
				ostr << std::right << std::setw(7) << std::fixed << std::showpoint << std::setprecision(2) << price() << '|';
				if (taxed() == false) {
					ostr << "  " << signature() << "|";
				}
				else {
					ostr << " T" << signature() << "|";
				}
				ostr << std::setw(4) << quantity() << '|';
				ostr << std::right << std::setw(9) << std::fixed << std::showpoint << std::setprecision(2) << cost() * quantity() << '|';
			}
			else {
				ostr << "Name:" << std::endl << name() << std::endl;
				ostr << "Sku: " << sku() << std::endl;
				ostr << "Price: " << price() << std::endl;
				if (taxed()) {
					ostr << std::setprecision(2) <<"Price after tax: " << ((1 + TAX) * price());
				}
				else {
					ostr << "Price after tax: N/A";
				}
				ostr << std::endl;
				ostr << "Quantity: " << quantity() << std::endl;
				ostr << "Total Cost: " << cost()*quantity() << std::endl;
			}
		}
		else {
			ostr << (const char*)m_err;
		}

		return ostr;
	}
	std::istream& NonPerishable::read(std::istream& is) {
		char D_SKU[MAX_SKU_LEN];
		char D_NAME[20];
		double D_PRICE;
		char D_TAX;
		int D_QUANTITY;

		if (is.fail() == false) {

			m_err.clear();
			std::cout << "Item Entry:" << std::endl;
			std::cout << "Sku:";
			is >> D_SKU;
			if (is.fail() == false) {
				sku(D_SKU);
			}
			else {
			}

			std::cout << "Name: " << std::endl;
			is >> D_NAME;
			if (is.fail() == false) {
				name(D_NAME);
			}

			std::cout << "Price: ";
			is >> D_PRICE;
			if (is.fail()) {
				m_err.message("Invalid Price Entry");
			}
			else {
				price(D_PRICE);
			}

			if (m_err.isClear()) {
				std::cout << "Taxed: ";
				is >> D_TAX;
				if (D_TAX == 'Y' || D_TAX == 'y') {
					taxed(true);
				}
				else if (D_TAX == 'N' || D_TAX == 'n') {
					taxed(false);
				}
				else {
					m_err.message("Invalid Taxed Entry, (y)es or (n)o");
					is.setstate(std::ios::failbit);
				}
			}

			if (m_err.isClear()) {
				std::cout << "Quantity: ";
				is >> D_QUANTITY;
				if (is.fail()) {
					m_err.message("Invalid Quantity Entry");
				}
				else {
					quantity(D_QUANTITY);
				}
			}
			else {
			}
		}
		//std::cin.ignore(1000,'\n');
		return is;
	}
}