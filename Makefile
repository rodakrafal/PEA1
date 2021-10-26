all: run valgrind valgrindleak run_new main

run:
	clear
	g++ -o main main.cpp Graph.cpp BrutForce.cpp BruteForceStl.cpp
	./main

valgrind:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp BrutForce.cpp BruteForceStl.cpp
	valgrind --track-origins=yes ./main

valgrindleak:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp BrutForce.cpp BruteForceStl.cpp
	valgrind --leak-check=full ./main