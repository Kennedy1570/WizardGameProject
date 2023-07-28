#include <iostream>
#include <String>

using namespace std;

class Character{
private:
    string name;
    string role;
    int hitPoints;
    int attackBonus;
    int damageBonus;
    int armorClass;
public:
    Character(string, string, int, int, int, int);
    void print(ostream&);
    void attack(Character& otherCharacter);
    int damage(int amt);
    int getHealth();
    string getName();
    string getRole();
};

