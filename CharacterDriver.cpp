#include "Character.h"
#include <iostream>
#include <string>
#include <ostream>

using namespace std;

int main()
{
    ///@brief first character variables
    string name;
    string role;
    int hp1, ab1, db1, ac1;

    ///@brief second character variables
    string name2;
    string role2;
    int hp2, ab2, db2, ac2;

    cout << "First character name: " << endl;
    cin >> name;
    cout << name << "'s role? " << endl;
    cin >> role;
    cout << name << " the " << role << "'s hit points? " << endl;
    cin >> hp1;
    cout << name << " the " << role << "'s attack bonus? " << endl;
    cin >> ab1;
    cout << name << " the " << role << "'s damage bonus? " << endl;
    cin >> db1;
    cout << name << " the " << role << "'s armor class? " << endl;
    cin >> ac1;

    ///Character1 Object
    Character c1(name, role, hp1, ab1, db1, ac1);
    c1.print(cout);

    cout << endl;
    cout << "Second character name: " << endl;
    cin >> name2;
    cout << name2 << "'s role? " << endl;
    cin >> role2;
    cout << name2 << " the " << role2 << "'s hit points? " << endl;
    cin >> hp2;
    cout << name2 << " the " << role2 << "'s attack bonus? " << endl;
    cin >> ab2;
    cout << name2 << " the " << role2 << "'s damage bonus? " << endl;
    cin >> db2;
    cout << name2 << " the " << role2 << "'s armor class? " << endl;
    cin >> ac2;

    ///Character2 Object
    Character c2(name2, role2, hp2, ab2, db2, ac2);
    c2.print(cout);
    

    c1.attack(c2);
    c2.attack(c1);

    return 0;
}