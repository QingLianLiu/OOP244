#include <iostream>
#include "Ship.h"
int const MIN=90;
int main()
{

	Engine engines[3]=
					{Engine("V8",6.0),
					Engine("V8",8.0),
					Engine("Inline",4.2)};

	Ship titanic("liner",engines,3);

	titanic.display(std::cout);

	//Comparing with the standards:
	if(titanic<MIN)
		std::cout<<"Below average!"<<std::endl;
	else
		std::cout<<"Above average!"<<std::endl;

}
