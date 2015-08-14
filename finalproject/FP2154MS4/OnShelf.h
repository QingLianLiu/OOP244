#ifndef __244_OnShelf_H__
#define __244_OnShelf_H__
#include <iostream>

namespace oop244{
  class OnShelf : public Good {
    private:
      ErrorMessage _err;
    public:
      OnShelf();
      std::fstream& store(std::fstream& file) const;
      std::fstream& load(std::fstream& file);
      std::ostream& display(std::ostream& os, bool linear) const;
      std::istream& conInput(std::istream& is);
    };
}
#endif
