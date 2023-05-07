#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "student.h"

Student::Student()
{
	this->studentId = " ";
	this->firstName = " ";
	this->lastName = " ";
	this->emailAddress = " ";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram = Degree::SOFTWARE;
}


	Student::Student(string stuId, string fName, string lName, string eMail, int a, int* days, Degree degreeProgram)
	{
		studentId = stuId;
		firstName = fName;
		lastName = lName;
		emailAddress = eMail;
		age = a;
		daysInCourse[0] = days[0];
		daysInCourse[1] = days[1];
		daysInCourse[2] = days[2];
		this->degreeProgram = degreeProgram;
	}

	void Student::setstudentId(string stuId)
	{
		studentId = stuId;
		return;
	}

	void Student::setfirstName(string fName)
	{
		firstName = fName;
		return;

	}

	void Student::setlastName(string lName)
	{
		lastName = lName;
		return;
	}

	void Student::setemailAddress(string eMail)
	{
		emailAddress = eMail;
		return;
	}

	void Student::setAge(int a)
	{
		age = a;
		return;
	}

	void Student::setdaysInCourse(int* days)
	{
		daysInCourse[0] = days[0];
		daysInCourse[1] = days[1];
		daysInCourse[2] = days[2];

		return;
	}

	void Student::setDegreeProgram(Degree dp)
	{
		degreeProgram = dp;
		return;
	}

	string Student::getstudentId()
	{
		return studentId;
	}

	string Student::getfirstName()
	{
		return firstName;
	}

	string Student::getlastName()
	{
		return lastName;
	}

	string Student::getemailAddress()
	{
		return emailAddress;
	}

	int Student::getAge()
	{
		return age;
	}

	int* Student::getdaysInCourse()
	{
		return daysInCourse;
	}

	Degree Student::getDegreeProgram()
	{
		return degreeProgram;
	}

	void Student::print()
	{
		string degreeStrings = "";
		if (degreeProgram == Degree::SECURITY)
		{
			degreeStrings = "SECURITY";
		}
		else if (degreeProgram == Degree::NETWORK)
		{
			degreeStrings = "NETWORK";
		}
		else if (degreeProgram == Degree::SOFTWARE)
		{
			degreeStrings = "SOFTWARE";
		}
		cout << "\tStudent Id: " << getstudentId() << "\tFirst Name: " << getfirstName() << "\tLast Name: " << getlastName() << "\tAge: " << getAge() << "\t Days In Course: " << "{" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}" << "\tDegree Program: " << degreeStrings << endl;
	}