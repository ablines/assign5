#ifndef GAMECORE_H
#define GAMECORE_H

#include "../controller/controller.h"

// The gamecore class is for handling the effects of external events on the game.
// You probably don't need to modify this class and .cpp file.

class GameCore {
private:
    Controller gameController;

public:
    GameCore();
    ~GameCore();

    GameState lifeCycle(InputState action);
    
    static InputState ConvertInputToAction(int input);
};

#endif