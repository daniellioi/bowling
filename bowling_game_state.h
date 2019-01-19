// bowling_game_state.h
#ifndef BOWLING_GAME_STATE_H
#define BOWLING_GAME_STATE_H

#include "frame.h"
#include <array>


class BowlingGameState {
 public:
  void hitPins(int count);
  int getFrameNum();
  bool isGameOver();
  int getScore();

  int getPins() { return pins_; }
  
  // position is 0.0-1.0f
  int roll(float position);
 private:
  void addPreviousFrameBonuses(int count, int cur_frame);
  void resetPins() { pins_ = 0b1111111111; }
    
  int current_frame_ = 0;
  Frame frames_[10];
    
  int pins_ = 0b1111111111;
};

#endif // BOWLING_GAME_STATE_H

