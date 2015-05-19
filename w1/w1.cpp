// OOP244 Workshop 1: Compiling modular source code
// File w1step1.cpp
// Version 1.0
// Date 2015/05/07
// Author Franz Newland
// Description
// This provides some source code in a single file to break
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name Date Reason
// F.Newland 2015/01/09 Preliminary release
// Larissa Voigt 2015/05/17 Modular program
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "w1.h"
#include "checkout.h"
using namespace std;


//Functions
int main(){
  int iCost = 0; // Selected item cost
  int iTotal = 0;
  cout << "SeneKEA Order Tool\n"
    << "======================\n";
  // process user input
  while (iCost != 10){
    iCost = checkout();
    if (iCost == 0)
      cout << errMsg;
    else if (iCost == -1) {
      iTotal = 0;
      cout << cancelMsg;
    }
    else if (iCost == 10) {
      cout << "Total is $" << iTotal << endl;
      cout << printMsg;
    }
    else {
      cout << "Total increases by $" << iCost << endl;
      iTotal += iCost;
    }
  }
  return 0;
}
