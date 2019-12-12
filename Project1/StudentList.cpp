/************************
	ZeroBugs

	Krishcko, Alina
	Silvestre Nuernberg, Samantha
	Yilmaz, Ferah

	CS A250 - Fall 2019

	Project 1
*************************/

#include "StudentList.h"

using namespace std;

// default constructor
StudentList::StudentList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

// copy constructor
StudentList::StudentList(const StudentList& newList)
{
	Node* temp = newList.first; 

	while (temp != nullptr)
	{
		Node* newStudent = new Node(temp->getStudent(), temp);
		first = newStudent;

		if (last == nullptr)
		{
			last = newStudent;
		}

		temp = temp->getNext(); 
	}

	count = newList.count; 
}

void StudentList::copyCallingObjIsEmpty(const StudentList& newList)
{
	Node* temp = newList.first;

	while (temp != nullptr)
	{
		Node* newStudent = new Node(temp->getStudent(), temp);
		first = newStudent;

		if (last == nullptr)
		{
			last = newStudent;
		}

		temp = temp->getNext();
	}

	count = newList.count;
}

void StudentList::copyObjectsSameLength(const StudentList& newList)
{
	Node* temp = newList.first;
	Node* myTemp = first; 

	while (temp != nullptr)
	{
		myTemp->setStudent(temp->getStudent()); 
		temp = temp->getNext(); 
		myTemp = myTemp->getNext(); 
	}

	//last = myTemp.getPrev(); 

	count = newList.count;
}

void StudentList::copyCallingObjLonger(const StudentList& newList)
{
	Node* temp = newList.first;
	Node* myTemp = first;

	while (temp != nullptr)
	{
		myTemp->setStudent(temp->getStudent());
		temp = temp->getNext();
		myTemp = myTemp->getNext();
	}

	Node* newTemp = myTemp;

	while (myTemp != nullptr)
	{
		myTemp = myTemp->getNext();
		delete newTemp;
		newTemp = myTemp;
	}

	count = newList.count;
}

void StudentList::copyCallingObjShorter(const StudentList& newList)
{
	Node* temp = newList.first;
	Node* myTemp = first;

	while (myTemp != nullptr)
	{
		myTemp->setStudent(temp->getStudent());
		temp = temp->getNext();
		myTemp = myTemp->getNext();
	}

	while (temp != nullptr)
	{
		Node* newStudent = new Node(temp->getStudent(), temp);

		if (last == nullptr)
		{
			last = newStudent;
		}

		temp = temp->getNext();
	}

	count = newList.count;
}

// assignment operator 
StudentList& StudentList::operator=(const StudentList& newList)
{
	if (this != &newList)
	{
		if (newList.first == nullptr)
			destroyStudentList();

		else if (first == nullptr)
			copyCallingObjIsEmpty(newList);

		// lists have the SAME number of nodes
		else if (count == newList.count)
			copyObjectsSameLength(newList);

		// calling object has MORE nodes than the parameter object
		else if (count > newList.count)
			copyCallingObjLonger(newList);
		
		// calling object has LESS nodes than the parameter object
		else
			copyCallingObjShorter(newList); 
	}

	else
	{
		cerr << "Attempting self-assignment";
	}

	return *this; 
}

// addStudent
void StudentList::addStudent(const Student& newGuy)
{
	Node* newStudent = new Node(newGuy, first); 
	first = newStudent;

	if (last == nullptr)
	{
		last = newStudent; 
	}

	++count; 
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return count; 
}

// printStudentByID
void StudentList::printStudentByID(int id) const
{
	if (first == nullptr)
	{
		cerr << "List is empty." << endl; 
	}
	
	else
	{
		Node* temp = first;
		bool found = false;

		while (temp != nullptr && !found)
		{
			if (temp->getStudent().getID() == id)
			{
				temp->getStudent().printStudentInfo();
				found = true;
			}

			else
				temp = temp->getNext();
		}

		if (!found)
		{
			cout << "No student with ID " << id 
				 << " found in the list." << endl;
		}
	}
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const std::string& pre, 
										int num) const
{
	if (first == nullptr)
	{
		cerr << "List is empty." << endl; 
	}

	else
	{
		Node* temp = first;
		bool completed = false; 

		while (temp != nullptr)
		{
			if (temp->getStudent().getNumberOfCourses() != 0)
			{
				if (temp->getStudent().courseIsCompleted(pre, num))
				{
					temp->getStudent().printStudent();
					completed = true; 
				}
			}

			temp = temp->getNext();
		}

		if (!completed)
		{
			cout << "No student completed " << num << endl; 
		}
	}
}

// printStudentByName
void StudentList::printStudentByName(const std::string& last) const
{
	if (first == nullptr)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		Node* temp = first; 
		bool found = false; 

		while (temp != nullptr)
		{
			if (temp->getStudent().getLastName() == last)
			{
				temp->getStudent().printStudent();
				found = true; 
			}

			temp = temp->getNext(); 
		}

		if (!found)
		{
			cout << "No student witht last name " << last 
				 << " is in the list" << endl; 
		}
	}
}

// printStudentsOnHold
void StudentList::printStudentsOnHold() const
{
	if (first == nullptr)
	{
		cerr << "No students in the list." << endl; 
	}
	else
	{
		Node* temp = first; 
		bool found = false; 

		while (temp != nullptr)
		{
			if (!temp->getStudent().isTuitionPaid())
			{
				temp->getStudent().printStudentInfo(); 
				found = true; 
			}
			
			temp = temp->getNext(); 
		}

		if (!found)
		{
			cout << "There are no students on hold." << endl; 
		}
	}
}

// printAllStudents
void StudentList::printAllStudents() const
{
	Node* temp = first; 

	while (temp != nullptr)
	{
		temp->getStudent().printStudentInfo(); 
		temp = temp->getNext(); 
	}
}

// destroyStudentList
void StudentList::destroyStudentList()
{
	Node* temp = first; 

	while (first != nullptr)
	{
		first = first->getNext(); 
		delete temp;
		temp = first; 
	}

	first = nullptr; 
	last = nullptr; 
	count = 0; 
}

// destructor
StudentList::~StudentList()
{
	destroyStudentList(); 
}

