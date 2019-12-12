#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>

class Node
{
public:
	Node( ): student( ), next(nullptr) {} 
    Node(const Student& newStudent, Node *newNext) 
		: student(newStudent), next(newNext){}
    Student getStudent( ) const { return student; }
	Node* getNext( ) const { return next; }	
    void setStudent(const Student& newStudent) { student = newStudent; }
	void setNext(Node *newNext) { next = newNext; }
private:
    Student student;	
    Node *next;		
};

class StudentList
{
public:
	// default constructor
	StudentList();

	// copy constructor
	StudentList(const StudentList& newList);

	// assignment operator
	StudentList& operator=(const StudentList& newList); 

	// addStudent
	void addStudent(const Student& newGuy); 

	// getNoOfStudents
	int getNoOfStudents() const; 

	// printStudentByID
	void printStudentByID(int id) const; 

	// printStudentsByCourse
	void printStudentsByCourse(const std::string& pre, int num) const;

	// printStudentByName
	void printStudentByName(const std::string& last) const; 

	// printStudentsOnHold
	void printStudentsOnHold() const; 

	// printAllStudents
	void printAllStudents() const; 

	void copyCallingObjIsEmpty(const StudentList& newList); 

	void copyObjectsSameLength(const StudentList& newList); 

	void copyCallingObjLonger(const StudentList& newList); 

	void copyCallingObjShorter(const StudentList& newList); 

	// destroyStudentList
	void destroyStudentList(); 

	// destructor
	~StudentList();

private:
	Node *first;
	Node *last;
	int count;
};

#endif

