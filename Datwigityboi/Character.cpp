#include "Character.h"

Character::Character(string description)
{
	this->description = description;
}

void Character::addExp(int newExp )
{
    this->exp += newExp;
}

void Character::damage(int damage)
{
    this->health -= damage;
}

void Character::heal(int heal)
{
    this->health += heal;
}

void Character::levelUp()
{
    this->level++;
    this->exp = exp - expCap;
    this->expCap = expCap/0.20;
}

int Character::getHealth()
{
    return this->health;
}

vector<Item> Character::getInventory()
{
    return this->itemsInCharacter;
}

int Character::getLevel()
{
    return this->level;
}

string Character::shortDescription()
{
    return this->description;
}

Character::~Character()
{

}

void Character::addItem(Item &item)
{
    itemsInCharacter.push_back(item);
}
void Character::addItem(Item *item)
{
    itemsInCharacter.push_back(*item);
    delete item;
}

string& operator<<(string &tempo, Character &charac)
{
    tempo += charac.longDescription();
    return tempo;
}

ostream& operator<<(ostream &tempo, Character &charac)
{
    tempo << charac.longDescription() << endl;
    return tempo;
}

void Character::operator+(Item pickup)
{
    this->addItem(pickup);
}

void Character::operator+(Item *pickup)
{
    this->addItem(pickup);
    delete pickup;
}





