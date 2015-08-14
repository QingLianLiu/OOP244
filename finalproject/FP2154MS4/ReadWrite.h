#ifndef __244__READWRITE_H__
#define __244__READWRITE_H__

// hearder file includes go here
#include <iostream>
#include <fstream>

namespace oop244{

    // read write class with pure virutal methods go here
    class ReadWrite {
      public:
        virtual std::fstream& store(std::fstream& file)const = 0;
        virtual std::fstream& load(std::fstream& file) = 0;
        virtual std::ostream& display(std::ostream& os, bool linear)const = 0;
        virtual std::istream& conInput(std::istream& is) = 0;
    };
}
#endif
