// OOP244 Workshop ??: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////


// TODO: header safeguards
#ifndef westeros_kingdom_H_
#define westeros_kingdom_H_

// TODO: westeros namespace
namespace westeros {

	// TODO: define the class Kingdom in the westeros namespace
	class Kingdom {
		public:
			char m_name[32];
			int m_population;
	};

	// TODO: add the declaration for the function display(...),
	//         also in the westeros namespace
	void display(Kingdom&);
	void display(Kingdom[], int);
	void display(Kingdom[], int, int);
	void display(Kingdom[], int, char[]);

}
#endif
