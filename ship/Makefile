all: compile link

compile:
	g++ -I src/include -c main.cpp -c entity.cpp -c player.cpp -c ship.cpp -c Vector2.cpp

link:
	g++ main.o entity.o player.o ship.o Vector2.o -o main -L src/lib -l sfml-system -l sfml-window -l sfml-graphics