#include <iostream>
#include <ctype.h>
#include <typeinfo>

//Return true if (testValue >= minimum && maximum >= testValue), return false otherwise
template <class T> bool validate(const T& minimum, const T& maximum, const T& testValue) {
  bool valid;
  if (typeid(T) == typeid(char)) {
    char v = toupper(testValue);
    if (v >= toupper(minimum) && toupper(maximum) >= v) {
      valid = true;
    } else {
      valid = false;
    }
  } else {
    if (testValue >= minimum && maximum >= testValue) {
      valid = true;
    } else {
      valid = false;
    }
  }
  return valid;
}
