/* OOP244 - Workshop7
 * Ship.cpp
 * Date: 14/07/15
 * Author: Larissa Voigt
 * Description: Implement function definitions on w7.cpp */

#include <cstring>
#include <iomanip>
#include <iostream>
#include "Ship.h"

Ship::Ship() {
  type[0] = '\0';
  number = 0;
}

Ship::Ship(const char* t, Engine* e, int n) {
  int max = strlen(t);
  if (max <= MAX_SHIP_TYPE && n > 0) {
    number = n;
    strncpy(type, t, MAX_SHIP_TYPE);
    for (int i = 0; i < n; i++) {
      engine[i] = e[i];
    }
  } else {
    type[0] = '\0';
    number = 0;
  }
}

bool Ship::empty() const {
  return type[0] == '\0' && number == 0;
}

float Ship::calculatePower() const {
  float sum = 0;
  for (int i = 0; i < number; i++) {
    sum += engine[i].get();
  }
  return sum * 5;
}

void Ship::display(std::ostream &os) const {
  if (!empty()) {
    os << type << "-" << std::fixed << std::setprecision(2)
       << std::setw(6) << calculatePower() << std::endl;
    for (int i = 0; i < number; i++) {
      engine[i].display(os);
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Ship& s) {
  s.display(os);
  return os;
}

bool operator<(const Ship& s, double p) {
  return s.calculatePower() < p;
}
