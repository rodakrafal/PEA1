#include <iostream>
#include <limits>
#include "Graph.hpp"
#include "BruteForce.hpp"
#include "BruteForceStl.hpp"
#include "DynamicPrograming.hpp"


using namespace std;

void displayBruteForce()
{
    // system("clear");
    cout << "================= BRUTE FORCE =================" << endl;
	cout << "\t   1. Load from file" << endl;
    cout << "\t   2. Generate adjacency matrix" << endl;
    cout << "\t   3. Display adjacency matrix" << endl;
    cout << "\t   4. Execute algorithm without Algorithms" << endl;
	cout << "\t   5. Execute algorithm with Algorithms" << endl;
	cout << "\t   0. Back to the main menu" << endl<<endl;
	cout << "Chosen option: ";
}

void displayDynamicPrograming()
{
    // system("clear");
    cout << "================= DYNAMIC PROGRAMING =================" << endl;
	cout << "\t   1. Load from file" << endl;
    cout << "\t   2. Generate adjacency matrix" << endl;
    cout << "\t   3. Display adjacency matrix" << endl;
    cout << "\t   4. Execute algorithm" << endl;
	cout << "\t   0. Back to the main menu" << endl<<endl;
	cout << "Chosen option: ";
}

void displayMainMenu(){
    // system("clear");
    cout << "================== MAIN MENU ==================" << endl;
    cout << "\t   1. Brute Force" << endl;
    cout << "\t   2. B&B" << endl;
    cout << "\t   3. Dynamic programming" << endl;
    cout << "\t   0. Exit" << endl<<endl;
    cout << "Chosen option: ";
}

void menuBruteForce(){
	bool quit = false;
	char option;
    string name;
    Graph graph (false, 0);
    BruteForceStl bForceSTL;
	BruteForce bForce;

	do {
        displayBruteForce();
		cin >> option;

		cout << endl;
		switch (option) {
		case '0':
			quit = true;
		 	break;
		case '1':
			cout << ("Plese enter name of the file: ");
            cin >> name;
            graph.readFromFile(name);
			break;
		case '2':
			float x;
			int y;
			cout << "Enter the density from 0.00 to 1.00: ";
			cin >> x;
			cout << "Enter amount of nodes: ";
			cin >> y;
			graph.generateGraph(x,y);
            break;
        case '3':
        	if(graph.getVertices() <=1){
				cout << ("No adjacency matrix was created.\n");
				break;
			}
            graph.printGraphMatrix();
            break;
         case '4':
			if(graph.getVertices() <=1){
				cout << ("No adjacency matrix was created.\n");
				break;
			}
            bForce.bruteForce(graph);
            break;
		case '5':
			if(graph.getVertices() <=1){
				cout << ("No adjacency matrix was created.\n");
				break;
			}
            bForceSTL.bruteForceStl(graph);
            break;
		default:
			cout << "Wrong option chosen.\n";

		}

	} while (!quit);
}

void menuDynamicPrograming(){
	bool quit = false;
	char option;
    string name;
    Graph graph (false, 0);
	DynamicPrograming dProg;
	do {
        displayDynamicPrograming();
		cin >> option;

		cout << endl;
		switch (option) {
		case '0':
			quit = true;
		 	break;
		case '1':
			cout << ("Plese enter name of the file: ");
            cin >> name;
            graph.readFromFile(name);
			break;
		case '2':
			float x;
			int y;
			cout << "Enter the density from 0.00 to 1.00: ";
			cin >> x;
			cout << "Enter amount of nodes: ";
			cin >> y;
			graph.generateGraph(x,y);
            break;
        case '3':
        	if(graph.getVertices() <=1){
				cout << ("No adjacency matrix was created.\n");
				break;
			}
            graph.printGraphMatrix();
            break;
         case '4':
			// if(graph.getVertices() <=1){
			// 	cout << ("No adjacency matrix was created.\n");
			// 	break;
			// }
            dProg.heldKarp(graph);
            break;
		default:
			cout << "Wrong option chosen.\n";

		}

	} while (!quit);
}

int main(int argc, char* argv[])
{
	bool quit = false;
	char option;
	do {
        displayMainMenu();
		cin >> option;

		cout << endl;
		switch (option) {
		case '0':
			quit = true;
		 	break;
		case '1':
			menuBruteForce();
			break;

		case '2':
			// menuB&B();
			break;

		case '3':
			menuDynamicPrograming();
			break;
		default:
			cout << "Wrong option chosen.\n";

		}

	} while (!quit);

	return 0;

}