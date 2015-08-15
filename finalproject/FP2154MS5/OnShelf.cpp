#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "OnShelf.h"

namespace oop244 {

  OnShelf::OnShelf() : Good("", "", 0, 1, true) {
  }

  std::fstream& OnShelf::store(std::fstream& file) const {
    file << 'S' << ',' << upc() << ',' << name() << ',' << price() << ',' << taxed()
      << ',' << quantity() << ',' << qtyNeeded() << std::endl;
    return file;
  }

  std::fstream& OnShelf::load(std::fstream& file) {
    char u[MAX_LINE_LEN];
    char n[MAX_LINE_LEN];
    double p;
    int t = 0;
    int q;
    int qn;

    file.getline(u, MAX_LINE_LEN, ',');
    file.getline(n, MAX_LINE_LEN, ',');
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
    if (t) {
      taxed(true);
    } else {
      taxed(false);
    }
    quantity(q);
    qtyNeeded(qn);

    return file;
  }

  std::ostream& OnShelf::display(std::ostream& os, bool linear) const {
    if(_err.isClear() == false) {
      os << _err.message();
    } else if(linear) {
      os << std::setfill(' ') << std::left << std::setw(MAX_UPC_LEN) << upc() << '|'
         << std::setw(20) << name() << '|'
         << std::right << std::setw(7) << std::fixed << std::showpoint << std::setprecision(2) << cost() << '|';
      if(taxed()) {
        os << " t |";
      } else {
        os << "   |";
      }
      os << std::setw(4) << quantity() << '|'
         << std::setw(4) << qtyNeeded() << '|' << std::endl;
    } else {
      os << "Upc: " << upc() << std::endl
         << "Name: " << name() << std::endl
         << "Price: " << price() << std::endl;
      if (taxed() == true) {
        os << "Price after tax: " << (TAX + 1) * price() << std::endl;
      } else {
        os << "Price after tax: N/A" << std::endl;
      }
      os << "Quantity on Hand: " << quantity() << std::endl
         << "Quantity Needed: " << qtyNeeded() << std::endl;
    }
    return os;
  }

  std::istream& OnShelf::conInput(std::istream& is) {
    char u[MAX_UPC_LEN];
    char n[MAX_UPC_LEN];
    double p;
    char t;
    int q;
    int qn;

    if (is.fail()==false) {

      _err.clear();
      std::cout << "OnShelf Good Item: " << std::endl;

      std::cout << "upc: ";
      is >> u;
      if (is.fail()==false) {
        upc(u);
      }

      std::cout << "name: ";
      is >> n;
      if (is.fail()==false) {
        name(n);
      }

      std::cout << "Price: ";
      is >> p;
      if (is.fail()) {
        _err.message("Invalid Price Entry");
      } else {
        price(p);
      }

      if (_err.isClear()) {
        std::cout << "Taxed: ";
        is >> t;
        if (t == 'Y' || t == 'y') {
          taxed(true);
        } else if (t == 'N' || t == 'n') {
          taxed(false);
        } else {
          _err.message("Invalid Taxed Entry, (y)es or (n)o");
          is.setstate(std::ios::failbit);
        }
      }

      if (_err.isClear()) {
        std::cout << "Quantity On Hand: ";
        is >> q;
        if (is.fail()) {
          _err.message("Invalid Quantity Entry");
        } else {
          quantity(q);
        }
      }

      if (_err.isClear()) {
        std::cout << "Quantity Needed: ";
        is >> qn;
        if (is.fail()) {
          _err.message("Invalid Quantity Needed Entry");
        } else {
          qtyNeeded(qn);
        }
      }
    }

    return is;
  }
}
