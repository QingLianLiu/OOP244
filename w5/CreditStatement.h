/* OOP244 = Workshop 5
 * CreditStatement.h
 * Date: 15/06/15
 * Author: Larissa Voigt
 * Description: Implement header file on w5.cpp */

class CreditStatement {
  private:
    char* item;
  public:
    double price;
    CreditStatement();
    CreditStatement(char* i, double p);
    CreditStatement(const CreditStatement&);
    CreditStatement& operator=(const CreditStatement&);
    ~CreditStatement();
    void display() const;
    bool isGreaterThan(const CreditStatement&) const;
};
