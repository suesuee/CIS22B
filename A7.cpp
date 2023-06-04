/*
 20th March 2023 - This is a game program where it has four different types
 of creatures: humans, cyberdemons, balrogs, and elves. There will be two
 creatures in one battle, and each creature takes turn attack each other.
 When one creature has positive hit points but the another one does not
 then the battle is over. If both creatures end up with zero or less hit
 points then the battle is a tie. Otherwise, whoever has hit points less
 than zero loses.
 */

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Creature {
private:
    int strength; //How much damage we can inflict
    int hitpoints; //How much damage we can sustain
public:
    Creature();
    Creature(int newStrength, int newHit);
    virtual int getDamage();
    void setStrength(int newStrength);
    void setHitpoints(int newHit);
    int getStrength() const;
    int getHitpoints() const;
    virtual string getSpecies();
};

/*
 1. It receives nothing.
 2. It returns nothing.
 3. It is the default constructor of the class
 and sets the values to 10 respectively.
 */
Creature::Creature() {
    strength = 10;
    hitpoints = 10;
}

/*
 1. It receives two integer values.
 2. It returns nothing.
 3. It is the overloaded constructor of the class Creature.
 */
Creature::Creature(int newStrength, int newHit) {
    strength = newStrength;
    hitpoints = newHit;
}

/*
 1. It receives an int value.
 2. It returns nothing.
 3. It sets the value of private variable in the class.
 */
void Creature::setStrength(int newStrength) {
    strength = newStrength;
}

/*
 1. It receives an int value.
 2. It returns nothing.
 3. It sets the value of private variable in the class.
 */
void Creature::setHitpoints(int newHit) {
    hitpoints = newHit;
}

/*
 1. It accepts nothing.
 2. It returns the value of a private data member of the object.
 3. It allows you to retrieve the value of a private data member of an object.
 */
int Creature::getStrength() const {
    return strength;
}

/*
 1. It accepts nothing.
 2. It returns the value of a private data member of the object.
 3. It allows you to retrieve the value of a private data member of an object.
 */
int Creature::getHitpoints() const {
    return hitpoints;
}

/*
 1. It accepts nothing.
 2. It returns the type of species of the creatures.
 3. It is a virtual function used in the child classes to return
 the type of species.
 */
string Creature::getSpecies()
{
    return "Unknown";
}

/*
 1. It accepts nothing.
 2. It returns the damage point.
 3. It computes the damage appropriate for objects.
 */
int Creature::getDamage()
{
    int damage;
    
    damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " << damage
    << " points!" << endl;
    
    return damage;
}
// ------------------------------------//

class Human: public Creature {
public:
    Human() : Creature() {}
    Human(int newStrength, int newHit) : Creature(newStrength, newHit) {}
    int getDamage() override {
        return Creature::getDamage();
    }
    
    /*
     1. It accepts nothing.
     2. It returns the type of species of the creatures.
     3. It is a function to override the virtual function in the parent class
     and return the type of species of the child class.
     */
    string getSpecies() override {
        return "Human";
    }
};

class Elf: public Creature {
public:
    Elf() : Creature() {}
    Elf(int newStrength, int newHit) : Creature(newStrength, newHit) {}
    
    /*
     1. It accepts nothing.
     2. It returns the damage point.
     3. It computes the damage appropriate for Elf object.
     */
    int getDamage() override {
        int damage = Creature::getDamage();
        if ((rand() % 10)==0)
        {
            cout << "Magical attack inflicts " << damage
            << " additional damage points!" << endl;
            damage = damage * 2;
        }
        return damage;;
    }
    
    /*
     1. It accepts nothing.
     2. It returns the type of species of the creatures.
     3. It is a function to override the virtual function in the parent class
     and return the type of species of the child class.
     */
    string getSpecies() override {
        return "Elf";
    }
};

class Demon: public Creature {
public:
    Demon() : Creature() {}
    Demon(int newStrength, int newHit) : Creature(newStrength, newHit) {}
    
    /*
     1. It accepts nothing.
     2. It returns the damage point.
     3. It computes the damage appropriate for Demon object.
     */
    int getDamage() override {
        int damage = Creature::getDamage();
        if ((rand() % 100) < 5)
        {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 "
            << " additional damage points!" << endl;
        }
        return damage;
    }
    
    /*
     1. It accepts nothing.
     2. It returns the type of species of the creatures.
     3. It is a function to override the virtual function in the parent class
     and return the type of species of the child class.
     */
    string getSpecies() override {
        return "Demon";
    }
};

class Balrog: public Demon {
public:
    Balrog() : Demon() {}
    Balrog(int newStrength, int newHit) : Demon(newStrength, newHit) {}
    
    /*
     1. It accepts nothing.
     2. It returns the damage point.
     3. It computes the damage appropriate for Balrog object.
     */
    int getDamage() override {
        int damage = Demon::getDamage();
        int damage2 = Demon::getDamage();
        cout << "Balrog speed attack inflicts " << damage2
        << " additional damage points!" << endl;
        damage = damage + damage2;
        return damage;
    }
    
    /*
     1. It accepts nothing.
     2. It returns the type of species of the creatures.
     3. It is a function to override the virtual function in the parent class
     and return the type of species of the child class.
     */
    string getSpecies() override {
        return "Balrog";
    }
};

class Cyberdemon: public Demon {
public:
    Cyberdemon() : Demon() {}
    Cyberdemon(int newStrength, int newHit) : Demon(newStrength, newHit) {}
    
    /*
     1. It accepts nothing.
     2. It returns the damage point.
     3. It computes the damage appropriate for Cyberdemon object.
     */
    int getDamage() override {
        return Demon::getDamage();
    }
    
    /*
     1. It accepts nothing.
     2. It returns the type of species of the creatures.
     3. It is a function to override the virtual function in the parent class
     and return the type of species of the child class.
     */
    string getSpecies() override{
        return "Cyberdemon";
    }
};

// ------------------------------------//

/*
 1. It accepts two objects passed by reference.
 2. It returns nothing.
 3. It determines wether creature 1 or creature 2 wins the game by using
 while loop until the battle is either a tie or over. When one creature
 has positive hit points but the another one does not then the battle
 is over. If both creatures end up with zero or less hit points then
 the battle is a tie. Otherwise, whoever has hit points less than zero loses.
 */
void battleArena(Creature &creature1, Creature &creature2) {
    
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        
        cout << endl;
        cout << "Creature 1 " << creature1.getSpecies() << " has "
        << creature1.getHitpoints() << " hit points now." << endl;
        cout << "Creature 2 " << creature2.getSpecies() << " has "
        << creature2.getHitpoints() << " hit points now." << endl;
        cout << endl;
        
        // Creature 1 attacks Creature 2
        creature1.setHitpoints(creature1.getHitpoints()-creature2.getDamage());
        
        // Display Creature 1's remaining hit points
        cout << "Creature 1 " << creature1.getSpecies() << " has "
        << creature1.getHitpoints() << " points left." << endl;
        
        // Creature 2 attacks Creature 1
        creature2.setHitpoints(creature2.getHitpoints()-creature1.getDamage());
        
        // Display Creature 2's remaining hit points
        cout << "Creature 2 " << creature2.getSpecies() << " has "
        << creature2.getHitpoints() << " points left." << endl;
        
        // If one creature's hit point drops lower than 0, the program exits
        // the loop
        if (creature1.getHitpoints() <= 0 || creature2.getHitpoints() <= 0) {
            break;
        }
        
    }
    
    cout << endl;
    
    if (creature1.getHitpoints() >= 0) {
        cout << creature1.getSpecies() << " won!" << endl;
    } else if (creature2.getHitpoints() >= 0) {
        cout << creature2.getSpecies() << " won!" << endl;
    } else {
        cout << "It is a tie." << endl;
    }
}

int main() {
    srand(static_cast<int>(time(NULL)));
    
    Human human1(30, 10);
    human1.getDamage();
    cout << endl;
    
    Elf elf1;
    elf1.getDamage();
    cout << endl;
    
    Balrog balrog1(50, 50);
    balrog1.getDamage();
    cout << endl;
    
    Cyberdemon cdemon(30, 40);
    cdemon.getDamage();
    cout << endl;
    
    Elf elf2(50, 50);
    Balrog balrog2(50, 50);
    cout << setfill('-') << setw(10) << "-" << endl;
    
    battleArena(elf2, balrog2);
    cout << endl;
    
    return 0;
}

/*
 Human attacks for 20 points!
 
 Elf attacks for 10 points!
 
 Balrog attacks for 22 points!
 Balrog attacks for 21 points!
 Balrog speed attack inflicts 21 additional damage points!
 
 Cyberdemon attacks for 29 points!
 
 ----------
 
 Creature 1 Elf has 50 hit points now.
 Creature 2 Balrog has 50 hit points now.
 
 Balrog attacks for 2 points!
 Balrog attacks for 36 points!
 Balrog speed attack inflicts 36 additional damage points!
 Creature 1 Elf has 12 points left.
 Elf attacks for 28 points!
 Creature 2 Balrog has 22 points left.
 
 Creature 1 Elf has 12 hit points now.
 Creature 2 Balrog has 22 hit points now.
 
 Balrog attacks for 17 points!
 Balrog attacks for 18 points!
 Balrog speed attack inflicts 18 additional damage points!
 Creature 1 Elf has -23 points left.
 Elf attacks for 41 points!
 Creature 2 Balrog has -19 points left.
 
 It is a tie.
 
 Program ended with exit code: 0
 */
