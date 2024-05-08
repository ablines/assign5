#include "room.h"
#include "roomdata.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

// read data to the Room class
Room::Room(RoomData data) {
    roomID = data.id;
    roomName = data.name;
    roomDescription = data.description;
    playerInitialPosition = data.playerInitialPosition;

    for(int i = 0; i < GAME_WINDOW_SIZE_Y; i++){
        for(int j = 0; j < GAME_WINDOW_SIZE_X; j++){
            defaultRoomObjectMap[i][j] = RoomObject(data.defaultRoomObjectMap[i][j]);
        }
    }
}

// add your code to implement the Room class here

Room::~Room(){}

//todo
bool
Room::walkable(Position position){
    if( 0 > position.getX() || position.getX() >= GAME_WINDOW_SIZE_X){
        return false;
    }else if(0 > position.getY() || position.getY() >= GAME_WINDOW_SIZE_Y){
        return false;
    }
    switch (defaultRoomObjectMap[position.getY()][position.getX()]){
        case OBJECT_NONE:
        case OBJECT_DOOR:
        case OBJECT_GRASS:
            return true;
        case OBJECT_WALL:
        case OBJECT_ROCK:
        case OBJECT_WATER:
        default:
            return false;
    }
}

int
Room::getRoomID(){
    return roomID;
}

Position
Room::getInitialPosition(){
    return playerInitialPosition;
}












// render
void Room::render(Position position) {
    switch(this->defaultRoomObjectMap[position.getY()][position.getX()]) {
        case OBJECT_NONE:
            AnsiPrint("  ", black, black);
            break;
        case OBJECT_DOOR:
            AnsiPrint("DR", yellow, black);
            break;
        case OBJECT_WALL:
            AnsiPrint("██", white, black);
            break;
        case OBJECT_GRASS:
            AnsiPrint("WW", green, black);
            break;
        case OBJECT_ROCK:
            AnsiPrint("▲▲", yellow, black);
            break;
        case OBJECT_WATER:
            if(rand() % 2 == 0) {
                AnsiPrint("~~", cyan, blue);
            } else {
                AnsiPrint("……", cyan, blue);
            }
            break;
    }
}