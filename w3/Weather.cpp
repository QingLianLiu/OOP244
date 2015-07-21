/* OOP244 - Workshop 3
 * Date: 31/05/2015
 * Author: Larissa Voigt
 * Description: Implement header file on w3.cpp */

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Weather.h"
using namespace std;

void Weather::set(const char* d, double h, double l) {

  strncpy(date, d, SIZE - 1);
  high_temp = h;
  low_temp = l;
}

void Weather::display() const {
  cout << left << setw(10) << setfill('_') << date << setw(6) << fixed <<
    setprecision(1) << high_temp << fixed << setprecision(1) << low_temp << endl;
}
