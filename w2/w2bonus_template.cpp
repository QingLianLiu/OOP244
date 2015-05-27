//OOP244 Wkshp2: Compound types, privacy, unit test
// File w2.cpp
// Version 1.0
// Date 2015/05/14
// Author Franz Newland
// Description
// This file is used to demonstrate classes
// and how member variables can be defined as
// private but accessed through member functions
// Revision History
//------------------------------------------------
// Name Date Reason
// F.Newland 2015/05/14 Preliminary release
//////////////////////////////////////////////////
#include <iostream>
#include "AccountNumber.h"
using namespace std;
using namespace oop244;

bool unitTests(AccountNumber* f)
{
	//WRITE unit test code HERE
}

int main(){
	AccountNumber myNum;		
	bool passed;
	passed = unitTests(&myNum);
	if (passed)
		cout << "Passed all tests" << endl;
	else
		cout << "Failed tests" << endl;
	return 0;
}