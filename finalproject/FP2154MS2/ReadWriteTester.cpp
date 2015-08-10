#include <iostream>
#include "MyFile.h"
using namespace std;
using namespace oop244;
int main(){
  fstream file;
  MyFile F("readwrite.txt");
  cout << "Run this program few times and keep adding to" <<endl<<"the content of the file created." << endl;
  F.load(file);
  cout << "Linear content of file readwrite.txt: " << endl << endl << F << endl;
  cout << "Press <ENTER> to continue...";
  cin.ignore();
  cout << endl << "readwrite.txt as is: " << endl;
  F.print();
  cout << " ---------------- " << endl << "Enter a text and then"
        <<endl<<"On windows end it by pressing <Ctrl-Z> and <ENTER> in a new line"
        <<endl<<"On Linux or mac end it with a new line with <Ctrl-D>"
        <<endl<< "to append to the end of readwrite.txt:" << endl;
  cin >> F;
  F.store(file);
  cout << "Re-run the program to see the appended lines." << endl;
  return 0;
}
