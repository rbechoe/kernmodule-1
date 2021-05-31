all: compile link

compile:
	g++ -I src/include -c main.cpp -c manager.cpp -c entity.cpp -c player.cpp -c ship.cpp -c vector2.cpp -c enemy.cpp

link:
	g++ main.o manager.o entity.o enemy.o player.o ship.o vector2.o -o main -L src/lib -l sfml-system -l sfml-window -l sfml-graphics