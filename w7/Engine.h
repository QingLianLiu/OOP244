/* OOP244 - Workshop7
 * Engine.h
 * Date: 14/07/15
 * Author: Larissa Voigt
 * Description: Implement function definitions on w7.cpp */

#define MAX_ENGINE_TYPE 30

class Engine {
  private:
    double size;
    char type[MAX_ENGINE_TYPE + 1];
  public:
    Engine(); //default constructor
    Engine(const char*, double);
    double get() const;
    void display(std::ostream& os) const;
};
