#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{


public:
    explicit Player(string desc = "");
    virtual ~Player();
    virtual string longDescription();
};

#endif // PLAYER_H
