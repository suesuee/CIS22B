#include <cstdlib>
#include <iostream>
using namespace std;

#ifndef Array_h
#define Array_h

class Array{
private:
    int size;
    int *arr;
    static int nOfElem;
    static bool isSrand;
public:
    
    //Default Constructor
    Array();
    
    //Overloaded Constructor
    Array(int);
    
    //Copy Constructor
    Array(const Array&);

    //Destructor
    ~Array();
    
    //Compound Assignment Operator
    Array& operator+= (const Array& right);

    //Comparison Operators
    bool operator== (const Array&) const;
    bool operator< (const Array&) const;
    
    //Prefix Operator
    Array& operator++ ();
    Array& operator-- ();
    
    //Postfix Operator
    Array operator++ (int);
    Array operator-- (int);
    
    //Ostream Operator
    friend ostream& operator<< (ostream& out, const Array&);
    
    //Not Operator
    Array& operator! ();
    
    //Indirection Operator
    int operator* ();
    
    //Bracket Operator
    int& operator[] (int);
    
    //Assignment Operator
    Array& operator= (const Array&);
    
    //Getter to access the private variables
    static int getNumberOfElements();
    int getSize();
};

#endif /* Array_h */
