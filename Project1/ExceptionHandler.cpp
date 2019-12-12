/************************
	ZeroBugs

	Krishcko, Alina
	Silvestre Nuernberg, Samantha
	Yilmaz, Ferah

	CS A250 - Fall 2019

	Project 1
*************************/

#include "ExceptionHandler.h"

using namespace std;

int ExceptionHandler::validateSelection(const string& input) const
{
	if (input.length() > 1)
		return 0;
	else
	{
		int id = input[0] - 48;
		if (id >= 1 && id <= 6)
			return id;
		else
			return 0;
	}
}

bool ExceptionHandler::lastNameValid(string& input) const
{
	for (auto it = input.begin(); it != input.end(); ++it) 
		if (isspace(*it)) 
			return false;

	input[0] = toupper(input[0]);
	for_each(input.begin() + 1, input.end(),
			[](char& c) { c = ::tolower(c); });
		return true;
}

bool ExceptionHandler::validateID
	(const string& input, int& id) const
{
	// your code here...
	for (auto it = input.begin(); it != input.end(); ++it)
		if (isspace(*it))
		{
			cout << "Invalid invalid input. ID is 6 digits. " 
				 << "Try again." << endl;
			return false;
		}

	if (input.length() != 6)
	{
		cout << "Invalid input. ID is 6 digits. "
			<< "Try again." << endl;
		return false;
	}

	else
	{
		id = stoi(input);

		if (id > 100000 && id < 99999)
		{
			cout << "Invalid input. ID is 6 digits. Try again" << endl;
			return false;
		}

		return true;
	}
}

bool ExceptionHandler::validateCoursePrefix(string& input) const
{
	if (input.length() != 3)
	{
		cout << "Invalid input. Course prefix is 3 letters. "
			<< "Try again." << endl;
		input = "";
		return false;
	}
	else
	{
		// your code here...
		for (auto iter = input.begin(); iter != input.end(); ++iter)
			if (isspace(*iter))
				return false;

		input[0] = toupper(input[0]);
		for_each(input.begin() + 1, input.end(),
			[](char& c) { c = ::toupper(c); });
		return true;
	}
}

bool ExceptionHandler::validateCourseNo
	(const string& input, int& courseNo) const
{
	if (input.length() != 3)
	{
		cout << "Invalid input. Course number is 3 digits. "
			<< "Try again." << endl;
		return false;
	}
	else
	{
		courseNo = stoi(input);
		return true;
	}
}


