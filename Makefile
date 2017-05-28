BananaStand: main.o
	g++ main.o -o BananaStand
main.o: main.cpp
	g++ -c main.cpp
clean: 
	rm main.o BananaStand
