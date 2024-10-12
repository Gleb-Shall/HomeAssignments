all: total

total: main.o ReversePolishNotation.o
	g++ -Wall main.o ReversePolishNotation.o -o total

main.o: main.cpp
	g++ -c main.cpp

ReversePolishNotation.o: ReversePolishNotation.cpp
	g++ -c ReversePolishNotation.cpp

clean:
	rm -rf *.o total
