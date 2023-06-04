/*
 1/18/2023 (Wed)
 My program is a simple memory game that asks the user
 two pairs of coordinates. Everytime, user enters the pairs, it reveals
 the values behind the chosen coordinate pairs. If the two pairs are
 the same, it flips the cards forever. If not, it changes back to the
 original value, *. The final goal for the user is to find the
 location of all matched pairs. If user wants to give up, he can enter 'q'.
 If not, just press a key on the keyboard except 'q' and continue playing.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
const int LENGTH = 4;
using namespace std;

//Function prototypes
string welcomeMsg();
void initializeCards(int cards[][LENGTH]);
void showCards(int cards[][LENGTH], bool faceup[][LENGTH]);

int main()
{
    string name;
    string userInput;
    int x1 = 0, x2 = 0;
    int y1 = 0, y2 = 0;
    
    //To know wether the pair has been matched before
    bool samePair[LENGTH][LENGTH] = {false};
    
    // 1) Welcome the user and ask him to enter his full name.
    name = welcomeMsg();
    
    // 2) Create a two 2D array that will hold the number for each card.
    //      Pass it to initializeCards function.
    int arr[LENGTH][LENGTH] = {0};
    initializeCards(arr);
    
    // 3) Create the 2D array of Booleans that represents
    //       whether or not the card is matched.
    //       This should be initialized to all FALSE at first.
    bool isMatched[LENGTH][LENGTH] = {false};
    
    //To know user's tries
    int turn = 0;
    bool validInput = false;
    
    
    // 4) while the game is not over :
    // Display the current state of the game board.
    //    Non-matched pairs are "facedown"
    //    and that matched pairs should be "faceup"
    while(true) {
        showCards(arr, isMatched);
        
        while(!validInput) {
            
            // Prompt the user to enter the coordinates of two cards
            cout << "Enter x and y position of the first card: ";
            
            // Input validation (set validInput to false)
            // 1. When user's input is not a number
            // 2. When user's input is out of range
            // 3. When user's input is the same as the first pair
            // 4. When user's input has been included in the matched pair
            if (!(cin >> x1) || !(cin >> y1 )) {
                cout << "Please enter a number." << endl;
                validInput = false;
                cin.clear();
                cin.ignore(123, '\n');
            } else if (x1 < 0 || x1 >= LENGTH || y1 < 0 || y1 >= LENGTH) {
                validInput = false;
                cout << "Please enter in the correct range." << endl;
                cin.clear();
                cin.ignore(123, '\n');
            } else if (samePair[x1][y1] == true && samePair[x2][y2] == true) {
                cout << "This pair has been included." << endl;
                validInput = false;
            } else {
                // When user's input is correct
                validInput = true;
            }
        }
        
        validInput = false;
        
        while(!validInput) {
            
            // Prompt the user to enter the coordinates of two cards
            cout << "Enter x and y position of the second card: ";
            
            // Input validation (set validInput to false)
            // 1. When user's input is not a number
            // 2. When user's input is out of range
            // 3. When user's input is the same as the first pair
            // 4. When user's input has been included in the matched pair
            if (!(cin >> x2) || !(cin >> y2 )) {
                cout << "Please enter a number." << endl;
                validInput = false;
                cin.clear();
                cin.ignore(123, '\n');
            } else if (x2 < 0 || x2 >= LENGTH || y2 < 0 || y2 >= LENGTH) {
                validInput = false;
                cout << "Please enter in the correct range." << endl;
                cin.clear();
                cin.ignore(123, '\n');
            } else if (x2 == x1 && y2 == y1) {
                validInput = false;
                cout << "Please enter a different pair." << endl;
            } else if (samePair[x1][y1] == true || samePair[x2][y2] == true) {
                cout << "This pair has been included." << endl;
                validInput = false;
            } else {
                // When user's input is correct
                validInput = true;
            }
        }
        
        validInput = false;
        
        // If the values of the two coordinates match :
        //     say that a match has been found and flip the cards forever
        if (arr[x1][y1] == arr[x2][y2]) {
            cout << endl;
            
            //Flip to reveal the values forever
            isMatched[x1][y1] = true;
            isMatched[x2][y2] = true;
            showCards(arr, isMatched);
            
            cout << endl;
            cout << "You found a match." << endl;
            
            //Record the matched pairs of cards
            samePair[x1][y1] = true;
            samePair[x2][y2] = true;
            
            //Record tries
            turn++;
            cout << endl;
            
            // else :
            // temporarily flip over the cards to show the user the values,
            // then flip them over again.
        } else {
            cout << endl;
            
            //Flip to show the values
            isMatched[x1][y1] = true;
            isMatched[x2][y2] = true;
            showCards(arr, isMatched);
            
            //Record the unmatched pairs of cards
            samePair[x1][y1] = false;
            samePair[x2][y2] = false;
            
            cout << endl;
            cout << "No match." << endl;
            cout << "Flipping cards over again." << endl;
            
            //Flip over to * again
            isMatched[x1][y1] = false;
            isMatched[x2][y2] = false;
            
            //Record tries
            turn++;
            cout << endl;
        }
        
        //Creating File to store user's infomation
        ofstream outFile;
        outFile.open("gamerecord.txt");
        
        bool gameOver = true;
        for (int i = 0; i < LENGTH; i++) {
            for (int j = 0; j < LENGTH; j++) {
                if (!isMatched[i][j]) {
                    gameOver = false;
                    break;
                }
            }
        }
        
        // 5) Save the user’s name and how many turns it took to
        // win the game into an output text file. If he enter 'q'
        // before winning save “Don’t give up” message in the file.
        if (gameOver) {
            cout << "Congratulations! You are the winner." << endl;
            cout << "You won after " << turn << " tries." << endl;
            outFile << name << " took " << turn << " turns to win." << endl;
            break;
        }
        
        cout << "Enter 'q' to quit or press any key to continue...";
        cin >> userInput;
        cout << endl;
        if (userInput == "q") {
            outFile << "Don't give up!" << endl;
            break;
        }
        outFile.close();
    }
    
    return 0;
}

// ======================
// welcomeMsg
// It receives nothing as it shows welcome message.
// It returns user's name.
// It displays welcome message and gets user's name.
// ======================
string welcomeMsg () {
    string name;
    cout << "Welcome to my game!" << endl;
    cout << "Please enter your full name: ";
    getline(cin, name);
    cout << "Find all the matching pairs on the board!" << endl;
    return name;
}

// ======================
// initializeCards
// It recieves a card array of 3 rows, 3 cols.
// It returns nothing as it's a void function.
// It sets values to each array index and randomly shuffles them.
// ======================
void initializeCards(int cards[][LENGTH])
{
    srand(time(NULL));
    int x1, y1, x2, y2;
    int temp;
    
    // Place pairs in known locations -  this is how our array looks like after
    cards[0][0] = 1; cards[0][1] = 1;//   1  1  2  2
    cards[0][2] = 2; cards[0][3] = 2;
    cards[1][0] = 3; cards[1][1] = 3;//   3  3  4  4
    cards[1][2] = 4; cards[1][3] = 4;
    cards[2][0] = 5; cards[2][1] = 5;//   5  5  6   6
    cards[2][2] = 6; cards[2][3] = 6;
    cards[3][0] = 7; cards[3][1] = 7;//   7  7  8   8
    cards[3][2] = 8; cards[3][3] = 8;
    
    // Now that 2D has been initialized with 8 pairs, we want to
    // shuffle the board so
    // that the pairs aren't right next to each other
    for (int i = 0; i < 30; i++) {
        //Get set of random coordinates and swap
        //First random coordinate on our 2d "grid"
        y1 = rand() % LENGTH;
        x1 = rand() % LENGTH;
        //Second random coordinate of our 2d "grid"
        y2 = rand() % LENGTH;
        x2 = rand() % LENGTH;
        
        temp = cards[x1][y1];
        cards[x1][y1] = cards[x2][y2];
        cards[x2][y2] = temp;
    }
    cout << endl;
}

// ======================
// showCards
// It receives a card array of 3 rows, 3 cols and a bool value.
// It returns nothing as it's a void function.
// It generates a display on the screen.  If faceup=false,
// an * is output, otherwise the card in that slot is output.
// ======================
void showCards(int cards[][LENGTH], bool faceup[][LENGTH]) {
    
    cout << "    0 1 2 3 " << endl;
    cout << "================= " << endl;
    
    for (int i = 0; i < LENGTH; i++) {
        cout << i << " | ";
        for (int j = 0; j < LENGTH; j++) {
            if (faceup[i][j])
            {
                cout << cards[i][j] << " ";
            }
            else {
                cout << "* ";
            }
        }
        cout << " | ";
        cout << endl;
    }
    cout << "=================" << endl;
}

/*
 
 Program Run
 1. one input with an invalid value
 
 Welcome to my game!
 Please enter your full name: sue sue
 Find all the matching pairs on the board!
 
     0 1 2 3
 =================
 0 | * * * *  |
 1 | * * * *  |
 2 | * * * *  |
 3 | * * * *  |
 =================
 Enter x and y position of the first card: 0 9
 Please enter in the correct range.
 Enter x and y position of the first card: a d
 Please enter a number.
 Enter x and y position of the first card:
 
 2. Three inputs with valid values
 Welcome to my game!
 Please enter your full name: sue sue
 Find all the matching pairs on the board!
 
     0 1 2 3
 =================
 0 | * * * *  |
 1 | * * * *  |
 2 | * * * *  |
 3 | * * * *  |
 =================
 Enter x and y position of the first card: 0 0
 Enter x and y position of the second card: 0 1
 
     0 1 2 3
 =================
 0 | 5 5 * *  |
 1 | * * * *  |
 2 | * * * *  |
 3 | * * * *  |
 =================
 
 You found a match.
 
 Enter 'q' to quit or press any key to continue...1
 
     0 1 2 3
 =================
 0 | 5 5 * *  |
 1 | * * * *  |
 2 | * * * *  |
 3 | * * * *  |
 =================
 Enter x and y position of the first card: 1 2
 Enter x and y position of the second card: 3 3
 
     0 1 2 3
 =================
 0 | 5 5 * *  |
 1 | * * 8 *  |
 2 | * * * *  |
 3 | * * * 2  |
 =================
 
 No match.
 Flipping cards over again.
 
 Enter 'q' to quit or press any key to continue...k
 
     0 1 2 3
 =================
 0 | 5 5 * *  |
 1 | * * * *  |
 2 | * * * *  |
 3 | * * * *  |
 =================
 Enter x and y position of the first card: 2 2
 Enter x and y position of the second card: 3 3
 
     0 1 2 3
 =================
 0 | 5 5 * *  |
 1 | * * * *  |
 2 | * * 6 *  |
 3 | * * * 2  |
 =================
 
 No match.
 Flipping cards over again.
 
 Enter 'q' to quit or press any key to continue...
 
 3. one input with the quit choice
 Welcome to my game!
 Please enter your full name: Sue Sue
 Find all the matching pairs on the board!
 
     0 1 2 3
 =================
 0 | * * * *  |
 1 | * * * *  |
 2 | * * * *  |
 3 | * * * *  |
 =================
 Enter x and y position of the first card: 1 0
 Enter x and y position of the second card: 0 2
 
     0 1 2 3
 =================
 0 | * * 6 *  |
 1 | 6 * * *  |
 2 | * * * *  |
 3 | * * * *  |
 =================
 
 You found a match.
 
 Enter 'q' to quit or press any key to continue...q
 
 Program ended with exit code: 0
 
 */
