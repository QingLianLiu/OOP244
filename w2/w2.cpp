// OOP244 Workshop 2: Compound types and privacy
// File w2.cpp
// Version 1.0
// Date 2015/05/14
// Author Franz Newland
// Description
// This file is used to demonstrate classes in C++ and
// how member variables can be defined as private but
// accessed through member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name Date Reason
// F.Newland 2015/05/14 Preliminary release
///////////////////////////////////////////////////////////
#include <iostream>
#include "AccountNumber.h"
using namespace std;
using namespace oop244;

int main(){
   AccountNumber myNumber;
   char name[41];
   int bankCode;
   int branchCode;
   int number;

   cout << "Bank account app" << endl << "===================" << endl << endl;
   cout << "Please enter your name: ";

   cin >> name;

   cout << "please enter your bank and branch code and account number separated by space."<<endl<<"999 999 99999: ";

   cin >> bankCode >> branchCode >> number;

   myNumber.setName(name);
   myNumber.setAccountNumber(bankCode, branchCode, number);

   if (!myNumber.isValid()){
      cout << "The bank account number entered is invalid." << endl << "please use the following format: 999 999 99999"<<endl<<endl;
   }

   myNumber.display();
   return 0;
}
