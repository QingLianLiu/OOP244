/* OOP244 - Workshop7
 * Engine.cpp
 * Date: 14/07/15
 * Author: Larissa Voigt
 * Description: Implement function definitions on w7.cpp */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Engine.h"

Engine::Engine() {
  size = 0;
  type[0] = '\0';
}

Engine::Engine(const char* t, double s) {
  if (s > 0 && t && t[0] != '\0') {
    size = s;
    strncpy(type, t, MAX_ENGINE_TYPE);
  } else {
    size = 0;
    type[0] = '\0';
  }
}

double Engine::get() const {
  return size;
}

void Engine::display(std::ostream& os) const {
  os << std::setprecision(1) << size << " litre - " << type << std::endl;
}
