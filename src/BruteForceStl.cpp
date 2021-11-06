#include "BruteForceStl.hpp"
#include <iostream>
#include <limits>

using namespace std;

void BruteForceStl::bruteForceStl(Graph &graph){
    
    vector <int> pathVer; // vector of vertices
    Result result; // structure of end values
    for (int i = 0; i < graph.getVertices(); i++){ // adding vertices
        pathVer.push_back(i);
    }
    int minPath = numeric_limits<int>::max(); // setting minimal path to max int value
    do {
        int current_weight = 0; 
        for(int i=1; i < pathVer.size(); i++){ 
            current_weight +=  graph.getTableValue(pathVer[i-1], pathVer[i]); // add next weight of the edge
        }
        current_weight +=  graph.getTableValue(pathVer[pathVer.size()-1], pathVer[0]); // closing "the loop"
        if (minPath > current_weight) { // changing minimal path and minimal weight
            minPath = current_weight;
            result.lowestWeight = current_weight;
            result.shortestPath = pathVer;
        }
    } while (next_permutation(pathVer.begin() + 1, pathVer.end())); // end of next permutation
    cout << result.lowestWeight << endl; // printing results
    for ( int y : result.shortestPath){
        cout << y << " ";
    }
    cout << result.shortestPath[0] << endl;

}
