CC = g++
CFLAGS = -Wall -Wextra -std=c++11

build: 1 2 3

1: 1.cpp
	$(CC) $(CFLAGS) -o 1 1.cpp
2: 2.cpp
	$(CC) $(CFLAGS) -o 2 2.cpp
3: 3.cpp
	$(CC) $(CFLAGS) -o 3 3.cpp

run-1:
	$(CC) $(CFLAGS) -o 1 1.cpp
	./1
run-2:
	$(CC) $(CFLAGS) -o 2 2.cpp
	./2
run-3:
	$(CC) $(CFLAGS) -o 3 3.cpp
	./3
run: run-1 run-2 run-3
clean:
	rm -f 1 2 3