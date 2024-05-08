#include "player.h"
#include "../../controller/enviroment.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

using namespace PlayerState;
using namespace GameState;

// Add your code to implement the Player class here.
Player::Player(Position initialPosition, int maxHealth, int attack, std::string name)
    : GameObject(initialPosition, maxHealth, attack, name){}

Player::~Player(){}

//todo
MoveState Player::move(InputState input){
    switch (input){
        case ACTION_UP:
            if(position.getY() > 0){
                position.moveUP();
            }
            return MOVE;
        case ACTION_DOWN:
            if(position.getY() < GAME_WINDOW_SIZE_Y - 1){
                position.moveDown();
            }
            return MOVE;
        case ACTION_LEFT:
            if(position.getX() > 0){
                position.moveLeft();
            }
            return MOVE;
        case ACTION_RIGHT:
            if(position.getX() < GAME_WINDOW_SIZE_X - 1){
                position.moveRight();
            }
            return MOVE;
        
        default:
            return MOVE;
    }
}




// render
void Player::render() {
    AnsiPrint("PL", green, blue);
}

