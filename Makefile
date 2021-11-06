all: run valgrind valgrindleak run_new main

run:
	clear
	g++ -o main main.cpp src/Graph.cpp src/BruteForce.cpp src/BruteForceStl.cpp src/DynamicPrograming.cpp src/BranchAndBound.cpp
	./main

valgrind:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp BruteForce.cpp BruteForceStl.cpp DynamicPrograming.cpp
	valgrind --track-origins=yes ./main

valgrindleak:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp BruteForce.cpp BruteForceStl.cpp DynamicPrograming.cpp
	valgrind --leak-check=full ./main