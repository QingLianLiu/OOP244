#define MAX_NAME 20

class Hero {
  private:
    char name[MAX_NAME + 1];
    double strength;
  public:
    Hero();
    Hero(const char*, double);
    void set(const char*, double);
    bool empty() const;
    double getStrength() const;
    void display(std::ostream&) const;
};

bool operator<(const Hero &,const Hero &);
