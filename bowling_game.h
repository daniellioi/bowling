// bowling_game.h
#ifndef BOWLING_GAME
#define BOWLING_GAME

#include "bowling_game_state.h"

#include <unistd.h>

class BowlingGame {
public:
    bool isGameOver() { return state_.isGameOver(); }
    int getScore() { return state_.getScore(); }
    void calculateRoll(float position);

    
    void drawRoll(float position);
    void start() {
        drawFrame();
    }
    
private:
    void drawFrame();
    BowlingGameState state_;
};

#endif // BOWLING_GAME
