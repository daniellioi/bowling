// bowling_game.cc
#include <curses.h>
#include "bowling_game.h"
#include "bowling_ui.h"

void BowlingGame::calculateRoll(float position) { 
    int pinsHit = state_.roll(position); 
    drawFrame();
    drawRoll(position);
    sleep(2);
    state_.hitPins(pinsHit);
    drawFrame();
}
void BowlingGame::drawFrame() {
    mvprintw(0,0,"%s", renderAlley(state_.getPins()).c_str());
    refresh();
}
void BowlingGame::drawRoll(float position) {
    int column = position * 22;
    for(int i = 0; i < 8; i++) {
      mvprintw(i, column, "O");
    }
    refresh();
}