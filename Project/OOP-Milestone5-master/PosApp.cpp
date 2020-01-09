#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <fstream>
#include "PosApp.h"
#include <sstream>
#include <cstring>

using namespace std;

namespace ict {

	// Constructor
	PosApp::PosApp(const char* filename, const char* billfname) {
		strcpy(m_filename, filename);
		strcpy(m_billfname, billfname);
		loadRecs();
		//m_noOfItems = 0;
	}

	// Private Functions
	int PosApp::menu() {
		int selectedOneSix;
		int max = 6;
		int min = 0;

		// DEBUGGING
		//cout << "Stats: m_noOfItems: " << m_noOfItems << endl;
		//cout << "File Name: " << m_filename << endl;
		// DEBUGGING
		std::cout << "The Sene-Store" << std::endl;
		std::cout << "1- List items" << std::endl;
		std::cout << "2- Add Perishable item" << std::endl;
		std::cout << "3- Add Non-Perishable item" << std::endl;
		std::cout << "4- Update item quantity" << std::endl;
		std::cout << "5- Show Item" << std::endl;
		std::cout << "6- POS" << std::endl;
		std::cout << "0- exit program" << std::endl;
		std::cout << "> ";

		std::cin >> selectedOneSix;

		if (!std::cin) {
			selectedOneSix = -1;
		}
		else if(selectedOneSix < min || selectedOneSix > max) {
			selectedOneSix = -1;
		}

		std::cin.clear(); // clear error bit
		std::cin.ignore(1000, '\n'); // clear 1000 char or until newline

		return selectedOneSix;
	}

	void PosApp::deallocateItems() {
		for (int i = 0; i < m_noOfItems; i++) { // As specified by pdf
			delete m_items[i];
		}
		m_noOfItems = 0;
	}


	void PosApp::loadRecs() {
		deallocateItems();
		//int count = 0;
		char PerOrNot = 'n';
		//string test;
		//int ALIVE;

		std::fstream LOADFILE(m_filename, ios::in);
		//cout << "LOAD IN" << endl;

		if (!LOADFILE.is_open()) {
			//m_noOfItems = 0;
		//	cout << "FILE EXISTS BUT FAIL" << endl;
			//LOADFILE >> ALIVE;//TEST
			/////while (LOADFILE.fail()) { // EOF FAILS, CONTINUES PAST FAIL
				LOADFILE.clear();
				LOADFILE.close();
				std::fstream MAKEFILE(m_filename, ios::out); // ios::out
															 // Empty Function
				MAKEFILE.close();
				//cout << "LOADED FAILED" << endl;
			////}
		}
		else {
			while (LOADFILE.good()) {
				//cout << "FILE EXIST< LOADING" << endl;
				PerOrNot = 'N';
				LOADFILE >> PerOrNot;
				if (LOADFILE.good()) {
					//cout << PerOrNot << endl;
					if (PerOrNot == 'P' || PerOrNot == 'p') {
						m_items[m_noOfItems] = new Perishable();						  //m_noOfItems++;
					}
					else if (PerOrNot == 'N' || PerOrNot == 'n') {
						m_items[m_noOfItems] = new NonPerishable();				  //m_noOfItems++;
					}
					else {
						//break;
					}
					if (PerOrNot == 'P' || PerOrNot == 'p' || PerOrNot == 'N' || PerOrNot == 'n') {
						LOADFILE.ignore();
						m_items[m_noOfItems]->load(LOADFILE); // load virtual function, ptd by ptr item
						m_noOfItems++;
						//cout << "ITEM LOADED! " << m_items[m_noOfItems-1]->name() << endl;
						//LOADFILE.ignore();
					}
					//cout << "LOADING:: " << m_items[m_noOfItems - 1]->name() << ">><>" << endl;
					//cout << "Passed" << endl;
				}
			}
			LOADFILE.close();
		}
		//cout << "MNOOFITEMS!!!!!!! ---- " << m_noOfItems << endl;
	}
	void PosApp::saveRecs() {

		std::fstream SAVEFILE(m_filename, ios::out);
		for (int i = 0; i < m_noOfItems; i++) {
			if (m_items[i]->quantity() > 0) { // Getter Quantity
				m_items[i]->save(SAVEFILE);
				//cout << "SAVED" << endl;
			}
		}
		SAVEFILE.close();

		loadRecs(); // Call Load
	}
	int PosApp::searchItems(const char* sku) const{
		int index = -1;
		for (int i = 0; i < m_noOfItems; i++) {
			if (*m_items[i] == sku) { // * to denote object original (C++ can ..)
				index = i;
			}
		}
		return index;
	}
	void PosApp::updateQty() {
		char sku[MAX_SKU_LEN];
		int itemsPurchased;

		loadRecs(); // BASE

		cout << "Please enter the SKU: ";
		cin >> sku;

		int ArrayValue = searchItems(sku);

		if (ArrayValue == -1) {
			cout << "Not found!" << endl;
			cout << endl;
		}
		else {
			m_items[ArrayValue]->write(cout, false);
			cout << "Please enter the number of purchased items: ";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> itemsPurchased;
			m_items[ArrayValue]->quantity(m_items[ArrayValue]->quantity() + itemsPurchased); // Increase Quantity of item
			saveRecs();
			cout << "Updated!" << endl;
			cout << endl;
		}

	}
	void PosApp::addItem(bool isPerishable) {
		bool addSuccess = false;
		//Item& tempItem();
		Item* tempItem[1];

		//temp = isPerishable ? Perishable : NonPerishable;
		tempItem[0] = isPerishable ? new Perishable : new NonPerishable;

		//m_items[m_noOfItems]->read(cin); // load virtual function, ptd by ptr item
		//cout << "READ" << endl;
		tempItem[0]->read(cin);
		if (cin.fail()) {
			std::cin.clear(); // clear error bit
			std::cin.ignore(1000, '\n'); // clear 1000 char or until newline
			//cout << "Failed" << endl;
			tempItem[0]->spititout();
			cout << endl;
		}
		else {
			addSuccess = true;
		}

		if (addSuccess) {
			//m_items[m_noOfItems]->read(cin);
			m_items[m_noOfItems] = tempItem[0];
			m_noOfItems += 1;

			// DEBUGGING
			//cout << "m_noOfITems:: " << m_noOfItems << endl;
			// DEBUGGING
			saveRecs();
			cout << "Item added." << endl;
			cout << endl;
		}
	}
	void PosApp::listItems()const {
		double TOTAL = 0;

		

		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		for (int i = 0; i < m_noOfItems; i++) {
			cout << setfill(' ') << setw(4) << (i+1) << " | ";
			m_items[i]-> write(cout, true);
			TOTAL += (m_items[i]->cost() * m_items[i]->quantity());
			cout << endl;
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
		cout << "                               Total Asset: $  |" << std::right << std::setw(14) << TOTAL << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl;

		//     | 1234   |Candle              |   1.23| TN|  38|    52.82|
		// Row | SKU    | Item Name          | Price |TX |Qty |   Total |"
	}
	void PosApp::truncateBillFile() {
		fstream KILLBILL(m_billfname, ios::out | ios::trunc);
		KILLBILL.close();
	}
	void PosApp::showBill() {
		fstream SHOWBILL(m_billfname, ios::in);
		Item* showItems[MAX_NO_ITEMS];
		Date currentDate;
		double TOTAL = 0;
		int count = 0;
		char PerOrNot = 'n';
		//int ALIVE;

		if (SHOWBILL.good()) {
			while (SHOWBILL.good()) { // EOF FAILS, CONTINUES PAST FAIL
				PerOrNot = 'z';
				SHOWBILL >> PerOrNot;
				if (PerOrNot == 'P' || PerOrNot == 'p') {
					showItems[count] = new Perishable();
				}
				else if (PerOrNot == 'N' || PerOrNot == 'n') {
					showItems[count] = new NonPerishable();
				}
				if (PerOrNot == 'P' || PerOrNot == 'p' || PerOrNot == 'N' || PerOrNot == 'n') {
				SHOWBILL.ignore();
				showItems[count]->load(SHOWBILL); // load virtual function, ptd by ptr item
				count++;
				}

			}
		}
		//currentDate.set();
		cout << "v-------------------------------------------------------v" << endl;
		cout << "| ";
		currentDate.write(cout);
		cout << setw(40) << "|" << endl;
		cout << "| SKU   | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "|-------|--------------------|-------|---|----|---------|" << endl;
		for (int i = 0; i < count; i++) {
			cout << "|";
			showItems[i]->write(cout, true);
			cout << endl;
			//m_items[i]->write(cout, true);
			TOTAL += (showItems[i]->cost() *showItems[i]->quantity());
		}
		cout << "^-------^--------------------^-------^---^----^---------^" << endl;
		cout << "|                              Total: $  |" << std::right << std::setw(14) << TOTAL << "|" << endl;
		cout << "^----------------------------------------^--------------^" << endl;
		truncateBillFile();
	}
	void PosApp::addToBill(Item& I) {
		int currentQty = I.quantity();

		fstream ADDBILL(m_billfname, ios::out | ios::app);
		if ((I.quantity()) <= 1) {
			I.quantity(1);
			I.save(ADDBILL);
			m_items[searchItems(I.sku())]->quantity(0);
		}
		else {
			I.quantity(1);
			I.save(ADDBILL);
			I.quantity(currentQty - 1);
			m_items[searchItems(I.sku())]->quantity(currentQty - 1);
		}
		//ADDBILL.close();

		saveRecs();
	}
	void PosApp::POS() {
		char searchSKU[MAX_SKU_LEN];
		string sSKU;
		bool found = false;
		fstream SEARCHFILE(m_filename, ios::in);
		bool end = false;
		Item* tempLoad[1];
		char PerOrNot = 'n';
		//int ALIVE;
		//cout << "BEINH" << endl;
		found = false;

		while (!end) {
			//cin.clear();
			//cin.ignore(1000, '\n');
			cout << "Sku: ";
			//cin >> sSKU;
			getline(std::cin, sSKU,'\n');
			//cout << "Your SKU :: " << searchSKU << endl;

			if (sSKU.empty()){
				showBill();
				cout << endl; // SKip
				end = true;
				found = false;
			}
			else {
				//cout << "Your string is !~" << sSKU << endl;
				SEARCHFILE.seekg(0);
				while (SEARCHFILE.good() && found == false) { // EOF FAILS, CONTINUES PAST FAIL
					SEARCHFILE >> PerOrNot;
					if (PerOrNot == 'P' || PerOrNot == 'p') {
						tempLoad[0] = new Perishable();
					}
					else if (PerOrNot == 'N' || PerOrNot == 'n') {
						tempLoad[0] = new NonPerishable();
					}
					SEARCHFILE.ignore();

					tempLoad[0]->load(SEARCHFILE); // load virtual function, ptd by ptr item
					strcpy(searchSKU, sSKU.c_str()); // CONVERT

					//char * w = new char[MAX_SKU_LEN];
					//std::copy(sSKU.begin(), sSKU.end(), w);
					//w[sSKU.size()] = '\0'; // don't forget the terminating 0
					//cout << "Compare these: " << searchSKU << "-and- " << tempLoad[0]->sku() << endl;

					if (strcmp(searchSKU, tempLoad[0]->sku()) == 0) {
						found = true;
					}
				}
			}
			if (found) {
				cout << "v------------------->" << endl;
				cout << "| " << tempLoad[0]->name() << endl;
				cout << "^------------------->" << endl;
				addToBill(*tempLoad[0]);
				//tempLoad[0] = nullptr;
				found = false;
				//SEARCHFILE.close();
				//fstream SEARCHFILE(m_filename, ios::in);
			}
			else if (!found && !end) {
				cout << "Not found!" << endl;
				cout << endl;
			}
		}
		//SEARCHFILE.close();
	}

	// Public Functions
	void PosApp::run() {
		int currentSelection = 9;
		char sku[MAX_SKU_LEN + 1];
		//loadRecs(); // DEBUGGER

		while (currentSelection != 0) {
			currentSelection = menu();
			std::cout << std::endl; // Formatting

			if (currentSelection == 1) {
				listItems();
			}
			else if (currentSelection == 2) {
				addItem(true);
			}
			else if (currentSelection == 3) {
				addItem(false);
			}
			else if (currentSelection == 4) {
				updateQty();
			}
			else if (currentSelection == 5) { // Show Items
				cout << "Please enter SKU: ";
				cin >> sku;
				if (searchItems(sku) == -1) {
					cout << "Not found!" << endl;
				}
				else {
					cout << "v-----------------------------------v" << endl;
					m_items[searchItems(sku)]->write(cout, false);
					cout << "^-----------------------------------^" << endl;
					cout << endl;
				}
			}
			else if (currentSelection == 6) {
				POS();
			}
			else if (currentSelection == 7) { // DEBUGGER
				loadRecs(); // DEBUGGER
			}
			else if (currentSelection == 8) {
				showBill();
			}
			else if (currentSelection == 0) {
				std::cout << "Goodbye!" << std::endl;
			}
			else {
				std::cout << "===Invalid Selection, try again===" << std::endl;
				cout << endl;
			}
		}
	}
}


/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
                               Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/