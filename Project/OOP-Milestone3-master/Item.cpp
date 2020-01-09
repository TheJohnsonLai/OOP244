#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <iostream>
#include <cstring>

// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"
#include "PosIO.h"

using namespace std;
namespace ict{
  // class Item implementaion

	Item::Item() {
		m_sku[0] = 0;
		m_name = 0;
		m_price = 0;
		m_taxed = 0;
		m_quantity = 0;
	}

	Item::Item(const char* iSKU, const char* iNAME, double iPRICE, bool iTAX) {
		sku(iSKU);
		name(iNAME);
		price(iPRICE);
		taxed(iTAX);
	}

	//Copy Constructor
	Item::Item(const Item& refer) {
		sku(refer.m_sku);
		name(refer.m_name);
		price(refer.m_price);
		taxed(refer.m_taxed);
		quantity(refer.m_quantity);
	}

	//Operator=
	Item& Item::operator=(const Item& other) {
		if (this != &other) {
			sku(other.m_sku);
			name(other.m_name);
			price(other.m_price);
			taxed(other.m_taxed);
			quantity(other.m_quantity);
		}
		return *this;
	}

	// Setters
	void Item::sku(const char* sku) {
		strncpy(m_sku, sku, MAX_SKU_LEN);
	}

	void Item::name(const char* name) {
		m_name = new (std::nothrow) char[strlen(name) + 1];
		if (m_name != nullptr) {
			strncpy(m_name, name, strlen(name) + 1);
		}
	}

	void Item::price(double price) {
		m_price = price;
	}

	void Item::taxed(bool taxed) {
		m_taxed = taxed;
	}

	void Item::quantity(int quantity) {
		m_quantity = quantity;
	}

	// Getters
	const char* Item::sku() const {
		return m_sku;
	}

	char* Item::name() const {
		return m_name;
	}

	double Item::price() const {
		return m_price;
	}

	bool Item::taxed() const {
		return m_taxed;
	}

	int Item::quantity() const {
		return m_quantity;
	}

	double Item::cost() const {
		double cost = m_price;
		if (m_taxed) {
			cost *= TAX + 1;
		}
		return cost;
	}

	bool Item::isEmpty() const {
		if (m_sku[0] == 0 && m_price == 0 && m_quantity == 0) {
			return true;
		}
		else return false;
	}

	// Member operator overloads
	bool Item::operator==(const char* sku) {
		return strcmp(m_sku, sku) == 0;
	}

	int Item::operator+=(int qty) {
		return m_quantity += qty;
	}

	int Item::operator-=(int qty) {
		return m_quantity -= qty;
	}

	Item::~Item() {
		if (m_name != nullptr) {
			delete m_name;
		}
	}

	// Non-member operator overloads
	double operator+=(double &other, const ict::Item& CS) {
		other += CS.cost() * CS.quantity();
		return other;
	}
	// NOn-member IO operator overloads
	std::ostream& operator<<(std::ostream& ostr, const ict::Item& Read) {
		return Read.write(ostr, true);
	}

	std::istream& operator >> (std::istream& istr, ict::Item& Write) {
		return Write.read(istr);
	}
}