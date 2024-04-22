#include "room.h"
#include "roomdata.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

// read data to the Room class
Room::Room(RoomData data) {
    
}

// add your code to implement the Room class here

















// render
void Room::render(Position position) {
    switch(this->defaultRoomObjectMap[position.getY()][position.getX()]) {
        case ROOM_OBJECT_NONE:
            AnsiPrint("  ", black, black);
            break;
        case ROOM_OBJECT_DOOR:
            AnsiPrint("DR", yellow, black);
            break;
        case ROOM_OBJECT_WALL:
            AnsiPrint("██", white, black);
            break;
        case ROOM_OBJECT_GRASS:
            AnsiPrint("WW", green, black);
            break;
        case ROOM_OBJECT_ROCK:
            AnsiPrint("▲▲", yellow, black);
            break;
        case ROOM_OBJECT_WATER:
            if(rand() % 2 == 0) {
                AnsiPrint("~~", cyan, blue);
            } else {
                AnsiPrint("……", cyan, blue);
            }
            break;
    }
}