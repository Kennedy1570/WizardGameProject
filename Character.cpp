#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

/// @brief 
/// @param cName 
/// @param cRole 
/// @param HP 
/// @param AB 
/// @param DB 
/// @param AC 
Character::Character(string cName, string cRole, int HP, int AB, int DB, int AC)
{
    name = cName;
    role = cRole;
    hitPoints = HP;
    attackBonus = AB;
    damageBonus = DB;
    armorClass = AC;
}

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
        cout << endl;
    }else
    {
        cout << "----> didn't hit :/" << endl;
    }
}

int Character::damage(int amt)
{
    hitPoints -= amt;
    return hitPoints;
}