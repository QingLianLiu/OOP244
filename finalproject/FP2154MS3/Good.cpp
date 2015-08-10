// includes go here
#include <iostream>
#include <cstring>
#include "Good.h"

namespace oop244 {
  // The Good class implementation goes here
  // Constructors
  Good::Good(){
    _upc[0] = '\0';
    _name = nullptr;
    _price = 0;
    _taxed = false;
    _quantity = 0;
    _qtyNeeded = 0;
  }

  Good::Good(const char* u, const char* n, double p, int q, bool t) {
    upc(u);
    name(n);
    price(p);
    qtyNeeded(q);
    taxed(t);
    quantity(0);
  }

  // Copy Constructor
  Good::Good(const Good& other) {
    upc(other._upc);
    name(other._name);
    price(other._price);
    qtyNeeded(other._qtyNeeded);
    taxed(other._taxed);
    quantity(other._quantity);
  }

  // Assignment Operator=
  Good& Good::operator=(const Good& other) {
    if (this != &other) {
      upc(other._upc);
      name(other._name);
      price(other._price);
      qtyNeeded(other._qtyNeeded);
      taxed(other._taxed);
      quantity(other._quantity);
    }
    return *this;
  }

  // Setters
  void Good::upc(const char* upc) {
    strncpy(_upc, upc, MAX_UPC_LEN);
  }

  void Good::name(const char* name) {
    _name = new (std::nothrow) char[strlen(name) + 1];
    if (_name != nullptr){
      strncpy(_name, name, strlen(name)+1);
    }
  }

  void Good::price(double price) {
    _price = price;
  }

  void Good::qtyNeeded(int qtyNeeded) {
    _qtyNeeded = qtyNeeded;
  }

  void Good::taxed(bool taxed) {
    _taxed = taxed;
  }

  void Good::quantity(int quantity) {
    _quantity = quantity;
  }

  // Getters
  const char* Good::upc() const {
    return _upc;
  }

  char* Good::name() const {
    return _name;
  }

  double Good::price() const {
    return _price;
  }

  int Good::qtyNeeded() const {
    return _qtyNeeded;
  }

  bool Good::taxed() const {
    return _taxed;
  }

  int Good::quantity() const {
    return _quantity;
  }

  double Good::cost() const {
    double cost = _price;
    if(_taxed) {
      cost *= TAX;
    }
    return cost;
  }

  // Member operator overloads
  bool Good::operator==(const char* upc) {
    return strcmp(_upc, upc) == 0;
  }

  int Good:: operator+=(int qty) {
    return _quantity += qty;
  }

  Good::~Good() {
    if (_name != nullptr) {
      delete _name;
    }
  }
}

//Non-member IO operator overloads

std::ostream& operator<<(std::ostream& os, const oop244::Good& RO){
  return RO.display(os, true);
}

std::istream& operator>>(std::istream& is, oop244::Good& RO){
  return RO.conInput(is);
}

// Non-member operator overloads
double operator+=(double &d, const oop244::Good& V) {
  d += V.cost() * V.quantity();
  return d;
}

