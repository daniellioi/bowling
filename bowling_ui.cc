// bowling_ui.cc
#include "bowling_ui.h"

constexpr int p1 = 0b0000000001;
constexpr int p2 = 0b0000000010;
constexpr int p3 = 0b0000000100;
constexpr int p4 = 0b0000001000;
constexpr int p5 = 0b0000010000;
constexpr int p6 = 0b0000100000;
constexpr int p7 = 0b0001000000;
constexpr int p8 = 0b0010000000;
constexpr int p9 = 0b0100000000;
constexpr int p10= 0b1000000000;

std::string renderAlley(int pins) {
    std::string alleyString;
    alleyString.reserve(90);
    
    
    // all pins look like this
    //       " || /\\  /\\  /\\  /\\ ||\n"
    //       " ||   /\\  /\\  /\\   ||\n"
    //       " ||     /\\  /\\     ||\n"
    //       " ||       /\\       ||\n";
    
    alleyString.append(" || ");
    alleyString.append((pins & p7) ? "/\\  " : "    ");
    alleyString.append((pins & p8) ? "/\\  " : "    ");
    alleyString.append((pins & p9) ? "/\\  " : "    ");
    alleyString.append((pins & p10)? "/\\" : "  ");
    
    alleyString.append(" ||\n ||   ");
    alleyString.append((pins & p4) ? "/\\  " : "    ");
    alleyString.append((pins & p5) ? "/\\  " : "    ");
    alleyString.append((pins & p6) ? "/\\" : "  ");
    
    alleyString.append("   ||\n ||     ");
    alleyString.append((pins & p2) ? "/\\  " : "    ");
    alleyString.append((pins & p3) ? "/\\" : "  ");
    
    alleyString.append("     ||\n ||       ");
    alleyString.append((pins & p1) ? "/\\" : "  ");
    alleyString.append("       ||\n");
    
    alleyString.append(" ||                ||\n");
    alleyString.append(" ||                ||\n");
    alleyString.append(" ||                ||\n");
    alleyString.append(" ||                ||\n");
    
    return alleyString;
}