#include <iostream>
#include "Vehicle.h"

class Truck : public Vehicle {
  private:
    bool tow;
  protected:
    bool getTow() const;
  public:
    Truck();
    Truck(double, bool);
    ~Truck() {};
    void accelerate();
    void brake();
    void display(std::ostream&) const;
};
