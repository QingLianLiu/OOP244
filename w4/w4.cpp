// OOP244 Workshop 4: Constructors
// File: w4.cpp
// Version: 1.0
// Date: 2015/05/28
// Author: A. C. Coder
// Description:
// This file demonstrates constructors in C++
/////////////////////////////////////////////


#include <iostream>
#include "Enrollment.h"
using namespace std;


int main()
{
    Enrollment e1("Introduction to Programming in C", "IPC144", 2015, 1, 5);
    Enrollment e2;

    cout << "Displaying this student’s enrolled courses..." << endl;

    e1.display();
    e2.display();

    cout << "Enrolling the student in a new course..." << endl;

    e2.enroll("Object Oriented Programming", "OOP244", 2015, 1, 5);

    if (e1.hasConflict(e2))
	{
        cout << "Sorry! This time slot is not available!" << endl;
	}
    e2.enroll("Object Oriented Programming", "OOP244", 2015, 2, 5);

    cout << "Updated enrolled courses..."<< endl;

	e1.display();
    e2.display();

    cout << "Withdrawing from a course..." << endl;

    e1.withdraw();

    cout << "Updated courses..." << endl;

    e1.display();
    e2.display();

    return 0;
}
