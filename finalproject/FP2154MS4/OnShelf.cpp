#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "OnShelf.h"
#include "Good.h"
#include "ReadWrite.h"

namespace oop244{

  OnShelf::OnShelf() : Good("", "", 0, 1, true) {
  }

  std::fstream& OnShelf::store(std::fstream& file) const {
    file << 'S' << ',' << upc() << ',' << name() << ',' << price() << ',' << taxed()
      << ',' << quantity() << ',' << qtyNeeded() << std::endl;
    return file;
  }

  std::fstream& OnShelf::load(fstream& file) {
    char u[MAX_UPC_LEN];
    char n[MAX_UPC_LEN];
    double p;
    bool t;
    int q;
    int qn;

    file.getline(u, MAX_UPC_LEN, ',');
    file.getline(n, MAX_UPC_LEN, ',');
    file >> p;
    file.ignore();
    file >> t;
    file.ignore();
    file >> q;
    file.ignore();
    file >> qn;
    file.ignore();

    //Call Setters

    upc(u);
    name(n);
    price(p);
    taxed(t);
    quantity(q);
    qtyNeeded(qn);

    return file;
  }

  std::ostream& OnShelf::display(ostream& ostr, bool linear) const {
    if(_err.isClear() == false) {
      os << _err.message();
    } else if(linear) {
      os << setfill(' ') << left << setw(MAX_UPC_LEN) << upc() << '|'
         << setw(20) << name() << '|'
         << right << setw(7) << fixed << showpoint << setprecision(2) << cost() << '|';
      if(taxed() == true) {
        os << set(3) << taxed() << '|';
      } else {
        os << set(3) << '|';
      }
      os << setw(4) << quantity() << '|'
         << setw(4) << qtyNeeded() << '|' << std::endl;
    } else {
      os << "Upc: " << upc() << std::endl
         << "Name: " << name() << std::endl
         << "Price: " << price() << std::end;
      if (taxed() == true) {
        os << "Price after tax: " << (TAX + 1) * price << std::endl;
      } else {
        os << "Price after tax: N/A" << std::endl;
      }
      os << "Quantity on Hand: " << quantity() << std::endl
         << "Quantity Needed: " << qtyNeeded() << std::endl;
    }
    return os;
  }

  std::istream& OnShelf::conInput(istream& istr) {
    char u[MAX_UPC_LEN];
    char n[MAX_UPC_LEN];
    double p;
    bool t;
    int q;
    int qn;

    if (is.fail()==false) {
      _err.clear();
      cout << "Perishable Item Entry: " << endl;

      cout << "upc: ";
      is >> u;
      if (is.fail()==false) {
        upc(s);
      }
  }
}
