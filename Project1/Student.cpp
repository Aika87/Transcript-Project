/************************
	ZeroBugs

	Krishcko, Alina
	Silvestre Nuernberg, Samantha
	Yilmaz, Ferah

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Student.h"

using namespace std;

// default constructor
Student::Student()
{
	studentID = 0;
	tuitionWasPaid = false;
	totalCourses = 0;
}

// setStudentInfo
void Student::setStudentInfo(const string& name, const string& last, 
				int id, bool paid, const multimap<Course, char>& courses)
{
	setName(name, last); 
	studentID = id;
	tuitionWasPaid = paid;
	coursesCompleted = courses; 
	totalCourses = static_cast<int>(courses.size()); 
}

// getID
int Student::getID() const
{
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return totalCourses; 
}

// getUnitsCompleted
double Student::getUnitsCompleted() const
{
	double completed = 0.0; 

	auto iter = coursesCompleted.begin(); 
	auto iterEnd = coursesCompleted.end(); 

	while (iter != iterEnd)
	{
		completed += iter->first.getCourseUnits();
		++iter; 
	}

	return completed; 
}

// getGpa
double Student::getGpa() const
{
	double gpa = 0.0; 

	auto iter = coursesCompleted.begin();
	auto iterEnd = coursesCompleted.end();

	while (iter != iterEnd)
	{
		char letter = iter->second;

		switch (letter)
		{
		case 'A':
			gpa += 4.0 * iter->first.getCourseUnits();
			break;
		case 'B':
			gpa += 3.0 * iter->first.getCourseUnits();
			break; 
		case 'C':
			gpa += 2.0 * iter->first.getCourseUnits();
			break;
		case 'D':
			gpa += iter->first.getCourseUnits(); 
			break; 
		case 'F':
			gpa = 0.0; 
			break; 
		default: cerr << "Invalid Course Grade" << endl;
		}
		++iter; 
	}
	return gpa / getUnitsCompleted();
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid; 
}

// courseIsCompleted
bool Student::courseIsCompleted(string pre, int num) const
{
	auto iter = coursesCompleted.begin(); 
	auto iterEnd = coursesCompleted.end(); 

	while (iter != iterEnd)
	{
		if ((iter->first.getCoursePrefix()) == pre)
			return true;
		else
			++iter; 
	}
	return false; 
}

// printStudent
void Student::printStudent() const
{
	cout << studentID << " - ";
	Person::printName();
}

// printStudentInfo
void Student::printStudentInfo() const
{
	cout << "Student Name: ";
	Person::printName();
	cout << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses completed: " << totalCourses 
		 << endl << endl;
	cout << "Course    Units    Grade \n";

	auto iter = coursesCompleted.begin();
	auto iterEnd = coursesCompleted.end();

	if (tuitionWasPaid)
	{
		while (iter != iterEnd)
		{
			cout << iter->first.getCoursePrefix() << " " 
				 << iter->first.getCourseNo() << setw(8)
				 << iter->first.getCourseUnits() << setw(7) 
				 << iter->second << endl;
			++iter;
		}

		cout << endl;
		cout << "Total number of unit hours: " 
			 << getUnitsCompleted() << endl;
		cout << "Current Term GPA: " << setprecision(2) 
			 << getGpa() << endl;
		cout << endl;
	}
	else
	{
		while (iter != iterEnd)
		{
			cout << iter->first.getCoursePrefix() << " " 
				 << iter->first.getCourseNo() << setw(8) 
				 << iter->first.getCourseUnits() << setw(9) 
				 << "***" << endl;
			++iter;
		}

		cout << endl;
		cout << "Total number of unit hours: " 
			 << getUnitsCompleted() << endl;
		cout << "*** Grades are being held "
			 << "for not paying the tuition. ***" << endl;
		cout << endl;
	}

	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
}

// destructor
Student::~Student() {};

