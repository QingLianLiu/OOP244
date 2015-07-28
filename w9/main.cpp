#include "Bus.h"
#include "Truck.h"

int main()
{

  Vehicle* vehicle;
  vehicle = new Bus(20, 78);
  move(*vehicle);
  show(*vehicle);
  delete vehicle;
  vehicle = new Truck(30, true);
  move(*vehicle);
  show(*vehicle);
  delete vehicle;

  return 0;
}
