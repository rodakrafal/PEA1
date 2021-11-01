#include "Graph.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iostream>
#include <fstream>

using namespace std;

Graph::Graph(bool x, int y){ // konstuktor z argumentem decydującym czy graf jest skierowany czy nie
    this->vertices = 0;
    this->created = true;
    this->edges = 0;
    this->wrong = false;
    this->isDirected = y;
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

void Graph::createTable(int V){ // tworzenie tablicy dwu wymiarowej zawierajacej połączenia między wierzchołkami 
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


void Graph::setFirstVertice(int x){ //ustawianie wartości "pierwszego" wierzchołka
    this->first_vertice =x;
}

int Graph::getFirstVertice(){ // getter dla "pierwszego" wierzchołka
    return first_vertice;
}

void Graph::setLastVertice(int x){ //ustawianie wartości "ostatniego" wierzchołka
    this->last_vertice = x;
}

int Graph::getLastVertice(){ // getter dla "ostatniego" wierzchołka
    return last_vertice;
}

int Graph::getVertices(){ // getter dla ilości wierzchołków
    return vertices;
}

int Graph::getEdges(){ // getter dla ilości krawędzi
    return edges;
}

bool Graph::checkIfNegativ(){ // getter dla ilości krawędzi
    return wrong;
}

void Graph::addEdge(int x, int y, int weight){   // dodawanie połączeń między wierzchołkami
    
    if (x==y) weight = numeric_limits<int>::max();
    tableMatrix[x][y] = weight;   // dla grafu skierowanego
    // if(!isDirected){    //dla grafu nieskierowanego
    //     tableMatrix[y][x] = weight;
    // }
}

void Graph::printGraphMatrix(){ // funckja wyświetlająca graficzną reprezentacje grafu
    if(vertices <= 1){
        cout<<"Nie odpowiednia ilosć wierzchołków." << endl;
        return;
    }

    cout << "   \tMacierz Sąsiedztwa" <<endl;
    cout << "  ";
    for (int i = 0; i<vertices; i++){
        cout << i <<"\t";
    }
    cout << endl;
    for (int i = 0; i<vertices;i++){
        cout << i << " ";
        for (int j = 0; j<vertices; j++){
            if(tableMatrix[i][j] == numeric_limits<int>::max()){   // dla wartości największej - reprezentującej nieskończoność wypisywana jest "--" dla przejrzystości 
                if(i == j) cout << "--\t";
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
    if(vertices >1) destruct();

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
            cout << "Graf o " << vertices<< " krawędziach, wczytany z pliku."<< endl<<endl;
            for (int x = 0; x<vertices;x++)
            {
               for (int y = 0; y < vertices;y++){
                    file >> w;
                    if(w<0){
                        wrong = true;
                    }
                    addEdge(x,y,w);
               }
            }
            setFirstVertice(0);
		}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

void Graph::generateGraph(float density, int amountOfVertices){

    if(amountOfVertices >1 && created && edges>0){
        destruct();
    }
    if(amountOfVertices <= 1){
        cout<<"Podano za małą ilość wierzchołków." << endl;
        return;
    }
    vertices = amountOfVertices; // ustawienie podanej ilości wierzchołków
    int amountOfEdges;
    if(!isDirected){
    amountOfEdges = (density * amountOfVertices * (amountOfVertices-1))/2;
    } else amountOfEdges = (density * amountOfVertices * (amountOfVertices-1));
    bool isBool = true;
    int first, second;
    // sprawdzenie czy jest minimalna liczba połaczeń miedzy wierzchołkami
    if(amountOfEdges<amountOfVertices-1){
        amountOfEdges = amountOfVertices-1;
        isBool = false;
    }
    edges = amountOfEdges;  // ustawienie odpowiedniej ilości połączeń
    cout << "\nDla gęstości wynoszącej " << density*100 << "% ilość krawędzi wynosi: " << amountOfEdges << ", podana ilość wierzchołków to: "<< vertices<<endl;
    createTable(vertices); // tworzenie tablicy dwuwymiarowej dla zadanej ilości wierzchołków
    
    //ustawiamy teraz pierwszego wierzchołek - domyślnie będzie to wierzchołek o indeksie 0  "ostatni" wierzchołek - domyslnie jest to n wierzchołek
    first_vertice = 0;
    last_vertice = vertices -1;
    srand(time(0)); 
    // tworzenie tablicy z wierzchołkami
    int tab [vertices];
    for (int i = 0; i<vertices ;i++){
        tab [i] = i;
    }
    // wyymieszanie elementów tablicy zawierajacej wierzchołki - losowa kolejność
    shuffle(tab,vertices);
    
    // tworzenie boolowskiej tablicy zawierającej krawędzie, dla krawędzi której nie chcemy powtarzać dajemy true
    bool ** tabEdge = new bool * [vertices];
    for (int i = 0; i <vertices; ++i){
        tabEdge[i] = new bool [vertices];
    }
    for (int i = 0; i<vertices; i++){
        for (int j =0; j<vertices;j++){
            if(i ==j)tabEdge[i][j] = true;
            else tabEdge[i][j] = false; // false jeżeli krawędź nie została "połączona"
        }
    }
    // zrobienie połaczeń miedzy wierzchołkami - "minimalne", takie łączenie stosowane w celu wystąpienia przynajmniej jedeneg połaczęnia miedzy wierzchołkami
    for(int i = 0; i < vertices;i++){
        if(i+1==vertices){
            break;
        } 
        addEdge(tab[i+1], tab[i], rand()%13);
        tabEdge[tab[i+1]][tab[i]] = true; // ustawiamy połaczenia na true, w celu "poinfomowania" że krawędź została juz wykorzystana/połaczona
        
        if(!isDirected){ // w przypadku grafu nieskierowanego
            tabEdge[tab[i]][tab[i+1]] = true;
        }
        
    }
    // dodanie dodatkowych połaczeń jeżeli takowe mają się znaleść - wynika to ze wzoru na gęstość 
    if(isBool){
        int temp;
        temp = amountOfEdges - vertices +1; 
        cout << "Dla zadanej wyżej gęstości dodane zostanie "<<temp << " krawędzi, pozostała ilość potrzebna była w celu utworzenienia minimalnej ilości połączeń. "<< endl<< endl;
        // amount = vertices-1;
        for (int i = 0; i<temp;i++){
            do{  // sprawdzamy czy dana krawędż została juz stworzona, gdyby była losujemy nowe wartośći
                first = rand()%vertices;
                second = rand()%vertices;
            }while(isDirected ? tabEdge[first][second] : (tabEdge[first][second] || tabEdge[second][first]));
            addEdge(first,second,rand()%13);
            tabEdge[first][second] = true;
            if(!isDirected){
                tabEdge[second][first] = true;
            }
        }
    } else cout << endl;

    for (int i = 0; i<vertices; i++){
       delete [] tabEdge [i];
    }
    delete [] tabEdge;
}

void Graph::shuffle (int arr[], int lenght){ // funckja służąca do losowego ustawienia wartości w tablicy
    int temp;
    int randomIndex;
    for (int i = 0; i < lenght; i++){
        randomIndex = rand()%lenght;
        temp = arr[i];
        arr [i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}