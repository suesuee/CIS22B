/*
 6th Feb 2023
 The program creates a simple database system for movie.
 The user will be prompted to enter a movie title to search, and if found, the information will be displayed. The search is not case sensitive, and the movie user saved can be added to a separate file called "favorites.txt". Upon exit, all saved movies from the favorites file will be displayed.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

static bool firstCall = true;

struct Movie {
    string title;
    double grossTotal;
    string director;
    string releaseDate;
    int runtime;
};

int numberOfLines(ifstream&);
void populateMovieFromFile(ifstream&, Movie&);
void displayMovie(const Movie&);
Movie* createDatabase(int &);
bool caseInsensitiveCmp(string, string);
void findMovie(Movie*, int);
void saveToFile(const Movie&);
bool PromptToContinue();
void displayFavorites();

int main() {
    int lineCount;
    
    Movie movieInfo;
    
    Movie* mPtr = nullptr;
    mPtr = createDatabase(lineCount);
    
    do {
        findMovie(mPtr, lineCount);
    } while (PromptToContinue() == true);
    
    displayFavorites();
    
    delete [] mPtr;
    mPtr = nullptr;
    
    return 0;
}

/* accepts input file
 returns an integer represent the number of lines
 it counts the line in the input file.
*/
int numberOfLines(ifstream& file) {
    string temp;
    int count = 0;
    while(getline(file, temp)) {
        count++;
    }
    return count;
}
/*
 It accepts file and movie object passed by reference.
 It returns nothing as it's void function.
 It separates the input value by comma and put in each member
 of struct Movie variables.
 */

void populateMovieFromFile(ifstream& inFile, Movie& m) {
    
    string line;
    
    getline(inFile, line, ',');
    m.title = line;
    getline(inFile, line, ',');
    m.grossTotal = stod(line);
    getline(inFile, line, ',');
    m.director = line.substr(1);
    getline(inFile, line, ',');
    m.releaseDate = line.substr(1);
    getline(inFile, line);
    m.runtime = stoi(line);
}
/*
 It accepts a constant pass by reference movie object.
 It returns nothing as it's void function.
 It displays the movie information on the screen.
 */
void displayMovie(const Movie& m) {
    cout << endl;
    cout << setw(15) << "Title: " << setw(3) << m.title << endl;
    cout << setw(15) << "Gross Total: " << setw(3) << m.grossTotal << " billion dollars" << endl;
    cout << setw(15) << "Director: " << setw(3) << m.director << endl;
    cout << setw(15) << "Release Date: " << setw(3) << m.releaseDate << endl;
    cout << setw(15) << "Runtime: " << setw(3) << m.runtime << " minutes" << endl;
    cout << endl;
}
/*
 It accepts a pass by reference the movie numbers in file.
 It returns a database pointer with all the struct members'
 values included.
 It asks for the input file, create a dynamically allocated array on the heap and insert the values of struct members into the array on the heap.
 */
Movie* createDatabase(int& numMovies) {
    string file;
    ifstream inFile;
    do{
        cout << "Enter an input file name: ";
        getline(cin, file);
        inFile.open(file);
        if(!inFile) {
            cout << "Error: Invalid File Name." << endl;
            cout << endl;
        }
    } while(!inFile);
    
    numMovies = numberOfLines(inFile);
    Movie* database = new Movie[numMovies];
    
    inFile.clear();
    inFile.seekg(0, ios::beg);
    
    for (int i = 0; i < numMovies; i++) {
        populateMovieFromFile(inFile, database[i]);
    }
    
    inFile.close();
    return database;
}

/*
 It accepts two string to compare.
 It returns a boolean value.
 It converts the strings to lower case first and compare them. If the same, return true.
 */

bool caseInsensitiveCmp (string s1, string s2) {
    
    for (int i = 0; i < s1.length(); i++) {
        s1[i] = tolower(s1[i]);
    }
    
    for (int i = 0; i < s2.length(); i++) {
        s2[i] = tolower(s2[i]);
    }
    return s1 == s2;
}

/*
 It accepts the movie pointer and the number of movies in file.
 It returns nothing as it's void function.
 It asks for movie to search for and display the info. It asks users whether to save the file or not. If answer is yes, it saves the file.
 */

void findMovie (Movie* mptr, int numMovie) {
    
    string searchTitle;
    char ans;
    bool found = false;
    
    cout << "Enter a movie to search for: " << endl;
    if (firstCall == false) {
        cin.ignore();
    }
    getline(cin, searchTitle);
    
    for (int i = 0; i < numMovie; i++) {
        if (caseInsensitiveCmp(mptr[i].title, searchTitle)) {
            displayMovie(mptr[i]);
            found = true;
            cout << "Would you like to save the above movie (Y or N): " << endl;
            cin >> ans;
            
            ans = tolower(ans);
            
            if (ans == 'y') {
                cout << "Successfully saved to favorites.txt" << endl;
                saveToFile(mptr[i]);
            }
            
        }
    }
    
    if (found == false) {
        cout << "Error: " << searchTitle << " not found in database. Please try again.";
        cout << endl;
    }
}

/* It accetps a constant movie object passed by reference.
 It returns nothing as it's void function.
 It creates a "favourites.txt" file to store the values users saved. If created, the inputs are appended.
 */

void saveToFile (const Movie& m) {
    ofstream outFile;
    
    if(firstCall) {
        outFile.open("favorites.txt");
        firstCall = false;
    } else {
        outFile.open("favorites.txt", ios::app);
    }
    
    outFile << setw(15) << "Title: " << m.title << endl;
    outFile << setw(15) << "Gross Total: " << m.grossTotal << " billion dollars" << endl;
    outFile << setw(15) << "Director: " << m.director << endl;
    outFile << setw(15) << "Released Date: " << m.releaseDate << endl;
    outFile << setw(15) << "Run Time: " << m.runtime << endl;
    outFile << endl;
    
    outFile.close();
}

/*
 It accepts nothing.
 It returns boolean value.
 It asks user if he wants to exit or not.
 if yes, return false. If no, return true.
 */

bool PromptToContinue() {
    char input;
    cout << "Would you like to exit? (Y/N): ";
    cin >> input;
    cout << endl;
    
    input = tolower(input);
    
    if(input == 'y') {
        return false;
    } else {
        firstCall = false;
        return true;
    }
    
    return true;
}

/* It accepts nothing.
 It returns nothing as it's void function.
 It loops the file to show the values on the display as
 saved movies to users.
 */
void displayFavorites() {
        ifstream inFS;
        
        string line;
        inFS.open("Favorites.txt");

        if(inFS >> line) {
            inFS.clear();
            inFS.seekg(0,ios::beg);
            cout << "Your saved movies are: " << endl;
            while (inFS) {
                for (int i = 0; i < 5; i++) {
                    getline(inFS, line);
                    cout << line;
                    cout << endl;
                }
                cout << endl;
            }
        } else {
            cout << "Error: No favorite movies found." << endl;
        }


    inFS.close();
}

/*
 Enter an input file name: input
 Error: Invalid File Name.

 Enter an input file name: input.txt
 Enter a movie to search for:
 avatar

         Title: Avatar
   Gross Total: 2.788 billion dollars
      Director: James Cameron
  Release Date: 12/18/09
       Runtime: 161 minutes

 Would you like to save the above movie (Y or N):
 Y
 Successfully saved to favorites.txt
 Would you like to exit? (Y/N): N

 Enter a movie to search for:
 frozen

         Title: Frozen
   Gross Total: 1.276 billion dollars
      Director: Chris Buck & Jennifer Lee
  Release Date: 11/27/13
       Runtime: 102 minutes

 Would you like to save the above movie (Y or N):
 Y
 Successfully saved to favorites.txt
 Would you like to exit? (Y/N): Y


 Your saved movies are:

         Title: Avatar
   Gross Total: 2.788 billion dollars
      Director: James Cameron
 Released Date: 12/18/09
      Run Time: 161

         Title: Frozen
   Gross Total: 1.276 billion dollars
      Director: Chris Buck & Jennifer Lee
 Released Date: 11/27/13
      Run Time: 102


 Program ended with exit code: 0
 */
