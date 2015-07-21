/* OOP244 - Workshop7
 * Ship.h
 * Date: 14/07/15
 * Author: Larissa Voigt
 * Description: Implement function definitions on w7.cpp */

#include "Engine.h"

#define FIXED_ENGINE_SIZE 10
#define MAX_SHIP_TYPE 6

class Ship {
  private:
    Engine engine[FIXED_ENGINE_SIZE];
    char type[MAX_SHIP_TYPE + 1];
    int number;
  public:
    Ship();
    Ship(const char*, Engine*, int);
    bool empty() const;
    float calculatePower() const;
    void display(std::ostream&) const;
};

std::ostream& operator<<(std::ostream&, const Ship&);
bool operator<(const Ship&, double);
