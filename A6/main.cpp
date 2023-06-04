/*
 10 March 2023
 This program uses linkedlist to perform operations such as searching,
 removing, displaying all the lines on a given text file by creating
 a class.
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "LinkedList.h"
#include "Composer.h"

int main() {
    
    LinkedList<Composer> composersList;
    
    // File operation
    ifstream inFile;
    inFile.open("composers.txt");
    if (!inFile) {
        cout << "Error: Invalid File Name!" << endl;
    }
    
    string line;
    Composer c;
    
    // Parsing each line to create a 'Composer' object
    // and add the object to the list
    while (!inFile.eof()) {
        getline(inFile, line, ',');
        c.setName(line);
        getline(inFile, line);
        c.setDeathYear(line);
        composersList.insert(c);
    }
    
    // Perform Search, Remove, and Display functions
    // Exit if user wants
    do {
        string input;
        cout <<
        "Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: ";
        getline(cin,input);
        
        string name;
        
        if (input == "s" || input == "S")
        {
            cout << "Enter a composer name to search for: ";
            getline(cin, name);
            c.setName(name);
            composersList.find(c);
            
        }
        else if (input == "r" || input == "R")
        {
            cout << "Enter a composer's name to remove: ";
            getline(cin, name);
            c.setName(name);
            composersList.remove(c);
            
        }
        else if (input == "d" || input == "D")
        {
            composersList.printList();
            cout << endl;
            
        }
        else if (input == "e" || input == "E")
        {
            break;
        }
    } while(true);
    
    inFile.close();
    return 0;
}

/*
 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
 Enter a composer name to search for: Franz Liszt
 
 Franz Lisztwas found on the list.
 
 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: asdf
 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
 Enter a composer name to search for: Hanz Zimmer
 
 Hanz Zimmer was not found on the list.
 
 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r
 Enter a composer's name to remove: Camille Saint-Saens
 
 Camille Saint-Saens was successfully removed from the list.
 
 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r
 Enter a composer's name to remove: CPE Bach
 
 CPE Bach was not found in the list when attempting to remove.
 
 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d
 
 Claudio Monteverdi, 1643
 Henry Purcell, 1695
 Antonio Vivaldi, 1741
 Johann Sebastian Bach, 1750
 George Frideric Handel, 1759
 Wolfgang Amadeus Mozart, 1791
 Joseph Haydn, 1809
 Ludwig van Beethoven, 1827
 Franz Schubert, 1828
 Felix Mendelssohn, 1847
 Frederic Chopin, 1849
 Robert Schumann, 1856
 Hector Berlioz, 1869
 Richard Wagner, 1883
 Franz Liszt, 1886
 Pyotr Ilyich Tchaikovsky, 1893
 Johannes Brahms, 1897
 Giuseppe Verdi, 1901
 Antonin Dvorak, 1904
 Edvard Grieg, 1907
 Gustav Mahler, 1911
 Claude Debussy, 1918
 Giacomo Puccini, 1924
 Maurice Ravel, 1937
 George Gershwin, 1937
 Sergei Rachmaninoff, 1943
 Bela Bartok, 1945
 Arnold Schoenberg, 1951
 Sergei Prokofiev, 1953
 Igor Stravinsky, 1971
 Dmitri Shostakovich, 1975
 Aaron Copland, 1990
 Leonard Bernstein, 1990
 
 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: e
 Program ended with exit code: 0
 */
