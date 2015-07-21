//Workshop 6 - Flying Points Calculator
// w6.cpp
#include <iostream>
#include "FlyingPoints.h"
using namespace std;
void read(const char* msg, FlyingPoints& f)
{
  int inPoints, outPoints;
  cout << "Enter " << msg << endl;
  cout << "Enter number of incoming flying points: ";
  cin >> inPoints;
  cout << "Enter number of spent flying points: ";
  cin >> outPoints;
  f = FlyingPoints(inPoints, outPoints);
}
int main()
{
  FlyingPoints left, right, result, ref;
  cout << "Flying Points Calculator\n";
  cout << "========================\n";
  read("Left Operand...", left);
  read("Right Operand...", right);
  cout << "Result: " << endl;
  left.display();
  cout << " + ";
  right.display();
  cout << " = ";
  result = left + right;
  result.display();
  cout << endl;
  read("2nd Right Operand...", right);
  cout << "Result: " << endl;
  result.display();
  cout << " += ";
  right.display();
  cout << " => ";
  result += right;
  result.display();
  cout << endl;
  read("Reference...", ref);

  if(result == ref) {
    cout << "Result == Reference" << endl;
  } else {
    cout << "Result != Reference" << endl;
  }

  return 0;
}
