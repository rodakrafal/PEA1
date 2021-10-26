#include "BruteForce.hpp"
#include <iostream>
#include <limits>

using namespace std;

void BruteForce::bruteForce(Graph &graph){ // main function responsible for the algorithm

    int *tab = new int [graph.getVertices()-1]; // creating temporary array of vertices
    int *tabTemp = new int [graph.getVertices()-1]; // creating temporary array of vertices with the best path
    int j = 0;
    for (int i = 0; i < graph.getVertices(); i++){ // initializing temporary array of vertices
        if (i != graph.getFirstVertice()) // omit the first vertice
        {
            tab [j] = i;
            j++;
        }
    }
    int minPath = numeric_limits<int>::max(); // set minimal path to max int size
    permutation(tab, 0, graph.getVertices()-2, graph, minPath,tabTemp); // premutate - main logic
    { // visual output of the Brute Force algorithm
        cout <<  minPath << endl; // the lowest path weight
        cout << graph.getFirstVertice() << " ";
        for (int i = 0; i < graph.getVertices()-1; i++){
            cout << tabTemp [i] << " ";
        }
        cout << graph.getFirstVertice() << endl;
    } 
    delete [] tab;
    delete [] tabTemp;
}

void BruteForce::permutation(int *arr, int start, int end, Graph &graph, int &minPath, int *tabTemp){ 
    if(start==end){
        int current_weight = 0; // set current path weight to 0
        int current_vert = graph.getFirstVertice(); // set the first vertice 
        for(int i=0; i<=end; i++){ 
            current_weight +=  graph.getTableValue(current_vert, arr[i]); // add next weight of the edge
            current_vert = arr [i]; // change current vertice to the next one
        }
        current_weight +=  graph.getTableValue(current_vert, graph.getFirstVertice()); // connect the last vertice to the first one

        if (minPath>current_weight) { // if current path weight is lower change the value
            for (int i = 0; i <= end; i++){ // copy path of vertices to tabTemp
                tabTemp[i]=arr[i];
            }
            minPath = current_weight;
        }
        return;
    }
    for(int i =start;i<=end;i++){ // main logic behind the permutation
        swap((arr[i]), (arr[start]));
        permutation(arr, start+1, end, graph, minPath,tabTemp);
        swap((arr[i]), (arr[start]));
    }
}

void BruteForce::swap(int &a, int &b){ // simple swap method
    int temp;
    temp = a;
    a = b;
    b = temp;
}
