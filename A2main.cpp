/*
 30th Jan 2023
 This program is created to save the students' information at a school.
 The collected information are name, number of tests taken, and grades.
 After saving these values, the program will output the number of students,
 their names and scores.
*/

#include <iostream>
#include <string>
using namespace std;

int inputData(string*&, double**&);
void displayData(string*, double**, int);
void cleanHeap(string*, double**, int);

int main(){
    
    string* ptrStr = nullptr;
    double** pptrDouble = nullptr;
    int numStudents = inputData(ptrStr, pptrDouble);
    displayData(ptrStr, pptrDouble, numStudents);
    cleanHeap(ptrStr, pptrDouble, numStudents);
    
    cout << endl;
    
    return 0;
}

/*
 1. It receives a string pointer and a pointer to a double pointer, both
    passed by reference.
 2. It returns the number of students that have been entered.
 3. It asks the users to enter the number of students. For each student,
    the user has to enter the name and their test grades.
*/
int inputData(string*& strPtr, double**& dPPtr){
    
    //prompt the user to enter the number of students (no neg value)
    int numStudents = -1;
    while (numStudents <= 0) {
        cout << "How many students do you have in the system? ";
        cin >> numStudents;
    }
    
    cout << endl;
    
    //create an array of string on the heap and make strPtr points at it
    strPtr = new string[numStudents];
    
    //create an array of pointers on the heap ready to point at double arr
    dPPtr = new double*[numStudents];
    
    //ask the user to enter the names, num of tests & grades of each student
    for (int i = 0; i < numStudents; i++) {
        int numTests;
        
        cout << "Enter the student's name: ";
        cin.ignore();
        getline(cin, strPtr[i]);
        
        cout << "Enter how many tests " << strPtr[i] << " took: ";
        cin >> numTests;
        while (numTests < 0) {
            cout << "Please enter a positive number of tests taken!" << endl;
            cout << "Enter how many tests " << strPtr[i] << " took: ";
            cin >> numTests;
        }
        
        dPPtr[i] = new double[numTests + 1];
        dPPtr[i][0] = numTests;
        
        for (int j = 1; j <= numTests; j++) {
            
            cout << "Enter grade #" << j << ": ";
            cin >> dPPtr[i][j];
            while (dPPtr[i][j] < 0 || dPPtr[i][j] > 100) {
                cout << "Please enter a grade between 0 and 100!" << endl;
                cout << "Enter grade #" << j << ": ";
                cin >> dPPtr[i][j];
            }
        }
        cout << endl;
    }
    return numStudents;
}

/*
 1. It receives the string pointer to the array of student names,
    double pointer to the array of student test scors, the number
    of students.
 2. It returns nothing as it is a void function.
 3. It displays data of number of students, the student's name,and
    a list of the students' test scores.

*/
void displayData(string* strPtr, double** dPPtr, int numStudents) {
    
    cout << "You have " << numStudents << " students in the system." << endl;
    
    for (int i = 0; i < numStudents; i++) {
        cout << "Name of student #" << i + 1 << ": " << strPtr[i] << endl;
        cout << "Grades for student #" << i + 1 << ": ";
        
        for (int j = 1; j <= dPPtr[i][0]; j++) {
            cout << dPPtr[i][j] << " ";
        }
        cout << endl;
    }
}

/*
 1. It receives a string pointer to the array of student names, a double
    pointer to the array of student test scores, and the number of students.
 2. It returns nothing as it is a void function.
 3. It cleans up everything that was dynamically-allocated on the heap.
*/
void cleanHeap(string* strPtr, double** dPPtr, int numStudents) {
    
    delete [] strPtr;
    for (int i = 0; i < numStudents; i++) {
        delete [] dPPtr[i];
    }
    delete [] dPPtr;
    
    strPtr = nullptr;
    dPPtr = nullptr;
}

/*
 How many students do you have in the system? 3

 Enter the student's name: Anna Mull
 Enter how many tests Anna Mull took: 4
 Enter grade #1: 100
 Enter grade #2: 85.2
 Enter grade #3: 50
 Enter grade #4: 68.2

 Enter the student's name: John Doe
 Enter how many tests John Doe took: 3
 Enter grade #1: 100
 Enter grade #2: 40
 Enter grade #3: 70.9

 Enter the student's name: Paige Turner
 Enter how many tests Paige Turner took: -10
 Please enter a positive number of tests taken!
 Enter how many tests Paige Turner took: 2
 Enter grade #1: 1000
 Please enter a grade between 0 and 100!
 Enter grade #1: -1
 Please enter a grade between 0 and 100!
 Enter grade #1: 90
 Enter grade #2: 100

 You have 3 students in the system.
 Name of student #1: Anna Mull
 Grades for student #1: 100 85.2 50 68.2
 Name of student #2: John Doe
 Grades for student #2: 100 40 70.9
 Name of student #3: Paige Turner
 Grades for student #3: 90 100

 Program ended with exit code: 0
*/
