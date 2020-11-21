FLAGS = -pedantic-errors -std=c++11
player.o: player.cpp player.h
	g++ $(FLAGS) -c $<
land.o: land.cpp land.h
	g++ $(FLAGS) -c $<
show_choice.o: show_choice.cpp show_choice.h
	g++ $(FLAGS) -c $<
save.o: save.cpp player.h land.h save.h
	g++ $(FLAGS) -c $<
load.o: load.cpp player.h land.h load.h
	g++ $(FLAGS) -c $<
game_init.o: game_init.cpp player.h land.h game_init.h
	g++ $(FLAGS) -c $<
roll.o: roll.cpp roll.h
		g++ $(FLAGS) -c $<
move.o: move.cpp player.h move.h
	g++ $(FLAGS) -c $<
land_manip.o: land_manip.cpp player.h land.h roll.h move.h land_manip.h
	g++ $(FLAGS) -c $<
monopoly.o: monopoly.cpp player.h land.h show_choice.h save.h load.h game_init.h roll.h move.h land_manip.h
	g++ $(FLAGS) -c $<
monopoly: monopoly.o player.o land.o show_choice.o save.o load.o game_init.o roll.o move.o land_manip.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f monopoly monopoly.o player.o land.o show_choice.o save.o load.o game_init.o roll.o move.o land_manip.o
.PHONY: clean
