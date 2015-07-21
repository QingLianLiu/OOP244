#include "Hero.h"

class SuperHero : public Hero {
  private:
    int aSize; // actual size
    int pMax;  // max size
    int *powers;
  public:
    SuperHero();
    SuperHero(int*, int, int, const char*, double);
    void display(std::ostream&) const;
};
