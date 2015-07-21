/* Workshop 6
 * FlyingPoints.h
 * Author: Larissa Voigt
 * Purpose: Adding function definitions */

class FlyingPoints {
  private:
    int in;
    int out;
    void updateBalance();
  public:
    FlyingPoints();
    FlyingPoints(int, int);
    void display() const;
    FlyingPoints& operator+=(const FlyingPoints& f);
    friend bool operator==(const FlyingPoints&, const FlyingPoints&);
};

FlyingPoints operator+(const FlyingPoints&, const FlyingPoints&);

