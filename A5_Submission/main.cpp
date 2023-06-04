/*
 28th Feb 2023
 This program creates an array class that is able to hold multiple
 integer values. The 'Array' class will be given functionality through
 the use of various overloaded operators.
 */

#include <iostream>
using namespace std;

#include "Array.h"

int main() {
    Array arr1(5), arr2(10);
    
    for (int i = 0; i < arr1.getSize(); i++)
        arr1[i] = i;
    
    for (int i = 0; i < arr2.getSize(); i++)
        arr2[i] = i;
    
    cout << "arr1 contains: " << arr1;
    cout << "arr2 contains: " << arr2;
    
    Array arr3(arr1);
    cout << "arr3 contains: " << arr3 << endl;
    
    arr2 = arr2;
    cout << "arr2 contains: " << arr2;
    
    arr3 = arr2;
    cout << "arr3 contains: " << arr3 << endl;
    
    cout << boolalpha;//Display booleans as 'true' or 'false' instead of 1 or 0
    cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
    cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
    cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
    
    arr3[0] = 100;
    cout << "New arr3: " << arr3;
    cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
    cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
    cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
    
    arr1 += arr2;
    cout << "arr1 += arr2: " << arr1 << endl;
    
    cout << "!arr1: " << !arr1;
    cout << "*arr1: " << *arr1 << endl << endl;
    
    cout << "arr++: " << arr1++;
    cout << "arr1 is: " << arr1 << endl;
    
    cout << "--arr1: " << --arr1;
    cout << "arr1 is: " << arr1 << endl;
    
    cout << "Total number of elements in all arrays: " <<
    Array::getNumberOfElements() << endl << endl;
    return 0;
}

/*
 arr1 contains: 0 1 2 3 4
 arr2 contains: 0 1 2 3 4 5 6 7 8 9
 arr3 contains: 0 1 2 3 4

 arr2 contains: 0 1 2 3 4 5 6 7 8 9
 arr3 contains: 0 1 2 3 4 5 6 7 8 9

 arr2 == arr3: true
 arr1 == arr3: true
 arr1 < arr3: false

 New arr3: 100 1 2 3 4 5 6 7 8 9
 arr2 == arr3: false
 arr1 == arr3: false
 arr1 < arr3: true

 arr1 += arr2: 0 1 2 3 4 0 1 2 3 4 5 6 7 8 9

 !arr1: 9 1 4 1 5 8 0 3 3 7 2 4 0 6 2
 *arr1: 0

 arr++: 9 1 4 1 5 8 0 3 3 7 2 4 0 6 2
 arr1 is: 10 2 5 2 6 9 1 4 4 8 3 5 1 7 3

 --arr1: 9 1 4 1 5 8 0 3 3 7 2 4 0 6 2
 arr1 is: 9 1 4 1 5 8 0 3 3 7 2 4 0 6 2

 Total number of elements in all arrays: 35

 Program ended with exit code: 0
 */
