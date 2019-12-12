/************************
	ZeroBugs

	Krishcko, Alina
	Silvestre Nuernberg, Samantha
	Yilmaz, Ferah

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

class CourseList
{
public:
	// CourseList
	CourseList(); 

	// Overloaded constructor
	CourseList(int cap); 

	// Copy constructor
	CourseList(const CourseList& newList);

	// addCourse
	void addCourse(const Course& newCourse); 

	// getCourseUnits
	double getCourseUnits(const std::string& pre, int num) const;

	// searchCourse
	bool searchCourse(const std::string& pre, int num) const;

	// overloaded operator=
	CourseList& operator=(const CourseList& rightSide); 

	// destructor
	~CourseList();

private:
	Course* courseList;	
	int totalCourses;
	int capacity;
	static const int CAP;

	// resize
	void resize(); 
};

#endif
