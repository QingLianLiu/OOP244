#include <iomanip>
#include <iostream>
#include "Date.h"
#include "general.h"

using namespace std;

namespace oop244{
  //Returns a unique value out of date. This value is used to compare two dates.
  int Date::value()const{
    return _year * 372 + _mon * 31 + _day;
  }

  //Sets the _readErrorCode member variable to one of the possible values listed above.
  void Date::errCode(int errorCode) {
    _readErrorCode = errorCode;
  }

  // validate(), this is an optional private function to write
  // for validation logic and setting the _readErrorCode.
  // see the read() function description for more detail
  void Date::validate() {
    if(_year < MIN_YEAR || _year > MAX_YEAR) {
      _readErrorCode = YEAR_ERROR;
    } else if(_mon < 1 || _mon > 12) {
      _readErrorCode = MON_ERROR;
    } else if(_day < 1 || _day > mdays()) {
      _readErrorCode = DAY_ERROR;
    } else {
      _readErrorCode = NO_ERROR;
    }
  }

  // mday():
  // returns the day of the month.
  // _mon value must be set for this to work
  // if _mon is invalid, this function returns -1
  // leap years are considered in this logic

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = _mon >= 1 && _mon <= 12 ? _mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
  }

  // constructors
  Date::Date() {
    _year = 0;
    _mon = 0;
    _day = 0;
    _readErrorCode = NO_ERROR;
  }

  Date::Date(int y, int m, int d) {
    _year = y;
    _mon = m;
    _day = d;
    validate();
  }

  // member functions
  int Date::errCode() const {
    return _readErrorCode;
  }

  bool Date::bad() const {
    return errCode() != NO_ERROR;
  }

  // operators
  bool Date::operator==(const Date& D) const {
    return value() == D.value();
  }

  bool Date::operator!=(const Date& D) const {
    return value() != D.value();
  }

  bool Date::operator<(const Date& D) const {
    return value() < D.value();
  }

  bool Date::operator>(const Date& D) const {
    return value() > D.value();
  }

  bool Date::operator<=(const Date& D) const {
    return value() <= D.value();
  }

  bool Date::operator>=(const Date& D) const {
    return value() >= D.value();
  }

  // IO functions
  std::istream& Date::read(std::istream& istr) {
    istr >> _year;
    if (istr.get() != '/') {
      _readErrorCode = CIN_FAILED;
      return istr;
    }
    istr >> _mon;
    if (istr.get() != '/') {
      _readErrorCode = CIN_FAILED;
      return istr;
    }
    istr >> _day;
    validate();
    return istr;
  }

  std::ostream& Date::write(std::ostream& ostr)const {
    ostr << _year << "/";
    if (_mon < 10) {
      ostr << "0";
    }
    ostr << _mon << "/";
    if (_day < 10) {
      ostr << "0";
    }
    ostr << _day;
    return ostr;
  }

  // non-memeber operator overloads
  std::ostream& operator<<(std::ostream& os, const Date& D) {
      return D.write(os);
  }

  std::istream& operator>>(std::istream& is, Date& D) {
      return D.read(is);
  }
}
