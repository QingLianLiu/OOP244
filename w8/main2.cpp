#include <iostream>
#include "SuperHero.h"

int main()
{
	int powers[] = { 2, 44, 20, -3 };
	SuperHero hercules(powers, 4, 10, "Hercules", 400);
	hercules.display(std::cout);
}
