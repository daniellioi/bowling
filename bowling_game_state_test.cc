// bowling_game_state_test.cc

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bowling_game_state.h"



TEST_CASE("roll center", "bowling_game_state") {
    BowlingGameState state;
    state.roll(.5);
    REQUIRE(state.getPins() == 0b1001000000); // 7/10 split
}

TEST_CASE("strike left", "bowling_game_state") {
    BowlingGameState state;
    state.roll(.47);
    REQUIRE(state.getPins() == 0);
}

TEST_CASE("strike right", "bowling_game_state") {
    BowlingGameState state;
    state.roll(.53);
    REQUIRE(state.getPins() == 0);
}

TEST_CASE("gutter left", "bowling_game_state") {
    BowlingGameState state;
    state.roll(.01);
    REQUIRE(state.getPins() == 0b1111111111);
}

TEST_CASE("gutter right", "bowling_game_state") {
    BowlingGameState state;
    state.roll(.99);
    REQUIRE(state.getPins() == 0b1111111111);
}

TEST_CASE("6 left hit", "bowling_game_state") {
    BowlingGameState state;
    state.roll(.38);
    REQUIRE(state.getPins() == 0b1000100101);
}

TEST_CASE("6 right", "bowling_game_state") {
    BowlingGameState state;
    state.roll(.62);
    REQUIRE(state.getPins() == 0b0001001011);
}

TEST_CASE("6 left and right", "bowling_game_state") {
    BowlingGameState state;
    state.roll(.62);
    state.roll(.38);
    REQUIRE(state.getPins() == 0b0000000001);
}

TEST_CASE("basic test", "bowling_game_state") {
    BowlingGameState state;
    
    // Frame 1: 7/3
    state.hitPins(7);
    REQUIRE(state.getScore() == 7);
    REQUIRE(state.getFrameNum() == 1);
    state.hitPins(3);
    REQUIRE(state.getScore() == 10);
    
    // Frame 2: Strike(10)
    REQUIRE(state.getFrameNum() == 2);
    state.hitPins(10);
    REQUIRE(state.getScore() == 30);
    
    // Frame 3: 7/0 open
    REQUIRE(state.getFrameNum() == 3);
    state.hitPins(7);
    REQUIRE(state.getFrameNum() == 3);
    REQUIRE(state.getScore() == 44);
    
    state.hitPins(0);
    REQUIRE(state.getScore() == 44);
}

TEST_CASE("perfect game 12 strikes", "bowling_game_state") {
    BowlingGameState state;
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    REQUIRE(state.getScore() == 60);
    REQUIRE(state.getFrameNum() == 4);
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    REQUIRE(state.getScore() == 150);
    REQUIRE(state.getFrameNum() == 7);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    REQUIRE(state.getScore() == 240);
    REQUIRE(state.getFrameNum() == 10);
    
    state.hitPins(10);
    REQUIRE(state.getFrameNum() == 10);
    
    state.hitPins(10);
    REQUIRE(state.getFrameNum() == 10);
    
    state.hitPins(10);
    REQUIRE(state.getScore() == 300);
    REQUIRE(state.isGameOver() == true);
}

TEST_CASE("open tenth frame", "bowling_game_state") {
    BowlingGameState state;
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    REQUIRE(state.getFrameNum() == 10);
    
    state.hitPins(5);
    state.hitPins(4);
    REQUIRE(state.isGameOver() == true);
    REQUIRE(state.getScore() == 263); // 240+15+8
    
}

TEST_CASE("spare tenth frame", "bowling_game_state") {
    BowlingGameState state;
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    REQUIRE(state.getFrameNum() == 10);
    
    state.hitPins(5);
    
    REQUIRE(state.getFrameNum() == 10);
    state.hitPins(5);
    REQUIRE(state.getScore() == 265); // 240+15+10
    REQUIRE(state.isGameOver() == false);
    
    state.hitPins(5);
    REQUIRE(state.getScore() == 270); // 240+15+10+5
    REQUIRE(state.isGameOver() == true);
}

TEST_CASE("tenth frame 10 0 10", "bowling_game_state") {
    BowlingGameState state;
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    REQUIRE(state.getFrameNum() == 10);
    
    state.hitPins(10);
    
    REQUIRE(state.getFrameNum() == 10);
    state.hitPins(0);
    REQUIRE(state.getScore() == 270); // 240+30
    REQUIRE(state.isGameOver() == false);
    
    state.hitPins(10);
    REQUIRE(state.getScore() == 280); // 240+30+10
    REQUIRE(state.isGameOver() == true);
}

TEST_CASE("tenth frame 10 0 0", "bowling_game_state") {
    BowlingGameState state;
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    
    state.hitPins(10);
    state.hitPins(10);
    state.hitPins(10);
    REQUIRE(state.getFrameNum() == 10);
    
    state.hitPins(10);
    
    REQUIRE(state.getFrameNum() == 10);
    state.hitPins(0);
    REQUIRE(state.getScore() == 270); // 240+30
    REQUIRE(state.isGameOver() == false);
    
    state.hitPins(0);
    REQUIRE(state.getScore() == 270); // 240+30+10
    REQUIRE(state.isGameOver() == true);
}

TEST_CASE("all single pin hits", "bowling_game_state") {
    BowlingGameState state;
    
    for(int i = 0; i < 20; i++) {
        state.hitPins(1);
    }
    REQUIRE(state.getScore() == 20); // 240+30
    REQUIRE(state.isGameOver() == true);
}
