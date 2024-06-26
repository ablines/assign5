#ifndef PLAYER_H
#define PLAYER_H

#include "../../gamecore/gamestate.h"
#include "../gameobject.h"
#include "playerstate.h"

using namespace PlayerState;

// Rewrite this class to inherit from the GameObject class
// at /src/gameobjects/gameobject.h

class Player {
    Position position;

    int health;
    int maxHealth;

    std::string name;

    int attack;

    int healPower = 8;
public:
    Player(Position initialPosition);
    ~Player();

    Position getPosition();

    void setPosition(Position position);

    int getMaxHealth();

    int getHealth();

    std::string getName();

    MoveState move();
    
    void render();
};

#endif