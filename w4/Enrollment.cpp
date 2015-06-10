/* OOP244 - Workshop4
 * Enrollment.cpp
 * Date: 08/06/15
 * Author: Larissa Voigt
 * Description: Implement function definitions on w4.cpp */

#include "Enrollment.h"
#include <iostream>
#include <string.h>

using namespace std;

void Enrollment::safevalues() {
  name[0] = '\0';
  code[0] = '\0';
  year = 0;
  term = 0;
  slot = 0;
  enrolled = false;
}

Enrollment::Enrollment() {
  safevalues();
}

Enrollment::Enrollment(const char* course_name, const char* course_code,
                       int course_year, int course_term, int course_slot) {

  bool valid = true;

  if (course_name && course_name != '\0') {
    strncpy(name, course_name, MAX_NAME_LENGTH);
  } else {
    valid = false;
  }

  if (course_code && course_code != '\0') {
    strncpy(code, course_code, MAX_CODE_LENGTH);
  } else {
    valid = false;
  }

  if (course_year >= MIN_YEAR) {
    year = course_year;
  } else {
    valid = false;
  }

  if (course_term >= MIN_TERM && course_term <= MAX_TERM) {
    term = course_term;
  } else {
    valid = false;
  }

  if (course_slot >= MIN_SLOT) {
    slot = course_slot;
  } else {
    valid = false;
  }

  if (valid) {
    enrolled = true;
  } else {
    safevalues();
  }
}

void Enrollment::enroll(const char* course_name, const char* course_code,
                        int course_year, int course_term, int course_slot) {
  strncpy(name, course_name, MAX_NAME_LENGTH);
  strncpy(code, course_code, MAX_CODE_LENGTH);
  year = course_year;
  term = course_term;
  slot = course_slot;
  enrolled = true;
}

bool Enrollment::isEnrolled() {
  return enrolled;
}

void Enrollment::withdraw() {
  safevalues();
  enrolled = false;
  cout << "The student is successfully withdrawl!" << endl;
}

bool Enrollment::hasConflict(const Enrollment &other) const {
  return year == other.year && term == other.term &&  slot == other.slot;
}

void Enrollment::display() const {
  if (enrolled) {
    cout << name << endl;
    cout << code << "\tYear: " << year << endl;
    cout << "Term: " << term << "\tSlot: " << slot << endl;
  } else {
    cout << "Student not enrolled!" << endl;
  }
}
