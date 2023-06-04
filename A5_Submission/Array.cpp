#include <iostream>
using namespace std;

#include "Array.h"

bool Array::isSrand = false;
int Array::nOfElem = 0;

/*
 1. It receives nothing.
 2. It returns nothing.
 3. It is the default constructor of the class
    and sets the values to null and 0 respectively.
 */
Array::Array(){
    
    arr = nullptr;
    size = 0;
    
    //to make sure srand hasn't been called
    if(!isSrand) {
        srand(static_cast<unsigned int>(time(0)));
        isSrand = true;
    }
}

/*
 1. It receives the integer size.
 2. It returns nothing.
 3. It is the overloaded constructor of the class, creates a pointer,
    and sets the initial values to each variable and pointer.
 */
Array::Array(int size) {
    
    arr = new int[size];
    this->size = size;
    nOfElem += size;
    
    //to make sure srand hasn't been called
    if(!isSrand) {
        srand(static_cast<unsigned int>(time(0)));
        isSrand = true;
    }
}

/*
 1. It receives an obj of type 'Array' as a reference to const obj 'right'.
 2. It returns nothing.
 3. It is the copy constructor of the class and creates a new object
    as a copy of an existing object of the same class.
 */
Array::Array(const Array& right) {
    size = right.size;
    arr = new int[size];
    
    for(int i = 0; i < size; i++) {
        arr[i] = right.arr[i];
    }
    nOfElem += size;
}

/*
 1. It receives nothing.
 2. It returns nothing.
 3. It is the destructor of the class.
    It deletes the point on the heap and subtracts the size.
 */
Array::~Array(){
    nOfElem -= size;
    delete[] arr;
    arr = nullptr;
}

/*
 1. It receives an obj of type 'Array' as a reference to const obj 'right'.
 2. It returns a reference to the current 'Array' obj '*this'.
 3. It adds the elements of arr2 into elements of arr1.
 */
Array& Array::operator+= (const Array& right) {
    int* newArr = new int[size + right.size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < right.size; i++) {
        newArr[size+i] = right.arr[i];
    }
    // delete the old array
    delete[] arr;
    
    //then point to a new pointer array
    arr = newArr;
    size += right.size;
    
    //add new size to this var
    nOfElem += right.size;
    return *this;
}


/*
 1. It receives an obj of type 'Array' as a reference to const obj 'right'.
 2. It returns a bool value.
 3. It checks wether two arrays are equal in values.
 */
bool Array::operator== (const Array& right) const {
    int min;
    if (size > right.size) {
        min = right.size;
    } else {
        min = size;
    }
    
    for (int i = 0; i < min; i++) {
        if (arr[i] != right.arr[i]){
            return false;
        }
    }
    return true;
}

/*
 1. It receives an obj of type 'Array' as a reference to const obj 'right'.
 2. It returns a bool value.
 3. It checks wether the arr1 is less than the arr2.
 */
bool Array::operator< (const Array& right) const {
    
    int min;
    
    if (size > right.size) {
        min = right.size;
    } else {
        min = size;
    }
    
    for (int i = 0; i < min; i++) {
        if(arr[i] < right.arr[i]) {
            return true;
        } else if (arr[i] > right.arr[i]) {
            return false;
        }
    }
    return false;
}

/*
 1. It receives nothing.
 2. It returns a reference to the current 'Array' obj '*this'.
 3. It acts as a prefix increment operator by increasing each element
    value in the object by 1.
 */
Array& Array::operator++ () {
    for (int i = 0; i < size; i++) {
        arr[i]++;
    }
    return *this;
}

/*
 1. It receives an integer to different from the prefix.
 2. It returns a temp value of a reference to the current 'Array' obj '*this'.
 3. It acts as a postfix increment operator and increase each element value
    in the object by 1.
 */
Array Array::operator++ (int) {
    Array temp = *this;
    operator++();
    return temp;
}

/*
 1. It receives nothing.
 2. It returns a reference to the current 'Array' obj '*this'.
 3. It acts as a prefix decrement operator by decreasing each element
    in the object by 1.
 */
Array& Array::operator--() {
    for (int i = 0; i < size; i++) {
        arr[i]--;
    }
    return *this;
}

/*
 1. It receives an integer to different from the postfix.
 2. It returns a temp value of a reference to the current 'Array' obj '*this'.
 3. It acts as a postfix decrement operator and decrease each element
    in the object by 1.
 */
Array Array::operator--(int) {
    Array temp = *this;
    operator--();
    return temp;
}

/*
 1. It receives an 'ostream' obj 'out' and a constant reference to
    an 'Array' obj 'right'.
 2. It returns a reference to the 'ostream' obj 'out'.
 3. It displays each element in the array with a single space
    between them.
 */
ostream& operator<< (ostream& out, const Array& right) {
    
    for (int i = 0; i < right.size; i++) {
        out << right.arr[i] << " ";
    }
    out << endl;
    return out;
}

/*
 1. It receives nothing.
 2. It returns a reference to the current 'Array' obj '*this'.
 3. It uses Fisher-Yates shuffle algorithm and randomly shuffle the
    elements in the array.
 */
Array& Array::operator!(){
    
    /*
     Steps for the Fisher-Yates shuffle algorithm:
     1. Start at the last element of the array.
     2. Generate a random number between 0 and the
        current element index (inclusive).
     3. Swap the current element with the element at the random index.
     4. Move to the next element in the array and
     repeat steps 2-3 until you reach the first element.
     */
    
    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    for (int i = size -1; i >= 1; i--) {
        int j = rand() % (i + 1);
        
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return *this;
}


/*
 1. It receives nothing.
 2. It returns the smallest value inside the Array object.
 3. It finds the smallest value in the array.
 */
int Array::operator* () {
    int smallestVal = arr[0];
    for (int i = 1; i <size; i++) {
        if(arr[i] < smallestVal){
            smallestVal = arr[i];
        }
    }
    return smallestVal;
}

/*
 1. It receives an integer index i.
 2. It returns a reference to an integer element of the 'arr' dynamic array
    member of the 'Array'.
 3. It is to access the individual elements of the 'Array' obj
    using the subscript [].
 */
int& Array::operator[] (int i){
    return arr[i];
}

/*
 1. It receives an obj of type 'Array' as a reference to const obj 'right'.
 2. It returns a reference to the current 'Array' obj '*this'.
 3. It is the assignment operator.
 */
Array& Array::operator= (const Array& right) {
    if (this != &right) {
        delete[] arr;
        
        nOfElem -= size;
        nOfElem += right.size;
        
        size = right.size;
        arr = new int[size];
        
        for (int i = 0; i < size; i++) {
            arr[i] = right.arr[i];
        }
    }
    return *this;
}

/*
 1. It receives nothing.
 2. It returns the value of a private static data member of the object.
 3. It allows you to retrieve the value of a private static data member
    of an object.
 */

int Array::getNumberOfElements() {
    return nOfElem;
}

/*
 1. It accepts nothing.
 2. It returns the value of a private data member of the object.
 3. It allows you to retrieve the value of a private data member of an object.
 */
int Array::getSize() {
    return size;
}

