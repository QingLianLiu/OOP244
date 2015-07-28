#include <iostream>
#include "Vehicle.h"

class Bus : public Vehicle {
  private:
    int capacity;
  public:
    Bus();
    Bus(double, int);
    ~Bus() {};
    void accelerate();
    void brake();
    void display(std::ostream&) const;
};
