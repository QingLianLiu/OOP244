#include <iostream>
#include <fstream>
#include <cstring>
#include "MyFile.h"
using namespace std;
namespace oop244{

  MyFile::MyFile(const char* fname){
      _text[0] = char(0);
      strcpy(_fname, fname);
    }
  fstream& MyFile::store(std::fstream& file)const{
      file.open(_fname, ios::app|ios::out);
      int i = 0;
      while (_text[i]){
            file << _text[i];
            i++;
          }
      file.close();
      return file;
    }
  fstream& MyFile::load(std::fstream& file){
      file.open(_fname, ios::in);
      int i=0;
      while (!file.fail()){
            _text[i++] = file.get();
          }
      file.clear();
      file.close();
      if(i > 0) i--;
      _text[i] = 0;
      return file;
    }
  ostream& MyFile::display(std::ostream& os, bool linear)const{
      for (int i = 0; _text[i]; i++){
            if (linear && _text[i] == '\n'){
                    os << " ";
                  }
            else{
                    os << _text[i];
                  }
          }
      return os;
    }
  istream& MyFile::conInput(std::istream& is){
      is.getline(_text, 9999, EOF);
      return is;
    }
  void MyFile::print(){
      display(cout, false);
      cout << endl;
    }
  std::ostream& operator<<(std::ostream& os, const MyFile& RO){
      return RO.display(os, true);
    }
  std::istream& operator>>(std::istream& is, MyFile& RO){
      return RO.conInput(is);
    }
}
