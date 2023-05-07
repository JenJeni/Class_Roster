// Class_Roster.cpp 


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "roster.h"
#include "degree.h"

int main()
{
    cout << "Class Roster" << endl << endl;

	//Set default value of type int for loops
	//Set number value of students for array
	//int i = 0; 

	const int numStudents = 6;	

	/*	Student Id, 
		First Name, 
		Last Name, 
		Email Address, 
		Age, 
		Days In Course (x3), 
		Degree Program
	*/
	const string studentData[numStudents] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Norma,Black,norma.black@yahoo.com,24,50,38,40,SECURITY",
	"A6,Shay,Burham,shay burham@comcast.net,29,30,45,40,NETWORK"/*,
	"A7,Gina,Peoples,ginapeoples@gma il.com,21,25,30,45,SECURITY",
	"A8,Wade,Truman,wade_truman@aol.com,32,20,30,30,NETWORK",
	"A9,Fred,Gleyton,fredgleyton@yahoo.com,27,40,30,40,SOFTWARE",
	"A10,Naomi,Young,naomi.young@gmail.com,42,30,30,40,SECURITY",
	"A11,Maxwell,Blawson,maxmax.blaw@gmailcom,19,30,25,32,SECURITY",
	"A12,Lauren,Hills,lauren_hillsyahoo.com,22,30,25,30,SOFTWARE",
	"A13,Dustin,Blacksmith,dblacksmith@gmail.com,42,45,30,35,SOFTWARE"*/
	};

	//Create new instance of Roster and parse data
	Roster* classRoster = nullptr;
	classRoster = new Roster;

	for (int i = 0; i < numStudents; ++i)
	{
		classRoster->parse(studentData[i]);
	}

	//Displays students
	cout << "Displaying all students: " << endl;
	classRoster->printAll();
	cout << endl;

	//Displays invalid email addresses
	cout << "Displaying invalid email addresses: " << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	//Displays average course days per student
	cout << "Displaying average course days per student: " << endl;
	for (int i = 0; i < numStudents; ++i)
	{
		classRoster->printAverageDaysInCourse(classRoster->getclassRosterArray(i)->getstudentId());
	}
	cout << endl;

	//Displays all students per degree program
	cout << "Showing students in degree program: SOFTWARE " << endl;
	classRoster->printByDegreeProgram(Degree::SOFTWARE);
	cout << endl;

	cout << "Showing students in degree program: SECURITY " << endl;
	classRoster->printByDegreeProgram(Degree::SECURITY);
	cout << endl;

	cout << "Showing students in degree program: NETWORK " << endl;
	classRoster->printByDegreeProgram(Degree::NETWORK);
	cout << endl;

	//Updates roster after removing specified student id
	cout << "Removing student(s) with an invalid email address: " << endl;
	classRoster->removeStudent("A1");
	classRoster->removeStudent("A3");
	//classRoster->removeStudent("A12");
	classRoster->printAll();
	
	cout << endl;

	//Confirms successfully deletion
	cout << "Removing A1 and A3 again: " << endl;
	classRoster->removeStudent("A1");
	classRoster->removeStudent("A3");
	//classRoster->removeStudent("A12");
	cout << "Done." << endl;
	cout << endl;

	//Destructor 
	delete classRoster;
	return 0;
}
