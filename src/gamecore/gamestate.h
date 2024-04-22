#ifndef GAMESTSATE_H
#define GAMESTSATE_H

enum GameState {
    GAME_STATE_PLAY,
    GAME_STATE_EXIT
};

enum InputState {
    GAME_ACTION_NONE,
    GAME_ACTION_UP,
    GAME_ACTION_DOWN,
    GAME_ACTION_LEFT,
    GAME_ACTION_RIGHT,
    GAME_ACTION_CONFIRN,
    GAME_ACTION_EXIT,
    GAME_ACTION_INIT
};

#endif