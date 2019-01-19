// frame.h
#ifndef FRAME_H
#define FRAME_H

//  Frame class manages state of an individual frame
//  it knows when it should receive bonus pins from
//  spares and strikes, particularly in regard to the
//  tenth frame rules.  It knows when to advance to 
//  the next frame.
class Frame {
 public:
  // adds pins for first/second roll and bonus pins for
  // strike/spare
  void addPins(int count);
    
  // based on the state of the frame determines if the
  // game should move onto the next frame
  int nextFrame(int cur_frame);

  bool shouldResetPins(int cur_frame);

  bool isStrike();
  bool isSpare();
  bool isOpen();
  int getFrameScore();
  
 private:
  void addBonus(int count);
    
  int first = -1;  // first roll of frame
  int second = -1; // second..
  int bonus1 = -1; // bonus pins from next roll for strike/spare on this frame
  int bonus2 = -1; // bonus pins from 2nd next roll for strike on this frame
};

#endif // FRAME_H