// bowling_ui_test.cc
#include "catch.hpp"
#include "bowling_ui.h"

// Ensure a frame with spare collects bonus pins from one roll
TEST_CASE("render full frame", "bowling_ui") {
    auto alley = renderAlley(0b1111111111);// all pins
    
    // pin 7
    REQUIRE(alley.at(4) == '/');
    REQUIRE(alley.at(5) == '\\');
    
    // pin 8
    REQUIRE(alley.at(8) == '/');
    REQUIRE(alley.at(9) == '\\');
    
    // pin 9
    REQUIRE(alley.at(12) == '/');
    REQUIRE(alley.at(13) == '\\');
    
    // pin 10
    REQUIRE(alley.at(16) == '/');
    REQUIRE(alley.at(17) == '\\');
    
    
    // pin 4
    REQUIRE(alley.at(22+6) == '/');
    REQUIRE(alley.at(22+7) == '\\');
    
    // pin 5
    REQUIRE(alley.at(22+10) == '/');
    REQUIRE(alley.at(22+11) == '\\');
    
    // pin 6
    REQUIRE(alley.at(22+14) == '/');
    REQUIRE(alley.at(22+15) == '\\');
    
    
    // pin 2
    REQUIRE(alley.at(44+8) == '/');
    REQUIRE(alley.at(44+9) == '\\');
    
    // pin 3
    REQUIRE(alley.at(44+12) == '/');
    REQUIRE(alley.at(44+13) == '\\');
    
    
    // pin 1
    REQUIRE(alley.at(66+10) == '/');
    REQUIRE(alley.at(66+11) == '\\');
    
    REQUIRE(alley == " || /\\  /\\  /\\  /\\ ||\n"
                     " ||   /\\  /\\  /\\   ||\n"
                     " ||     /\\  /\\     ||\n"
                     " ||       /\\       ||\n"
                     " ||                ||\n"
                     " ||                ||\n"
                     " ||                ||\n"
                     " ||                ||\n");
}

// Ensure a frame with spare collects bonus pins from one roll
TEST_CASE("odd pins", "bowling_ui") {
    
    auto alley = renderAlley(0b0101010101);// odd pins
    
    REQUIRE(alley == " || /\\      /\\     ||\n"
                     " ||       /\\       ||\n"
                     " ||         /\\     ||\n"
                     " ||       /\\       ||\n"
                     " ||                ||\n"
                     " ||                ||\n"
                     " ||                ||\n"
                     " ||                ||\n");
}

// Ensure a frame with spare collects bonus pins from one roll
TEST_CASE("even pins", "bowling_ui") {
    
    auto alley = renderAlley(0b1010101010);// even pins
    
    REQUIRE(alley == " ||     /\\      /\\ ||\n"
                     " ||   /\\      /\\   ||\n"
                     " ||     /\\         ||\n"
                     " ||                ||\n"
                     " ||                ||\n"
                     " ||                ||\n"
                     " ||                ||\n"
                     " ||                ||\n");
}