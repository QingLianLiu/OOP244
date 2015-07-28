#include "Bus.h"

Bus::Bus() {
  setSpeed(0);
}

Bus::Bus(double s, int c) {
  setSpeed(s);
  capacity = c;
}

void Bus::accelerate() {
  double speed = getSpeed();
  speed += 20;
  setSpeed(speed);
}

void Bus::brake() {
  double speed = getSpeed();
  if(speed >= 10) {
    speed -= 10;
  } else {
    speed = 0;
  }
  setSpeed(speed);
}

void Bus::display(std::ostream& os) const {
  double speed = getSpeed();
  os << "This bus has a total capacity of " << capacity <<
    " passengers and a speed of " << speed << " after accelerating and braking" << std::endl;
}

