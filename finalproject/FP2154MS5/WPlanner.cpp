#include <cstring>
#include <iomanip>

#include "WPlanner.h"

using namespace std;
namespace oop244{

  WPlanner::WPlanner(const char* fname) {
    if (fname) {
      strncpy(_filename, fname, MAX_LINE_LEN);
      if (strlen(fname) >= MAX_LINE_LEN) {
        _filename[MAX_LINE_LEN-1] = 0;
      }
      for (int i = 0; i < MAX_NO_RECS; i++) {
        _good[i] = nullptr;
      }
      _noOfGoods = 0;
      loadRecs();
    }
  }

  int WPlanner::menu() {
    unsigned int n;
    cout
      << endl
      << "Wedding Planner Management Program" << endl
      << "1 - List goods" << endl
      << "2 - Add On Shelf Good" << endl
      << "3 - Add Custom-Made Good" << endl
      << "4 - Update Good quantity" << endl
      << "0 - Exit program" << endl
      << "> ";
    cin >> n;
    if (cin.fail() || n >= 5) {
      cin.clear();
      cin.ignore();
      n = -1;
    }
    return n;
  }

  void WPlanner::loadRecs() {
    int i = 0;
    char c;
    Good* good;

    datafile.open(_filename, ios::in);
    if (datafile.fail()) {
      datafile.clear();
      datafile.close();
      datafile.open(_filename, ios::out);
    } else {
      while(true) {
        datafile >> c;
        if (datafile.fail()) {
          break;
        }
        datafile.ignore();

        good = nullptr;
        if (c == 'C') {
          good = new CustomMade();
        } else if (c == 'S') {
          good = new OnShelf();
        }

        if (good != nullptr) {
          good->load(datafile);
          _good[i++] = good;
        }
      }
    }

    _noOfGoods = i;
    datafile.clear();
    datafile.close();
  }

  void WPlanner::saveRecs() {
    datafile.open(_filename, ios::out);
    for (int i = 0; i < _noOfGoods; i++) {
      _good[i]->store(datafile);
    }
    datafile.clear();
    datafile.close();
  }

  void WPlanner::listGoods() const {
    double total = 0;

    cout <<
      " Row | UPC    | Good Name          | Cost  |Tax| QTY|Need| Delivery " << endl <<
      "-----|--------|--------------------|-------|---|----|----|----------" << endl;

    for (int i = 0; i < _noOfGoods; i++) {
      total += *_good[i];
      cout << setfill(' ') << right << setw(4) << (i+1) << " | " << *_good[i];
    }

    cout <<
      "--------------------------------------------------------------------" << endl
      << "Total cost of Wedding: $" << fixed << setprecision(2) << showpoint << total << endl;
  }

  int WPlanner::SearchGoods(const char* upc) const {
    bool found = false;
    int i;
    for (i = 0; i < _noOfGoods; i++) {
      if (*_good[i] == upc) {
        found = true;
        break;
      }
    }
    return found ? i : -1;
  }

  void WPlanner::updateQty(const char* upc) {
    int i = SearchGoods(upc);
    int qty, req = 0;
    Good* good;

    if (i >= 0) {
      good = _good[i];
      good->display(cout, false);
      cout << endl << "Please enter the number of purchased goods: ";
      cin >> qty;
      if (cin.fail()) {
        cout << "Invalid Quantity value!" << endl;
      } else {
        cin.ignore();
        req = good->qtyNeeded() - good->quantity();
        if (qty <= req) {
          *good += qty;
        } else {
          *good += req;
          cout << "Too many purchased, only " << req << " is needed, please return the extra " << (qty-req) << "." << endl;
        }
        saveRecs();
        cout << "Updated!" << endl;
      }
    } else {
      cout << "Not found!" << endl;
    }
  }

  void WPlanner::addGood(bool isCustomMade) {
    Good *good;
    if (isCustomMade) {
      good = new CustomMade();
    } else {
      good = new OnShelf();
    }

    cin >> *good;
    if (cin.fail()) {
      good->display(cout, false);
    } else {
      datafile.open(_filename, ios::out | ios::app);
      good->store(datafile);
      datafile.close();
      cout << "Good added" << endl;
    }
  }

  int WPlanner::run() {
    int i = 0;
    char upc[MAX_UPC_LEN];

    while ((i=menu()) != 0) {
      switch (i) {
        case 1:
          listGoods();
          break;
        case 2:
          addGood(false);
          loadRecs();
          cin.clear();
          cin.ignore(10000, '\n');
          break;
        case 3:
          addGood(true);
          loadRecs();
          cin.clear();
          cin.ignore(10000, '\n');
          break;
        case 4:
          cout << "Please enter the UPC: ";
          cin >> upc;
          updateQty(upc);
          break;
        default:
          cout << "==Invalid Selection, try again.===";
          cout << endl;
      }
    }

    cout << "Goodbye!!" << endl;
    return 0;
  }
}
