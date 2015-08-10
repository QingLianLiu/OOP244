#ifndef __244_GOOD_H__
#define __244_GOOD_H__
#include "ReadWrite.h"
#include "general.h"

namespace oop244{

  //inherited from ReadWrite:
  class Good: public ReadWrite {
    private:
      // attribues
      char _upc[MAX_UPC_LEN + 1];
      char *_name;
      double _price;
      bool _taxed;
      int _quantity;
      int _qtyNeeded;
    public:
      // constructors
      Good();
      Good(const char*, const char*, double, int, bool = true);
      Good(const Good&);

      // virtual destructor
      ~Good();
      // setters
      void upc(const char*);
      void name(const char*);
      void price(double);
      void taxed(bool);
      void quantity(int);
      void qtyNeeded(int);
      // getters
      const char* upc() const;
      char* name() const;
      double price() const;
      bool taxed() const;
      int quantity() const;
      int qtyNeeded() const;
      double cost() const;
      // operators
      Good& operator=(const Good&);
      bool operator==(const char*);
      int operator+=(int);
};

  // Helper operator overloads
  double operator+=(double&, const Good&);

}

std::ostream& operator<<(std::ostream& os, const oop244::Good& RO);
std::istream& operator>>(std::istream& is, oop244::Good& RO);

#endif
