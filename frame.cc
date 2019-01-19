#include "frame.h"

void Frame::addPins(int count) {
  if (first == -1) {
      first = count;
  }
  else if(first != 10 && second == -1){
      second = count;
  }
  else {
      addBonus(count);
  }
}

int Frame::nextFrame(int cur_frame) {
  if (cur_frame == 9) { // which is "tenth" bowling frame
      if (bonus2 != -1) {
          return -1; // end of game
      }

      if (isSpare() && bonus1 != -1) {// one extra roll after spare
          return -1; // end of game
      }

      if (isOpen()) {
          return -1; // no bonus rolls
      }
      return cur_frame;
  }
  if (first == 10 || second != -1) {
      return cur_frame + 1;
  }
  return cur_frame;
}

bool Frame::shouldResetPins(int cur_frame) {
    if (cur_frame == 9) { // tenth frame
        if (bonus1 == 10) {
            return true;
        }
        if (isSpare()) {
            return true;
        }
        if (isStrike() && bonus1 == -1){
            return true;
        }
    }
    
    return isStrike() || second != -1;
}

bool Frame::isStrike() {
  return first == 10;
}
bool Frame::isSpare() {
  return first + second == 10;
}
bool Frame::isOpen() {
  return second != -1 && getFrameScore() < 10;
}
int Frame::getFrameScore() {
  return (first  == -1 ? 0 : first) +
         (second == -1 ? 0 : second) +
         (bonus1 == -1 ? 0 : bonus1) +
         (bonus2 == -1 ? 0 : bonus2);
  }
  

void Frame::addBonus(int count) {
  if ((isSpare() || isStrike()) && bonus1 == -1) {
      bonus1 = count;
  } else
  if (isStrike() && bonus2 == -1) {
      bonus2 = count;
  } 
}