#pragma once
#include <string>

#include "degree.h"

class Student
{
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age = 0;
	int daysInCourse[3];
	Degree degreeProgram;

public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, Degree degreeProgram);

	//Mutators
	void setstudentId(string stuId);
	void setfirstName(string fName);
	void setlastName(string lName);
	void setemailAddress(string eMail);
	void setAge(int a);
	void setdaysInCourse(int* days);
	void setDegreeProgram(Degree dp);

	//Accessors
	string getstudentId();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getAge();
	int* getdaysInCourse();
	Degree getDegreeProgram();

	void print();
};

