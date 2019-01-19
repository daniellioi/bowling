#include <stdio.h>
#include <time.h>
#include <curses.h>
#include "bowling_game.h"



int main() {
  BowlingGame game;
  int input;
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, true);  
  
  game.start();

  do {
    input = getch();
      
    long millis = (clock() % CLOCKS_PER_SEC)*1000/CLOCKS_PER_SEC;
    char ball_position_output[23] = "[                    ]";
    
    ball_position_output[millis/50+1] = '*';
    mvprintw(9, 0, "%s", ball_position_output);
    refresh();
      
    if (input == ' ') {
        game.calculateRoll( (float)millis/1000.0 );
        if (game.isGameOver()) {
            break;
        }
    }
  } while (input != 'q');
  endwin();
  printf("Game over score: %d\n", game.getScore());
  return 0;
}
