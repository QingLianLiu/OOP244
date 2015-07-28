#include "Truck.h"

Truck::Truck() {
  setSpeed(0);
  tow = false;
}

Truck::Truck(double s, bool t) {
  setSpeed(s);
  tow = t;
}

void Truck::accelerate() {
  double speed = getSpeed();
  speed += 50;
  setSpeed(speed);
}

void Truck::brake() {
  double speed = getSpeed();
  if(speed >= 20) {
    speed -= 20;
  } else {
    speed = 0;
  }
  setSpeed(speed);
}

void Truck::display(std::ostream& os) const {
  double speed = getSpeed();
  const char *towed = "can";
  if (!tow) {
    towed = "cannot";
  }
  os << "This truck is going " << speed << " after acceleration and braking, and it "
    << towed << " be used to tow." << std::endl;
}
