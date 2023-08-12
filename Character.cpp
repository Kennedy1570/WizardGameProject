#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

/// @brief parameterized constructor
/// @param cName variable to hold name
/// @param cRole variable to hold role
/// @param HP variable to hold hit points
/// @param AB variable to hold attack bonus
/// @param DB variable to hold damage bonus
/// @param AC variable to hold armor class
Character::Character(string cName, string cRole, int HP, int AB, int DB, int AC)
{
    name = cName;
    role = cRole;
    hitPoints = HP;
    attackBonus = AB;
    damageBonus = DB;
    armorClass = AC;
}

/// @brief method to print out character object
/// @param out cout
void Character::print(ostream& out)
{
    out << "Character Summary: " << std::endl;
    out << endl;
    out << "---------------------" << endl;
    out << endl;
    out << name << " the " << role << "." << std::endl;
    out << "HP: " << hitPoints << endl;
    out << "AB: " << attackBonus << endl;
    out << "DB: " << damageBonus << endl;
    out << "AC: " << armorClass << endl;
    out << endl;
}


/// @brief Function to perform attack on a character by rolling dice multiple times
///until other Characters hitpoints reaches zero
/// @param otherCharacter refernece variable to represent character being attacked
void Character::attack(Character& otherCharacter)
{
    int attB, dmgB;
    srand(time(nullptr));
    cout << "Simulated Combat: " << endl;
    cout << name << " attacks! " << endl;
    int roll1 = rand() % 20;
    attB = attackBonus + roll1;
    cout << "Attack Roll is: " << attackBonus << " + " << roll1 << " = " << attB;
    if(attackBonus > otherCharacter.armorClass)
    {
        cout << "---> HIT!" << endl;
        int roll2 = rand() % 10;
        dmgB = damageBonus + roll2;
        cout << "Damage: " << damageBonus << " + " << roll2 << " = " << dmgB << endl;
        otherCharacter.damage(dmgB);
        cout << otherCharacter.getName() << " has " << otherCharacter.getHealth() << " hitpoints remaining " << endl;
        if(otherCharacter.hitPoints > 0)
        {
            int rollA = rand() % 10;
            dmgB = damageBonus + rollA;
            cout << "Damage: " << damageBonus << " + " << rollA << " = " << dmgB << endl;
            otherCharacter.damage(dmgB);
            cout << otherCharacter.getName() << " has " << otherCharacter.getHealth() << " hitpoints remaining " << endl;
        }
        else if(otherCharacter.hitPoints <= 0)
        {
            cout << "Game over! " << name << " wins" << endl;
        }
        cout << endl;
    }else
    {
        cout << "----> didn't hit :/" << endl;
    }
}

/// @brief function to return damage done to hit points of character that was attacked by subtracting amout from hitpoints
/// @param amount 
/// @return new hit points
int Character::damage(int amt)
{
    hitPoints -= amt;
    return hitPoints;
}

/// @brief function to return characters hit points
/// @return hitpoints
int Character::getHealth()
{
    return hitPoints;
}

/// @brief funtion to return characters name
/// @return name
string Character::getName()
{
    return name;
}

/// @brief Function to return characters role
/// @return role
string Character::getRole()
{
    return role;
}