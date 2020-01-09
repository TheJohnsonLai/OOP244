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


// TODO: include the necessary headers
#include <iostream>
#include "kingdom.h"

using namespace std;

// TODO: the westeros namespace
namespace westeros {
	//char[32] m_name = "";
	//int m_population = 0;

	// TODO:definition for display(...) 
	void display(Kingdom& pKingdom) {

		//for (int i = 0; i < pKingdom.size(); i++) {
			cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
		//}
	}
	void display(Kingdom pKingdom[], int pSize){
		int tpop = 0;
		cout << "---------------------------" << endl << "Kingdoms of Westeros" << endl << "---------------------------" << endl;
		for (int i = 0; i < pSize; i++) {
			cout << pKingdom[i].m_name << ", population " << pKingdom[i].m_population << endl;
			tpop += pKingdom[i].m_population;
		}

		cout << "---------------------------" << endl << "Total population of Westeros: "<< tpop << endl;
		cout << "---------------------------" << endl;
	}
	void display(Kingdom pKingdom[],int pSize, int pMin){
		cout << "---------------------------" << endl << "Kingdoms of Westeros with more than " << pMin << " people" << endl << "---------------------------" << endl;
		for (int i = 0; i < pSize; i++) {
			if (pKingdom[i].m_population > pMin) {
				cout << pKingdom[i].m_name << ", population " << pKingdom[i].m_population << endl;
			}
		}

		cout << "---------------------------" << endl;
	}
	void display(Kingdom pKingdom[], int pSize, char pName[]){
		int isPart = 0;
		cout << "---------------------------" << endl << "Searching for kingdom " << pName << " in Westeros" << endl << "---------------------------" << endl;
		for (int i = 0; i < pSize; i++) {
			if (strcmp(pKingdom[i].m_name, pName) == 0) {
				cout << i + 1 << ". " << pKingdom[i].m_name << ", population " << pKingdom[i].m_population << endl;
				isPart = 1;
			}
		}
		if (isPart == 0) {
			cout << pName << " is not part of Westeros." << endl;
		}

		cout << "---------------------------" << endl;
	}

}