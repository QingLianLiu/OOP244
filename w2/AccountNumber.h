/*  OOP244 - Workshop 2
 *  Date: 25/05/2015
 *  Author: Larissa Voigt
 *  Description: Implement header file on w2.cpp */

#define MAX_NAME_LENGTH 41

namespace oop244 {
  class AccountNumber {
    private:
      char _name[MAX_NAME_LENGTH + 1];
      int _bankCode;
      int _branchCode;
      int _accountNumber;
      bool _validAccNumber;
    public:
      void setName(const char name[]);
      void setAccountNumber(int bankCode, int branchCode, int accountNumber);
      void display() const;
      bool isValid() const;
  };
}
