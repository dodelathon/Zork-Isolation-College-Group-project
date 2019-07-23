#ifndef CHARACTER_H_
#define CHARACTER_H_


#include <string>
#include <vector>
#include "item.h"
using namespace std;



class Character
{
protected:
	string description;
    vector < Item > itemsInCharacter;
    int health;
    int exp, level, expCap;
    virtual void levelUp();
    virtual void addItem(Item& Item);
    virtual void addItem(Item *Item);
    virtual string longDescription() = 0;

public:
	Character(string description);
    virtual ~Character();
    virtual string shortDescription();
    virtual void heal(int = 0);
    virtual void damage(int = 0);
    virtual void addExp(int = 0);
    virtual int getHealth();
    virtual int getLevel();
    virtual vector<Item> getInventory();
    friend string& operator<<(string &tempo, Character &charac);
    friend ostream& operator<<(ostream &tempo, Character &charac);
    void operator+(Item pickup);
    void operator+(Item *pickup);


};

#endif
