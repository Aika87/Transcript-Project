/************************
	ZeroBugs

	Krishcko, Alina
	Silvestre Nuernberg, Samantha
	Yilmaz, Ferah

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Course.h"

using namespace std;

// default constructor
Course::Course()
{
	courseNo = 0;
	courseUnits = 0.0;
}

// setCourseInfo
void Course::setCourseInfo(const string& name, const string& pre, 
							int num, double units)
{
	courseName = name;
	coursePrefix = pre;
	courseNo = num;
	courseUnits = units;
}

// getCourseName
string Course::getCourseName() const
{
	return courseName; 
}

// getCoursePrefix
string Course::getCoursePrefix() const
{
	return coursePrefix; 
}

// getCourseNo
int Course::getCourseNo() const
{
	return courseNo; 
}

// getCourseUnits
double Course::getCourseUnits() const
{
	return courseUnits; 
}

// printCourseInfo
void Course::printCourseInfo() const
{
	cout << coursePrefix << setw(4) << courseNo << setw(5) 
		 << courseUnits << endl; 
}

bool Course::operator<(const Course& course) const
{
	return (courseNo < course.courseNo);
}

// destructor;
Course::~Course()
{}