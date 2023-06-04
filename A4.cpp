/*
 15th Feb 2023
 This program is a simple vending machine that sells chips, candy, and soda.
 It asks for a number of quarters to buy the items and show the users
 the amount entered in dollars and cents. After that, it asks the users
 choose one. If the amount entered is sufficient, it will dispense the
 chosen item. If not, it will display a warning that money is not enough.
 If the item is sold out, it will also display a message showing it has been
 sold out. The program will work until the users enter the character N.
 */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#pragma warning (disable:4996) //display the time
using namespace std;

class Snack
{
public:
    Snack();
    Snack(string n, double p, int q);
    void setName(string n);
    void setPrice(double p);
    void setQuantity(int q);
    string getName() const;
    double getPrice() const;
    int getQuantity() const;
    bool buyItem(double& moneyEntered);
    ~Snack();
    
private:
    string name;
    double price;
    int quantity;
    int numSold;
    string getCurrentTime();
    string* times;
    double tempPrice;
};

// Default Constructor
Snack::Snack()
{
    name = "void";
    price = 0.0;
    quantity = 0;
    numSold = 0;
    times = nullptr;
}

// Overloaded Constructor
Snack::Snack(string n, double p, int q)
{
    name = n;
    price = p;
    quantity = q;
    numSold = 0;
    times = new string[quantity];
}

/*
 1. It accepts the value from the constructor that user entered.
 2. It returns nothing as it is a void function.
 3. It sets the value of a private data member of an object.
 */
void Snack::setName(string n) {
    name = n;
}

/*
 1. It accepts the value from the constructor that user entered.
 2. It returns nothing as it is a void function.
 3. It sets the value of a private data member of an object.
 */
void Snack::setPrice(double p) {
    price = p;
}

/*
 1. It accepts the value from the constructor that user entered.
 2. It returns nothing as it is a void function.
 3. It sets the value of a private data member of an object.
 */
void Snack::setQuantity(int q) {
    quantity = q;
    times = new string[quantity];
}

/* No setter for numSold as it's not accessible via outside of class by user.
 It is an internal variable that is incremented each time an item is
 successfully bought.
 */

/*
 1. It accepts nothing.
 2. It returns the value of a private data member of the object.
 3. It allows you to retrieve the value of a private data member of an object.
 */
string Snack::getName() const {
    return name;
}

/*
 1. It accepts nothing.
 2. It returns the value of a private data member of the object.
 3. It allows you to retrieve the value of a private data member of an object.
 */
double Snack::getPrice() const {
    return price;
}

/*
 1. It accepts nothing.
 2. It returns the value of a private data member of the object.
 3. It allows you to retrieve the value of a private data member of an object.
 */
int Snack::getQuantity() const {
    return quantity;
}

/*
 1. It accepts nothing.
 2. It returns an array.
 3. It get the current time that user entered.
 */
string Snack::getCurrentTime() {
    time_t t = time(0);
    struct tm ts;
    char buff[10];
    ts = *localtime(&t);
    strftime(buff, sizeof(buff), "%X", &ts);
    return buff;
}

/* No getter for numSold as it's not accessible via outside of class by user.
 It is an internal variable that is incremented each time an item is
 successfully bought.
 */

/*
 1. It accepts the amount of money user entered.
 2. It returns a boolean value.
 3. It displays message to users according to the amount of money user entered
 wether it's sufficient or not. It also shows a message if the item has been
 sold out. If the money is sufficient, it reduces the product number, record
 the transaction time, and increase the number of sold products.
 */
bool Snack::buyItem(double& moneyEntered) {
    if (quantity == 0) {
        if (moneyEntered < price) {
            cout << name << " is sold out." << endl;
            cout << "Money amount is not sufficient." << endl;
            cout << "$" << moneyEntered << " dispensed below." << endl;
            return false;
        } else {
            cout << name << " is sold out." << endl;
            cout << "$" << moneyEntered << " dispensed below." << endl;
            return false;
        }
    }
    else if (moneyEntered < price) {
        cout << "Please insert more money." << endl;
        return false;
    }
    else {
        moneyEntered -= price;
        quantity--;
        times[numSold] = getCurrentTime();
        numSold++;
        tempPrice = price;
        tempPrice *= numSold;
        cout << "Item has been dispensed below." << endl;
        if(moneyEntered > 0) {
            cout << fixed << setprecision(2) << moneyEntered;
            cout << " dispensed below." << endl;
            moneyEntered = 0;
        }
        return true;
    }
}

// Destructor
Snack::~Snack() {
    
    cout << "Closing info for " << name <<":" << endl;
    cout << right << setw(9) << quantity << " in stock" << endl;
    cout << right << setw(9) << numSold << " sold for a profit of " << "$" <<
    tempPrice << endl;
    cout << endl;
    if (numSold != 0) {
        cout << "Transaction occured at: " << endl;
        for (int i = 0; i < numSold; i++) {
            cout << right << setw(16) << times[i] << endl;
        }
    }
    
    cout << endl;
    
    delete[] times;
    times = nullptr;
    
}

// Functions
void displayVendingMachine(const Snack [], int);
int getQuarters();
void userBuyItem(Snack[], int);
bool promptToContinue();

int main() {
    
    const int SIZE = 3;
    
    Snack snack[SIZE] = {Snack(), Snack("Candy", 1.25, 5),
        Snack("Soda ", 1.00, 2)};
    snack[0].setName("Chips");
    snack[0].setPrice(1.75);
    snack[0].setQuantity(3);
    
    cout << "Welcome to the vending machine!" << endl;
    cout << endl;
    do {
        userBuyItem(snack, SIZE);
    } while (promptToContinue() == true);
    return 0;
}

/*
 1. It accepts the array of Snack objects and the number of elements
 in the array.
 2. It returns nothing as it's a void function.
 3. It displays the vending machine contents.
 */
void displayVendingMachine(const Snack snack[], int SIZE) {
    
    cout << "Item #";
    cout << setw(15) << "Item Name";
    cout << setw(14) << "Price";
    cout << setw(15) << "# in-stock" << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << setw(16) << snack[i].getName() << setw(17) <<
        fixed << setprecision(2) << snack[i].getPrice() << setw(7) <<
        snack[i].getQuantity() << endl;
    }
}

/*
 1. It accepts nothing.
 2. It returns the number of quarters.
 3. It asks the users to enter a number of quarters.
 If the number is less than 1, display an error message
 and ask again.
 */
int getQuarters() {
    
    int numQuarters;
    
    cout << "\nEnter a number of quarters: ";
    cin >> numQuarters;
    
    while (numQuarters < 1) {
        cout << "Error: Please enter a value greater than 0!";
        cout << "\n\nEnter a number of quarters: ";
        cin >> numQuarters;
    }
    return numQuarters;
}

/*
 1. It receives the array of Snack objects and the number of
 elements in the array.
 2. It returns nothing as it's a void function.
 3. It includes the function to display the conents of the vending
 machine and the function to ask for money. It then shows the
 amount in dollar and cents. Lastly, it will ask the users to
 choose an item to be dispensed until the users enter a valid
 choice. Then, it calls the buyItem().
 */
void userBuyItem(Snack snack[], int SIZE) {
    
    double dollars;
    double cents = 0.25;
    int numQuarters;
    int userChoice;
    
    displayVendingMachine(snack, SIZE);
    numQuarters = getQuarters();
    dollars = numQuarters * cents;
    cout << "Amount Entered: $" << fixed << setprecision(2) << dollars
    << endl;
    
    cout << "\nEnter a number between 1 and 3 to make your selection: ";
    cin >> userChoice;
    
    cin.clear();
    cin.ignore(123,'\n');
    
    while(userChoice < 1 || userChoice > SIZE) {
        cout << "Error: Enter a valid number." << endl;
        cout << "\nEnter a number between 1 and 3 to make your selection: ";
        cin >> userChoice;
        cin.clear();
        cin.ignore(123,'\n');
    }
    snack[userChoice - 1].buyItem(dollars);
}

/*
 1. It accepts nothing.
 2. It returns a boolean value.
 3. It changes what users enter to lower case and ask if
 users want to continue the program or not.
 */
bool promptToContinue() {
    char input;
    cout << "\nContinue (Y/N): ";
    cin >> input;
    cout << endl;
    cout << endl;
    
    input = tolower(input);
    
    if(input == 'y') {
        return true;
    } else {
        return false;
    }
}

/*
 Welcome to the vending machine!

 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      5
 3           Soda              1.00      2

 Enter a number of quarters: 5
 Amount Entered: $1.25

 Enter a number between 1 and 3 to make your selection: 2
 Item has been dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      4
 3           Soda              1.00      2

 Enter a number of quarters: 5
 Amount Entered: $1.25

 Enter a number between 1 and 3 to make your selection: 2
 Item has been dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      3
 3           Soda              1.00      2

 Enter a number of quarters: 5
 Amount Entered: $1.25

 Enter a number between 1 and 3 to make your selection: 2
 Item has been dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      2
 3           Soda              1.00      2

 Enter a number of quarters: 5
 Amount Entered: $1.25

 Enter a number between 1 and 3 to make your selection: 2
 Item has been dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      1
 3           Soda              1.00      2

 Enter a number of quarters: 5
 Amount Entered: $1.25

 Enter a number between 1 and 3 to make your selection: 2
 Item has been dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      0
 3           Soda              1.00      2

 Enter a number of quarters: 5
 Amount Entered: $1.25

 Enter a number between 1 and 3 to make your selection: 2
 Candy is sold out.
 $1.25 dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      0
 3           Soda              1.00      2

 Enter a number of quarters: 5
 Amount Entered: $1.25

 Enter a number between 1 and 3 to make your selection: 2
 Candy is sold out.
 $1.25 dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      0
 3           Soda              1.00      2

 Enter a number of quarters: 4
 Amount Entered: $1.00

 Enter a number between 1 and 3 to make your selection: 3
 Item has been dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      0
 3           Soda              1.00      1

 Enter a number of quarters: 4
 Amount Entered: $1.00

 Enter a number between 1 and 3 to make your selection: 3
 Item has been dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      3
 2           Candy             1.25      0
 3           Soda              1.00      0

 Enter a number of quarters: 7
 Amount Entered: $1.75

 Enter a number between 1 and 3 to make your selection: 1
 Item has been dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      2
 2           Candy             1.25      0
 3           Soda              1.00      0

 Enter a number of quarters: 8
 Amount Entered: $2.00

 Enter a number between 1 and 3 to make your selection: 1
 Item has been dispensed below.
 0.25 dispensed below.

 Continue (Y/N): y


 Item #      Item Name         Price     # in-stock
 ----------------------------------------------------
 1           Chips             1.75      1
 2           Candy             1.25      0
 3           Soda              1.00      0

 Enter a number of quarters: -1
 Error: Please enter a value greater than 0!

 Enter a number of quarters: 8
 Amount Entered: $2.00

 Enter a number between 1 and 3 to make your selection: 2
 Candy is sold out.
 $2.00 dispensed below.

 Continue (Y/N): n


 Closing info for Soda :
         0 in stock
         2 sold for a profit of $2.00

 Transaction occured at:
         23:31:15
         23:31:19

 Closing info for Candy:
         0 in stock
         5 sold for a profit of $6.25

 Transaction occured at:
         23:30:38
         23:30:44
         23:30:49
         23:30:54
         23:30:58

 Closing info for Chips:
         1 in stock
         2 sold for a profit of $3.50

 Transaction occured at:
         23:31:25
         23:31:35

 Program ended with exit code: 0
 */
