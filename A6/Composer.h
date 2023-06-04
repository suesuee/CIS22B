#ifndef Composer_h
#define Composer_h
#include <string>

class Composer {
public:
    Composer();
    Composer(string n, int dy);
    void setName(string n);
    void setDeathYear(string dy);
    string getName() const;
    int getDeathYear() const;
    bool operator<= (const Composer& rhs) const;
    bool operator== (const Composer& rhs) const;
    friend ostream& operator<< (ostream& os, const Composer&);
private:
    string name;
    int deathYear;
};

#endif /* Composer_h */
