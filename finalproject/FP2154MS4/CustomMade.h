#ifndef __244_CUSTOMMADE_H__
#define __244_CUSTOMMADE_H__

#include "Good.h"
#include "Date.h"
#include "ErrorMessage.h"

namespace oop244{

  class CustomMade: public Good {
    private:
      ErrorMessage _err;
      Date _delivery;

    public:
      CustomMade();
      const Date& delivery() const;
      void delivery(const Date&);
      std::fstream& store(std::fstream& file) const;
      std::fstream& load(std::fstream& file);
      std::ostream& display(std::ostream& os, bool linear) const;
      std::istream& conInput(std::istream& is);
  };

}

#endif
