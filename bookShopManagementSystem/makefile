main: main.o Book.o
	g++-6 -o main main.o Book.o

main.o: main.cpp
	g++-6 -c main.cpp

Book.o: Book.cpp
	g++-6 -c Book.cpp

clean:
	rm -rf main.o Book.o main
