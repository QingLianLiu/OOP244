/* OOP244 - Workshop5
 * CreditStatement.cpp
 * Date: 15/06/15
 * Author: Larissa Voigt
 * Description: Implement function definitions on w5.cpp */

#include <new>
#include <iostream>
#include <string.h>
#include <iomanip>
#include "CreditStatement.h"

using namespace std;

//Default Constructor
CreditStatement::CreditStatement() {
  item = nullptr;
  price = 0;
}

//Overloaded Constructor
CreditStatement::CreditStatement(char* i, double p){
  if(i != nullptr && p > 0.0) {
      price = p;
      item = new (nothrow) char[strlen(i) + 1];
      if (item != nullptr){
        strncpy(item, i, strlen(i)+1);
      }
  } else {
    *this = CreditStatement();
  }
}

//Deconstructor
CreditStatement::~CreditStatement() {
  if(item != nullptr) {
    delete [] item;
    item = nullptr;
  }
}

// Copy Constructor
CreditStatement::CreditStatement(const CreditStatement& src) {
  *this = CreditStatement(src.item, src.price);
}

// Assignment operator
CreditStatement& CreditStatement::operator=(const CreditStatement& src) {
  if (this != &src) {
    price = src.price;
    delete [] item;
    if (src.item != nullptr){
      item = new (nothrow) char[strlen(src.item) + 1];
      strncpy(item, src.item, strlen(src.item)+1);
    } else {
      item = nullptr;
    }
  }
  return *this;
}

void CreditStatement::display() const{
  cout << setw(26) << right << item << fixed << setprecision(2) << setw(8) << right << price <<  endl;
}

bool CreditStatement::isGreaterThan(const CreditStatement& other) const{
  return price > other.price;
}

