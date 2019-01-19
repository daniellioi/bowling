// bowling_game_state.cc
#include "bowling_game_state.h"

// simple attemp to simulate pin strikes, this could be improved
int BowlingGameState::roll(float pos) {
    int start_pins = pins_;
    if (pos <= .125 || pos >= 1.0-.125) { // gutter
        return 0;
    }
    
    if (pins_ & 0b1) { // if head pin present
        if (pos >= .48 && pos <= .52) { // too center, split
            pins_ &= 0b1001000000;
        }
        if ((pos <= .48 && pos >= .45) ||
            (pos >= .52 && pos <= .55)) { // strike
            pins_ = 0;
        }
    }
    if (pos <= .45 && pos >= .35) { // left 6 pins
        pins_ &= 0b1000100101;
    }
    if (pos >= .55 && pos <= .65) { // right 6 pins
        pins_ &= 0b0001001011;
    }
    if (pos <= .35 && pos >= .25) { // left 3
        pins_ &= 0b1100110111;
    }
    if (pos >= .65 && pos <= .75) {// right 3
        pins_ &= 0b0011011111;
    }
    if (pos >= .75) { // right pin
        pins_ &= 0b0111111111;
    }
    if (pos <= .25) { // left pin
        pins_ &= 0b1110111111;
    }
    int hit_bits = start_pins - pins_;
    int hit_count = 0;
    for(int i = 0; i < 10; i++) {
        hit_count += hit_bits & 0b1;
        hit_bits = hit_bits >> 1;
    }
    
    return hit_count;
}
void BowlingGameState::hitPins(int count) {
    if (isGameOver()) {
        // game over just return
        return;
    }
    
    frames_[current_frame_].addPins(count);
    
    addPreviousFrameBonuses(count, current_frame_);

    if (frames_[current_frame_].shouldResetPins(current_frame_)) {
        resetPins();
    }
    
    current_frame_ = frames_[current_frame_].nextFrame(current_frame_);
}

void BowlingGameState::addPreviousFrameBonuses(int count, int cur_frame) {
    if (cur_frame >= 2) {
        frames_[cur_frame-2].addPins(count);
    }
    if (cur_frame >= 1) {
        frames_[cur_frame-1].addPins(count);
    }
}

int BowlingGameState::getFrameNum() {
    return current_frame_ + 1;
}
bool BowlingGameState::isGameOver() {
    return current_frame_ == -1;
}
int BowlingGameState::getScore() {
    int sum = 0;
    for(int i = 0; i < 10; i++) {
      sum+=frames_[i].getFrameScore();   
    }
    return sum;
}