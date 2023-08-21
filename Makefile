CC = g++
CFLAGS = -std=c++11

all: main

main: main.o Request.o Game.o
	$(CC) $(CFLAGS) -o main main.o Request.o Game.o -lcurl

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -lcurl

Request.o: Request.cpp Request.h
	$(CC) $(CFLAGS) -c Request.cpp -lcurl

Game.o: Game.cpp Game.h
	$(CC) $(CFLAGS) -c Game.cpp

clean:
	rm -f *.o main
