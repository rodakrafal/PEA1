#include "Graph.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iostream>
#include <fstream>

using namespace std;

Graph::Graph(){ // konstuktor z argumentem decydującym czy graf jest skierowany czy nie
    this->vertices = 0;
    this->created = true;
    this->first_vertice = 0;
    this->edges = 0;
}


Graph::~Graph(){ // destruktor
    if(vertices>=1){
    destruct();
    }
}

void Graph::destruct(){ // "wnętrze" destruktora
    for (int i = 0; i<vertices; i++){
        delete [] tableMatrix [i];
    }
    delete [] tableMatrix;
}

void Graph::createTable(int V){ // tworzenie tablicy dwu wymiarowej zawierajacej połączenia między wierzołkami 
    if(V <= 1){
        cout << "To little nodes were given."<<endl;
        return;
    }

    tableMatrix = new int * [V];
    for (int i = 0; i <V; ++i){
        tableMatrix[i] = new int [V];
    }
    for (int i = 0; i<V; i++){
        for (int j =0; j<V;j++){
            tableMatrix[i][j] = numeric_limits<int>::max();       // tablica początkowo wypełniana jest nieskończonością - nawjwiększą wartością dla tego typu
        }
    }
}

int Graph::getTableValue(int x, int y){ //getter dla tablicy dwuwymiarowej
    return tableMatrix[x][y];
}

int Graph::getFirstVertice(){ // getter dla "pierwszego" wierzchołka
    return first_vertice;
}

int Graph::getVertices(){ // getter dla ilości wierzchołków
    return vertices;
}

void Graph::addEdge(int x, int y, int weight){   // dodawanie połączeń między wierzchołkami
    
    if (x==y) weight = numeric_limits<int>::max();
    tableMatrix[x][y] = weight;   // dla grafu skierowanego
}

void Graph::printGraphMatrix(){ // funckja wyświetlająca graficzną reprezentacje grafu
    if(vertices <= 1){
        cout<<"To little nodes were given." << endl;
        return;
    }
    if(vertices > 6){
        for (int i = 0; i < (int)(vertices/4) ;i++){
            cout << "\t";
        }
    }    
    cout << "   \tADJACENCY MATRIX" <<endl;
    cout << "  ";
    for (int i = 0; i<vertices; i++){
        cout << i <<"\t";
    }
    cout << endl;
    for (int i = 0; i<vertices;i++){
        cout << i << " ";
        for (int j = 0; j<vertices; j++){
            if(tableMatrix[i][j] == numeric_limits<int>::max()){   // dla wartości największej - reprezentującej nieskończoność wypisywana jest "--" dla przejrzystości 
                if(i == j) cout << "-1\t";
                else cout << " " << "\t";
            }else {
                cout << tableMatrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout <<endl <<endl;
}


void Graph::readFromFile(string filename){ // wczytywanie grafu z pliku
    if(vertices >1 && created && edges>0) destruct();

    ifstream file;
	file.open(filename);
	int first,last,w;
	if (file.is_open())
	{
        file >> vertices;
		if (vertices <= 0) {
			cout << "Not enough vertices were given" << endl;
			return;
		}
        cout << endl;
		if (file.fail())
			cout << "File error - READ SIZE" << endl;
		else {
            createTable(vertices);
            for (int x = 0; x<vertices;x++)
            {
               for (int y = 0; y < vertices;y++){
                    file >> w;
                    addEdge(x,y,w);
               }
            }
            first_vertice = 0;
		}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

void Graph::generateGraph(int amountOfVertices){

    if(amountOfVertices >1 && created && edges>0) destruct();
    
    if(amountOfVertices <= 1){
        cout<<"To little nodes were given." << endl;
        return;
    }
    vertices = amountOfVertices;
    createTable(vertices);
    for (int i = 0; i < vertices; i ++){
        for (int j = 0; j < vertices; j++){
            addEdge(i,j,rand()%100+1);
        }
    }
}