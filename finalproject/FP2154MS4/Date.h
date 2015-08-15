#ifndef __244_DATE_H__
#define __244_DATE_H__
// header file includes
#include <iostream>

namespace oop244{
  // Error code values goes here
  #define NO_ERROR 0
  #define CIN_FAILED 1
  #define YEAR_ERROR 2
  #define MON_ERROR 3
  #define DAY_ERROR 4
  class Date{
  private:
    // private member variables
    int _year;
    int _mon;
    int _day;
    int _readErrorCode;
    // private member functions and setters
    int value() const;
    void errCode(int);
    void validate();
  public:
    // constructors
    Date();
    Date(int, int, int);
    // operator overloads
    bool operator==(const Date& D)const;
    bool operator!=(const Date& D)const;
    bool operator<(const Date& D)const;
    bool operator>(const Date& D)const;
    bool operator<=(const Date& D)const;
    bool operator>=(const Date& D)const;
    // IO member funcions
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr)const;
    // public member functions and getters
    int mdays()const;
    int errCode()const;
    bool bad()const;
  };
  // operator << and >> overloads prototypes for ostream and istream go here


  std::ostream& operator<<(std::ostream& os, const Date& D);
  std::istream& operator>>(std::istream& is, Date& D);
}
#endif
