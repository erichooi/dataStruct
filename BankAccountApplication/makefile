main: main.o BankAccount.o
	g++ -o main main.o BankAccount.o

main.o: main.cpp BankAccount.cpp
	g++ -c main.cpp

BankAccount.o: BankAccount.cpp
	g++ -c BankAccount.cpp

clean:
	rm -rf main.o BankAccount.o main
