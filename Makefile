output: critter.o board.o yomu.o main.o
	g++ -std=c++11 critter.o board.o yomu.o main.o -o output

critter.o: critter.cpp
	g++ -c -std=c++11 critter.cpp

board.o: board.cpp
	g++ -c -std=c++11 board.cpp

yomu.o: yomu.cpp
	g++ -c -std=c++11 yomu.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

make clean:
	rm *.o output
