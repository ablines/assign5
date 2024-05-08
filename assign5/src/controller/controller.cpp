#include <iostream>

#include "controller.h"
#include "../gameobjects/room/roomdata.h"
#include "../functions/position/position.h"
#include "../functions/AnsiPrint/AnsiPrint.h"

Controller::Controller() {
    const int defaultRoomIndex = 0;
    RoomData roomData = ROOM_DATA[defaultRoomIndex];

    // initialize class
    rooms[0] = new Room(roomData);

    currentRoomIndex = defaultRoomIndex;
    
    player = new Player(rooms[defaultRoomIndex]->getInitialPosition(), 20, 20, "Player001");

    state = PROCESS_MOVEMENT;
}

// Add your code to implement the Controller class here.
Controller::~Controller(){
    delete rooms[0];
    delete player;
}

RunningState
Controller::run(InputState action){
    Position tempPos = player->getPosition();
    switch (action)
    {
    case ACTION_UP:
        tempPos.moveUP();
        if(rooms[currentRoomIndex]->walkable(tempPos)){
            player->move(action);
        }
        break;
    case ACTION_DOWN:
        tempPos.moveDown();
        if(rooms[currentRoomIndex]->walkable(tempPos)){
            player->move(action);
        }
        break;
    case ACTION_LEFT:
        tempPos.moveLeft();
        if(rooms[currentRoomIndex]->walkable(tempPos)){
            player->move(action);
        }
        break;
    case ACTION_RIGHT:
        tempPos.moveRight();
        if(rooms[currentRoomIndex]->walkable(tempPos)){
            player->move(action);
        }
        break;
    
    default:
        break;
    }
    render();
    return PLAY;
}
















// render
void Controller::render() {
    switch (state) {
    case PROCESS_MOVEMENT:{
        for (int y = 0; y < GAME_WINDOW_SIZE_Y; y++) {
            for (int x = 0; x < GAME_WINDOW_SIZE_X; x++) {
                if(player->getPosition() == Position(x, y)) {
                    player->render();
                    continue;
                }
                rooms[currentRoomIndex]->render(Position(x, y));
            }
            AnsiPrint("\n", nochange, nochange);
        }
        break;
    }
    
    default:
        break;
    }
    output();
}