#include <iostream>
#include "Hero.h"

int main()

{
  Hero stuart("Stu Dent", 400.00);
  Hero trevor("T Cher", 650.00);

  stuart.display(std::cout);
  trevor.display(std::cout);

  if (trevor<stuart)
    std::cout << "Stewart is stronger.";
  else
    std::cout << "Trevor is stronger.";
}
