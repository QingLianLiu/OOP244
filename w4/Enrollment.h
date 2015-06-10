/* OOP244 - Workshop4
 * Enrollment.h
 * Date: 08/06/15
 * Author: Larissa Voigt
 * Description: Implement header file on w4.cpp */

#define MAX_NAME_LENGTH 30
#define MAX_CODE_LENGTH 10
#define MIN_YEAR 2015
#define MIN_TERM 1
#define MAX_TERM 2
#define MIN_SLOT 1

class Enrollment {
  char name[MAX_NAME_LENGTH + 1];
  char code[MAX_CODE_LENGTH + 1];
  int year;
  int term;
  int slot;
  bool enrolled;
  void safevalues();
public:
  Enrollment(const char*, const char*, int, int, int);
  Enrollment();
  void enroll(const char*, const char*, int, int, int);
  bool isEnrolled();
  void withdraw();
  bool hasConflict(const Enrollment &other) const;
  void display() const;
};
