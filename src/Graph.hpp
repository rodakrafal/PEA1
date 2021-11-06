#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <string>
class Graph
{

    private:
    int vertices, first_vertice, edges;      // wierzchołki, krawędzie, pierwszy/ostatni wierzchołek
    bool created;        // czy graf jest skierowany czy nie, domyślnie nie jest
    void destruct();
    
    public:
    int ** tableMatrix;
    Graph();
    ~Graph();     // destruktory
    void createTable (int x);  // tworzenie tabeli 2D zawierającej (reprezentującej) graf nieskierowany - macierz sąsiedztwa

    int getTableValue(int x, int y);
    int getFirstVertice();
    int getVertices();      // getter dla liczby wierzchołków

    void addEdge(int x, int y, int weight);  // dodwawanie krawędzi między wierzchołkami

    void printGraphMatrix();         // wyświetlenie grafu - macierz sąsiedztwa 

    void readFromFile(std::string filename);            // wczytanie grafu z pliku

    void generateGraph(int x);       // generowanie grafu 



};
#endif