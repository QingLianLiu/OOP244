#include "Vehicle.h"

Vehicle::Vehicle() {
  speed = 0;
}

double Vehicle::getSpeed() const {
  return speed;
}

void Vehicle::setSpeed(double s) {
  if(s < 0) {
    speed = 0.0;
  } else {
    speed = s;
  }
}

void move(Vehicle& v) {
  v.accelerate();
}

void show(const Vehicle& v) {
  v.display(std::cout);
}
