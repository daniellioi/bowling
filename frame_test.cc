// frame_test.cc

#include "catch.hpp"
#include "frame.h"

// Ensure a frame with spare collects bonus pins from one roll
TEST_CASE("frame spare bonus", "frame") {
    Frame frame;
    frame.addPins(7);
    REQUIRE(frame.getFrameScore() ==7);
    REQUIRE(frame.isStrike() == false);
    REQUIRE(frame.isSpare() == false);
    REQUIRE(frame.nextFrame(5) == 5); // should continue frame
    
    frame.addPins(3);
    REQUIRE(frame.getFrameScore() == 10);
    REQUIRE(frame.isStrike() == false);
    REQUIRE(frame.isSpare() == true);
    REQUIRE(frame.nextFrame(5) == 6); // should advance frame
    
    frame.addPins(10);
    REQUIRE(frame.getFrameScore() == 20);
    
    frame.addPins(7);// should be ignored
    REQUIRE(frame.getFrameScore() == 20);
    
    frame.addPins(0);// should be ignored
    REQUIRE(frame.getFrameScore() == 20);
}

// ensure a frame witha strike collects 2 bonus rolls
TEST_CASE("frame strike bonus", "frame") {
    Frame frame;
    frame.addPins(10);
    REQUIRE(frame.getFrameScore() == 10);
    REQUIRE(frame.isStrike() == true);
    REQUIRE(frame.isSpare() == false);
    REQUIRE(frame.nextFrame(5) == 6); // should advance frame
    
    frame.addPins(7);
    REQUIRE(frame.getFrameScore() == 17);
    REQUIRE(frame.isStrike() == true);
    REQUIRE(frame.isSpare() == false);
    
    frame.addPins(2);
    REQUIRE(frame.getFrameScore() == 19);
    REQUIRE(frame.isStrike() == true);
    REQUIRE(frame.isSpare() == false);
    
    frame.addPins(10); // should be ignored
    REQUIRE(frame.getFrameScore() == 19);
    REQUIRE(frame.isStrike() == true);
    REQUIRE(frame.isSpare() == false);
}

TEST_CASE("tenth frame spare", "frame") {
    Frame frame;
    frame.addPins(5);
    REQUIRE(frame.nextFrame(9) == 9);
    REQUIRE(frame.getFrameScore() == 5);
    frame.addPins(5);
    REQUIRE(frame.nextFrame(9) == 9);
    REQUIRE(frame.getFrameScore() == 10);
    frame.addPins(5);
    REQUIRE(frame.nextFrame(9) == -1);// end of game
    REQUIRE(frame.getFrameScore() == 15);
}

TEST_CASE("tenth frame triple", "frame") {
    Frame frame;
    frame.addPins(10);
    REQUIRE(frame.nextFrame(9) == 9);
    REQUIRE(frame.getFrameScore() == 10);
    frame.addPins(10);
    REQUIRE(frame.nextFrame(9) == 9);
    REQUIRE(frame.getFrameScore() == 20);
    frame.addPins(10);
    REQUIRE(frame.nextFrame(9) == -1);// end of game
    REQUIRE(frame.getFrameScore() == 30);
}

