all: run valgrind valgrindleak run_new main

run:
	clear
	g++ -o main main.cpp Graph.cpp
	./main

valgrind:
	clear
	g++ -ggdb -o main.cpp Graph.cpp
	valgrind --track-origins=yes ./main

valgrindleak:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp
	valgrind --leak-check=full ./main