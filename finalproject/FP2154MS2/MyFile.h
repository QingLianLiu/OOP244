#ifndef __244_ReadWrite_H__
#define __244_ReadWrite_H__
#include "ReadWrite.h"
namespace oop244{
  class MyFile : public ReadWrite {
      char _fname[256];
      char _text[10000];
    public:
      MyFile(const char* fname);
      std::fstream& store(std::fstream& file)const;
      std::fstream& load(std::fstream& file);
      std::ostream& display(std::ostream& os, bool linear)const;
      std::istream& conInput(std::istream& is);
      void print();
    };
  std::ostream& operator<<(std::ostream& os, const MyFile& RO);
  std::istream& operator>>(std::istream& id, MyFile& RO);
}
#endif
