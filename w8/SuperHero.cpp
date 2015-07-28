#include <iostream>
#include <cstring>
#include <iomanip>
#include <new>
#include "SuperHero.h"

SuperHero::SuperHero() {
  powers = nullptr;
  aSize = 0;
  pMax = 0;
}

SuperHero::SuperHero(int* p, int size, int max, const char* n, double s) {
  powers = new int[max];
  for(int i = 0; i < size; i++) {
    if(p[i] < 0) {
      powers[i] = 0;
    } else {
      powers[i] = p[i];
    }
  }
  aSize = size;
  pMax = max;
  set(n, s);
}

void SuperHero::display(std::ostream& os) const {
  Hero::display(os);
  os << "This hero has the following powers:" << std::endl;
  for(int i = 0; i < aSize; i++) {
    int p = powers[i];
    os << p;
    if(p == 0) {
      os << "-failed power";
    } else if(p >= 1 && p <= 10) {
      os << "-firebolt";
    } else if(p >= 11 && p <= 20) {
      os << "-invisibility";
    } else if(p >= 21 && p <= 30) {
      os << "-double strength";
    } else if(p >= 31 && p <= 40) {
      os << "-shield";
    } else {
      os << "-speed";
    }
    os << std::endl;
  }
}

SuperHero::SuperHero(const SuperHero& src) {
  *this = src;
}

SuperHero& SuperHero::operator=(const SuperHero& hero) {
  if(this != &hero) {
    delete [] powers;
    if (hero.powers != nullptr) {
      powers = new (std::nothrow) int[hero.pMax];
      for(int i = 0; i < hero.aSize; i++) {
        powers[i] = hero.powers[i];
      }
    }
  } else {
      powers = nullptr;
    }
  return *this;
}

SuperHero::~SuperHero() {
  if(powers != nullptr) {
    delete [] powers;
    powers = nullptr;
  }
}


