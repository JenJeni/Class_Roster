#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "roster.h"

void Roster::parse(string row)
{
	size_t rSide = row.find(',');
	string studentId = row.substr(0, rSide);

	size_t lSide = rSide + 1;
	rSide = row.find(',', lSide);
	string firstName = row.substr(lSide, rSide - lSide);

	lSide = rSide + 1;
	rSide = row.find(',', lSide);
	string lastName = row.substr(lSide, rSide - lSide);

	lSide = rSide + 1;
	rSide = row.find(',', lSide);
	string emailAddress = row.substr(lSide, rSide - lSide);

	lSide = rSide + 1;
	rSide = row.find(',', lSide);
	int age = stoi(row.substr(lSide, rSide - lSide));

	lSide = rSide + 1;
	rSide = row.find(',', lSide);
	int daysInCourse1 = stoi(row.substr(lSide, rSide - lSide));

	lSide = rSide + 1;
	rSide = row.find(',', lSide);
	int daysInCourse2 = stoi(row.substr(lSide, rSide - lSide));

	lSide = rSide + 1;
	rSide = row.find(',', lSide);
	int daysInCourse3 = stoi(row.substr(lSide, rSide - lSide));

	lSide = rSide + 1;
	rSide = row.find(',', lSide);
	string strDegree = row.substr(lSide, rSide - lSide);

	Degree degreeProgram = Degree::SOFTWARE;
	if (strDegree == "SECURITY")
	{
		degreeProgram = Degree::SECURITY;
	}
	else if (strDegree == "NETWORK")
	{
		degreeProgram = Degree::NETWORK;
	}
	else if (strDegree == "SOFTWARE")
	{
		degreeProgram = Degree::SOFTWARE;
	}

	add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string stuId, string fName, string lName, string eMail, int a, int n1, int n2, int n3, Degree dp)
{
	int daysInCourse[3] = { n1, n2, n3 };

	classRosterArray[studentIndex] = new Student(stuId, fName, lName, eMail, a, daysInCourse, dp);
	++studentIndex;
}

void Roster::removeStudent(string studentId)
{
	bool foundStudent = false;

	for (int i = 0; i < studentIndex; ++i)
	{
		if (classRosterArray[i]->getstudentId() == studentId)
		{
			foundStudent = true;
			delete classRosterArray[i];
			--studentIndex;
			classRosterArray[i] = classRosterArray[studentIndex];
		}
	}

	if (foundStudent)
	{
		cout << "Student with Id: " << studentId << " has been removed from the roster." << endl;
	}
	else
	{
		cout << "Error! Student with Id: " << studentId << " was not found!" << endl;
	}
}


void Roster::printAll()
{
	for (int i = 0; i < studentIndex; ++i)
	{
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentId)
{
	for (int i = 0; i < studentIndex; ++i)
	{
		double totalAvg = 0.0;
		if (classRosterArray[i]->getstudentId() == studentId)
		{
			totalAvg += studentIndex;
			totalAvg = classRosterArray[i]->getdaysInCourse()[0] + classRosterArray[i]->getdaysInCourse()[1] +
				classRosterArray[i]->getdaysInCourse()[2] / 3.0;
			cout << "\tStudent Id: " << classRosterArray[i]->getstudentId() << ", average days in course is: " << fixed << setprecision(0) << totalAvg / 3.0 << " days" << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < (studentIndex - 1); ++i)
	{
		string eMail = classRosterArray[i]->getemailAddress();
		bool hasAtSign = false;
		bool hasPeriod = false;
		bool hasSpace = true;

		if (eMail.find('@') == string::npos || eMail.find('.') == string::npos || eMail.find(' ') != string::npos)
		{
			cout << "\t" << eMail << " - is invalid." << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram)
{
	for (int i = 0; i < studentIndex; ++i)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
}

Student* Roster::getclassRosterArray(int studentIndex)
{
	return classRosterArray[studentIndex];
}

//Destructor
Roster::~Roster()
{
	for (int i = 0; i < studentIndex; ++i)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

