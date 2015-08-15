#ifndef __244_WPlanner_H__
#define __244_WPlanner_H__

#include "general.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"

namespace oop244{
  class WPlanner{
    char _filename[MAX_LINE_LEN];
    Good* _good[MAX_NO_RECS];
    std::fstream datafile;
    int _noOfGoods;

    // Prevent copy and assignment
    WPlanner(const WPlanner& A);
    WPlanner& operator=(const WPlanner& A);

    int menu();
    void loadRecs();
    void saveRecs();
    void listGoods() const;
    int SearchGoods(const char*) const;
    void updateQty(const char*);
    void addGood(bool);
  public:
    WPlanner(const char*);
    int run();
  };
}
#endif
