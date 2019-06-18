CC=g++
CFLAGS=-c -Wall

all: Output

Output: Main.o HashSet.o
	$(CC) Main.o HashSet.o -o Output
Main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o Main.o 
HashSet.o: HashSet.cpp
	$(CC) $(CFLAGS) HashSet.cpp -o HashSet.o
Clean: 
	rm -rf *.o Output *.out