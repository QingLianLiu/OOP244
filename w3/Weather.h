/* OOP244 - Workshop 3
 * Date: 31/05/2015
 * Author: Larissa Voigt
 * Description: Implement header file on w3_template.cpp */

#define SIZE 31

class Weather {
  char date[SIZE];
  double high_temp;
  double low_temp;

  public:
  void set(const char*, double, double);

  void display() const;
};
