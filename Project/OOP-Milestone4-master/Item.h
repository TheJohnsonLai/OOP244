#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include "PosIO.h"
#include "POS.h"
#include "Error.h"

namespace ict{
  // class Item
	class Item : public PosIO {
	private: 
		char m_sku[MAX_SKU_LEN + 1];
		char* m_name;
		double m_price;
		bool m_taxed;
		int m_quantity;
	public:
		Item();
		Item(const char* iSKU, const char* iNAME, double iPRICE, bool iTAX = true);
		Item(const Item&);

		// virtual destructor
		~Item();
		// setters
		void sku(const char*);
		void name(const char*);
		void price(double);
		void taxed(bool);
		void quantity(int);
		// getters
		const char* sku() const;
		char* name() const;
		double price() const;
		bool taxed() const;
		int quantity() const;
		double cost() const;
		bool isEmpty() const;
		// operators
		Item& operator=(const Item&);
		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int);


	};
  // end class Item
  // operator += 
  double operator+=(double& d, const ict::Item& CS);
  // operator << and operator >>
  std::ostream& operator<<(std::ostream& ostr, const ict::Item& Read);
  std::istream& operator >> (std::istream& istr, ict::Item& Write);
}


#endif