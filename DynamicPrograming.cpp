#include "DynamicPrograming.hpp"
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

void DynamicPrograming::heldKarp(Graph &graph){

	// because we are searching for Hamilton cycle, starting vertex does not matter, it is easier to set it to the last one
    int firstVertice = graph.getVertices()-1;
    // number of vertices except the first one 
    int amoutOfVertecies = firstVertice;
    // binary shift giving the amount of vertices in the path
    int path  = (1 << amoutOfVertecies)-1;

    MapInfo mapInfo;
	// adding first set of distances
    for (int i = 0; i < amoutOfVertecies; i++) {
			mapInfo.parent = firstVertice;
			mapInfo.weight = graph.getTableValue(firstVertice,i);
			umap.insert({{0,i},mapInfo});
	}
    int minPath = INT_MAX;
	
	// main loop with recursion
    for (int destination = 0; destination < amoutOfVertecies; destination++) {
		// getting the distance from destination to the starting vertex using recursion, plus the distance from first to destination - closing the path to make hamilton cycle
		int distance = calculateDistance(graph, amoutOfVertecies,(path & ~(1 << destination)), destination) + graph.getTableValue(destination, firstVertice);
		// if found a shorter path 
		if (distance < minPath) {
			minPath = distance;
		}
    }

	cout << "sciezka minimalna waga: " << minPath << endl;
}

int DynamicPrograming::calculateDistance(Graph &graph, int amoutOfVertecies, int subset, int wantedVertex) { // searching for shortest path 
	auto search = umap.find({subset,wantedVertex}); // if found the connection, return the weight of the path 
	if (search != umap.end()) {
		return search->second.weight;
	} else { // otherwise add the shortes path to the unordered map
		int minPath = INT_MAX; // setting minimal path cost as -1
		int minParent = -1; // setting parent as -1

		for (int destination = 0; destination < amoutOfVertecies; destination++) { // looping through vertices in the path
				if ((subset & (1 << destination)) != 0) { // next vertices in the path
					int nextSubset = (subset & ~(1 << destination)); 
					int distance = calculateDistance(graph, amoutOfVertecies, nextSubset, destination) + graph.getTableValue(destination, wantedVertex); // distance from destination to the starting vertex using recursion

					// getting shortest path and parent
					if (distance < minPath) {
						minPath = distance;
						minParent = destination;
					}
				}
		}

		// adding to the unordered map
		MapInfo mapInfo;
		mapInfo.weight = minPath;
		mapInfo.parent = minParent;
		umap.insert({{subset,wantedVertex},mapInfo});
		return minPath;
	}
}