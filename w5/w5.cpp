// Workshop 5 - Credit Card Statement
// w5.cpp

#include <iostream>
#include <cstring>
#include "w5.h"
#include "CreditStatement.h"

using namespace std;

void sort(CreditStatement* statement, int n);

int main()
{
    double price;
    int n = 0;
	CreditStatement statement[MAX_PURCHASES];

	cout << "Credit Statement Processor\n";
	cout << "==========================\n";

	do
    {
		cout << "Item price (0 to quit): ";
		cin >> price;
		if(cin.fail() || (cin.get() != '\n'))
        {
			cin.ignore(2000, '\n');
			cerr << "Bad character. Try again." << endl;
			cin.clear();
		}
		else if((int)price != 0)
        {
			cout << "Statement item: ";
			char item[MAX_LINE_LENGTH];
			cin.getline(item, MAX_LINE_LENGTH);
			if(strlen(item) > 0)
            {
				statement[n] = CreditStatement(item, price);
                n++;
            }
		}
	} while((int)price != 0 && n < MAX_PURCHASES);

	cout << endl;

	//sort(statement, n);

	cout << "         Credit Statement\n\n";
	cout << " Item                        Price\n";
	cout << "----------------------------------\n";

	for(int i = 0; i < n; i++)
    {
		statement[i].display();
	}
	cout << endl;

    return 0;
}

// sort sorts the elements of Credit Card Statement[n] in ascending order
//
void sort(CreditStatement* s, int n)
{
	int i, j;
	CreditStatement temp;

	for(i = n - 1; i > 0; i--)
    {
		for(j = 0; j < i; j++)
        {
			if(s[j].isGreaterThan(s[j + 1]))
            {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}
