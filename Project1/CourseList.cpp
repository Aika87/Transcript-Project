/************************
	ZeroBugs

	Krishcko, Alina
	Silvestre Nuernberg, Samantha
	Yilmaz, Ferah

	CS A250 - Fall 2019

	Project 1
*************************/

#include "CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

// CourseList
CourseList::CourseList()
{
	totalCourses = 0;
	capacity = CAP;
	courseList = new Course[capacity];
}

// Overloaded constructor
CourseList::CourseList(int cap)
{
	totalCourses = 0;
	capacity = cap;
	courseList = new Course[capacity];
}

// Copy constructor
CourseList::CourseList(const CourseList& newList)
{
	totalCourses = newList.totalCourses;
	capacity = newList.capacity;

	courseList = new Course[newList.capacity]; 

	for (int i = 0; i < newList.totalCourses; ++i)
	{
		courseList[i] = newList.courseList[i]; 
	}
}

// addCourse
void CourseList::addCourse(const Course& newCourse)
{
	if (totalCourses == capacity)
	{
		resize(); 
	}

	courseList[totalCourses] = newCourse; 
	++totalCourses; 
}

// getCourseUnits
double CourseList::getCourseUnits(const std::string& pre, int num) const
{
	int i = 0; 

	while(i < totalCourses)
	{
		if ((courseList[i].getCoursePrefix() == pre) && 
			(courseList[i].getCourseNo() == num))
		{
			return courseList[i].getCourseUnits(); 
		}

		++i; 
	}

	return 0;
}

// searchCourse
bool CourseList::searchCourse(const std::string& pre, int num) const
{
	int i = 0; 

	while (i < totalCourses)
	{
		if ((courseList[i].getCoursePrefix() == pre) && 
			(courseList[i].getCourseNo() == num))
		{
			return true; 
		}

		++i; 
	}

	return false; 
}

// overloaded operator=
CourseList& CourseList::operator=(const CourseList& rightSide)
{
	if (this != &rightSide)
	{
		if (capacity != rightSide.capacity)
		{
			delete[] courseList;
			courseList = new Course[rightSide.capacity]; 
			capacity = rightSide.capacity; 
		}
		
		for (int i = 0; i < rightSide.totalCourses; ++i)
		{
			courseList[i] = rightSide.courseList[i]; 
		}
		totalCourses = rightSide.totalCourses;
	} 

	else
	{
		cerr << "Attempting self-assignment";
	} 

	return *this; 
}

// destructor
CourseList::~CourseList() 
{
	delete[] courseList; 
	courseList = nullptr; 
}

// resize
void CourseList::resize()
{
	Course* temp = new Course[capacity * 2];

	for (int i = 0; i < totalCourses; ++i)
	{
		temp[i] = courseList[i]; 
	}

	capacity = (capacity * 2);

	delete[] courseList; 
	courseList = temp; 
}
