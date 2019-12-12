/************************
	ZeroBugs

	Krishcko, Alina
	Silvestre Nuernberg, Samantha
	Yilmaz, Ferah

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Person.h"

using namespace std;

// default constructor
Person::Person()
{
	firstName = "N/A";
	lastName = "N/A";
}

// overloaded constructor
Person::Person(const string& first, const string& last)
{
	firstName = first;
	lastName = last;
}

// setName
void Person::setName(const string& first, const string& last)
{
	firstName = first; 
	lastName = last; 
}

// getLastName
string Person::getLastName() const
{
	return lastName; 
}

// printName
void Person::printName() const
{
	cout << lastName << ", " << firstName << endl; 
}

// destructor
Person::~Person()
{}
