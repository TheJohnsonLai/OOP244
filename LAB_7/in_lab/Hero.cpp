#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;


//////////////////////////////////////////////
// Default constructor
//
Hero::Hero ()
{
	strcpy(m_name, "");
	m_name[41] = '\0';
	m_attack = 0;
	m_maximumHealth = 0;
	m_health = 0;
}


///////////////////////////////////////////////////
// Constructor
// 
Hero::Hero (const char name[], unsigned maximumHealth, unsigned attack)
{
	strcpy(m_name,name);
	m_attack = attack;
	m_maximumHealth = maximumHealth;
	m_health = maximumHealth;
}



/////////////////////////////////////////////////////////
// 
// Hero::display function
void Hero::display (ostream & out) const 
{
	if (isEmpty()) {
		out << "";
	}
	else {
		out << m_name;
	}
}



/////////////////////////////////////////////////
// Hero::isEmpty ()
// return true if the Hero object is uninitialized
//
bool Hero::isEmpty () const 
{
	return (m_name[41] == '\0' && m_attack == 0 && m_health == 0) ? true : false;
}

/////////////////////////////////////////////////
// sets the Hero object's health back to full
//
void Hero::respawn() 
{
	m_health = m_maximumHealth;
}

