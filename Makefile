
CFLAGS = -c -Wall
LFLAGS = -g -o
CMP = g++

all: main

main: main.o function.o
	$(CMP) main.o function.o $(LFLAGS) main

main.o: main.cpp
	$(CMP) $(CFLAGS) main.cpp

function.o: function.c
	$(CMP) $(CFLAGS) function.cpp 

clean: 
	rm *.o main