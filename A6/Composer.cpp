#include <iostream>
#include <string>
using namespace std;

#include "Composer.h"
#include "Node.h"
#include "LinkedList.h"

/*
 1. It receives nothing.
 2. It returns nothing.
 3. It is the default constructor of the class
    and sets the values to null and 0 respectively.
 */
Composer::Composer() {
    name = " ";
    deathYear = 0;
}

/*
 1. It receives a string and an integer.
 2. It returns nothing.
 3. It is the overloaded constructor of the class,
    sets the values received into this object's vars.
 */
Composer::Composer(string n, int dy) {
    name = n;
    deathYear = dy;
}

/*
 1. It receives a string var.
 2. It returns nothing.
 3. It sets the value received into the obj's var.
 */
void Composer::setName(string n) {
    name = n;
}

/*
 1. It receives a string var.
 2. It returns nothing.
 3. It sets the value received into the obj's var
     after converting it from string to integer.
 */
void Composer::setDeathYear(string dy) {
    deathYear = stoi(dy);
}

/*
 1. It receives nothing.
 2. It returns the value of a private static data member of the object.
 3. It allows you to retrieve the value of a private static data member
    of an object.
 */
string Composer::getName() const {
    return name;
}

/*
 1. It receives nothing.
 2. It returns the value of a private static data member of the object.
 3. It allows you to retrieve the value of a private static data member
    of an object.
 */
int Composer::getDeathYear() const {
    return deathYear;
}

/*
 1. It receives an obj of type 'Composer' as a reference to const obj 'rhs'.
 2. It returns a bool value.
 3. It checks wether the passed argument is less than the obj's value.
 */
bool Composer::operator<= (const Composer &rhs) const {
    if (deathYear <= rhs.deathYear) {
        return true;
    }
    return false;
}

/*
 1. It receives an obj of type 'Composer' as a reference to const obj 'rhs'.
 2. It returns a bool value.
 3. It checks wether two values are equal.
 */
bool Composer::operator== (const Composer &rhs) const {
    if (name == rhs.name) {
        return true;
    }
    return false;
}

/*
 1. It receives an 'ostream' obj 'os' and a constant reference to
    an 'Composer' obj 'obj'.
 2. It returns a reference to the 'ostream' obj 'os'.
 3. It displays names and years of death with a comma
    between them.
 */
ostream& operator<< (ostream& os, const Composer& obj) {
    os << obj.name << ", " << obj.deathYear;
    os << endl;
    return os;
}
