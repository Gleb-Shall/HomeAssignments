all: total

total: main.o Gun.o Transformer.o
	g++ main.o Gun.o Transformer.o -o total

main.o: main.cpp
	g++ -c main.cpp

Gun.o: Gun.cpp
	g++ -c Gun.cpp

Transformer.o: Transformer.cpp
	g++ -c Transformer.cpp

clean:
	rm -rf *.o total
