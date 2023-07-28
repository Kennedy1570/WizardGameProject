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