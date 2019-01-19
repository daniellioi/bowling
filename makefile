all: bowl bowling_test

bowl: bowl.o bowling_ui.o bowling_game.o bowling_game_state.o frame.o
	g++ -std=c++11 -o bowl bowl.o bowling_ui.o bowling_game.o bowling_game_state.o frame.o -lncurses

bowling_test: bowling_game_state_test.o bowling_game_state.o frame_test.o frame.o bowling_ui_test.o bowling_ui.o
	g++ -std=c++11 -o bowling_test bowling_game_state_test.o bowling_game_state.o frame_test.o frame.o bowling_ui_test.o bowling_ui.o

bowl.o: bowl.cc bowling_game.h
	g++ -std=c++11 -c bowl.cc

bowling_game.o : bowling_game.cc bowling_game.h
	g++ -std=c++11 -c bowling_game.cc

bowling_game_state.o: bowling_game_state.cc bowling_game_state.h frame.h
	g++ -std=c++11 -c bowling_game_state.cc

frame.o: frame.cc frame.h
	g++ -std=c++11 -c frame.cc

bowling_ui.o: bowling_ui.cc bowling_ui.h
	g++ -std=c++11 -c bowling_ui.cc

frame_test.o: frame_test.cc frame.h
	g++ -std=c++11 -c frame_test.cc

bowling_ui_test.o: bowling_ui_test.cc bowling_ui.h
	g++ -std=c++11 -c bowling_ui_test.cc

bowling_game_state_test.o: bowling_game_state_test.cc bowling_game_state.h frame.h
	g++ -std=c++11 -c bowling_game_state_test.cc

clean:
	rm *.o bowl bowling_test
