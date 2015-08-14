/* OOP244 -Workshop 9
 * Student: Larissa de Jesus Voigt
 * Student Number: 024769143 */

#include <iostream>
#pragma once

class Vehicle {
  private:
    double speed;
  protected:
    double getSpeed() const;
    void setSpeed(double);
  public:
    Vehicle();
    virtual ~Vehicle() {};
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void display(std::ostream&) const = 0;
};

void move(Vehicle&);
void show(const Vehicle&);
