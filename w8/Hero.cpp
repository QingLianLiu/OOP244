#include <iostream>
#include <cstring>
#include <iomanip>
#include "Hero.h"

Hero::Hero() {
  strength = 0;
  name[0] = '\0';
}

Hero::Hero(const char* n, double s) {
  set(n, s);
}

void Hero::set(const char* n, double s) {
  strncpy(name, n, MAX_NAME);
  if (s > 0) {
    strength = s;
  } else {
    strength = 0;
  }
}

bool Hero::empty() const {
  return name[0] == '\0' && strength == 0;
}

double Hero::getStrength() const {
  if (strength > 0) {
    return strength;
  }
  return 0;
}

void Hero::display(std::ostream& os) const {
  if (strength != 0 && name[0] != '\0') {
    os << name << " - " << std::fixed << std::setprecision(0) << strength << std::endl;
  }
}

bool operator<(const Hero& a, const Hero& b) {
  return a.getStrength() < b.getStrength();
}
