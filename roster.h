#pragma once

#include <iostream>

using namespace std;

#include "student.h"

class Roster
{
private:
	Student* classRosterArray[6]; //pointer array
	int studentIndex = 0; //Loop through index to access next item in the array

public:
	//Roster()
	//Roster(int studentIndex);

	void parse(string row);
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgam);
	void removeStudent(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);

	Student* getclassRosterArray(int studentIndex);

	~Roster();
};

