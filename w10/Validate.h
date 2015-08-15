#include <iostream>

//Return true if (testValue >= minimum && maximum >= testValue), return false otherwise
bool validate(const T& minimum, const T& maximum, const T& testValue) {
  int temp;
  if (testValue >= minimum && maximum >= testValue) {
    temp = 1;
  } else {
    temp = 0;
  }
  return temp;
}

