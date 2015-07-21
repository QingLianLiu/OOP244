/* Workshop 6
 * FlyingPoints.cpp
 * Author: Larissa Voigt
 * Purpose: Functions definitions */

#include <iostream>
#include "FlyingPoints.h"
using namespace std;

FlyingPoints::FlyingPoints() {
  in = 0;
  out = 0;
}

FlyingPoints::FlyingPoints(int i, int o) {
  in = i;
  out = o;
}

void FlyingPoints::updateBalance() {
  if (in > out) {
    in = in - out;
    out = 0;
  } else {
    out = out - in;
    in = 0;
  }
}

void FlyingPoints::display()const {
  cout << in << " points available to fly." << endl;
  cout << out << " points spent." << endl;
}

FlyingPoints& FlyingPoints::operator+=(const FlyingPoints& f) {
  in += f.in;
  out += f.out;
  updateBalance();
  return *this;
}

FlyingPoints operator+(const FlyingPoints& a, const FlyingPoints& b) {
  FlyingPoints copy = a;
  copy += b;
  return copy;
}

bool operator==(const FlyingPoints& a, const FlyingPoints& b) {
  FlyingPoints copy_a = a;
  FlyingPoints copy_b = b;
  copy_a.updateBalance();
  copy_b.updateBalance();
  return (copy_a.in == copy_b.in) && (copy_a.out == copy_b.out);
}
