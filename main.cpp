#include <iostream>
#include <limits>
#include "Graph.hpp"
#include "BrutForce.hpp"

using namespace std;

void displayBrutForce()
{
    // system("clear");
    cout << "================= BRUTE FORCE =================" << endl;
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
    BrutForce bForce;
	do {
        displayBrutForce();
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
            bForce.brutForce(graph);
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
			// menuDynamicPrograming();
			break;
		default:
			cout << "Wrong option chosen.\n";

		}

	} while (!quit);

	return 0;

}