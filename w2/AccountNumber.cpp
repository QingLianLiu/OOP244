/*  OOP244 - Workshop 2
 *  Date: 25/05/2015
 *  Author: Larissa Voigt
 *  Description: Place your member function definitions */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "AccountNumber.h"

using namespace std;

#define MIN_BANKCODE 100
#define MAX_BANKCODE 999
#define MIN_BRANCHCODE 1
#define MAX_BRANCHCODE 220
#define MIN_ACCNO 10000
#define MAX_ACCNO 99999


namespace oop244 {
  void AccountNumber::setName(const char name[]) {
    strcpy(_name, name);
  }

  void AccountNumber::setAccountNumber(int bankCode, int branchCode, int accountNumber) {
    _bankCode = bankCode;
    _branchCode = branchCode;
    _accountNumber = accountNumber;

    if ((_bankCode >= MIN_BANKCODE && _bankCode <= MAX_BANKCODE) &&
        (_branchCode >= MIN_BRANCHCODE && _branchCode <= MAX_BRANCHCODE) &&
        (_accountNumber >= MIN_ACCNO && _accountNumber <= MAX_ACCNO)) {
      _validAccNumber = true;
    } else {
      _validAccNumber = false;
    }
    }

  void AccountNumber::display() const {
    if(_validAccNumber == true) {
      cout << "name: " << _name << ", Account number: " << _bankCode << "-"
         << _branchCode << "-" << _accountNumber << endl;
    } else {
      cout << _name << " does not have a valid account number." << endl;
    }
  }

  bool AccountNumber::isValid() const {
    return _validAccNumber;
  }
}


